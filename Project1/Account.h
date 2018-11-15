#pragma once
#include "main.h"

class Account
{
private:
	int accID; 											//���¹�ȣ
	int balance;    									//�ܾ�
	char *cusName; 										//����
public:
	Account(int ID, int money, char* name);
	~Account();
	int GetID();										//	account�� ID�� Ȯ��
	virtual void InputMoney(int inputMoney);					//	���� �Ա�
	int GetBalance();
	void SetBalance(int balance);
	bool OutputMoney(int outputMoney);					//	���� ���
	void PrintAccount();								//	���� ������ ���
};

