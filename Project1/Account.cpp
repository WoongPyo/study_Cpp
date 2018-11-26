#include "Account.h"

Account::Account(int ID, int money, String name) : accID(ID), balance(money)
{
	cusName = name;
}


Account::~Account()
{
}

int Account::GetID()
{
	return accID;
}

void Account::InputMoney(int inputMoney)
{}

int Account::GetBalance()
{
	return balance;
}

void Account::SetBalance(int balance)
{
	this->balance = balance;
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
	cout << "���� ID		: " << accID << endl;
	cout << "�̸�		: " << cusName << endl;
	cout << "�Աݾ�		: " << balance << endl << endl;
}