#include <iostream>
#include <cstring>

using namespace std;

/* ������ �����ε� */
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

	// ��������� ���� ������ �����ε�
	/*
	Point operator+(const Point &ref) const
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
	*/

	//�����Լ��� ���� ������ �����ε�
	friend Point operator+(const Point &pos1, const Point &pos2); //������ private�Լ��� ����ϱ� ���ؼ� friend�Լ��� �ʿ�
};

Point operator+(const Point &pos1, const Point &pos2)
{
	Point pos(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
	return pos;
}

int main()
{
	/* ������ �����ε� 
		-����
		�����ڰ� �����ε� �Ǹ�, �ǿ������� ������ ���� ������ ����� �޶����� ���� ����.
	*/
	Point pos1(3, 4);
	Point pos2(10, 10);
	Point *pt = &pos1;
	pos1.ShowPosition();
	pos2.ShowPosition();

	//������ �����ε� 2�� ��������� �ص� ��.
	Point pos3 = pos1 + pos2;
	//Point pos3 = pos1.operator+(pos2);
	//Point pos3 = pt->operator+(pos2);
	pos3.ShowPosition();

	return 0;
}
