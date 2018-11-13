#include <iostream>

using namespace std;

/* 
	this pointer
	객체 자기자신을 가리키는 용도.
*/
class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		cout << "num = " << num << endl;
		cout << "address = " << this << endl;
	}
	void ShowSimpleData()
	{
		cout << num << endl;
	}
	SoSimple *GetThisPointer()
	{
		return this;
	}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple *ptr1 = sim1.GetThisPointer();
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple *ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	return 0;
}
