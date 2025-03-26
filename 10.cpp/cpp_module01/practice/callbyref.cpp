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
    Person(const string &_name, int _age) : name(_name), age(_age)
    {
    };
    int getAge() { return age; }
    const string &getName() { return name; }
};

void printPersonRef(Person &p)
{
    printf("Ref : value %s %d\n", p.getName().c_str(), p.getAge());
    printf("Ref : addr p %p\n", &p);
}

void printPersonPointer(Person *p)
{
    printf("Pointer : value %s %d\n", p->getName().c_str(), p->getAge());
    printf("Pointer : addr p %p\n", p);
}

int main( void )
{
    Person p1("wonie", 29);
    Person *p2 = new Person("konie", 28);
    printPersonRef(p1);
    printPersonPointer(&p1);
    printPersonPointer(p2);

    printf("addr p1 %p\n", &p1);
    printf("addr p2 %p\n", p2);

    delete p2;
    
    return 0;
}