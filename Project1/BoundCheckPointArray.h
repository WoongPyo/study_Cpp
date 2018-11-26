#pragma once
#include "main.h"
#include "Account.h"

template <typename T>
class BoundCheckPointArray
{
private:
	//Account **accArr;							// ���¸� �����ϴ� �迭
	T *accArr;
	int accNum;									// ���� ��ϵ� ���¼�

	// ������ ��ü(��� 111�̶�� ��ü)�� �ý��� ������ �������� �ʵ��� �ϱ� ���ؼ�.
	BoundCheckPointArray &operator=(const BoundCheckPointArray &buf) {}

	// ��������ڸ� ���� ���
	BoundCheckPointArray(const BoundCheckPointArray &ref) {}

public:
	BoundCheckPointArray(int maxNum);
	~BoundCheckPointArray();
	T SelectAccount(int accNum);
	void AddAccount(T account);
	void ShowAccountsInfo() const;
	int CheckingID(int ID);
	int GetAccountNumber(void);
};


