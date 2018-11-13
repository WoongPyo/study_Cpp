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

			result = check.CheckingID(idNum);

			if (result == NO_MATCH)
			{
				accounts[accountNumber]->MakeAccounts(idNum);
				accountNumber++;
			}
			checkFlag = 0;
			break;
		case 2:
			//입금
			std::cout << std::endl;
			std::cout << "[입금]" << std::endl;
			inputIDNum = CheckingID(accounts);
			if(inputIDNum != ERROR_NUM)
				InputMoney(accounts + inputIDNum);
			break;
		case 3:
			//출금
			std::cout << std::endl;
			std::cout << "[출금]" << std::endl;
			inputIDNum = CheckingID(accounts);
			if (inputIDNum != ERROR_NUM)
				OutputMoney(accounts + inputIDNum);
			break;
		case 4:
			//계좌정보출력
			std::cout << std::endl;
			std::cout << "[전체출력]" << std::endl;
			PrintAccounts(accounts, accountNumber);
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
void PrintSelect(void)
{
	std::cout << "--------Menu--------" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입금" << std::endl;
	std::cout << "3. 출금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl << std::endl;
}

void Account::MakeAccounts(int inNum)
{
	account->account_id = inNum;
	std::cout << "이름		: "; 
	std::cin >> account->name;
	std::cout << "입금액		: "; 
	std::cin >> account->money;
	std::cout << std::endl;
}

int Account::CheckingID(Account* accounts)
{
	int idNum;
	std::cout << "계좌 ID		: ";
	std::cin >> idNum;
	for (int i = 0; i < 100; i++)
	{
		if (idNum == accounts[i].account_id)
			return i;
	}
	std::cout << "올바른 ID가 아닙니다." << std::endl << std::endl;
	return ERROR_NUM;
}

void Account::InputMoney(Account* account)
{
	int inputMoney;
	std::cout << "입금액		: ";
	std::cin >> inputMoney;
	account->money += inputMoney;
	std::cout << "입금완료 되었습니다." << std::endl << std::endl;
}

void Account::OutputMoney(Account* account)
{
	int outputMoney;
	std::cout << "출금액		: ";
	std::cin >> outputMoney;
	if ((account->money - outputMoney) > 0)
	{
		account->money -= outputMoney;
		std::cout << "출금완료 되었습니다." << std::endl << std::endl;
	}
	else
		std::cout << "출금액이 잔액보다 많습니다." << std::endl << std::endl;
}

void Account::PrintAccounts(Account* account, int accountNum)
{
	for(int i = 0; i < accountNum; i++)
	{
		std::cout << "계좌 ID		: " << (account+i)->account_id << std::endl;
		std::cout << "이름		: " << (account+i)->name << std::endl;
		std::cout << "입금액		: " << (account+i)->money << std::endl << std::endl;
	}
}