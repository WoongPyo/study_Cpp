#pragma once
#include "main.h"
#include "Account.h"

class BoundCheckPointArray
{
private:
	Account *accArr[100];						// ���¸� �����ϴ� �迭
	int accNum;									// ���� ��ϵ� ���¼�

public:
	BoundCheckPointArray();
	~BoundCheckPointArray();
	Account *SelectAccount(int accNum);
};

