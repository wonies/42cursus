#include <iostream>

using namespace std;

class SoSimple{
	private:
		int num;
	public:
		SoSimple(int n) : num(n) {
		}
		SoSimple(const SoSimple& copy) : num(copy.num) {
			cout<<"Called SoSimple(const SoSimple& copy)"<<endl;
		}
		SoSimple& AddNum(int n) {
			num+=n;
			return *this;
		}
		void ShowData() {
			cout<<"num : "<<num<<endl;
		}
};

SoSimple SimpleFuncObjTest(SoSimple ob) 
{
	std::cout << "test" << std::endl;
	ob.ShowData();
	std::cout << "int: " << &ob << "\n";
	return ob;
}

SoSimple SimpleFuncObj(SoSimple &ob) 
{
	std::cout << "test" << std::endl;
	ob.ShowData();
	std::cout << "int: " << &ob << "\n";
	return ob;
}

int main(void) 
{
	SoSimple obj(7);
	// std::cout << &SimpleFuncObj(obj) << "\n";
    SimpleFuncObjTest(obj);
    const SoSimple &test = SimpleFuncObj(obj); 
    cout << "diff : " << &test << std::endl; 
	SimpleFuncObj(obj);
	obj.ShowData();

	return 0;
}
