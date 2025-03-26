#include <iostream>

using namespace std;

class Person
{
private: 
    string name;
    int age;
public:
    Person() : name("") , age(0)
    {
    };
    Person(string _name, int _age) : name(_name), age(_age)
    {
    };
    int getAge() { return age; }
    string getName() { return name; }
};

void printPerson(Person p)
{
    printf("value %s %d\n", p.getName().c_str(), p.getAge());
    printf("addr p %p\n", &p);
}

int main( void )
{
    Person p1("wonie", 29);
    printPerson(p1);
    printf("addr p1 %p\n", &p1);
    
    return 0;
}