#include <iostream>
#include <cstring>

using namespace std;

class Point
{
private:
	int xPos, yPos;
	
	// �⺻ ���Կ������� �����ε��� ���� ���
	// �ٸ� �Լ����� ���Կ����ڸ� ���� ���ϰ� �ϱ� ���� ����.
	// ������ ��ü(��� 111�̶�� ��ü)�� �ý��� ������ �������� �ʵ��� �ϱ� ���ؼ�.
	Point &operator=(const Point &ref);

	//��������ڸ� ���� ���
	Point(const Point &ref) {}

public:
	Point(int x=0, int y=0) : xPos(x), yPos(y)
	{}
	void ShowData() const
	{
		cout << "X��ǥ : " << xPos << " , "
			<< "Y��ǥ : " << yPos << endl;
	}
};

class BoundCheckPointArray
{
private:
	Point *arr;
	int arrLen;

	//���� ������ ����
	BoundCheckPointArray(const BoundCheckPointArray &arr) {}

	//�⺻���Կ����� �����ε� ����
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
			cout << "�ź��� ������ ������ϴ�." << endl;
			exit(1);
		}
		return arr[idx];
	}
};

int main()
{
	/* ��ü�� ������ ���� �迭 Ŭ������ ���� */
	BoundCheckPointArray arr(3);

	arr[0] = Point(3, 4); //�⺻ ���Կ����� ȣ�� -> Point��ü�� ��� (xPos,yPos) 0,0�� 3,4�� ����
	//���� ��������� 2�� ����� ���� ���ƾ� �� ��� -> ���ƾ� �ϴ°� ���� �� ����.
	arr[1] = Point(5, 6); //�⺻ ���Կ����� ȣ��
	arr[2] = Point(7, 8); //�⺻ ���Կ����� ȣ��

	for(int i=0; i<3; i++)
		arr[i].ShowData();

	//�迭 ����
	BoundCheckPointArray cpy(3);
	cpy = arr;

	return 0;
}