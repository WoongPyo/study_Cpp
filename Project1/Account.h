#pragma once
class Account
{
private:
	int accID; 				//���¹�ȣ
	int balance;    		//�ܾ�
	char *cusName; 			//����
public:
	Account(int ID, int money, char* name);
	~Account();
	int GetID();								//	account�� ID�� Ȯ��
	void InputMoney(int inputMoney);			//	���� �Ա�
	bool OutputMoney(int outputMoney);			//	���� ���
	void PrintAccount();						//	���� ������ ���
};

