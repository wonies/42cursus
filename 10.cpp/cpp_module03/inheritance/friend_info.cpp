#include <iostream>
#include <string>

class FriendInfo {
 private:
  std::string name;
  int age;

 public:
  FriendInfo() : age(0) {}
  FriendInfo(const std::string& _name, int _age) : name(_name), age(_age) {}
  virtual ~FriendInfo() { std::cout << "Basic Destructor" << std::endl; }
  void showFriendInfo() {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
  }
  void setName(std::string _name) { name = _name; }
  void setAge(int _age) { age = _age; }
};

class DetailInfo : public FriendInfo {
 private:
  std::string address;
  std::string phone;

 public:
  DetailInfo() {}
  DetailInfo(const std::string& _name, int _age, const std::string& _address,
             const std::string& _phone)
      : FriendInfo(_name, _age), address(_address), phone(_phone) {}
  ~DetailInfo() { std::cout << "Detail Destructor" << std::endl; }
  void showDetail() {
    showFriendInfo();
    std::cout << "Address: " << address << ", Phone: " << phone << std::endl;
  }
  void setAdd(std::string _add) { address = _add; }
  void setPhone(std::string _phone) { phone = _phone; }
};

int main() {
  DetailInfo fre;

  fre.showDetail();
  //   fre("konie", 28, "doksan", "08");
  std::cout << "----------------" << std::endl;
  fre.setName("Konie");
  fre.setAge(28);
  fre.setAdd("doksan");
  fre.setPhone("001");
  fre.showDetail();
  std::cout << "----------------" << std::endl;

  return 0;
}
