#pragma once
class Account
{
private:
	int accID; 			//°èÁÂ¹øÈ£
	int balance;    		//ÀÜ¾×
	char *cusName; 		//°í°´¸í
public:
	Account(int ID, int money, char* name);
	~Account();
	int PutID();
	void InputMoney(int inputMoney);
	bool OutputMoney(int outputMoney);
	void PrintAccount();
};

