#include <iostream>

using namespace std;

/* this pointer의 활용 */
class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1; //지역변수의 이름과 멤버 변수의 이름이 같은 경우 this pointer를 이용해서 해결
		this->num2 = num2;
	}
	void ShowTwoNumber()
	{
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

/* 
	this pointer 이해
	객체 자기자신을 가리키는 용도.

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
*/
int main(void)
{
	/* this pointer의 활용 */
	TwoNumber two(2, 4);
	two.ShowTwoNumber();

	/* this pointer 이해
	SoSimple sim1(100);
	SoSimple *ptr1 = sim1.GetThisPointer();
	cout << ptr1 << ", ";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple *ptr2 = sim2.GetThisPointer();
	cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	*/

	return 0;
}
