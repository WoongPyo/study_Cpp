#pragma once
#include "main.h"
#include "Account.h"
#include "BoundCheckPointArray.h"
#include "BoundCheckPointArray.cpp"

class AccountHandler
{
private:
	BoundCheckPointArray<Account *> *arrays;

	// 동일한 객체(사번 111이라는 객체)가 시스템 내에서 존재하지 않도록 하기 위해서.
	AccountHandler &operator=(const AccountHandler &buf) {}

	// 복사생성자를 막는 방법
	AccountHandler(const AccountHandler &ref) {}

public:
	AccountHandler(int maxNum);
	int GetInt(const char *inputStr);			// 정수값을 받음
	Account *SelectAccount(int accNum);
	int GetAccType(const char *inputStr);
	void AddAccount(Account *account);			// 계좌를 추가함
	void ShowAccountsInfo() const;				// 계좌의 정보를 출력함
	int CheckingID(int ID);						// 계좌의 ID의 중복을 막기위한 확인작업 return으로 계좌의 accNum이 출력 없으면 오류가 출력
	int GetAccountNumber();						// 등록된 계좌의 숫자를 확인
	void PrintSelect();							// 선택화면 출력
	int TranlateCreditGrade(int creditSel);
};
