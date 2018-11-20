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
	/*	예외의 다중 위임 */
	/*
		예외가 처리되지 않아서, Exception이 main함수까지 도달했는데,
		main함수에서조차 예외를 처리하지 않으면,
		terminate함수가 호출되면서, 프로그램이 종료된다.
	*/
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
	throw -1;	//throw는 try블럭 안에 있을 것.
}