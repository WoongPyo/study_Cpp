#pragma once
class Account
{
private:
	int accID; 			//���¹�ȣ
	int balance;    		//�ܾ�
	char *cusName; 		//����
public:
	Account(int ID, int money, char* name);
	~Account();
	int PutID();
	void InputMoney(int inputMoney);
	bool OutputMoney(int outputMoney);
	void PrintAccount();
};

