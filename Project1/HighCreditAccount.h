#pragma once
#include "NormalAccount.h"

class HighCreditAccount :	public NormalAccount
{
private:
	int specialRate;		//�⺻������ �߰��Ǵ� ������
public:
	HighCreditAccount();
	~HighCreditAccount();
};
