#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// void leak() { system("leaks Brain"); }
int main(void) {
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  int animal_size = 100;
  Animal* ani[animal_size];

  for (int i = 0; i < animal_size; i++) {
    if (i < animal_size / 2)
      ani[i] = new Dog();
    else
      ani[i] = new Cat();
  }
  std::cout << "probably.. bark" << std::endl;
  ani[20]->makeSound();
  std::cout << "probably.. meow" << std::endl;
  ani[59]->makeSound();

  for (int i = 0; i < animal_size; i++) delete ani[i];
  //   // case1 : 깊은 복사에 대한 이해
  //   Cat wonie;
  //   wonie.brainAllocate();        // wonie가 할당
  //   Cat* konie = new Cat(wonie);  // 복사연산자!
  //   wonie.brainSound();           // wonie 출력
  //   konie->brainSound();          // wonie 출력
  //   konie->brainAlert();          // konie 로 변경
  //   konie->brainSound();          // konie 출력
  //   wonie.brainSound();           // wonie 출력
  //   // ..이렇게 되면 깊은 복사 완료 깊은 복사됨!
  //   std::cout << "-----------------CASE 2-----------------------\n";
  //   // case 2 : Cat *monie(konie); -> 깊은 복사일까? 얕은 복사일까?
  //   둘다아닐지도. Cat* monie(konie); monie->brainSound();
  //   monie->brainAllocate();
  //   monie->brainSound();
  //   konie->brainSound();

  //   std::cout << "-----------------CASE 3-----------------------\n";

  //   // case 3: donie <-> konie 깊은 복사 수행해보기.
  //   //   Cat* donie = new Cat(konie); // Error! // 왜인지 생각해보기!
  //   Cat* donie = new Cat(*konie);  // Error! // 왜인지 생각해보기!
  //   donie->brainSound();
  //   konie->brainSound();
  //   donie->brainAlert();
  //   donie->brainSound();
  //   konie->brainSound();

  //   std::cout << "-----------------CASE 4 & 5 -----------------------\n";
  //   Cat* sonie = new Cat();
  //   *sonie = wonie;
  //   //   sonie = &wonie; // 이건 뭔지 설명하기
  //   wonie.brainAllocate();
  //   wonie.brainSound();   // wonie
  //   sonie->brainSound();  // wonie
  //   wonie.brainAlert();
  //   wonie.brainSound();   // konie
  //   sonie->brainSound();  // wonie

  //   std::cout << "-----------------CASE 6 -----------------------\n";

  //   Cat* bonie = new Cat();
  //   *bonie = *sonie;
  //   //   bonie = sonie;
  //   bonie->brainSound();  // wonie
  //   sonie->brainAlert();
  //   bonie->brainSound();  // konie?
  //   sonie->brainSound();

  delete j;
  delete i;
  // leak();
  return 0;
}