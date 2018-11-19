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
		cout << xpos << endl;
		Point pos(xpos++, ypos++);
		return pos;
		/*
		xpos++;
		ypos++;
		return *this;
		*/
	}

	//�����Լ��� ���� ���� ������ �����ε�
	friend Point &operator--(Point &ref); //������ private�Լ��� ����ϱ� ���ؼ� friend�Լ��� �ʿ�
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
	/* ������ �����ε� 
		-����
		�����ڰ� �����ε� �Ǹ�, �ǿ������� ������ ���� ������ ����� �޶����� ���� ����.
	*/

	/* ���� ������ �����ε� */
	Point pos(1, 5);
	pos.ShowPosition();
	//++pos; //���� ������
	pos.operator++();	//����Լ��� ���
	//operator++(pos);	//�����Լ��� ���
	pos.ShowPosition();
	--pos; //���� ������
	//pos.oparator--();
	pos.ShowPosition();
	operator--(pos);	//�����Լ��� ���
	pos.ShowPosition();

	++(++pos);
	cout << '2' << endl;
	pos.ShowPosition();
	--(--pos);
	cout << '1' << endl;
	pos.ShowPosition();

	/*���� ������ �����ε�(����)
		- ++pos, --pos (�����϶�)
		pos.operator++();
		pos.operator--();

		- pos++, pos-- (�����϶�)
		pos.operator++(int); //int�� ������ ���� ������ ����
		pos.poerator--(int);
	*/

	return 0;
}
