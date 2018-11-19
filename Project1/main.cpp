#include <iostream>
#include <cstring>

using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{}
	SoSimple &AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData() const
	{
		cout << "num : " << num << endl;
	}
};

int main()
{
	/* const ��ü 
		- const ��ü�� const �Լ��� ȣ�� ����.
		��ü�� ��������� ������ ������� ����.
	*/
	SoSimple generalObj(10);
	generalObj.AddNum(10);
	generalObj.ShowData();

	const SoSimple constObj(100);
	constObj.ShowData(); // const ��ü�� const �Լ��� ȣ�� �� �� �ִ�.
	//constObj.AddNum(200);

	/* const  �Լ� �����ε� */
	/* friend ���� */

	return 0;
}