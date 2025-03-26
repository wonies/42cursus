#include <iostream>

using namespace std;

class Student
{
private:
	char name[10];
	int age;
	int stuId;
public:
	Student()
	{
		cout<< "call of Construct" << endl;
	}
	void setInfo(char *_name, int _age, int _stuId)
	{
		strcpy(name, _name);
		age = _age;
		stuId = _stuId;
	}
	
	void getInfo()
	{
		cout << "name : " << name << endl;
		cout << "age : " << age << endl;
		cout << "id : " << stuId << endl;
	}
	~Student()
	{
		cout << "call of Destructor" << endl;
	}
};

int main()
{
	Student student[5];
	char name[10];
	int age, id;

	for (int i=0; i<5; i++)
	{
		cin >> name >> age >> id;
		student[i].setInfo(name, age, id);
	}
	for (int i=0; i<5; i++)
		student[i].getInfo();
}
