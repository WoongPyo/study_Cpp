#include <iostream>

using namespace std;

/*얕은 복사(shallow copy)
깊은 복사(deep copy)*/
class SoSimple
{
private:
	int num;
	int num2;
public:
	SoSimple(int n, int n2) : num(n), num2(n2)
	{}

	/* 복사생성자(Copy constructor) */
	explicit SoSimple(SoSimple &copy) : num(copy.num), num2(copy.num2)
	{
		cout << "called copy constructor." << endl;
	}

	void ShowSimpleData()
	{
		cout << num << endl;
		cout << num2 << endl;
	}
};

int main()
{
	SoSimple sim1(20, 40);

	//SoSimple sim2 = sim1; // 생성자를 호출하지 않아도 sim1에 있는 멤버변수를 복사 한다. explicit 키워드를 쓰면 이렇게 사용할 수 없음
	SoSimple sim2(sim1);

	sim2.ShowSimpleData();

	return 0;
}