#pragma once
#include "NormalAccount.h"

class HighCreditAccount :	public NormalAccount
{
private:
	int specialRate;		//�⺻������ �߰��Ǵ� ������
public:
	HighCreditAccount(int ID, int money, String name, int rate, int specialRate);
	~HighCreditAccount();
	void InputMoney(int inputMoney);
};
