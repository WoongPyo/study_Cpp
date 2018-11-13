#include <iostream>
#include <cstring>

using namespace std;

#define N_ACCOUNT	100
#define NO_MATCH	101

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

public:
	Checking(Account **firAccountAdr);
	int CheckingID(int ID, int accountNumber);
	void PrintAccounts(int accountNum);
	void PrintSelect(void);
};

int main(void)
{
	Account *accounts[N_ACCOUNT];
	Checking check(accounts);
	int sel;
	int accountNumber = 0;
	int result;
	char *name = new char[30];
	int money;
	bool availableFlag;

	int closeFlag = 0;
	int idNum;

	check.PrintAccounts(0);

	while(1)
	{
		check.PrintSelect();
		cout << "[����] : " ;
		cin >> sel;

		switch (sel)
		{
		case 1:
			//���¸� ����
			cout << endl;
			cout << "[���� ����]" << endl;
			cout << "���� ID		: ";
			cin >> idNum;
			result = check.CheckingID(idNum, accountNumber);
			if (result == NO_MATCH)
			{
				cout << "�̸�		: ";
				cin >> name;
				cout << "�Աݾ�		: ";
				cin >> money;
				accounts[accountNumber] = new Account(idNum, money, name);
				accountNumber++;
			}
			else
			{
				cout << "���� ID�� ���� �մϴ�." << endl;
			}
			break;
		case 2:
			//�Ա�
			cout << endl << "[�Ա�]" << endl;
			cout << "���� ID		: ";
			cin >> idNum;
			result = check.CheckingID(idNum, accountNumber);
			if (result == NO_MATCH)
			{
				cout << "���� ID�� ���� ���� �ʽ��ϴ�." << endl;
			}
			else
			{
				cout << "�Աݾ�		: ";
				cin >> money;
				accounts[result]->InputMoney(money);
				cout << "�ԱݿϷ� �Ǿ����ϴ�." << endl << endl;
			}
			break;
		case 3:
			//���
			cout << endl << "[���]" << endl;
			cout << "���� ID		: ";
			cin >> idNum;
			result = check.CheckingID(idNum, accountNumber);
			if (result == NO_MATCH)
			{
				cout << "���� ID�� ���� ���� �ʽ��ϴ�." << endl;
			}
			else
			{
				cout << "��ݾ�		: ";
				cin >> money;
				availableFlag = accounts[result]->OutputMoney(money);
				if (availableFlag)
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
			check.PrintAccounts(accountNumber);
			break;
		case 5:
			//���α׷� ����
			closeFlag = 1;
			break;
		}
		if (closeFlag)		break;
	}


	//���α׷� ����

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
	std::cout << "���� ID		: " << account_id << endl;
	std::cout << "�̸�		: " << name << endl;
	std::cout << "�Աݾ�		: " << money << endl << endl;
}


Checking::Checking(Account **firAccountAdr)
{
	accounts = firAccountAdr;
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

void Checking::PrintAccounts(int accountNum)
{
	for (int i = 0; i < accountNum; i++)
	{
		accounts[i]->PrintAccount();
	}
}

void Checking::PrintSelect(void)
{
	std::cout << "--------Menu--------" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �Ա�" << std::endl;
	std::cout << "3. ���" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl << std::endl;
}