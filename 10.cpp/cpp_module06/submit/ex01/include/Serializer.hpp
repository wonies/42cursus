#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

#include <iostream>
#include <string>

#include "Data.hpp"

class Serializer {
 public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);

 private:
  Serializer(void);
  Serializer(Serializer const &instance);
  Serializer &operator=(Serializer const &rhs);
  ~Serializer(void);
};

#endif