#include <iostream>
#include <cstring>

using namespace std;

/* ���ø�(Template)�� Ư��ȭ */
template <class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template<> // template<>�� ��� ���� �������� �ʾ�. Ư��ȭ �ϴ� ����. 
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
	/*	���ø�(Template)�� Ư��ȭ*/

	cout << Max(11, 15) << endl;
	cout << Max('T','Q') << endl;
	cout << Max(3.5, 10.5) << endl;

	// ������ �ָ��� ���.
	// const char *�� ���
	cout << Max("Simple", "Best") << endl;

	// char *�� ���
	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;


	return 0;
}