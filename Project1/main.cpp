#include <iostream>
#include <cstring>

using namespace std;

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
	/* 예외의 전달(위임) */

	int num1, num2;
	cout << "두 개의 숫자 입력 : ";
	cin >> num1 >> num2;			// 예외 발생

	try
	{
		Divide(num1, num2);			//함수 내부에서 throw해도 cat가 가능
		//if (num2 == 0)
		//	throw num2;				// catch로 넘어감.
		//cout << "나눗셈의 몫 : " << num1 / num2 << endl;
		//cout << "나눗셈의 나머지 : " << num1 % num2 << endl;
	}
	catch (int expn)
	{
		cout << "제 수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}

	return 0;
}
