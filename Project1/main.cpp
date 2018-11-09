#include <iostream>

using namespace std;

void SwapByRef(int &ref1, int &ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int &RefRetFuncOne(int &ref)
{
	ref++;
	return ref;
}

int main(void)
{
	// 반환형이 참조자인 경우.
	int num2 = 1;
	int &num3 = RefRetFuncOne(num2); // int &num3 = num2;
	num2++;
	num3++;

	cout << "num2  : " << num2 << endl;
	cout << "num3  : " << num3 << endl;


	// 참조자를 이용한 call by reference
	/*
	int val2 = 10;
	int val3 = 20;

	SwapByRef(val2, val3);

	cout << "val2 : " << val2 << endl;
	cout << "val3 : " << val3 << endl;
	*/
	return 0;
}