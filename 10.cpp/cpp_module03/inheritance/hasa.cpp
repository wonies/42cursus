#include <cstring>
#include <iostream>

class Gun {
 private:
  int bullet;

 public:
  Gun(int bnum) : bullet(bnum) {}
  void shot() {
    std::cout << "Bang!\n";
    bullet--;
  }
};

class Police : public Gun {
 private:
  int handcuffs;

 public:
  Police(int bnum, int bcuff) : Gun(bnum), handcuffs(bcuff) {}
  void PutHandcuff() {
    std::cout << "Snap!\n";
    handcuffs--;
  }
};

int main(void) {
  Police pman(5, 3);
  pman.shot();
  pman.PutHandcuff();

  return 0;
}