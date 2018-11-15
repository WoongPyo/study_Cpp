#include <iostream>

using namespace std;

/*���� ����(shallow copy)
���� ����(deep copy)*/
class SoSimple
{
private:
	int num;
	int num2;
public:
	SoSimple(int n, int n2) : num(n), num2(n2)
	{}

	/* ���������(Copy constructor) */
	explicit SoSimple(SoSimple &copy) : num(copy.num), num2(copy.num2)
	{
		cout << "called copy constructor." << endl;
	}

	void ShowSimpleData()
	{
		cout << num << endl;
		cout << num2 << endl;
	}
};

int main()
{
	SoSimple sim1(20, 40);

	//SoSimple sim2 = sim1; // �����ڸ� ȣ������ �ʾƵ� sim1�� �ִ� ��������� ���� �Ѵ�. explicit Ű���带 ���� �̷��� ����� �� ����
	SoSimple sim2(sim1);

	sim2.ShowSimpleData();

	return 0;
}