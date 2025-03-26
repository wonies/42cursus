#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <climits>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

class Pmerge {
 public:
  /* vector */
  std::vector<int> vec;
  std::vector<std::pair<int, int> > _vector;
  std::vector<int> _sequence;
  std::vector<int> mainchain;
  int _vecsize;
  int k;
  /* share */
  double oddvec;
  int pairsize;
  /* deque */
  std::deque<int> deq;
  std::deque<std::pair<int, int> > _deque;
  std::deque<int> _seq;
  std::deque<int> deqmainchain;
  int _deqsize;
  int ic;
  /*vector function*/
  void jnum(int n);
  void mainsort(int left, int mid, int right);
  void pendtomain(int index, int bindex);
  void binaryinsert(int value, int left, int right);
  void pendingorder(void);
  void sortpair(int left, int right);
  void pairvector(void);
  void pair(void);
  /* share function */
  bool input(int ac, char** av);
  void execute(int ac, char** av);
  void printvector(void);
  void vector(void);
  /*deque function*/
  void jnumdeq(int n);
  void mainsortdeq(int left, int mid, int right);
  void pendtomaindeq(int idx, int bidx);
  void binaryinsertdeq(int value, int left, int right);
  void pendingorderdeq(void);
  void sortdeque(int left, int right);
  void pairdeque(void);
  void pairdeq(void);

 private:
  //   Pmerge(void);
  //   //   Pmerge(**replace parameters **);
  //   Pmerge(Pmerge const &instance);
  //   Pmerge &operator=(Pmerge const &rhs);
  //   ~Pmerge(void);
};

#endif