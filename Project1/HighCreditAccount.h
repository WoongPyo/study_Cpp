#pragma once
#include "NormalAccount.h"

class HighCreditAccount :	public NormalAccount
{
private:
	int specialRate;		//기본이율에 추가되는 이자율
public:
	HighCreditAccount(int ID, int money, String name, int rate, int specialRate);
	~HighCreditAccount();
	void InputMoney(int inputMoney);
};
