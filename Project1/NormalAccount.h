#pragma once
#include "Account.h"

class NormalAccount :	public Account
{
private:
	int interRate;   		// �Աݽ� �߻��ϴ� ������ %����
public:
	NormalAccount();
	~NormalAccount();
};

