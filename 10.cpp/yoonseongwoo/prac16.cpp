#include <iostream>
using namespace std;

#define ID_LEN 20
#define MAXC_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 10
#define BRK_STEP 10


struct Car
{
    char gamerID[ID_LEN];
    int fuelGauge;
    int carSpeed;
};

void    ShowCarState(const Car &car)
{
    cout<<"ID : "<<car.gamerID<<endl;
    cout<<"Fuel : "<<car.fuelGauge<<"%"<<endl;
    cout<<"Speed : "<<car.carSpeed<<"km/s"<<endl<<endl;
}

void Accel(Car &car)
{
    if (car.fuelGauge <=0)
        return ;
    else 
        car.fuelGauge-=FUEL_STEP;
    if (car.carSpeed+ACC_STEP >= MAXC_SPD)
    {
        car.carSpeed = MAXC_SPD;
        return ;
    }
    car.carSpeed += ACC_STEP;
}


void Break(Car &car)
{
    if (car.carSpeed<BRK_STEP)
    {
        car.carSpeed =0;
        return ;
    }
    car.carSpeed -= BRK_STEP;
}




int main(void)
{
    Car run99 = {"run99", 100, 0};
    Accel(run99);
    Accel(run99);
    ShowCarState(run99);
    Break(run99);
    ShowCarState(run99);


    Car sped77 =  {"spedd77", 100, 0};
    Accel(sped77);
    Break(sped77);
    ShowCarState(sped77);
    return 0;
}