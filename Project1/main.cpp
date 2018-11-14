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

// 데이터 관리 클래스 entity class
class Employee
{
private:
	char name[100];
public:
	//생성자
	Employee(const char *name)
	{
		strcpy(this->name, name);
	}
	//사원명을 출력하는 함수
	void ShowYourName() const
	{
		cout << "name : " << name << endl;
	}
	//급여를 반환하는 가상함수
	virtual int GetSalary() const
	{
		return 0;
	}
	// 사원 정보를 출력하는 가상함수
	virtual void ShowEmployeeInfo() const
	{}
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	//생성자
	PermanentWorker(const char *name, int money) : Employee(name), salary(money)
	{}
	//급여를 반환하는 함수
	int GetSalary() const
	{
		return salary;
	}
	//정규직원 정보를 출력하는 함수
	void ShowEmployeeInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetSalary() << endl << endl;
	}

};

//기능적 클래스 handler class
class EmployeeHandler
{
private:
	//다형성
	Employee *empList[50];
	int empNum;
public:
	//생성자
	EmployeeHandler() : empNum(0)
	{}
	//사원추가기능의 함수
	void AddEmployee(Employee *emp)
	{
		empList[empNum++] = emp;
	}
	//전체사원 급여정보를 출력하는 함수
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowEmployeeInfo();
	}
	//이번달에 지급해야 할 총급여를 출력하는 함수
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetSalary();
		cout << "Total Salary : " << sum << endl;
	}
	//소멸자
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main()
{
	EmployeeHandler handler;

	handler.AddEmployee(new PermanentWorker("홍길동", 200));
	handler.AddEmployee(new PermanentWorker("박수남", 300));
	handler.AddEmployee(new PermanentWorker("아무개", 500));
	
	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();
	return 0;
}