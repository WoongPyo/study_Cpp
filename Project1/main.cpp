#include <iostream>
#include <cstring>

using namespace std;

/* ���� ������ �����ε� */
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

	// ��������� ���� ���� ������ �����ε�
	Point &operator++()
	{		
		xpos++;
		ypos++;
		return *this;
	}

	// ++ ���������� �����ε�
	Point operator++(int)
	{
		const Point retobj(xpos, ypos);
		xpos++;
		ypos++;
		return retobj;
	}

	//�����Լ��� ���� ���� ������ �����ε�
	friend Point &operator--(Point &ref); //������ private�Լ��� ����ϱ� ���ؼ� friend�Լ��� �ʿ�
	friend Point operator--(Point &ref, int);
};

Point &operator--(Point &ref)
{
	ref.xpos--;
	ref.ypos--;
	return ref;
}

//-- ���������� �����ε�
Point operator--(Point &ref, int)
{
	const Point retobj(ref);
	ref.xpos--;
	ref.ypos--;
	return retobj;
}

int main()
{
	/* ������ �����ε� 
		-����
		�����ڰ� �����ε� �Ǹ�, �ǿ������� ������ ���� ������ ����� �޶����� ���� ����.
	*/

	/*���� ������ �����ε�(����)
		- ++pos, --pos (�����϶�)
		pos.operator++();
		pos.operator--();

		- pos++, pos-- (�����϶�)
		pos.operator++(int); //int�� ������ ���� ������ ����
		pos.poerator--(int);
	*/

	Point pos(3, 5);
	Point cpy;
//	cpy = pos--; //�����Լ�
	cpy.ShowPosition();
	pos.ShowPosition();

	cpy = pos++; //����Լ�
	cpy.ShowPosition();
	pos.ShowPosition();

	return 0;
}
