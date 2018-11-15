#include <iostream>
#include <stdlib.h>

using namespace std;

/*
- 정규직은 사원이다.(상속)
- 사원명, 월급을 관리할 수 있도록 클래스를 디자인하세요.(캡슐화)
- 사원을 관리할 수 있는 클래스를 디자인하세요.(다형성)
- 이번 달에 지불해야 할 급여의 총합(virtual)
- 영업직, 임시직의 엔터티 클래스를 작성하세요.
- 영업직의 급여는 기본급에 성과급을 포함할 수 있도록 디자인하세요.
- 임시직 시급으로 계산해서 지급될 수 있도록 디자인하세요.
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

class SalesWorker : public PermanentWorker
{
private:
	//판매실적
	int salesResult;
	//상여금비율
	double bonusRatio;
public:
	//생성자
	SalesWorker(const char *name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{}
	//판매실적을 더하는 함수
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	//급여를 반환하는 함수
	int GetSalary() const
	{
		return PermanentWorker::GetSalary() + (int)(salesResult * bonusRatio);
	}
	//급여정보를 출력하는 함수
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "Salary : " << GetSalary() << endl << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	//일한시간
	int workTime;
	//시급
	double payPerHour;
public:
	//생성자
	TemporaryWorker(const char *name, double pay) : Employee(name), workTime(0), payPerHour(pay)
	{}
	//근무시간을 더하는 함수
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	//급여를 반환하는 함수
	int GetSalary() const
	{
		return workTime * payPerHour;
	}
	//급여정보를 출력하는 함수
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


	//정규직 사원등록
	handler.AddEmployee(new PermanentWorker("홍길동", 200));

	//영업직 사원등록
	SalesWorker *seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(10000);
	handler.AddEmployee(seller);

	//아르바이트직 사원등록
	TemporaryWorker *alba = new TemporaryWorker("Kim", 0.8);
	alba->AddWorkTime(100);
	handler.AddEmployee(alba);

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();
	return 0;
}