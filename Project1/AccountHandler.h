#pragma once
#include "Account.h"

class AccountHandler
{
private:
	Account *accArr[100];		//계좌를 관리하는 배열
	int accNum;					//현재 등록된 계좌수
public:
	AccountHandler();
	~AccountHandler();
	int CheckingID(int ID);
	int GetAccountNumber();
	void PrintAccounts();
	void PrintSelect();
};
