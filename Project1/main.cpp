#include "main.h"
#include "Account.h"
#include "AccountHandler.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"

int main()
{
	int iDbuf;
	char *namebuf = new char[20];
	int moneybuf;
	int interestbuf;
	int creditbuf;
	int additionalRate;
	int accNum;
	int accSel;

	bool finishFlag = false;

	AccountHandler handler(100);

	while (1)
	{
		handler.PrintSelect();											// ���� �޴� ���

		switch (handler.GetInt("[����] : "))								// case ���� �ϱ�
		{
		case 1:
			//���¸� ����
			try
			{
				while (1)
				{
					accSel = handler.GetInt("�ʿ�� �ϴ� ������ ���´� �����Դϱ�?(1.���뿹�ݰ��� 2.�ſ���� 3.�޴�������)");	// ID�� ����
					if (accSel == NORMAL || accSel == CREDIT || accSel == EXIT)
						throw accSel;
					cout << "�ʿ�� �ϴ� ������ ���°� �������� �ʽ��ϴ�." << endl;
				}
			}
			catch (int accSel)
			{
				try
				{
					cout << endl << "[���� ����]" << endl;
					iDbuf = handler.GetInt("���� ID		: ");					// ID�� ����

					if (handler.CheckingID(iDbuf) == NO_MATCH)					// ����� ID�� �ִ��� Ȯ�� ���� ���°���
						throw iDbuf;

					cout << "���� ID�� ���� �մϴ�." << endl;
				}
				catch(int iDbuf)
				{
					interestbuf = handler.GetInt("�⺻����(%)	: ");
					if(accSel == NORMAL)
					{
						cout << "�̸�		: ";
						cin >> namebuf;
						moneybuf = handler.GetInt("�Աݾ�		: ");
						handler.AddAccount(new NormalAccount(iDbuf, moneybuf, namebuf, interestbuf));
					}
					else if (accSel == CREDIT)
					{
						cout << "����� �ſ����� ���Դϱ�?" << endl;
						creditbuf = handler.GetInt("(1.LEVEL_A, 2.LEVEL_B=4, 3.LEVEL_C)	: ");
						additionalRate = handler.TranlateCreditGrade(creditbuf);
						cout << "�̸�		: ";
						cin >> namebuf;
						moneybuf = handler.GetInt("�Աݾ�		: ");
						handler.AddAccount(new HighCreditAccount(iDbuf, moneybuf, namebuf, interestbuf, additionalRate));
					}
				}
			}
			break;
		case 2:
			//�Ա�
			cout << endl << "[�Ա�]" << endl;
			iDbuf = handler.GetInt("���� ID		: ");
			accNum = handler.CheckingID(iDbuf);
			if (accNum == NO_MATCH)										// ���� ID�� ���� ���°� �������� ����
			{
				cout << "���� ID�� ���� ���� �ʽ��ϴ�." << endl;
			}
			else
			{
				moneybuf = handler.GetInt("�Աݾ�		: ");
				handler.SelectAccount(accNum)->InputMoney(moneybuf);					// ���� ���¿� ���� �Ա�
				cout << "�ԱݿϷ� �Ǿ����ϴ�." << endl << endl;
			}
			break;
		case 3:
			//���
			cout << endl << "[���]" << endl;
			iDbuf = handler.GetInt("���� ID		: ");
			accNum = handler.CheckingID(iDbuf);
			if (accNum == NO_MATCH)										// ���� ID�� ���� ���°� �������� ����
			{
				cout << "���� ID�� ���� ���� �ʽ��ϴ�." << endl;
			}
			else
			{
				moneybuf = handler.GetInt("��ݾ�		: ");
				if (handler.SelectAccount(accNum)->OutputMoney(moneybuf))			// ���� ���¿� �Է��� ���� ��ݰ��� Ȯ��
				{
					cout << "��ݿϷ� �Ǿ����ϴ�." << endl << endl;
				}
				else
				{
					cout << "��ݾ��� �ܾ׺��� �����ϴ�." << endl << endl;
				}
			}
			break;
		case 4:
			//�����������
			cout << endl << "[��ü���]" << endl;						// ���� ���� ���
			handler.ShowAccountsInfo();
			break;
		case 5:
			//���α׷� ����
			finishFlag = true;
			break;
		}

		if (finishFlag)
		{
			delete[] namebuf;
			break;
		}
	}
	return 0;
}