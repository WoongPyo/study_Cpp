#include <iostream>
#include <cstring>

using namespace std;

/* 예외의 다중 위임 */
void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

/* 예외의 전달(위임) */
void Divide(int num1, int num2)
{
	if (num2 == 0)
		throw num2;

	cout << "나눗셈의 몫 : " << num1 / num2 << endl;
	cout << "나눗셈의 나머지 : " << num1 % num2 << endl;
}


int main(void)
{
	SimpleFuncOne();
	/* 예외의 다중 위임 */
	try
	{
		SimpleFuncOne();
	}
	catch (int expn)
	{
		cout << "예외코드 : " << expn << endl;
	}

	return 0;
}

void SimpleFuncOne(void)
{
	cout << "SimpleFuncOne(void)" << endl;
	SimpleFuncTwo();
}

void SimpleFuncTwo(void)
{
	cout << "SimpleFuncTwo(void)" << endl;
	SimpleFuncThree();
}

void SimpleFuncThree(void)
{
	cout << "SimpleFuncThree(void)" << endl;
	throw -1;
}