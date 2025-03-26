#include <iostream>
using namespace std;

class Account {
 private:
  char _account[50];
  int _balance;

 public:
  virtual void ShowException() = 0;
};

class DepositException : public Account {
 private:
  int _request;

 public:
  DepositException(int money) : _request(money) {}
  void ShowException() {
    cout << "[except! " << _request << " can't depose ]" << endl;
  }
};

class WithdrawException : public Account {
 private:
  int _balance;

 public:
  WithdrawException(int money) : _balance(money) {}
  void ShowException() {
    cout << "[except! " << _balance << " lack of balace ]" << endl;
  }
};

class NewAccount {
 private:
  char _account[50];
  int _balance;

 public:
  NewAccount(char* acc, int money) : _balance(money) { strcpy(_account, acc); }
  void Deposit(int money) throw(Account) {
    if (money < 0) {
      DepositException expn(money);
      throw expn;
    }
    _balance += money;
  }

  void Withdraw(int money) throw(Account) {
    if (money > _balance) throw WithdrawException(_balance);
    _balance -= money;
  }
  void ShowMoney() { cout << "Balance : " << _balance << endl; }
};

int main(void) {
  NewAccount Acc("56789-827120", 5000);

  try {
    Acc.Deposit(2000);
    Acc.Deposit(-300);
  } catch (Account& e) {
    e.ShowException();
  }
  Acc.ShowMoney();

  try {
    Acc.Withdraw(3500);
    Acc.Withdraw(4500);
  } catch (Account& e) {
    e.ShowException();
  }
  Acc.ShowMoney();
  return 0;
}