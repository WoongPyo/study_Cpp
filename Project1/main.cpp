#include <iostream>
#include <stdlib.h>

using namespace std;

/*
- �������� ����̴�.
- �����, ������ ������ �� �ֵ��� Ŭ������ �������ϼ���.
- ����� ������ �� �ִ� Ŭ������ �������ϼ���.
- �̹� �޿� �����ؾ� �� �޿��� ����
- ������ �λ���� ���α׷��� �ۼ��ϼ���.
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
		cout << "�̸� : " << name << endl;
	}
	void ShowPay()
	{
		cout << "���� : " << pay << endl;
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
	FullTime person1("����", 3000);
	FullTime person2("����", 5000);
	Employee employee;

	employee.AddEmployee(&person1);
	employee.AddEmployee(&person2);
	employee.ShowEmployee();
	cout << employee.MoneyForMonth() << endl;
	return 0;
}