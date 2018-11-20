#include <iostream>
#include <cstring>

using namespace std;

class First
{
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0) : num1(n1), num2(n2)
	{}
	void ShowData()
	{
		cout << num1 << ", " << num2 << endl;
	}
};

class Second
{
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0) : num3(n3), num4(n4)
	{}
	void ShowData()
	{
		cout << num3 << ", " << num4 << endl;
	}
	// ���� ������ �����ε�
	Second &operator=(const Second &ref)
	{
		cout << "Second& operator=()" << endl;
		num3 = ref.num3;
		num4 = ref.num4;

		return *this;
	}
};

int main(void)
{
	/*	���� �������� �����ε� 
		-����������ϰ� �� ���
	*/
	
	//Point pos1(5, 7);
	//Point pos2 = pos1;	// ���������
	//Point pos2(pos1);		// �����Ϸ��� �ڵ带 ����
	//����������� ���� ->
	//���� ���� : ��� �� ��� ���� -> ���� ����

	//Point pos1(5, 7);
	//Point pos2(9, 10);
	//pos2 = pos1; // �������� �ǿ������� ����� ��ü �̱� ������ ��� �� ��� ����
	//pos2.operator=(pos1);

	First firstOrg(111, 222);
	First firstCpy(222, 333);
	firstCpy.ShowData();

	firstCpy = firstOrg;
	firstCpy.ShowData();

	Second secondOrg(111, 222);
	Second secondCpy(222, 333);
	secondCpy.ShowData();

	secondCpy = secondOrg;
	secondCpy.ShowData();

	return 0;
}
