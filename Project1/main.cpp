#include <iostream>
#include <cstring>

using namespace std;

/* 클래스 템플릿 */
/*
템플릿 클래스		<- 템플릿으로 부터 생성된 클래스
템플릿 함수		<- 템플릿으로 부터 생성된 함수

함수 템플릿		<- 템플릿을 사용한 함수
클래스 템플릿		<- 템플릿을 사용한 클래스
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

/* 템플릿(Template)의 특수화 */
template <class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template<> // template<>인 경우 형을 지정하지 않아. 특수화 하는 것임. 지정된 변수의 형태는 다음과 같은 형태로 변환하자. char *
char *Max(char *a, char *b)
{
	cout << "char *Max(char *a, char *b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

template<> //지정된 변수의 형태는 다음과 같은 형태로 변환하자. const char *
const char *Max(const char *a, const char *b)
{
	cout << "const char *Max(const char *a, const char *b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main()
{
	/* 클래스 템플릿 */

	Point<int> pos1(3, 4);
	pos1.ShowPosition();

	Point<double> pos2(2.5, 7.5);
	pos2.ShowPosition();

	Point<char> pos3('X', 'Y');
	pos3.ShowPosition();

	/*	템플릿(Template)의 특수화*/

	//cout << Max(11, 15) << endl;
	//cout << Max('T','Q') << endl;
	//cout << Max(3.5, 10.5) << endl;

	//// 기준이 애매한 경우.
	//// const char *의 경우
	//cout << Max("Simple", "Best") << endl;

	//// char *의 경우
	//char str1[] = "Simple";
	//char str2[] = "Best";
	//cout << Max(str1, str2) << endl;


	return 0;
}

//istream sdf;