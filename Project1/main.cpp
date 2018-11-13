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
		cout << "[선택] : " ;
		cin >> sel;

		switch (sel)
		{
		case 1:
			//계좌를 개설
			cout << endl;
			cout << "[계좌 개설]" << endl;
			cout << "계좌 ID		: ";
			cin >> idNum;
			result = check.CheckingID(idNum, accountNumber);
			if (result == NO_MATCH)
			{
				cout << "이름		: ";
				cin >> name;
				cout << "입금액		: ";
				cin >> money;
				accounts[accountNumber] = new Account(idNum, money, name);
				accountNumber++;
			}
			else
			{
				cout << "같은 ID가 존재 합니다." << endl;
			}
			break;
		case 2:
			//입금
			cout << endl << "[입금]" << endl;
			cout << "계좌 ID		: ";
			cin >> idNum;
			result = check.CheckingID(idNum, accountNumber);
			if (result == NO_MATCH)
			{
				cout << "같은 ID가 존재 하지 않습니다." << endl;
			}
			else
			{
				cout << "입금액		: ";
				cin >> money;
				accounts[result]->InputMoney(money);
				cout << "입금완료 되었습니다." << endl << endl;
			}
			break;
		case 3:
			//출금
			cout << endl << "[출금]" << endl;
			cout << "계좌 ID		: ";
			cin >> idNum;
			result = check.CheckingID(idNum, accountNumber);
			if (result == NO_MATCH)
			{
				cout << "같은 ID가 존재 하지 않습니다." << endl;
			}
			else
			{
				cout << "출금액		: ";
				cin >> money;
				availableFlag = accounts[result]->OutputMoney(money);
				if (availableFlag)
				{
					std::cout << "출금완료 되었습니다." << std::endl << std::endl;
				}
				else
				{
					cout << "출금액이 잔액보다 많습니다." << std::endl << std::endl;
				}
			}
			break;
		case 4:
			//계좌정보출력
			cout << endl << "[전체출력]" << endl;
			check.PrintAccounts(accountNumber);
			break;
		case 5:
			//프로그램 종료
			closeFlag = 1;
			break;
		}
		if (closeFlag)		break;
	}


	//프로그램 종료

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
	std::cout << "계좌 ID		: " << account_id << endl;
	std::cout << "이름		: " << name << endl;
	std::cout << "입금액		: " << money << endl << endl;
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
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입금" << std::endl;
	std::cout << "3. 출금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl << std::endl;
}