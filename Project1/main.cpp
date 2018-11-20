#include <iostream>
#include <cstring>

using namespace std;

/* ������ ���� ���� */
void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

/* ������ ����(����) */
void Divide(int num1, int num2)
{
	if (num2 == 0)
		throw num2;

	cout << "�������� �� : " << num1 / num2 << endl;
	cout << "�������� ������ : " << num1 % num2 << endl;
}


int main(void)
{
	SimpleFuncOne();
	/* ������ ���� ���� */
	try
	{
		SimpleFuncOne();
	}
	catch (int expn)
	{
		cout << "�����ڵ� : " << expn << endl;
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