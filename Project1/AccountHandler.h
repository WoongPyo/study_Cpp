#pragma once
#include "main.h"
#include "Account.h"
#include "BoundCheckPointArray.h"
#include "BoundCheckPointArray.cpp"

class AccountHandler
{
private:
	BoundCheckPointArray<Account *> *arrays;

	// ������ ��ü(��� 111�̶�� ��ü)�� �ý��� ������ �������� �ʵ��� �ϱ� ���ؼ�.
	AccountHandler &operator=(const AccountHandler &buf) {}

	// ��������ڸ� ���� ���
	AccountHandler(const AccountHandler &ref) {}

public:
	AccountHandler(int maxNum);
	int GetInt(const char *inputStr);			// �������� ����
	Account *SelectAccount(int accNum);
	int GetAccType(const char *inputStr);
	void AddAccount(Account *account);			// ���¸� �߰���
	void ShowAccountsInfo() const;				// ������ ������ �����
	int CheckingID(int ID);						// ������ ID�� �ߺ��� �������� Ȯ���۾� return���� ������ accNum�� ��� ������ ������ ���
	int GetAccountNumber();						// ��ϵ� ������ ���ڸ� Ȯ��
	void PrintSelect();							// ����ȭ�� ���
	int TranlateCreditGrade(int creditSel);
};
