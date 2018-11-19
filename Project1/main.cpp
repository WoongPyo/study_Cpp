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

	/* �ڷ����� �ٸ� ����� ������ �����ε� */
	Point operator*(int times)
	{
		Point pos(xpos*times, ypos*times);
		return pos;
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
	/* �ڷ����� �ٸ� ����� ������ �����ε� */
	Point pos(1, 2);
	Point cpy;

	//cpy = pos * 3;
	cpy.ShowPosition();

	return 0;
}
