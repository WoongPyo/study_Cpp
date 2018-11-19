#include <iostream>
#include <cstring>

using namespace std;

/* 연산자 오버로딩 */
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
	Point operator+(const Point &ref)
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};


int main()
{
	/* 연산자 오버로딩 
		-정의
		연산자가 오버로딩 되면, 피연산자의 종류에 따라서 연산의 방식이 달라지는 것을 말함.
	*/
	Point pos1(3, 4);
	Point pos2(10, 10);

	pos1.ShowPosition();
	pos2.ShowPosition();

	//연산자 오버로딩
	//Point pos3 = pos1 + pos2;
	Point pos3 = pos1.operator+(pos2);

	pos3.ShowPosition();

	return 0;
}
