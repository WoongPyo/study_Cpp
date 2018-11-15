#include "HighCreditAccount.h"



HighCreditAccount::HighCreditAccount(int ID, int money, char* name, int rate, int specialRate) : NormalAccount(ID, money, name, rate), specialRate(specialRate)
{}


HighCreditAccount::~HighCreditAccount()
{}
