#include "AccountHandler.h"
#include "main.h"

AccountHandler::AccountHandler() : accNum(0)
{}


AccountHandler::~AccountHandler()
{}

int AccountHandler::CheckingID(int ID)
{
	for (int i = 0; i < accNum; i++)
		if (ID == accArr[i]->PutID())			return i;
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