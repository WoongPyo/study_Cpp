#include <iostream>

using namespace std;

/*	얕은 복사(shallow copy)
	깊은 복사(deep copy)		*/

/*	
	얕은 복사의 문제가 발생하는 타이밍
	1. "="
	2. call by value 방식의 함수 호출과정에서 객체를 인자로 전달할 때
	3. 객체를 반환할 때, 참조형으로 반환하지 않는 경우.
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
	/* 깊은 복사 */
	Person(const Person &copy) : age(copy.age)
	{
		int len = strlen(copy.name) + 1;
		cout << len << endl;
		name = new char[len];
		strcpy(name, copy.name);
	}

	void ChangeName(const char *changeName)
	{
		int len = strlen(changeName) + 1; //strlen의 경우 '\0' 문자의 길이는 세지 않음 따라서 '\0'를 측정하기 위한 방법이 필요.
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
	/*얕은 복사(shallow copy)의 문제점<--오류남 
	char *name은 주소를 저장하는 공간, Lee의 주소가 들어감*/
	Person man1("Lee", 25);
	Person man2(man1); //복사생성자로 생성하기 때문에 char *name에는 man1에 저장되었던 name의 주소가 들어감.

	//man1.ChangeName("hong");
	//man1.WhatYourName();
	man2.WhatYourName();
	man2.HowOldAreYou();

	return 0;
}