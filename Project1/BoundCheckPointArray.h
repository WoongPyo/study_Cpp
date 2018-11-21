#pragma once
#include "main.h"
#include "Account.h"

class BoundCheckPointArray
{
private:
	Account *accArr;						// 계좌를 관리하는 배열
	int accNum;									// 현재 등록된 계좌수

	// 동일한 객체(사번 111이라는 객체)가 시스템 내에서 존재하지 않도록 하기 위해서.
	BoundCheckPointArray &operator=(const BoundCheckPointArray &buf) {}

	// 복사생성자를 막는 방법
	BoundCheckPointArray(const BoundCheckPointArray &ref) {}

public:
	BoundCheckPointArray();
	~BoundCheckPointArray();
	Account *SelectAccount(int accNum);
};

