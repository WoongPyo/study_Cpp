#include <iostream>
#include <cstring>

using namespace std;

/* 디폴트 대입연산자의 문제점 */
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
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}
	~Person()
	{
		delete[] name;
		cout << "Called destructor!" << endl;
	}
};

int main(void)
{
	/* 디폴트 대입연산자의 문제점 */
	
	Person man1("Lee", 25);
	Person man2("Yoon", 27);

	man2 = man1;

	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	
	return 0;
}
