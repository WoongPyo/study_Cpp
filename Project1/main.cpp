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
		cout << xpos << endl;
		Point pos(xpos++, ypos++);
		return pos;
		/*
		xpos++;
		ypos++;
		return *this;
		*/
	}

	//전역함수에 의한 단항 연산자 오버로딩
	friend Point &operator--(Point &ref); //내부의 private함수를 사용하기 위해서 friend함수가 필요
};

Point &operator--(Point &ref)
{
	
	Point pos(ref.xpos--, ref.ypos--);
	return pos;
	
	/*
	ref.xpos--;
	ref.ypos--;
	return ref;
	*/
}

int main()
{
	/* 연산자 오버로딩 
		-정의
		연산자가 오버로딩 되면, 피연산자의 종류에 따라서 연산의 방식이 달라지는 것을 말함.
	*/

	/* 단항 연산자 오버로딩 */
	Point pos(1, 5);
	pos.ShowPosition();
	//++pos; //전위 연산자
	pos.operator++();	//멤버함수의 경우
	//operator++(pos);	//전역함수의 경우
	pos.ShowPosition();
	--pos; //전위 연산자
	//pos.oparator--();
	pos.ShowPosition();
	operator--(pos);	//전역함수의 경우
	pos.ShowPosition();

	++(++pos);
	cout << '2' << endl;
	pos.ShowPosition();
	--(--pos);
	cout << '1' << endl;
	pos.ShowPosition();

	/*단항 연산자 오버로딩(후위)
		- ++pos, --pos (전위일때)
		pos.operator++();
		pos.operator--();

		- pos++, pos-- (후위일때)
		pos.operator++(int); //int가 붙으면 후위 연산자 정의
		pos.poerator--(int);
	*/

	return 0;
}
