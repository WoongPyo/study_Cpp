#pragma once
#include "Account.h"

class NormalAccount :	public Account
{
private:
	int interRate;   		// 입금시 발생하는 이자율 %단위
public:
	NormalAccount(int ID, int money, char* name, int rate);
	~NormalAccount();
};

