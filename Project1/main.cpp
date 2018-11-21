#include <iostream>
#include <cstring>

using namespace std;

class Point
{
private:
	int xPos, yPos;
	
	// 기본 대입연산자의 오버로딩을 막는 방법
	// 다른 함수에서 대입연산자를 쓰지 못하게 하기 위해 넣음.
	// 동일한 객체(사번 111이라는 객체)가 시스템 내에서 존재하지 않도록 하기 위해서.
	Point &operator=(const Point &ref);

	//복사생성자를 막는 방법
	Point(const Point &ref) {}

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

	//복사 생성자 막음
	BoundCheckPointArray(const BoundCheckPointArray &arr) {}

	//기본대입연산자 오버로딩 막음
	BoundCheckPointArray &operator=(const BoundCheckPointArray &arr) {}

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
	//내부 멤버변수가 2개 생기는 것을 막아야 할 경우 -> 막아야 하는게 맞을 수 있음.
	arr[1] = Point(5, 6); //기본 대입연산자 호출
	arr[2] = Point(7, 8); //기본 대입연산자 호출

	for(int i=0; i<3; i++)
		arr[i].ShowData();

	//배열 복사
	BoundCheckPointArray cpy(3);
	cpy = arr;

	return 0;
}