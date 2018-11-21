#include "AccountHandler.h"

AccountHandler::AccountHandler(int maxNum)
{
	arrays = new BoundCheckPointArray(maxNum);
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
	return arrays->SelectAccount(accNum);
}

void AccountHandler::AddAccount(Account *account)
{
	arrays->AddAccount(account);
}

void AccountHandler::ShowAccountsInfo() const
{
	arrays->ShowAccountsInfo();
}

int AccountHandler::CheckingID(int ID)
{
	arrays->CheckingID(ID);
}

int AccountHandler::GetAccountNumber(void)
{
	arrays->GetAccountNumber();
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
