#include <iostream>
#include <cstring>

using namespace std;

/* static �Լ�(Ŭ���� �Լ�) 
	-����� Ŭ������ ��� ��ü�� ����.
	- public�� ������ �Ǹ�, Ŭ������ �̸��� �̿��ؼ� ȣ���� ����.
	- ��ü�� ����� �����ϴ� ���� �ƴ�.
*/

class SoSimple
{
private:
	int num1;
	static int num2;
public:
	SoSimple(int n) : num1(n)
	{}
	//Ŭ���� �Լ�
	static void Adder(int n)
	{
		//num1 += n; //static ������ �ƴϱ� ������ static�Լ� ������ ������ �� ����.
		num2 += n;
	}
};

int SoSimple::num2 = 0;


int main()
{
	/* static �Լ�(Ŭ���� �Լ�) */

	return 0;
}
