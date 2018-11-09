#include <iostream>

using namespace std;

int main(void)
{
	int num1 = 1020;
	int &num2 = num1;
	int &num3 = num2;
	int &num4 = num3;

	num2 = 3047;

	cout << "Val : " << num1 << endl;
	cout << "Ref : " << num2 << endl;
	cout << "Ref num3: " << num3 << endl;
	cout << "Ref num4: " << num4 << endl;

	cout << "Val : " << &num1 << endl;
	cout << "Ref : " << &num2 << endl;
	cout << "Ref num3: " << &num3 << endl;
	cout << "Ref num4: " << &num4 << endl;


	return 0;
}