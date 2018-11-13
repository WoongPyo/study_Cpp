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
		check.PrintSelect();											// 선택 메뉴 출력

		switch (print.GetInt("[선택] : "))								// case 선택 하기
		{
		case 1:
			//계좌를 개설
			cout << endl << "[계좌 개설]" << endl;
			iDbuf = print.GetInt("계좌 ID		: ");					// ID를 받음

			if (check.CheckingID(iDbuf) == NO_MATCH)					// 공통된 ID가 있는지 확인 이후 계좌개설
			{
				cout << "이름		: ";
				cin >> namebuf;
				moneybuf = print.GetInt("입금액		: ");
				accounts[check.GetAccountNumber()] = new Account(iDbuf, moneybuf, namebuf);
				check.IncreaseAccountNumber();							// 계좌개수를 1 더함
			}
			else
			{
				cout << "같은 ID가 존재 합니다." << endl;
			}
			break;
		case 2:
			//입금
			cout << endl << "[입금]" << endl;
			iDbuf = print.GetInt("계좌 ID		: ");
			matchIdOrder = check.CheckingID(iDbuf);
			if (matchIdOrder == NO_MATCH)										// 같은 ID를 가진 계좌가 존재하지 않음
			{
				cout << "같은 ID가 존재 하지 않습니다." << endl;
			}
			else
			{
				moneybuf = print.GetInt("입금액		: ");
				accounts[matchIdOrder]->InputMoney(moneybuf);					// 지정 계좌에 돈을 입금
				cout << "입금완료 되었습니다." << endl << endl;
			}
			break;
		case 3:
			//출금
			cout << endl << "[출금]" << endl;
			iDbuf = print.GetInt("계좌 ID		: ");
			matchIdOrder = check.CheckingID(iDbuf);
			if (matchIdOrder == NO_MATCH)										// 같은 ID를 가진 계좌가 존재하지 않음
			{
				cout << "같은 ID가 존재 하지 않습니다." << endl;
			}
			else
			{
				moneybuf = print.GetInt("출금액		: ");
				if (accounts[matchIdOrder]->OutputMoney(moneybuf))			// 지정 계좌에 입력한 돈을 출금가능 확인
				{
					cout << "출금완료 되었습니다." << endl << endl;
				}
				else
				{
					cout << "출금액이 잔액보다 많습니다." << endl << endl;
				}
			}
			break;
		case 4:
			//계좌정보출력
			cout << endl << "[전체출력]" << endl;						// 계좌 전부 출력
			check.PrintAccounts();
			break;
		case 5:
			//프로그램 종료
			finishFlag = true;
			for (int i = 0; i < check.GetAccountNumber(); i++)			// 계좌 제거
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
	std::cout << "계좌 ID		: "	<< account_id << endl;
	std::cout << "이름		: "		<< name << endl;
	std::cout << "입금액		: "		<< money << endl << endl;
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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl << endl;
}

int Print::GetInt(const char *inputStr)
{
	int buf;
	cout << inputStr;
	cin >> buf;
	return buf;
}