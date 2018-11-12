#include <iostream>

using namespace std;

class Person
{
private : 
	char *name = {};
	int age;

public:
	// 매개변수가 없는 constructor
	Person()
	{
		name = NULL;
		age = 0;
		cout << "Person() called!" << endl;
	}

	// 매개변수가 있는 constructor
	Person(const char *myName, int myAge)
	{
		int len = strlen(myName) + 1;
		name = new char[len];
		strcpy(name, myName);
		age = myAge;
	}
	//멤버변수 수정 함수
	void SetPersonInfo(char *myName, int myAge)
	{
		name = myName;
		age = myAge;
	}

	//출력함수
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

/*객체 포인터 배열*/

int main(void)
{
	/*객체배열*/
	Person personArr[3];
	char namestr[100];
	char *strptr;
	int age;
	int len;
	
	for (int i = 0; i < 3; i++)
	{
		cout << "이름 : ";
		cin >> namestr;
		cout << "나이 : ";
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
