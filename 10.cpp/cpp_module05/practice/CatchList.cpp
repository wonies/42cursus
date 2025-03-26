#include <iostream>
using namespace std;

class DepositException {
 private:
  int _request;

 public:
  DepositException(int money) : _request(money) {}
  void ShowException() {
    cout << "[except! " << _request << " can't depose ]" << endl;
  }
};

class WithdrawException {
 private:
  int _balance;

 public:
  WithdrawException(int money) : _balance(money) {}
  void ShowException() {
    cout << "[except! " << _balance << " lack of balace ]" << endl;
  }
};

class Account {
 private:
  char _account[50];
  int _balance;

 public:
  Account(char* acc, int money) : _balance(money) { strcpy(_account, acc); }
  void Deposit(int money) throw(DepositException) {
    if (money < 0) {
      DepositException expn(money);
      throw expn;
    }
    _balance += money;
  }

  void Withdraw(int money) throw(WithdrawException) {
    if (money > _balance) throw WithdrawException(_balance);
    _balance -= money;
  }
  void ShowMoney() { cout << "Balance : " << _balance << endl; }
};

int main(void) {
  Account Acc("56789-827120", 5000);

  try {
    Acc.Deposit(2000);
    Acc.Deposit(-300);
  } catch (DepositException& e) {
    e.ShowException();
  }
  Acc.ShowMoney();

  try {
    Acc.Withdraw(3500);
    Acc.Withdraw(4500);
  } catch (WithdrawException& e) {
    e.ShowException();
  }
  Acc.ShowMoney();
  return 0;
}