#include <iostream>
#include <cstring>
using namespace std;


namespace CAR_CONST
{
    enum
    {
        ID_LEN = 20,
        MAXC_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
}

class Car
{
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int carSpeed;

public:
    void InitMembers(char *ID, int fuel);
    void ShowCarState();
    void Accel();
    void Break();


};

void Car::InitMembers(char *ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    carSpeed = 0;
}

void    Car::ShowCarState()
{
    cout<<"ID : "<<gamerID<<endl;
    cout<<"Fuel : "<<fuelGauge<<"%"<<endl;
    cout<<"Speed : "<<carSpeed<<"km/s"<<endl<<endl;
}

void Car::Accel()
{
    if (fuelGauge <=0)
        return ;
    else 
        fuelGauge-=CAR_CONST::FUEL_STEP;
    if (carSpeed+CAR_CONST::ACC_STEP >= CAR_CONST::MAXC_SPD)
    {
        carSpeed = CAR_CONST::MAXC_SPD;
        return ;
    }
    carSpeed += CAR_CONST::ACC_STEP;
}


void Car::Break()
{
    if (carSpeed<CAR_CONST::BRK_STEP)
    {
        carSpeed =0;
        return ;
    }
    carSpeed -= CAR_CONST::BRK_STEP;
}



int main(void)
{
    Car run99;
    run99.InitMembers("run99", 100);
    run99.Accel();
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();
    return 0;
}