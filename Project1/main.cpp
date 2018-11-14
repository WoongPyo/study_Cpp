#include <iostream>

using namespace std;

/* ���
	- ���谡 �������� ������ �Ǿ�� ����̶�� ���� �� �ִ�.
	- is A ����, has A ����
	- is A ����
	��Ʈ���� ��ǻ���̴�. Notebook is a computer.
	- has A ����
	������ ���� ������. Police has a gun.

	- ����� ����
	class ���� ���踦 ü�������� ���� �� �����ϱ� ���ؼ��̴�.
	�����ϱ� ���ؼ� <- ���谡 ü�����̾.

	����) - is A ���� : �л��� ����̴�. Student is a person.
*/

class Person
{
private:
	char name[30];
	int age;
public:
	Person(const char *myName, int myage) : age(myage)
	{
		strcpy(name, myName);
	}

	void WhatYourName() const
	{
		cout << "My Name is " << endl;
	}

	void HowOldAreYou() const
	{
		cout << "I'm " << age << " years old." << endl;
	}
};

class Student : public Person
{
private:
	char major[50];
public:
	Student(const char *myName, int myAge, const char *myMajor) : Person(myName, myAge)
	{
		strcpy(major, myMajor);
	}

	void MyMajor() const
	{
		cout << "My major is " << major << "." << endl;
	}

	void WhoAreYou() const
	{
		WhatYourName();
		HowOldAreYou();
		MyMajor();
	}
};

int main()
{
	Student stu1("ȫ�浿", 30, "���");
	stu1.WhoAreYou();

	return 0;
}