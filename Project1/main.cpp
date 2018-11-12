#include <iostream>

using namespace std;

class Person
{
private : 
	char *name = {};
	int age;

public:
	// �Ű������� ���� constructor
	Person()
	{
		name = NULL;
		age = 0;
		cout << "Person() called!" << endl;
	}

	// �Ű������� �ִ� constructor
	Person(const char *myName, int myAge)
	{
		int len = strlen(myName) + 1;
		name = new char[len];
		strcpy(name, myName);
		age = myAge;
	}
	//������� ���� �Լ�
	void SetPersonInfo(char *myName, int myAge)
	{
		name = myName;
		age = myAge;
	}

	//����Լ�
	void ShowPersonInfo() const
	{
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}

	//destructor
	~Person()
	{
		delete[] name;
		cout << "called destructor!!" << endl;
	}
};

/*��ü ������ �迭*/

int main(void)
{
	/*��ü�迭*/
	Person personArr[3];
	char namestr[100];
	char *strptr;
	int age;
	int len;
	
	for (int i = 0; i < 3; i++)
	{
		cout << "�̸� : ";
		cin >> namestr;
		cout << "���� : ";
		cin >> age;

		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		personArr[i].SetPersonInfo(strptr, age);
		cout << endl;
	}
	personArr[0].ShowPersonInfo();
	personArr[1].ShowPersonInfo();
	personArr[2].ShowPersonInfo();

	return 0;
}
