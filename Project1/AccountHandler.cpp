#include "AccountHandler.h"

AccountHandler::AccountHandler(BoundCheckPointArray arr) : arrays(arr)
{}


AccountHandler::~AccountHandler()
{
}

int AccountHandler::GetInt(const char *inputStr)
{
	int buf;
	cout << inputStr;
	cin >> buf;
	return buf;
}

int AccountHandler::GetAccType(const char *inputStr)
{
	int buf;
	cout << inputStr;
	cin >> buf;
	if (buf == 1 || buf == 2)
		return buf;
	else
		return NO_MATCH;
}

Account *AccountHandler::SelectAccount(int accNum) 
{
	return accArr[accNum];
}

void AccountHandler::AddAccount(Account *account)
{
	accArr[accNum++] = account;
}

void AccountHandler::ShowAccountsInfo() const
{
	for (int i = 0; i < accNum; i++)		accArr[i]->PrintAccount();
}

int AccountHandler::CheckingID(int ID)
{
	for (int i = 0; i < accNum; i++)
		if (ID == accArr[i]->GetID())			return i;
	return NO_MATCH;
}

int AccountHandler::GetAccountNumber(void)
{
	return accNum;
}

void AccountHandler::PrintAccounts()
{
	for (int i = 0; i < accNum; i++)		accArr[i]->PrintAccount();
}

void AccountHandler::PrintSelect(void)
{
	cout << "--------Menu--------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl << endl;
}

int AccountHandler::TranlateCreditGrade(int creditSel)
{
	if (creditSel == 1)				return LEVEL_A;
	else if (creditSel == 2)		return LEVEL_B;
	else if (creditSel == 3)		return LEVEL_C;
	else							return NO_LEVEL;

}
