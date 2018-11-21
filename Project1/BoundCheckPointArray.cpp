#include "BoundCheckPointArray.h"

BoundCheckPointArray::BoundCheckPointArray(int maxNum) : accNum(0)
{
	accArr = new Account*[maxNum];
}

BoundCheckPointArray::~BoundCheckPointArray()
{
	delete[] accArr;
}

Account *BoundCheckPointArray::SelectAccount(int accNum)
{
	return accArr[accNum];
}

void BoundCheckPointArray::AddAccount(Account *account)
{
	accArr[accNum++] = account;
}

void BoundCheckPointArray::ShowAccountsInfo() const
{
	for (int i = 0; i < accNum; i++)		accArr[i]->PrintAccount();
}

int BoundCheckPointArray::CheckingID(int ID)
{
	for (int i = 0; i < accNum; i++)
		if (ID == accArr[i]->GetID())			return i;
	return NO_MATCH;
}

int BoundCheckPointArray::GetAccountNumber(void)
{
	return accNum;
}
