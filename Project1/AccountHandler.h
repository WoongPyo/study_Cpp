#pragma once
#include "Account.h"

class AccountHandler
{
private:
	Account *accArr[100];		//���¸� �����ϴ� �迭
	int accNum;					//���� ��ϵ� ���¼�
public:
	AccountHandler();
	~AccountHandler();
	int CheckingID(int ID);
	int GetAccountNumber();
	void PrintAccounts();
	void PrintSelect();
};
