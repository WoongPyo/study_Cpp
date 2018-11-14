#include <iostream>

using namespace std;

/* 상속
	- 관계가 논리적으로 성립이 되어야 상속이라고 말할 수 있다.
	- is A 관계, has A 관계
	- is A 관계
	노트북은 컴퓨터이다. Notebook is a computer.
	- has A 관계
	경찰은 총을 가진다. Police has a gun.

	- 상속의 목적
	class 간의 관계를 체계적으로 유지 및 관리하기 위해서이다.
	재사용하기 위해서 <- 관계가 체계적이어서.

	예시) - is A 관계 : 학생은 사람이다. Student is a person.
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
	Student stu1("홍길동", 30, "기계");
	stu1.WhoAreYou();

	return 0;
}