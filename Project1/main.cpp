#include <iostream>
#include <stdlib.h>

using namespace std;

/*
- 정규직은 사원이다.
- 사원명, 월급을 관리할 수 있도록 클래스를 디자인하세요.
- 사원을 관리할 수 있는 클래스를 디자인하세요.
- 이번 달에 지불해야 할 급여의 총합
- 간단한 인사관리 프로그램을 작성하세요.
*/

class FullTime
{
private:
	char name[20];
	int pay;
public:
	FullTime(const char *name, int pay) : pay(pay)
	{
		strcpy(this->name, name);
	}
	int GetPay()
	{
		return pay;
	}
	void ShowName()
	{
		cout << "이름 : " << name << endl;
	}
	void ShowPay()
	{
		cout << "봉급 : " << pay << endl;
	}
};

class Employee
{
private:
	FullTime *fulltime[100];
	int numEmployee;
public:
	Employee()
	{
		numEmployee = 0;
	}
	void AddEmployee(FullTime *fulltime)
	{
		this->fulltime[numEmployee] = fulltime;
		numEmployee++;
	}
	void ShowEmployee()
	{
		for (int i = 0; i < numEmployee; i++)
		{
			fulltime[i]->ShowName();
			fulltime[i]->ShowPay();
			cout << endl;
		}
	}
	int MoneyForMonth()
	{
		int sum = 0;
		for (int i = 0; i < numEmployee; i++)
		{
			sum += fulltime[i]->GetPay();
		}
		return sum;
	}
};

int main()
{
	FullTime person1("진우", 3000);
	FullTime person2("지우", 5000);
	Employee employee;

	employee.AddEmployee(&person1);
	employee.AddEmployee(&person2);
	employee.ShowEmployee();
	cout << employee.MoneyForMonth() << endl;
	return 0;
}