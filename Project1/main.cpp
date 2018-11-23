#include <iostream>
#include <cstring>

using namespace std;

/* ���ø�(Template)�� Ư��ȭ */
template <class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template<> // template<>�� ��� ���� �������� �ʾ�. Ư��ȭ �ϴ� ����. ������ ������ ���´� ������ ���� ���·� ��ȯ����.
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

	//cout << Max<int>(11, 15) << endl; // ����(�̷� ���°� �� �ùٸ�)
	cout << Max(11, 15) << endl;
	//cout << Max<char>('T','Q') << endl; // ����(�̷� ���°� �� �ùٸ�)
	cout << Max('T','Q') << endl;
	//cout << Max<float>(3.5, 10.5) << endl; // ����(�̷� ���°� �� �ùٸ�)
	cout << Max(3.5, 10.5) << endl;

	// ������ �ָ��� ���.
	// const char *�� ���
	//cout << Max<const char *>("Simple", "Best") << endl; // ����(�̷� ���°� �� �ùٸ�)
	cout << Max("Simple", "Best") << endl;

	// char *�� ���
	char str1[] = "Simple";
	char str2[] = "Best";
	//cout << Max<char *>(str1, str2) << endl; // ����(�̷� ���°� �� �ùٸ�)
	cout << Max(str1, str2) << endl;


	return 0;
}

//istream sdf;