#include <iostream>

using namespace std;

/*	���� ����(shallow copy)
	���� ����(deep copy)		*/

/*	
	���� ������ ������ �߻��ϴ� Ÿ�̹�
	1. "="
	2. call by value ����� �Լ� ȣ��������� ��ü�� ���ڷ� ������ ��
	3. ��ü�� ��ȯ�� ��, ���������� ��ȯ���� �ʴ� ���.
*/

class Person
{
private:
	char *name;
	int age;

public:
	Person(const char *myName, int myAge) : age(myAge)
	{
		int len = strlen(myName) + 1;
		cout << len << endl;
		name = new char[len];
		strcpy(name, myName);
	}
	/* ���� ���� */
	Person(const Person &copy) : age(copy.age)
	{
		int len = strlen(copy.name) + 1;
		cout << len << endl;
		name = new char[len];
		strcpy(name, copy.name);
	}

	void ChangeName(const char *changeName)
	{
		int len = strlen(changeName) + 1; //strlen�� ��� '\0' ������ ���̴� ���� ���� ���� '\0'�� �����ϱ� ���� ����� �ʿ�.
		name = new char[len];
		strcpy(name, changeName);
	}

	void WhatYourName() const
	{
		cout << "My name is " << name << endl;
	}

	void HowOldAreYou() const
	{
		cout << "I'm " << age << " years old." << endl;
	}

	~Person()
	{
		delete[] name;
		cout << "called destructor!!" << endl;
	}
};


int main()
{
	/*���� ����(shallow copy)�� ������<--������ 
	char *name�� �ּҸ� �����ϴ� ����, Lee�� �ּҰ� ��*/
	Person man1("Lee", 25);
	Person man2(man1); //��������ڷ� �����ϱ� ������ char *name���� man1�� ����Ǿ��� name�� �ּҰ� ��.

	//man1.ChangeName("hong");
	//man1.WhatYourName();
	man2.WhatYourName();
	man2.HowOldAreYou();

	return 0;
}