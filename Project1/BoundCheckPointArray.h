#pragma once
#include "main.h"
#include "Account.h"

class BoundCheckPointArray
{
private:
	Account *accArr;						// ���¸� �����ϴ� �迭
	int accNum;									// ���� ��ϵ� ���¼�

	// ������ ��ü(��� 111�̶�� ��ü)�� �ý��� ������ �������� �ʵ��� �ϱ� ���ؼ�.
	BoundCheckPointArray &operator=(const BoundCheckPointArray &buf) {}

	// ��������ڸ� ���� ���
	BoundCheckPointArray(const BoundCheckPointArray &ref) {}

public:
	BoundCheckPointArray();
	~BoundCheckPointArray();
	Account *SelectAccount(int accNum);
};

