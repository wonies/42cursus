void Pmerge::jnum(int n) {
  _sequence.push_back(0);
  _sequence.push_back(1);
  for (int i = 2; i <= n + 1; ++i) {
    int next = _sequence[i - 1] + 2 * _sequence[i - 2];
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
    mainchain.insert(mainchain.begin() + left, value);
    return;
  }
  int mid = left + (right - left) / 2;
  if (mainchain[mid] < value) {
    binaryinsert(value, left, mid);
  } else
    binaryinsert(value, mid + 1, right);
}

void Pmerge::pendtomain(int idx, int bidx) {
  while (idx > bidx) {
    binaryinsert(_vector[idx - 1].second, 0, idx - 1);
    idx--;
  }
}

void Pmerge::pendingorder(void) {
  int j = 1;
  int ssize = _sequence.size();
  while (j < ssize) {
    if (pairsize < _sequence[j])
      break;
    else {
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
  jnum(pairsize);
  for (int i = 0; i < pairsize; ++i) mainchain.push_back(_vector[i].first);
  pendingorder();
}

bool Pmerge::input(int ac, char **av) {
  if (ac == 2) {
    int i = 0;
    int numflag = 0;
    std::string systeminput;
    while (av[1][i] != '\0') {
      systeminput += av[1][i];
      if (av[1][i] < 48 || av[1][i] > 57) numflat = 1;
      ++i;
    }
    if (numflag == 1) {
      FILE *pipe = popen(systeminput.c_str(), "r");
      if (!pipe) throw std::runtime_error("Error: can't read the command");
      char buf[128];
      while (fgets(buf, sizeof(buf), pipe) != NULL) {
        std::istringstream iss(buf);
        int num = 0;
        while (iss >> num) vec.push_back(num);
      }
    } else {
      throw std::runtime_error("Error: can't sort");
    }
  } else {
    int i = 0;
    char *endptr = NULL;
    while (av[++i]) {
      double input = strtod(av[i], &endptr);
      if (*endptr != '\0') throw std::runtime_error("Error: not valid input");
      vec.push_back(input);
    }
    int _vecsize = vec.size();
    i = 0;
    std::cout << "Before: ";
    while (i < _vecsize) {
      std::cout << vec[i] << " ";
    }
    std::cout << "\n";
  }
  return true;
}

void Pmerge::execute(int ac, char **av) {
  input(ac, av);
  int _vecsize = vec.size();
  clock_t vecstart = clock();
  pair();
  clock_t vecend = clock();
  std::cout << "After: ";
  int i = -1;
  while (++i < _vecsize) std::cout << _vector[i] << " ";
  double usec = (((double)(vecend - vecstart)) * 1000 / CLOCKS_PER_SEC);
  std::cout << "Time to process a range of " << _vecsize
            << " elements with std::vector : " << usec << " us\n";
}