#include "NormalAccount.h"


NormalAccount::NormalAccount(int ID, int money, char* name, int rate) : Account(ID, money, name), interRate(rate)
{}

NormalAccount::~NormalAccount()
{}

int NormalAccount::GetInterRate()
{
	return interRate;
}

void NormalAccount::InputMoney(int inputMoney)
{
	cout << GetBalance() << endl;
	SetBalance(GetBalance() * (1 + interRate / 100.0));
	SetBalance(GetBalance() + inputMoney);
}