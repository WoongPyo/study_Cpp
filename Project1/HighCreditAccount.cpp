#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(int ID, int money, String name, int rate, int specialRate) : NormalAccount(ID, money, name, rate), specialRate(specialRate)
{}


HighCreditAccount::~HighCreditAccount()
{}

void HighCreditAccount::InputMoney(int inputMoney)
{
	SetBalance(GetBalance() * (1 + (GetInterRate() + specialRate)/ 100.0));
	SetBalance(GetBalance() + inputMoney);
}