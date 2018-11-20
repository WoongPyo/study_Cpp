#include <iostream>
#include <cstring>

using namespace std;

/* 예외처리 - Exception Handling */



int main(void)
{
	/* 예외처리 - Exception Handling */
	
	/* C++에서의 예외처리 */
	//try ...블록		예외를 발견
	//catch ...블록		예외를 인지해서 처리
	//throw ...블록		예외 처리의 위임
	int num1, num2;
	cout << "두 개의 숫자 입력 : ";
	cin >> num1 >> num2;	// 예외 발생

	try
	{
		if (num2 == 0)
			throw num2; // catch로 넘어감.
		else
		{
			cout << "나눗셈의 몫 : " << num1 / num2 << endl;
			cout << "나눗셈의 나머지 : " << num1 % num2 << endl;
		}
	}
	catch(int expn)
	{
		cout << "제 수는 " << expn << "이 될 수 없습니다." << endl;
		cout << "프로그램을 다시 실행하세요." << endl;
	}



	/* 전통적인 C언어의 예외처리 */
	//int num1, num2;
	//cout << "두 개의 숫자 입력 : ";
	//cin >> num1 >> num2;	// 예외 발생

	//if (num2 == 0)			//예외 체크
	//{						//예외 처리
	//	cout << "제 수는 0이 될 수 없습니다." << endl;
	//	cout << "프로그램을 다시 실행하세요." << endl;
	//}
	//else
	//{
	//	cout << "나눗셈의 몫 : " << num1 / num2 << endl;
	//	cout << "나눗셈의 나머지 : " << num1 % num2 << endl;
	//}


	return 0;
}
