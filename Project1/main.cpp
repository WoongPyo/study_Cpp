#include <iostream>
#include <cstring>

using namespace std;

/* friend 선언 함수인경우 */
class Point;

class PointOP
{
private:
	int opCnt;
public:
	PointOP() : opCnt(0)
	{}
	Point PointAdd(const Point &pnt1, const Point &pnt2);
	Point PointSub(const Point &pnt1, const Point &pnt2);
	~PointOP()
	{
		cout << "Operation Timmes : " << opCnt << endl;
	}
};

class Point
{
private:
	int x;
	int y;
public:
	Point(const int &xpos, const int &ypos) : x(xpos), y(ypos)
	{}
	//friend 함수
	friend Point PointOP::PointAdd(const Point &pnt1, const Point &pnt2);
	//friend 함수
	friend Point PointOP::PointSub(const Point &pnt1, const Point &pnt2);
	//friend 함수 <-- 전역함수를 friend선언
	friend void ShowPointPos(const Point&);
};

Point PointOP::PointAdd(const Point &pnt1, const Point& pnt2)
{
	opCnt++;
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2)
{
	opCnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

void ShowPointPos(const Point &pos)
{
	cout << "x : " << pos.x << ", ";
	cout << "y : " << pos.y << endl;
}

int main()
{
	/*friend 선언 - 함수인 경우 */
	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos1, pos2));

	return 0;
}