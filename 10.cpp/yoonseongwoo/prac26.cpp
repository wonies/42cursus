#include <iostream>
#include <cstring>
using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	bool InitMembers(int xpos, int ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};

class Rectangle
{
private:
	Point upLeft;
	Point lowRight;

public:
	bool InitMembers(const Point &ul, const Point &lr);
	void ShowRecInfo() const;
};


bool Point::InitMembers(int xpos, int ypos)
{
	if (xpos<0 || ypos<0)
	{
		cout<<"ERR the res in out of range"<<endl;
		return 0;
	}
	x = xpos;
	y = ypos;
	return 1;
}

int Point::GetX() const{
	return x;
}

int Point::GetY() const{
	return y;
}

bool Point::SetX(int xpos)
{
	if (xpos<0 || xpos>100)
	{
		cout<<"ERR the res in out of range"<<endl;
		return 0;
	}
	x = xpos;
	return 1;
}

bool Point::SetY(int ypos)
{
	if (ypos<0 || ypos>100)
	{
		cout<<"ERR the res in out of range"<<endl;
		return 0;
	}
	y = ypos;
	return 1;
}

bool Rectangle::InitMembers(const Point &ul, const Point &lr)
{
	if (ul.GetX()>lr.GetX() || ul.GetY()>lr.GetY())
	{
		cout<<"the res of wrong location"<<endl;
		return 0;
	}
	upLeft=ul;
	lowRight=lr;
	return 1;
}

void Rectangle::ShowRecInfo() const
{
	cout<<"left up : "<<'['<<upLeft.GetX()<<", ";
	cout<<upLeft.GetY()<<']'<<endl;
	cout<<"right down : "<<'['<<lowRight.GetX()<<", ";
	cout<<lowRight.GetY()<<']'<<endl<<endl;
}

int main(void)
{
	Point pos1;
	if (!pos1.InitMembers(-2, 4))
		cout<<"Fail to Initalization"<<endl;
	if (!pos1.InitMembers(2, 4))
		cout<<"Fail to Initalization"<<endl;
	
	Point pos2;
	if (!pos2.InitMembers(5, 9))
		cout<<"Fail to Initalization"<<endl;

	Rectangle rec;
	if (!rec.InitMembers(pos2, pos1))
		cout<<"Fail to Rectangle Initalization"<<endl;
	if (!rec.InitMembers(pos1, pos2))
		cout<<"Fail to Rectangle Initalization"<<endl;
	rec.ShowRecInfo();
	return 0;
}
