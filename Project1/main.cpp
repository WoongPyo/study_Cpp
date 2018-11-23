#include <iostream>
#include <cstring>

using namespace std;

/* ���ø�(Template) */
/*
int Add(int num1, int num2)
{
	return num1 + num2;
}

	���: ����
	��� �ڷ��� : int�� ������

template <typename T> �Ǵ� template <class T> <-- ������ �Լ� �տ� �־�� ��.
T Add(T num1, T num2)
{
	return num1 + num2;
}
*/
template <class T1, class T2>
void ShowData(double num)
{
	cout << (T1)num << ", " << (T2)num << endl;
}

template <typename T>
T Add(T num1, T num2)
{
	cout << "T Add(T num1, T num2)" << endl;
	return num1 + num2;
}

int Add(int num1, int num2)
{
	cout << "int Add(int num1, int num2)" << endl;
	return num1 + num2;
}

istream str;

int main()
{
	/*
	���ø�(Template)
	- �� : ���� -> ������.
	- �Լ� ���ø�, Ŭ���� ���ø�
	  �پ��� �ڷ����� �Լ�, Ŭ������ ����� ����.
	*/
	//<int> : T�� int�� �ؼ� ������� �Լ��� ȣ��.
	//		-> ���ø� �Լ� : ���ø��� ������� �����Ϸ��� ����� ���� ������ �Լ�.
	cout << Add(15, 20) << endl; //int�� ������ �Լ��� ��µ�.

	cout << Add<int>(15, 20) << endl; 
	/*
	���� ������ ������...
		int Add(int num1, int num2)
		{
			return num1 + num2;
		}
	*/
	cout << Add<double>(2.9, 5.5) << endl;
	ShowData<char, int>(65);


	cout << "mfi" << endl;
	return 0;
}