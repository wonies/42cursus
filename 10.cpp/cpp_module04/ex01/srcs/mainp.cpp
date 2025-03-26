// #include "Animal.hpp"
// #include "Cat.hpp"
// #include "Dog.hpp"

// int main(void) {
//   Cat a;
//   a.brainAllocate();
//   Cat b(a);
//   a.brainSound();  // wonie
//   b.brainSound();  // wonie
//   b.brainAlert();  // alert -> konie
//   a.brainSound();  // wonie
//   b.brainSound();  // konie
//   //   Cat c;
//   //   c = a;
//   //   Cat c = a;  // 이렇게 하면 기본생성자가 안만들어진 상태이기 때문에
//   delete
//   // 돼서 에러...
//   //   c.brainSound();  // wonie
//   //   c.brainAlert();
//   //   a.brainSound();  // wonie
//   //   c.brainSound();  // konie
// }