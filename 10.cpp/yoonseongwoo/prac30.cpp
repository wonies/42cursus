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

class CONTAC999
{
private:
    SinivelCap sin;
    SneezeCap sne;
    SnuffleCap snu;

public:
    void Take() const
    {
        sin.Take();
        sne.Take();
        snu.Take();
    }
};

class ColdPatient
{
public:
    void    TakeCONTAC999(const CONTAC999 &cap) const { cap.Take(); }
};

int main(void)
{
    CONTAC999 cap;
    ColdPatient sufferer;
    sufferer.TakeCONTAC999(cap);

    return 0;
}
