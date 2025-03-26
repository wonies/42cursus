#include "FragTrap.hpp"

int main(void) {
  FragTrap fr("🦊이브이");
  FragTrap kk;

  kk = fr;
  std::cout << fr.getHP() << std::endl;
  std::cout << kk.getHP() << std::endl;  // 복사할당연산자 -> 선언시 초기화 가능
  kk.highFivesGuys();
  fr.attack("나옹이");
  fr.takeDamage(30);
  std::cout << fr.getHP() << std::endl;
  std::cout << kk.getHP()
            << std::endl;  // 서로 다른 hp를 가지는 것을 알 수 있음

  return 0;
}
