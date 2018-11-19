#include <iostream>
#include <cstring>

using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{}
	SoSimple &AddNum(int n)
	{
		num += n;
		return *this;
	}
	void SimpleFunc()
	{
		cout << "SimpleFunc : " << num << endl;
	}
	void SimpleFunc() const
	{
		cout << "const SimpleFunc : " << num << endl;
	}
};

int main()
{
	/* const  함수 오버로딩 
		- 함수 오버로딩 조건에서 const도 포함됨.
	*/
	SoSimple obj1(7);
	const SoSimple obj2(10);

	obj1.SimpleFunc();
	obj2.SimpleFunc();


	/* friend 선언 */

	return 0;
}