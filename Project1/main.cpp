#include <iostream>
#include <stdlib.h>

using namespace std;

/*
- �������� ����̴�.(���)
- �����, ������ ������ �� �ֵ��� Ŭ������ �������ϼ���.(ĸ��ȭ)
- ����� ������ �� �ִ� Ŭ������ �������ϼ���.(������)
- �̹� �޿� �����ؾ� �� �޿��� ����(virtual)
- ������, �ӽ����� ����Ƽ Ŭ������ �ۼ��ϼ���.
- �������� �޿��� �⺻�޿� �������� ������ �� �ֵ��� �������ϼ���.
- �ӽ��� �ñ����� ����ؼ� ���޵� �� �ֵ��� �������ϼ���.
- ������ �λ���� ���α׷��� �ۼ��ϼ���.
*/

// ������ ���� Ŭ���� entity class
class Employee
{
private:
	char name[100];
public:
	//������
	Employee(const char *name)
	{
		strcpy(this->name, name);
	}
	//������� ����ϴ� �Լ�
	void ShowYourName() const
	{
		cout << "name : " << name << endl;
	}
	//�޿��� ��ȯ�ϴ� �����Լ�
	virtual int GetSalary() const
	{
		return 0;
	}
	// ��� ������ ����ϴ� �����Լ�
	virtual void ShowEmployeeInfo() const
	{}
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	//������
	PermanentWorker(const char *name, int money) : Employee(name), salary(money)
	{}
	//�޿��� ��ȯ�ϴ� �Լ�
	int GetSalary() const
	{
		return salary;
	}
	//�������� ������ ����ϴ� �Լ�
	void ShowEmployeeInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetSalary() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	//�ǸŽ���
	int salesResult;
	//�󿩱ݺ���
	double bonusRatio;
public:
	//������
	SalesWorker(const char *name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{}
	//�ǸŽ����� ���ϴ� �Լ�
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	//�޿��� ��ȯ�ϴ� �Լ�
	int GetSalary() const
	{
		return PermanentWorker::GetSalary() + (int)(salesResult * bonusRatio);
	}
	//�޿������� ����ϴ� �Լ�
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "Salary : " << GetSalary() << endl << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	//���ѽð�
	int workTime;
	//�ñ�
	double payPerHour;
public:
	//������
	TemporaryWorker(const char *name, double pay) : Employee(name), workTime(0), payPerHour(pay)
	{}
	//�ٹ��ð��� ���ϴ� �Լ�
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	//�޿��� ��ȯ�ϴ� �Լ�
	int GetSalary() const
	{
		return workTime * payPerHour;
	}
	//�޿������� ����ϴ� �Լ�
	void ShowEmployeeInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetSalary() << endl << endl;
	}
};

//����� Ŭ���� handler class
class EmployeeHandler
{
private:
	//������
	Employee *empList[50];
	int empNum;
public:
	//������
	EmployeeHandler() : empNum(0)
	{}
	//����߰������ �Լ�
	void AddEmployee(Employee *emp)
	{
		empList[empNum++] = emp;
	}
	//��ü��� �޿������� ����ϴ� �Լ�
	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowEmployeeInfo();
	}
	//�̹��޿� �����ؾ� �� �ѱ޿��� ����ϴ� �Լ�
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetSalary();
		cout << "Total Salary : " << sum << endl;
	}
	//�Ҹ���
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main()
{
	EmployeeHandler handler;


	//������ ������
	handler.AddEmployee(new PermanentWorker("ȫ�浿", 200));

	//������ ������
	SalesWorker *seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(10000);
	handler.AddEmployee(seller);

	//�Ƹ�����Ʈ�� ������
	TemporaryWorker *alba = new TemporaryWorker("Kim", 0.8);
	alba->AddWorkTime(100);
	handler.AddEmployee(alba);

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();
	return 0;
}