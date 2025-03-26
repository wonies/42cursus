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

    void    ShowCarState()
    {
        cout<<"ID : "<<gamerID<<endl;
        cout<<"Fuel : "<<fuelGauge<<"%"<<endl;
        cout<<"Speed : "<<carSpeed<<"km/s"<<endl<<endl;
    }

    void Accel()
    {
        if (fuelGauge <=0)
            return ;
        else 
            fuelGauge-=FUEL_STEP;
        if (carSpeed+ACC_STEP >= MAXC_SPD)
        {
            carSpeed = MAXC_SPD;
            return ;
        }
        carSpeed += ACC_STEP;
    }


    void Break()
    {
        if (carSpeed<BRK_STEP)
        {
            carSpeed =0;
            return ;
        }
        carSpeed -= BRK_STEP;
    }

};




int main(void)
{
    Car run99 = {"run99", 100, 0};
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Break();
    run99.ShowCarState();


    Car sped77 =  {"spedd77", 100, 0};
    sped77.Accel();
    sped77.Break();
    sped77.ShowCarState();
    return 0;
}