#include <iostream>
#include <cstring>

using namespace std;

/* 단항 연산자 오버로딩 */
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	// 멤버변수에 의한 단항 연산자 오버로딩
	Point &operator++()
	{
		xpos++;
		ypos++;
		return *this;
	}

	// ++ 후위연산자 오버로딩
	Point operator++(int)
	{
		const Point retobj(xpos, ypos);
		xpos++;
		ypos++;
		return retobj;
	}

	/* 자료형이 다른 경우의 연산자 오버로딩 */
	Point operator*(int times)
	{
		Point pos(xpos*times, ypos*times);
		return pos;
	}

	//전역함수에 의한 단항 연산자 오버로딩
	friend Point &operator--(Point &ref); //내부의 private함수를 사용하기 위해서 friend함수가 필요
	friend Point operator--(Point &ref, int);
};

Point &operator--(Point &ref)
{
	ref.xpos--;
	ref.ypos--;
	return ref;
}

//-- 후위연산자 오버로딩
Point operator--(Point &ref, int)
{
	const Point retobj(ref);
	ref.xpos--;
	ref.ypos--;
	return retobj;
}

int main()
{
	/* 자료형이 다른 경우의 연산자 오버로딩 */
	Point pos(1, 2);
	Point cpy;

	//cpy = pos * 3;
	cpy.ShowPosition();

	return 0;
}
