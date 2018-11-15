#pragma once
#include "Account.h"
#include "main.h"

class AccountHandler
{
private:
	Account *accArr[100];				// ���¸� �����ϴ� �迭
	int accNum;							// ���� ��ϵ� ���¼�
public:
	AccountHandler();
	~AccountHandler();
	void AddAccount(Account *account);	// ���¸� �߰���
	void ShowAccountsInfo() const;		// ������ ������ �����
	int CheckingID(int ID);				// ������ ID�� �ߺ��� �������� Ȯ���۾� return���� ������ accNum�� ��� ������ ������ ���
	int GetAccountNumber();				// ��ϵ� ������ ���ڸ� Ȯ��
	void PrintSelect();					// ����ȭ�� ���
};
