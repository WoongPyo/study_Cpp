#pragma once
#include "main.h"
#include "Account.h"

class AccountHandler
{
private:
	Account *accArr[100];						// ���¸� �����ϴ� �迭
	int accNum;									// ���� ��ϵ� ���¼�

public:
	AccountHandler();
	~AccountHandler();
	int GetInt(const char *inputStr);			// �������� ����
	Account *SelectAccount(int accNum);
	int GetAccType(const char *inputStr);
	void AddAccount(Account *account);			// ���¸� �߰���
	void ShowAccountsInfo() const;				// ������ ������ �����
	int CheckingID(int ID);						// ������ ID�� �ߺ��� �������� Ȯ���۾� return���� ������ accNum�� ��� ������ ������ ���
	int GetAccountNumber();						// ��ϵ� ������ ���ڸ� Ȯ��
	void PrintAccounts();						// ����� ���� ������ ��ü ���
	void PrintSelect();							// ����ȭ�� ���
	int TranlateCreditGrade(int creditSel);
};
