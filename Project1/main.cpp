#include <iostream>
#include <cstring>

using namespace std;

class Point
{
private:
	int xPos, yPos;
public:
	Point(int x=0, int y=0) : xPos(x), yPos(y)
	{}
	void ShowData() const
	{
		cout << "X좌표 : " << xPos << " , "
			<< "Y좌표 : " << yPos << endl;
	}
};

class BoundCheckPointArray
{
private:
	Point *arr;
	int arrLen;
public:
	BoundCheckPointArray(int len) : arrLen(len)
	{
		arr = new Point[len];
	}
	~BoundCheckPointArray()
	{
		delete[] arr;
	}
	Point &operator[](int idx)
	{
		if (idx < 0 || idx >= arrLen)
		{
			cout << "매별의 범위를 벗어났습니다." << endl;
			exit(1);
		}
		return arr[idx];
	}
};

int main()
{
	/* 객체의 저장을 위한 배열 클래스의 정의 */
	BoundCheckPointArray arr(3);

	arr[0] = Point(3, 4); //기본 대입연산자 호출 -> Point객체의 멤버 (xPos,yPos) 0,0을 3,4로 변경
	arr[1] = Point(5, 6); //기본 대입연산자 호출
	arr[2] = Point(7, 8); //기본 대입연산자 호출

	for(int i=0; i<3; i++)
		arr[i].ShowData();

	return 0;
}