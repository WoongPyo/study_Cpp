#pragma once
#include "main.h"

class Account
{
private:
	int accID; 											//계좌번호
	int balance;    									//잔액
	char *cusName; 										//고객명
public:
	Account(int ID, int money, char* name);
	~Account();
	int GetID();										//	account의 ID를 확인
	virtual void InputMoney(int inputMoney);					//	돈을 입금
	int GetBalance();
	void SetBalance(int balance);
	bool OutputMoney(int outputMoney);					//	돈을 출금
	void PrintAccount();								//	계좌 정보를 출력
};

