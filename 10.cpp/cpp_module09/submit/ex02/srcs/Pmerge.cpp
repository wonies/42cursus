#include "../include/Pmerge.hpp"

void Pmerge::jnum(int n) {
  _sequence.push_back(0);
  _sequence.push_back(1);
  for (int i = 2; i <= n + 1; ++i) {
    int next = (_sequence[i - 1]) + (_sequence[i - 2] * 2);
    _sequence.push_back(next);
  }
}

void Pmerge::mainsort(int left, int mid, int right) {
  std::vector<std::pair<int, int> > _L(mid - left + 1);
  std::vector<std::pair<int, int> > _R(right - mid);
  int lsize = _L.size();
  int rsize = _R.size();
  for (int i = 0; i < lsize; i++) _L[i] = _vector[left + i];
  for (int i = 0; i < rsize; i++) _R[i] = _vector[mid + 1 + i];

  int i = 0;
  int j = 0;
  int k = left;

  while (i < lsize && j < rsize) {
    if (_L[i].first <= _R[j].first) {
      _vector[k++] = _L[i++];
    } else {
      _vector[k++] = _R[j++];
    }
  }
  while (i < lsize) _vector[k++] = _L[i++];
  while (j < rsize) _vector[k++] = _R[j++];
}

void Pmerge::binaryinsert(int value, int left, int right) {
  if (left >= right) {
    if (mainchain[left] > value) {
      k++;
      mainchain.insert(mainchain.begin() + left, value);
    } else {
      mainchain.insert(mainchain.begin() + left + 1, value);
    }
    return;
  }
  int mid = (left + right) / 2;
  if (mainchain[mid] == value) {
    mainchain.insert(mainchain.begin() + mid, value);
    return;
  } else if (mainchain[mid] < value) {
    binaryinsert(value, mid + 1, right);
  } else {
    binaryinsert(value, left, mid);
  }
}

void Pmerge::pendtomain(int idx, int bidx) {
  while (idx > bidx) {
    binaryinsert(_vector[idx - 1].second, 0, idx + k - 1);
    idx--;
  }
}

void Pmerge::pendingorder(void) {
  int j = 1;
  int ssize = _sequence.size();
  while (j < ssize) {
    if (pairsize < _sequence[j]) {
      pendtomain(pairsize, _sequence[j - 1]);
      if (_vecsize % 2 != 0) {
        int msize = mainchain.size();
        binaryinsert(oddvec, 0, msize - 1);
      }
      break;
    } else {
      pendtomain(_sequence[j], _sequence[j - 1]);
      j++;
    }
  }
}

void Pmerge::sortpair(int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    sortpair(left, mid);
    sortpair(mid + 1, right);
    mainsort(left, mid, right);
  }
}

void Pmerge::pairvector(void) {
  int mid = vec.size() / 2;
  for (int i = 0; i < mid; i++) {
    if (vec[i] > vec[i + mid])
      _vector.push_back(std::make_pair(vec[i], vec[i + mid]));
    else
      _vector.push_back(std::make_pair(vec[i + mid], vec[i]));
  }
  sortpair(0, mid - 1);
}

void Pmerge::pair(void) {
  pairsize = vec.size() / 2;
  pairvector();
  jnum(pairsize + 1);
  for (int i = 0; i < pairsize; ++i) mainchain.push_back(_vector[i].first);
  pendingorder();
}

bool Pmerge::input(int ac, char **av) {
  if (ac == 2) {
    // int i = 0;
    // int numflag = 0;
    // std::string systeminput;
    // while (av[1][i] != '\0') {
    //   systeminput += av[1][i];
    //   if (av[1][i] < 48 || av[1][i] > 57) numflag = 1;
    //   ++i;
    // }
    // if (numflag == 1) {
    //   FILE *pipe = popen(systeminput.c_str(), "r");
    //   if (!pipe) throw std::runtime_error("Error: can't read the command");
    //   char buf[128];
    //   while (fgets(buf, sizeof(buf), pipe) != NULL) {
    //     std::istringstream iss(buf);
    //     int num = 0;
    //     while (iss >> num) vec.push_back(num);
    //   }
    // } else {
    throw std::runtime_error("Error: can't sort");
    // }
  } else {
    int i = 0;
    char *endptr = NULL;
    while (av[++i]) {
      double input = strtod(av[i], &endptr);
      if (*endptr != '\0') throw std::runtime_error("Error: not valid input");
      if (input >= INT_MAX) throw std::runtime_error("Error: not integer");
      vec.push_back(input);
      deq.push_back(input);
    }
    _vecsize = vec.size();
    _deqsize = _vecsize;
    int sortflag = 0;
    for (int i = 0; i < _vecsize - 1; i++) {
      if (vec[i] > vec[i + 1]) sortflag = 1;
    }
    if (sortflag == 0) {
      throw std::runtime_error("Error: already sorted");
    }
    k = 0;
    ic = 0;
    if (_vecsize % 2 != 0) {
      oddvec = vec[_vecsize - 1];
    }
    i = 0;
    std::cout << "Before: ";
    while (i < _vecsize) {
      std::cout << vec[i++] << " ";
    }
    std::cout << "\n";
  }
  return true;
}

