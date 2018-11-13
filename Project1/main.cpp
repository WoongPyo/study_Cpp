#include <iostream>

using namespace std;

/* self_reference �ڱ� ������ ���� */
class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "��ü����" << endl;
	}
	SelfRef &Adder(int n)
	{
		num += n;
		return *this; // �ڱ��ڽ��� �����ϱ� ���� *�� this �տ� ����.
	}
	SelfRef &ShowNumber()
	{
		cout << num << endl;
		return *this;
	}
};

int main(void)
{
	/* self_reference �ڱ� ������ ���� */
	SelfRef obj(3);
	SelfRef &ref = obj.Adder(2);

	obj.ShowNumber();
	ref.ShowNumber();

	return 0;
}
