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
	/* 연산자 오버로딩 
		-정의
		연산자가 오버로딩 되면, 피연산자의 종류에 따라서 연산의 방식이 달라지는 것을 말함.
	*/

	/*단항 연산자 오버로딩(후위)
		- ++pos, --pos (전위일때)
		pos.operator++();
		pos.operator--();

		- pos++, pos-- (후위일때)
		pos.operator++(int); //int가 붙으면 후위 연산자 정의
		pos.poerator--(int);
	*/

	Point pos(3, 5);
	Point cpy;
//	cpy = pos--; //전역함수
	cpy.ShowPosition();
	pos.ShowPosition();

	cpy = pos++; //멤버함수
	cpy.ShowPosition();
	pos.ShowPosition();

	return 0;
}
