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
	int GetSomting2Int(const char *inputStr)
	{
		int buf;
		cout << inputStr;
		cin >> buf;
		return buf;
	}
	char *GetSomting2Str(const char *inputStr)
	{
		char *buf;
		cout << inputStr;
		cin >> buf;
		return buf;
	}
};

int main(void)
{
	Account *accounts[N_ACCOUNT];
	Checking check(accounts);
	Print print;
	int sel;
	int result;
	char *name = new char[30];
	int money;
	bool availableFlag;

	int closeFlag = 0;
	int idNum;

	while(1)
	{
		check.PrintSelect();
		sel = print.GetSomting2Int("[선택] : ");

		switch (sel)
		{
		case 1:
			//계좌를 개설
			cout << endl << "[계좌 개설]" << endl;
			idNum = print.GetSomting2Int("계좌 ID		: ");

			if (check.CheckingID(idNum, check.GetAccountNumber()) == NO_MATCH)
			{
				name = print.GetSomting2Str("이름		: ");
				money = print.GetSomting2Int("입금액		: ");
				accounts[check.GetAccountNumber()] = new Account(idNum, money, name);
				check.SetAccountNumber();
			}
			else
			{
				cout << "같은 ID가 존재 합니다." << endl;
			}
			break;
		case 2:
			//입금
			cout << endl << "[입금]" << endl;
			idNum = print.GetSomting2Int("계좌 ID		: ");
			result = check.CheckingID(idNum, check.GetAccountNumber());
			if (result == NO_MATCH)
			{
				cout << "같은 ID가 존재 하지 않습니다." << endl;
			}
			else
			{
				money = print.GetSomting2Int("입금액		: ");
				accounts[result]->InputMoney(money);
				cout << "입금완료 되었습니다." << endl << endl;
			}
			break;
		case 3:
			//출금
			cout << endl << "[출금]" << endl;
			idNum = print.GetSomting2Int("계좌 ID		: ");
			result = check.CheckingID(idNum, check.GetAccountNumber());
			if (result == NO_MATCH)
			{
				cout << "같은 ID가 존재 하지 않습니다." << endl;
			}
			else
			{
				money = print.GetSomting2Int("출금액		: ");
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
			check.PrintAccounts();
			break;
		case 5:
			//프로그램 종료
			closeFlag = 1;
			delete[] name;
			delete accounts[]
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
	std::cout << "--------Menu--------" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입금" << std::endl;
	std::cout << "3. 출금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl << std::endl;
}