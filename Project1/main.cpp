#include <iostream>
#include <cstring>

using namespace std;

/* 템플릿(Template)의 특수화 */
template <class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template<> // template<>인 경우 형을 지정하지 않아. 특수화 하는 것임. 
char *Max(char *a, char *b)
{
	cout << "char *Max(char *a, char *b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template<>
const char *Max(const char *a, const char *b)
{
	cout << "const char *Max(const char *a, const char *b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main()
{
	/*	템플릿(Template)의 특수화*/

	cout << Max(11, 15) << endl;
	cout << Max('T','Q') << endl;
	cout << Max(3.5, 10.5) << endl;

	// 기준이 애매한 경우.
	// const char *의 경우
	cout << Max("Simple", "Best") << endl;

	// char *의 경우
	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;


	return 0;
}