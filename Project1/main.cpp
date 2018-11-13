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
		sel = print.GetSomting2Int("[선택] : ");

		switch (sel)
		{
		case 1:
			//계좌를 개설
			cout << endl << "[계좌 개설]" << endl;
			idNum = print.GetSomting2Int("계좌 ID		: ");

			if (check.CheckingID(idNum, check.GetAccountNumber()) == NO_MATCH)
			{
				cout << "이름		: ";
				cin >> namebuf;
				moneybuf = print.GetSomting2Int("입금액		: ");
				accounts[check.GetAccountNumber()] = new Account(idNum, moneybuf, namebuf);
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
				moneybuf = print.GetSomting2Int("입금액		: ");
				accounts[result]->InputMoney(moneybuf);
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
				moneybuf = print.GetSomting2Int("출금액		: ");
				if (accounts[result]->OutputMoney(moneybuf))
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
	std::cout << "계좌 ID		: "	<< account_id << endl;
	std::cout << "이름		: "		<< name << endl;
	std::cout << "입금액		: "		<< money << endl << endl;
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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl << endl;
}

int Print::GetSomting2Int(const char *inputStr)
{
	int buf;
	cout << inputStr;
	cin >> buf;
	return buf;
}