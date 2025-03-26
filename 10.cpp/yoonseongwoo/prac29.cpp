#include <iostream>
#include <cstring>
using namespace std;


class SinivelCap
{
private: 

public:
    void Take() const {cout<<"Sinivel is Better than Before."<<endl;}
};

class SneezeCap
{
private: 

public:
    void Take() const {cout<<"Sneeze is Better than Before."<<endl;}
};

class SnuffleCap
{
private: 

public:
    void Take() const {cout<<"Snuffle is Better than Before."<<endl;}
};

class ColdPatient
{
public:
    void TakeSinivelCap(const SinivelCap &cap) const {cap.Take();}
    void TakeSneezeCap(const SneezeCap &cap) const {cap.Take();}
    void TakeSnuffleCap(const SnuffleCap &cap) const {cap.Take();}
};


int main(void)
{
    SinivelCap scap;
    SneezeCap zcap;
    SnuffleCap ncap;

    ColdPatient sufferer;
    sufferer.TakeSinivelCap(scap);
    sufferer.TakeSneezeCap(zcap);
    sufferer.TakeSnuffleCap(ncap);
    return 0;
}