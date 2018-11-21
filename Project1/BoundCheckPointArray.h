#pragma once
#include "main.h"
#include "Account.h"

class BoundCheckPointArray
{
private:
	Account **accArr;						// ���¸� �����ϴ� �迭
	int accNum;									// ���� ��ϵ� ���¼�

	// ������ ��ü(��� 111�̶�� ��ü)�� �ý��� ������ �������� �ʵ��� �ϱ� ���ؼ�.
	BoundCheckPointArray &operator=(const BoundCheckPointArray &buf) {}

	// ��������ڸ� ���� ���
	BoundCheckPointArray(const BoundCheckPointArray &ref) {}

public:
	BoundCheckPointArray(int maxNum);
	~BoundCheckPointArray();
	Account *SelectAccount(int accNum);
	void AddAccount(Account *account);
	void ShowAccountsInfo() const;
	int CheckingID(int ID);
	int GetAccountNumber(void);
};

