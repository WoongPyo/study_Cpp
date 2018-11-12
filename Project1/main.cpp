#include <iostream>

using namespace std;

class Person
{
private : 
	char *name = {};
	int age;
public:
	//constructor
	Person(const char *myName, int myAge)
	{
		int len = strlen(myName) + 1;
		name = new char[len];
		strcpy(name, myName);
		age = myAge;
	}
	void ShowPersonInfo() const
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}

	//destructor
	~Person()
	{
		delete[] name;
		cout << "called destructor!!" << endl;
	}
};

int main(void)
{
	Person man1("이동우", 25);
	Person man2("홍길동", 29);

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();


	return 0;
}
