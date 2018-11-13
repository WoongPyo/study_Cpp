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
	int CheckingID(int ID, int accountNumber);
	int GetAccountNumber();
	void SetAccountNumber();
	void PrintAccounts();
	void PrintSelect();
};

class Print {
public :
	int GetSomting2Int(const char *inputStr);
};

int main(void)
{
	Account *accounts[N_ACCOUNT];
	Checking check(accounts);
	Print print;
	int sel;
	int result;
	char *namebuf = new char[30];
	int moneybuf;

	int closeFlag = 0;
	int idNum;

	while(1)
	{
		check.PrintSelect();
		sel = print.GetSomting2Int("[����] : ");

		switch (sel)
		{
		case 1:
			//���¸� ����
			cout << endl << "[���� ����]" << endl;
			idNum = print.GetSomting2Int("���� ID		: ");

			if (check.CheckingID(idNum, check.GetAccountNumber()) == NO_MATCH)
			{
				cout << "�̸�		: ";
				cin >> namebuf;
				moneybuf = print.GetSomting2Int("�Աݾ�		: ");
				accounts[check.GetAccountNumber()] = new Account(idNum, moneybuf, namebuf);
				check.SetAccountNumber();
			}
			else
			{
				cout << "���� ID�� ���� �մϴ�." << endl;
			}
			break;
		case 2:
			//�Ա�
			cout << endl << "[�Ա�]" << endl;
			idNum = print.GetSomting2Int("���� ID		: ");
			result = check.CheckingID(idNum, check.GetAccountNumber());
			if (result == NO_MATCH)
			{
				cout << "���� ID�� ���� ���� �ʽ��ϴ�." << endl;
			}
			else
			{
				moneybuf = print.GetSomting2Int("�Աݾ�		: ");
				accounts[result]->InputMoney(moneybuf);
				cout << "�ԱݿϷ� �Ǿ����ϴ�." << endl << endl;
			}
			break;
		case 3:
			//���
			cout << endl << "[���]" << endl;
			idNum = print.GetSomting2Int("���� ID		: ");
			result = check.CheckingID(idNum, check.GetAccountNumber());
			if (result == NO_MATCH)
			{
				cout << "���� ID�� ���� ���� �ʽ��ϴ�." << endl;
			}
			else
			{
				moneybuf = print.GetSomting2Int("��ݾ�		: ");
				if (accounts[result]->OutputMoney(moneybuf))
				{
					std::cout << "��ݿϷ� �Ǿ����ϴ�." << std::endl << std::endl;
				}
				else
				{
					cout << "��ݾ��� �ܾ׺��� �����ϴ�." << std::endl << std::endl;
				}
			}
			break;
		case 4:
			//�����������
			cout << endl << "[��ü���]" << endl;
			check.PrintAccounts();
			break;
		case 5:
			//���α׷� ����
			closeFlag = 1;
			delete[] namebuf;
			break;
		}
		if (closeFlag)		break;
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

int Checking::CheckingID(int ID, int accountNumber)
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

void Checking::SetAccountNumber(void)
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

int Print::GetSomting2Int(const char *inputStr)
{
	int buf;
	cout << inputStr;
	cin >> buf;
	return buf;
}