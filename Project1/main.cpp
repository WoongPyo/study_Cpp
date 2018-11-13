#include <iostream>
#include <cstring>

#define N_ACCOUNT	100
#define NO_MATCH	101

using namespace std;


class Account {
private:
	int account_id;
	int money;
	char name[30];

public : 
	Account(int ID, int money, char* name) : account_id(ID), money(money)
	{
		strcpy()
		this->name = name;
	}
	int ShowID()
	{
		return account_id;
	}

	void PrintSelect(void);
	void MakeAccounts(int inNum);
	void InputMoney();
	void OutputMoney();
	void PrintAccounts(int accountNum);
};

class Checking {
private:
	Account **accounts;

public:
	Checking(Account **firAccountAdr)
	{
		accounts = firAccountAdr;
	}

	int CheckingID(int ID)
	{
		int i;

		for (i = 0; i < N_ACCOUNT; i++)
		{
			if (ID == accounts[i]->ShowID)
			{
				return i;
			}
		}
		return NO_MATCH;
	}
};

int main(void)
{
	Account *accounts[N_ACCOUNT];
	Checking check(accounts);
	int result;

	int accountNumber = 0;
	int sel;
	int closeFlag = 0;
	int checkFlag = 0;
	int inputIDNum;
	int idNum;

	while(1)
	{
		PrintSelect();
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

			result = check.CheckingID(idNum);

			if (result == NO_MATCH)
			{
				accounts[accountNumber]->MakeAccounts(idNum);
				accountNumber++;
			}
			checkFlag = 0;
			break;
		case 2:
			//�Ա�
			std::cout << std::endl;
			std::cout << "[�Ա�]" << std::endl;
			inputIDNum = CheckingID(accounts);
			if(inputIDNum != ERROR_NUM)
				InputMoney(accounts + inputIDNum);
			break;
		case 3:
			//���
			std::cout << std::endl;
			std::cout << "[���]" << std::endl;
			inputIDNum = CheckingID(accounts);
			if (inputIDNum != ERROR_NUM)
				OutputMoney(accounts + inputIDNum);
			break;
		case 4:
			//�����������
			std::cout << std::endl;
			std::cout << "[��ü���]" << std::endl;
			PrintAccounts(accounts, accountNumber);
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
void PrintSelect(void)
{
	std::cout << "--------Menu--------" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �Ա�" << std::endl;
	std::cout << "3. ���" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl << std::endl;
}

void Account::MakeAccounts(int inNum)
{
	account->account_id = inNum;
	std::cout << "�̸�		: "; 
	std::cin >> account->name;
	std::cout << "�Աݾ�		: "; 
	std::cin >> account->money;
	std::cout << std::endl;
}

int Account::CheckingID(Account* accounts)
{
	int idNum;
	std::cout << "���� ID		: ";
	std::cin >> idNum;
	for (int i = 0; i < 100; i++)
	{
		if (idNum == accounts[i].account_id)
			return i;
	}
	std::cout << "�ùٸ� ID�� �ƴմϴ�." << std::endl << std::endl;
	return ERROR_NUM;
}

void Account::InputMoney(Account* account)
{
	int inputMoney;
	std::cout << "�Աݾ�		: ";
	std::cin >> inputMoney;
	account->money += inputMoney;
	std::cout << "�ԱݿϷ� �Ǿ����ϴ�." << std::endl << std::endl;
}

void Account::OutputMoney(Account* account)
{
	int outputMoney;
	std::cout << "��ݾ�		: ";
	std::cin >> outputMoney;
	if ((account->money - outputMoney) > 0)
	{
		account->money -= outputMoney;
		std::cout << "��ݿϷ� �Ǿ����ϴ�." << std::endl << std::endl;
	}
	else
		std::cout << "��ݾ��� �ܾ׺��� �����ϴ�." << std::endl << std::endl;
}

void Account::PrintAccounts(Account* account, int accountNum)
{
	for(int i = 0; i < accountNum; i++)
	{
		std::cout << "���� ID		: " << (account+i)->account_id << std::endl;
		std::cout << "�̸�		: " << (account+i)->name << std::endl;
		std::cout << "�Աݾ�		: " << (account+i)->money << std::endl << std::endl;
	}
}