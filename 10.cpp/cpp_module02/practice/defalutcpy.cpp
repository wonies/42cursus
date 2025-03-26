#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    void ShowInfo() const
    {
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
    }
    ~Person()
    {
        delete [] name;
        cout << "called Destructor!!" << endl;
    }
};


int main( void )
{
    Person man1("wonie wonie", 28);
    Person man2 = man1;
    man1.ShowInfo();
    man2.ShowInfo();
    return 0;
}