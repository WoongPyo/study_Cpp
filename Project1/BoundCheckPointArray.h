#pragma once
#include "main.h"
#include "Account.h"

class BoundCheckPointArray
{
private:
	Account *accArr[100];						// 계좌를 관리하는 배열
	int accNum;									// 현재 등록된 계좌수

public:
	BoundCheckPointArray();
	~BoundCheckPointArray();
	Account *SelectAccount(int accNum);
};

