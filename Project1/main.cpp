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
	/*	대입 연산자의 오버로딩 
		-복사생성자하고 좀 비슷
	*/
	
	//Point pos1(5, 7);
	//Point pos2 = pos1;	// 복사생성자
	//Point pos2(pos1);		// 컴파일러가 코드를 변경
	//복사생성자의 단점 ->
	//얕은 복사 : 멤버 대 멤버 복사 -> 깊은 복사

	//Point pos1(5, 7);
	//Point pos2(9, 10);
	//pos2 = pos1; // 연산자의 피연산자의 대상이 객체 이기 때문에 멤버 대 멤버 복사
	//pos2.operator=(pos1);
	
	return 0;
}