void Pmerge::execute(int ac, char **av) {
  input(ac, av);
  _vecsize = vec.size();
  clock_t vecstart = clock();
  pair();
  clock_t vecend = clock();
  std::cout << "After: ";
  int i = -1;
  while (++i < _vecsize) std::cout << mainchain[i] << " ";
  double usec = (((double)(vecend - vecstart)) * 10 / CLOCKS_PER_SEC);
  // double usec = ((double)(vecend - vecstart)) * 1000000;
  std::cout << "\nTime to process a range of " << _vecsize
            << " elements with std::vector : " << usec << " us\n";
  clock_t deqstart = clock();
  pairdeq();
  clock_t deqend = clock();
  i = -1;
  // while (++i < _deqsize) std::cout << deqmainchain[i] << " ";
  double usecdeq = (((double)(deqend - deqstart)) * 10 / CLOCKS_PER_SEC);
  std::cout << "Time to process a range of " << _deqsize
            << " elements with std::deque : " << usecdeq << " us\n";
}

void Pmerge::jnumdeq(int n) {
  _seq.push_back(0);
  _seq.push_back(1);
  for (int i = 2; i <= n + 1; ++i) {
    int next = (_seq[i - 1]) + (_seq[i - 2] * 2);
    _seq.push_back(next);
  }
}

void Pmerge::mainsortdeq(int left, int mid, int right) {
  std::deque<std::pair<int, int> > _L(mid - left + 1);
  std::deque<std::pair<int, int> > _R(right - mid);
  int lsize = _L.size();
  int rsize = _R.size();
  for (int i = 0; i < lsize; i++) _L[i] = _deque[left + i];
  for (int i = 0; i < rsize; i++) _R[i] = _deque[mid + 1 + i];

  int i = 0;
  int j = 0;
  int k = left;

  while (i < lsize && j < rsize) {
    if (_L[i].first <= _R[j].first) {
      _deque[k++] = _L[i++];
    } else {
      _deque[k++] = _R[j++];
    }
  }
  while (i < lsize) _deque[k++] = _L[i++];
  while (j < rsize) _deque[k++] = _R[j++];
}

void Pmerge::sortdeque(int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    sortdeque(left, mid);
    sortdeque(mid + 1, right);
    mainsortdeq(left, mid, right);
  }
}

void Pmerge::binaryinsertdeq(int value, int left, int right) {
  if (left >= right) {
    if (deqmainchain[left] > value) {
      ic++;
      deqmainchain.insert(deqmainchain.begin() + left, value);
    } else {
      deqmainchain.insert(deqmainchain.begin() + left + 1, value);
    }
    return;
  }
  int mid = (left + right) / 2;
  if (deqmainchain[mid] == value) {
    deqmainchain.insert(deqmainchain.begin() + mid, value);
    return;
  } else if (deqmainchain[mid] < value) {
    binaryinsertdeq(value, mid + 1, right);
  } else {
    binaryinsertdeq(value, left, mid);
  }
}

void Pmerge::pendtomaindeq(int idx, int bidx) {
  while (idx > bidx) {
    binaryinsertdeq(_vector[idx - 1].second, 0, idx + ic - 1);
    idx--;
  }
}

void Pmerge::pendingorderdeq(void) {
  int j = 1;
  int ssize = _seq.size();
  while (j < ssize) {
    if (pairsize < _seq[j]) {
      pendtomaindeq(pairsize, _seq[j - 1]);
      if (_deqsize % 2 != 0) {
        int msize = deqmainchain.size();
        binaryinsertdeq(oddvec, 0, msize - 1);
      }
      break;
    } else {
      pendtomaindeq(_seq[j], _seq[j - 1]);
      j++;
    }
  }
}

void Pmerge::pairdeque(void) {
  int mid = deq.size() / 2;
  for (int i = 0; i < mid; ++i) {
    if (deq[i] > deq[i + mid])
      _deque.push_back(std::make_pair(deq[i], deq[i + mid]));
    else
      _deque.push_back(std::make_pair(deq[i + mid], vec[i]));
  }
  sortdeque(0, mid - 1);
}

void Pmerge::pairdeq(void) {
  pairdeque();
  jnumdeq(pairsize + 1);
  for (int i = 0; i < pairsize; ++i) deqmainchain.push_back(_deque[i].first);
  pendingorderdeq();
}