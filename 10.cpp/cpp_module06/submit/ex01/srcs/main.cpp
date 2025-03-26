#include "Serializer.hpp"

int main(void) {
  Data data;
  data._data = "wonie";
  uintptr_t ptr;
  Data *deptr;

  ptr = Serializer::serialize(&data);
  deptr = Serializer::deserialize(ptr);
  std::cout << "serialize : "
            << "[" << ptr << "]" << std::endl;
  std::cout << "raw data : "
            << "[" << (uintptr_t)&data << "]" << std::endl;
  std::cout << "raw data[deptr] : "
            << "[" << (uintptr_t)deptr << "]" << std::endl;
  std::cout << "raw data's data : "
            << "[" << data._data << "]" << std::endl;
  std::cout << "desrialize ptr: "
            << "[" << deptr->_data << "]" << std::endl;
}
