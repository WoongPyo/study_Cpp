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
	Person &operator=(Person &ref)
	{
		delete[] name;
		int len = strlen(ref.name) + 1;
		name = new char[len];
		strcpy(name, ref.name);
		age = ref.age;
		return 
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
	/* ����Ʈ ���Կ������� ������ */
	
	Person man1("Lee", 25);
	Person man2("Yoon", 27);

	man2 = man1;

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	
	return 0;
}
