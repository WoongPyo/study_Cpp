#pragma once
#include "Account.h"

class NormalAccount :	public Account
{
private:
	int interRate;   		// �Աݽ� �߻��ϴ� ������ %����
public:
	NormalAccount(int ID, int money, char* name, int rate);
	~NormalAccount();
};

