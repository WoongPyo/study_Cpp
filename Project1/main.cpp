#include <iostream>
#include <cstring>

using namespace std;

/* 템플릿(Template) */
/*
int Add(int num1, int num2)
{
	return num1 + num2;
}

	기능: 덧셈
	대상 자료형 : int형 데이터

template <typename T> 또는 template <class T> <-- 무조건 함수 앞에 있어야 함.
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
	템플릿(Template)
	- 뜻 : 형판 -> 모형자.
	- 함수 템플릿, 클래스 템플릿
	  다양한 자료형의 함수, 클래스를 만드는 도구.
	*/
	//<int> : T를 int로 해서 만들어진 함수를 호출.
	//		-> 템플릿 함수 : 템플릿을 기반으로 컴파일러가 만들어 내는 유형의 함수.
	cout << Add(15, 20) << endl; //int형 형태의 함수가 출력됨.

	cout << Add<int>(15, 20) << endl; 
	/*
	위의 구문을 만나면...
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