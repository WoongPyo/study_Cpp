#include <iostream>
#include <cstring>

using namespace std;

/* Ŭ���� ���ø� */
/*
���ø� Ŭ����		<- ���ø����� ���� ������ Ŭ����
���ø� �Լ�		<- ���ø����� ���� ������ �Լ�

�Լ� ���ø�		<- ���ø��� ����� �Լ�
Ŭ���� ���ø�		<- ���ø��� ����� Ŭ����
*/
template <typename T>
class Point
{
private:
	T xPos, yPos;
public:
	Point(T x = 0, T y = 0) : xPos(x), yPos(y)
	{}
	void ShowPosition() const
	{
		cout << "[ " << xPos << ", " << yPos << " ]" << endl;
	}
};

/* ���ø�(Template)�� Ư��ȭ */
template <class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template<> // template<>�� ��� ���� �������� �ʾ�. Ư��ȭ �ϴ� ����. ������ ������ ���´� ������ ���� ���·� ��ȯ����. char *
char *Max(char *a, char *b)
{
	cout << "char *Max(char *a, char *b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template<> //������ ������ ���´� ������ ���� ���·� ��ȯ����. const char *
const char *Max(const char *a, const char *b)
{
	cout << "const char *Max(const char *a, const char *b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main()
{
	/* Ŭ���� ���ø� */

	Point<int> pos1(3, 4);
	pos1.ShowPosition();

	Point<double> pos2(2.5, 7.5);
	pos2.ShowPosition();

	Point<char> pos3('X', 'Y');
	pos3.ShowPosition();

	/*	���ø�(Template)�� Ư��ȭ*/

	//cout << Max(11, 15) << endl;
	//cout << Max('T','Q') << endl;
	//cout << Max(3.5, 10.5) << endl;

	//// ������ �ָ��� ���.
	//// const char *�� ���
	//cout << Max("Simple", "Best") << endl;

	//// char *�� ���
	//char str1[] = "Simple";
	//char str2[] = "Best";
	//cout << Max(str1, str2) << endl;


	return 0;
}

//istream sdf;