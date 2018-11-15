#pragma once
#include "main.h"
#include "Account.h"

class AccountHandler
{
private:
	Account *accArr[100];						// 계좌를 관리하는 배열
	int accNum;									// 현재 등록된 계좌수

public:
	AccountHandler();
	~AccountHandler();
	int GetInt(const char *inputStr);			// 정수값을 받음
	Account *SelectAccount(int accNum);
	int GetAccType(const char *inputStr);
	void AddAccount(Account *account);			// 계좌를 추가함
	void ShowAccountsInfo() const;				// 계좌의 정보를 출력함
	int CheckingID(int ID);						// 계좌의 ID의 중복을 막기위한 확인작업 return으로 계좌의 accNum이 출력 없으면 오류가 출력
	int GetAccountNumber();						// 등록된 계좌의 숫자를 확인
	void PrintAccounts();						// 저장된 계좌 정보를 전체 출력
	void PrintSelect();							// 선택화면 출력
	int TranlateCreditGrade(int creditSel);
};
