#include <iostream>
#include <cstring>

using namespace std;

/* ����Ŭ������ ���� ����ó�� */
// �Ա�, ��� ���� class�� �θ� class
// �߻�Ŭ���� : ���������Լ��� ����� class
// ��ü�� ������� �ϸ� ������ ������ �߻�.
class AccountException
{
public:
	//���������Լ� : �Լ��� ��ü�� ���� �����Լ�.
	virtual void ShowExceptionReason() = 0;
	//�����Լ�
	//virtual void ShowExceptionReason() {}
};

class DepositException : public AccountException
{
private:
	int deMoney;
public:
	DepositException(int money) : deMoney(money)
	{}
	void ShowExceptionReason()
	{
		cout << "���ܸ޼��� : " << deMoney << "�� �ԱݺҰ��մϴ�." << endl;
	}
};

//��� ����ó�� class
class WirhdrawException : public AccountException
{
private:
	int balance;
public:
	WirhdrawException(int money) : balance(money)
	{}
	void ShowExceptionReason()
	{
		cout << "���ܸ޼��� : ���� �ܾ��� " << balance << "���� �۽��ϴ�." << endl;
	}
};

//���� class
class Account
{
private:
	char accNum[50];	//���¹�ȣ
	int balance;		//�����ܾ�
public:
	// ������
	Account(const char *acc, int money) : balance(money)
	{
		strcpy(accNum, acc);
	}
	//�Ա��Լ�
	void Deposit(int money) //throw (DepositException) // ���ܿ� ���� Ŭ������ throw ���� ��� <--��� ����
	{
		if (money < 0)
		{
			throw DepositException(money);
		}
		balance += money;
	}
	//����Լ�
	void Withdraw(int money) throw (WirhdrawException) // ���ܿ� ���� Ŭ������ throw ���� ���
	{
		if (money > balance)
			throw WirhdrawException(money);

		balance -= money;
	}
	//�ܾ�����Լ�
	void ShowMyMoney()
	{
		cout << "�ܾ� : " << balance << endl << endl;
	}
};

int main(void)
{

	/* ����Ŭ������ ���� ����ó�� */
	Account myAcc("77777-77777", 5000);
	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	catch (AccountException &expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	try
	{
		myAcc.Withdraw(1000);
		myAcc.Withdraw(9000);
	}
	catch (AccountException &expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	return 0;
}

/* ���� ó���� ���� ��Ӱ��迡���� �������ӿ� ���� ���ǻ��� */
class AAA
{
public:
	void ShowYou()
	{
		cout << "AAA exception" << endl;
	}
};

class BBB : public AAA
{
public:
	void ShowYou()
	{
		cout << "BBB exception" << endl;
	}
};

class CCC: public BBB
{
public:
	void ShowYou()
	{
		cout << "BBB exception" << endl;
	}
};

void ExceptionGenerator(int expn)
{
	if (expn == 1)
		throw AAA();
	else if (expn == 2)
		throw BBB();
	else
		throw CCC();
}