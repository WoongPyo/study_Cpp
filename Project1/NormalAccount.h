#pragma once
#include "main.h"
#include	"Account.h"

class NormalAccount :	public Account
{
private:
	int interRate;   		// �Աݽ� �߻��ϴ� ������ %����
public:
	NormalAccount(int ID, int money, char* name, int rate);
	~NormalAccount();
	virtual void InputMoney(int inputMoney);
	int GetInterRate();
};

