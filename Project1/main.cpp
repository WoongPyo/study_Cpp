#include <iostream>
#include <cstring>

using namespace std;

/* mutable 키워드 */

class SoSimple
{
private:
	int num1;
	mutable int num2;
public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2)
	{}
	void ShowSimpleData() const
	{
		cout << num1 << ", " << num2 << endl;
	}
	void CopyToNum2() const // const함수는 본래 내부 변수 값을 바꿀수 없지만 내부 변수를 변경할 수 있는 예외를 mutable변수로 둠.
	{
		num2 = num1;
	}
};


int main()
{
	/* mutable 키워드 
		-const 함수 내에서 멤버변수 값의 변경을 예외적으로 허용.
	*/
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();

	return 0;
}
