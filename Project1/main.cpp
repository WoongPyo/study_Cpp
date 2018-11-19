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
	Point operator+(const Point &ref)
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};


int main()
{
	/* ������ �����ε� 
		-����
		�����ڰ� �����ε� �Ǹ�, �ǿ������� ������ ���� ������ ����� �޶����� ���� ����.
	*/
	Point pos1(3, 4);
	Point pos2(10, 10);

	pos1.ShowPosition();
	pos2.ShowPosition();

	//������ �����ε�
	//Point pos3 = pos1 + pos2;
	Point pos3 = pos1.operator+(pos2);

	pos3.ShowPosition();

	return 0;
}
