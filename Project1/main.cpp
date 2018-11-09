#include <iostream>

using namespace std;

int main(void)
{
	//배열요소를 대상으로 한 참조자
	int arr[3] = { 1, 2, 3 };
	int &ref1 = arr[0];
	int &ref2 = arr[1];
	int &ref3 = arr[2];

	cout << ref1 << endl;
	cout << ref2 << endl;
	cout << ref3 << endl;

	//일반변수를 대상으로 한 참조자
	/*
	int num1 = 1020;
	int &num2 = num1;
	int &num3 = num2;
	int &num4 = num3;

	//int &ref = 20;		참조자는 상수를 선언할 수 없어
	//int &ref;				참조자 자체 선언 불가
	//int &ref = NULL;		참고자는 변수 자체의 선언이 불가

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