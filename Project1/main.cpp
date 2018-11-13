#include <iostream>
#include <cstring>

using namespace std;

#define N_ACCOUNT	100
#define NO_MATCH	N_ACCOUNT+1

class Account {
private:
	int account_id;
	int money;
	char *name;

public : 
	Account(int ID, int money, char* name);
	~Account();
	int PutID();
	void InputMoney(int inputMoney);
	bool OutputMoney(int outputMoney);
	void PrintAccount();

};

class Checking {
private:
	Account **accounts;
	int accountNumber;

public:
	Checking(Account **firAccountAdr);
	int CheckingID(int ID);
	int GetAccountNumber();
	void IncreaseAccountNumber();
	void PrintAccounts();
	void PrintSelect();
};

class Print {
public :
	int GetInt(const char *inputStr);
};

int main(void)
{
	Account *accounts[N_ACCOUNT];
	Checking check(accounts);
	Print print;

	int iDbuf;
	char *namebuf = new char[30];
	int moneybuf;

	int matchIdOrder;
	bool finishFlag = false;

	while(1)
	{
		check.PrintSelect();											// ���� �޴� ���

		switch (print.GetInt("[����] : "))								// case ���� �ϱ�
		{
		case 1:
			//���¸� ����
			cout << endl << "[���� ����]" << endl;
			iDbuf = print.GetInt("���� ID		: ");					// ID�� ����

			if (check.CheckingID(iDbuf) == NO_MATCH)					// ����� ID�� �ִ��� Ȯ�� ���� ���°���
			{
				cout << "�̸�		: ";
				cin >> namebuf;
				moneybuf = print.GetInt("�Աݾ�		: ");
				accounts[check.GetAccountNumber()] = new Account(iDbuf, moneybuf, namebuf);
				check.IncreaseAccountNumber();							// ���°����� 1 ����
			}
			else
			{
				cout << "���� ID�� ���� �մϴ�." << endl;
			}
			break;
		case 2:
			//�Ա�
			cout << endl << "[�Ա�]" << endl;
			iDbuf = print.GetInt("���� ID		: ");
			matchIdOrder = check.CheckingID(iDbuf);
			if (matchIdOrder == NO_MATCH)										// ���� ID�� ���� ���°� �������� ����
			{
				cout << "���� ID�� ���� ���� �ʽ��ϴ�." << endl;
			}
			else
			{
				moneybuf = print.GetInt("�Աݾ�		: ");
				accounts[matchIdOrder]->InputMoney(moneybuf);					// ���� ���¿� ���� �Ա�
				cout << "�ԱݿϷ� �Ǿ����ϴ�." << endl << endl;
			}
			break;
		case 3:
			//���
			cout << endl << "[���]" << endl;
			iDbuf = print.GetInt("���� ID		: ");
			matchIdOrder = check.CheckingID(iDbuf);
			if (matchIdOrder == NO_MATCH)										// ���� ID�� ���� ���°� �������� ����
			{
				cout << "���� ID�� ���� ���� �ʽ��ϴ�." << endl;
			}
			else
			{
				moneybuf = print.GetInt("��ݾ�		: ");
				if (accounts[matchIdOrder]->OutputMoney(moneybuf))			// ���� ���¿� �Է��� ���� ��ݰ��� Ȯ��
				{
					cout << "��ݿϷ� �Ǿ����ϴ�." << endl << endl;
				}
				else
				{
					cout << "��ݾ��� �ܾ׺��� �����ϴ�." << endl << endl;
				}
			}
			break;
		case 4:
			//�����������
			cout << endl << "[��ü���]" << endl;						// ���� ���� ���
			check.PrintAccounts();
			break;
		case 5:
			//���α׷� ����
			finishFlag = true;
			for (int i = 0; i < check.GetAccountNumber(); i++)			// ���� ����
			{
				delete accounts[i];
			}
			break;
		}

		if (finishFlag)
		{
			delete[] namebuf;
			break;
		}
	}
	return 0;
}


Account::Account(int ID, int money, char* name) : account_id(ID), money(money)
{
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy(this->name, name);
}
Account::~Account()
{
	delete[] name;
}

int Account::PutID()
{
	return account_id;
}

void Account::InputMoney(int inputMoney)
{
	money += inputMoney;
}

bool Account::OutputMoney(int outputMoney)
{
	if ((money - outputMoney) < 0)
		return false;
	else
	{
		money -= outputMoney;
		return true;
	}
}
void Account::PrintAccount()
{
	std::cout << "���� ID		: "	<< account_id << endl;
	std::cout << "�̸�		: "		<< name << endl;
	std::cout << "�Աݾ�		: "		<< money << endl << endl;
}


Checking::Checking(Account **firAccountAdr)
{
	accounts = firAccountAdr;
	accountNumber = 0;
}

int Checking::CheckingID(int ID)
{
	for (int i = 0; i < accountNumber; i++)
	{
		if (ID == accounts[i]->PutID())
		{
			return i;
		}
	}
	return NO_MATCH;
}

int Checking::GetAccountNumber(void)
{
	return accountNumber;
}

void Checking::IncreaseAccountNumber(void)
{
	accountNumber++;
}

void Checking::PrintAccounts()
{
	for (int i = 0; i < accountNumber; i++)
	{
		accounts[i]->PrintAccount();
	}
}

void Checking::PrintSelect(void)
{
	cout << "--------Menu--------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl << endl;
}

int Print::GetInt(const char *inputStr)
{
	int buf;
	cout << inputStr;
	cin >> buf;
	return buf;
}