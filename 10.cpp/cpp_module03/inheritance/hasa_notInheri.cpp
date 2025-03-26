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

class Police {
 private:
  int handcuffs;
  Gun *pistol;

 public:
  Police(int bnum, int bcuff) : handcuffs(bcuff) {
    if (bnum > 0)
      pistol = new Gun(bnum);
    else
      pistol = NULL;
  }
  void PutHandcuff() {
    std::cout << "Snap!\n" << std::endl;
    handcuffs--;
  }
  void shot() {
    if (pistol == NULL)
      std::cout << "Hut Bang!\n";
    else
      pistol->shot();
  }
  ~Police() {
    if (pistol != NULL) delete pistol;
  }
};

int main(void) {
  Police pman1(5, 3);
  pman1.shot();
  pman1.PutHandcuff();

  Police pman2(0, 3);
  pman2.shot();
  pman2.PutHandcuff();
  return 0;
}