#include <iostream>
#include <cstring>

using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{}
	void ShowData()
	{
		cout << num1 << ", " << num2 << endl;
	}
};

class Second
{
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
	{}
	void ShowData()
	{
		cout << num3 << ", " << num4 << endl;
	}
	// 대입 연산자 오버로딩
	Second &operator=(const Second &ref)
	{
		cout << "Second& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;

		return *this;
	}
};

int main(void)
{
	/*	대입 연산자의 오버로딩 
		-복사생성자하고 좀 비슷
	*/
	
	//Point pos1(5, 7);
	//Point pos2 = pos1;	// 복사생성자
	//Point pos2(pos1);		// 컴파일러가 코드를 변경
	//복사생성자의 단점 ->
	//얕은 복사 : 멤버 대 멤버 복사 -> 깊은 복사

	//Point pos1(5, 7);
	//Point pos2(9, 10);
	//pos2 = pos1; // 연산자의 피연산자의 대상이 객체 이기 때문에 멤버 대 멤버 복사
	//pos2.operator=(pos1);

	First firstOrg(111, 222);
	First firstCpy(222, 333);
	firstCpy.ShowData();

	firstCpy = firstOrg;
	firstCpy.ShowData();

	Second secondOrg(111, 222);
	Second secondCpy(222, 333);
	secondCpy.ShowData();

	secondCpy = secondOrg;
	secondCpy.ShowData();

	return 0;
}
