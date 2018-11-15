#include "main.h"
#include "Account.h"

Account::Account(int ID, int money, char* name) : accID(ID), balance(money)
{
	int len = strlen(name) + 1;
	this->cusName = new char[len];
	strcpy(this->cusName, name);
}


Account::~Account()
{
	delete[] cusName;
}

int Account::PutID()
{
	return accID;
}

void Account::InputMoney(int inputMoney)
{
	balance += inputMoney;
}

bool Account::OutputMoney(int outputMoney)
{
	if ((balance - outputMoney) < 0)
		return false;
	else
	{
		balance -= outputMoney;
		return true;
	}
}
void Account::PrintAccount()
{
	std::cout << "계좌 ID		: " << accID << endl;
	std::cout << "이름		: " << cusName << endl;
	std::cout << "입금액		: " << balance << endl << endl;
}