#include <iostream>
#include <cstring>

using namespace std;

/* ����Ʈ ���Կ������� ������ */
class Person
{
private:
	char *name;
	int age;
public:
	Person(const char *myName, int myAge)
	{
		int len = strlen(myName) + 1;
		name = new char[len];
		strcpy(name, myName);
		age = myAge;
	}
	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "Called destructor!" << endl;
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
	
	return 0;
}
