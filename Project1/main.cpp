#include <iostream>

using namespace std;

int main(void)
{
	//�迭��Ҹ� ������� �� ������
	int arr[3] = { 1, 2, 3 };
	int &ref1 = arr[0];
	int &ref2 = arr[1];
	int &ref3 = arr[2];

	cout << ref1 << endl;
	cout << ref2 << endl;
	cout << ref3 << endl;

	//�Ϲݺ����� ������� �� ������
	/*
	int num1 = 1020;
	int &num2 = num1;
	int &num3 = num2;
	int &num4 = num3;

	//int &ref = 20;		�����ڴ� ����� ������ �� ����
	//int &ref;				������ ��ü ���� �Ұ�
	//int &ref = NULL;		�����ڴ� ���� ��ü�� ������ �Ұ�

	num2 = 3047;

	cout << "Val : " << num1 << endl;
	cout << "Ref : " << num2 << endl;
	cout << "Ref num3: " << num3 << endl;
	cout << "Ref num4: " << num4 << endl;

	cout << "Val : " << &num1 << endl;
	cout << "Ref : " << &num2 << endl;
	cout << "Ref num3: " << &num3 << endl;
	cout << "Ref num4: " << &num4 << endl;
	*/

	return 0;
}