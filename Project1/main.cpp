#include <iostream>
#include <cstring>

using namespace std;

/* static 함수(클래스 함수) 
	-선언된 클래스의 모든 객체가 공유.
	- public로 선언이 되면, 클래스의 이름을 이용해서 호출이 가능.
	- 객체의 멤버로 존재하는 것이 아님.
*/

class SoSimple
{
private:
	int num1;
	static int num2;
public:
	SoSimple(int n) : num1(n)
	{}
	//클래스 함수
	static void Adder(int n)
	{
		//num1 += n; //static 변수가 아니기 때문에 static함수 내에서 변경할 수 없음.
		num2 += n;
	}
};

int SoSimple::num2 = 0;


int main()
{
	/* static 함수(클래스 함수) */

	return 0;
}
