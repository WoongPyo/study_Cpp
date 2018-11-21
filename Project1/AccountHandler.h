#pragma once
#include "main.h"
#include "Account.h"
#include "BoundCheckPointArray.h"

class AccountHandler
{
private:
	BoundCheckPointArray arrays;

	// ������ ��ü(��� 111�̶�� ��ü)�� �ý��� ������ �������� �ʵ��� �ϱ� ���ؼ�.
	AccountHandler &operator=(const AccountHandler &buf) {}

	// ��������ڸ� ���� ���
	AccountHandler(const AccountHandler &ref) {}

public:
	AccountHandler(BoundCheckPointArray arr);
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
