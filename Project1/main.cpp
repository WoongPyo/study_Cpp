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
	bool exitButton=true;

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
					accSel = handler.GetInt("�ʿ�� �ϴ� ������ ���´� �����Դϱ�?(1.���뿹�ݰ��� 2.�ſ���� 0.�޴�������)");	// ID�� ����
					if (accSel == EXIT)
						throw exitButton;
					if (accSel == NORMAL || accSel == CREDIT)
						throw accSel;
					cout << "�ʿ�� �ϴ� ������ ���°� �������� �ʽ��ϴ�." << endl;
				}
			}
			catch (bool exitButton) { break; }
			catch (int accSel)
			{
				try
				{
					while (1)
					{
						cout << endl << "[���� ����]" << endl;
						iDbuf = handler.GetInt("���� ID		: ");					// ID�� ����
						if (iDbuf == EXIT)
							throw exitButton;
						if (handler.CheckingID(iDbuf) == NO_MATCH)					// ����� ID�� �ִ��� Ȯ�� ���� ���°���
							throw iDbuf;

						cout << "���� ID�� ���� �մϴ�. �ٸ� ���̵� �Է��ϼ���. (�������� 0Ű�� ��������.)" << endl;
					}
				}
				catch (bool exitButton) { break; }
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
			try
			{
				while (1)
				{
					cout << endl << "[�Ա�]" << endl;
					iDbuf = handler.GetInt("���� ID		: ");
					accNum = handler.CheckingID(iDbuf);
					if (accNum == EXIT)
						throw exitButton;
					if (accNum != NO_MATCH)										// ���� ID�� ���� ���°� �������� ����
						throw accNum;
					cout << "���� ID�� ���� ���°� ���� ���� �ʽ��ϴ�. �ٽ� �Է��ϼ���. (�������� 0Ű�� ��������.)" << endl;
				}
			}
			catch (bool exitButton) { break; }
			catch(int accNum)
			{
				moneybuf = handler.GetInt("�Աݾ�		: ");
				handler.SelectAccount(accNum)->InputMoney(moneybuf);					// ���� ���¿� ���� �Ա�
				cout << "�ԱݿϷ� �Ǿ����ϴ�." << endl << endl;
			}
			break;
		case 3:
			//���
			try
			{
				cout << endl << "[���]" << endl;
				iDbuf = handler.GetInt("���� ID		: ");
				accNum = handler.CheckingID(iDbuf);
				if (accNum == EXIT)
					throw exitButton;
				if (accNum != NO_MATCH)										// ���� ID�� ���� ���°� �������� ����
					throw accNum;
				cout << "���� ID�� ���� ���°� ���� ���� �ʽ��ϴ�. �ٽ� �Է��ϼ���. (�������� 0Ű�� ��������.)" << endl;
			}
			catch (bool exitButton) { break; }
			catch (int accNum)
			{
				try
				{
					while (1)
					{
						moneybuf = handler.GetInt("��ݾ�		: ");
						if (moneybuf == EXIT)
							throw exitButton;
						if (handler.SelectAccount(accNum)->OutputMoney(moneybuf))			// ���� ���¿� �Է��� ���� ��ݰ��� Ȯ��
							throw 0;
						cout << "��ݾ��� �ܾ׺��� �����ϴ�. �ٽ� �Է��ϼ���. (�������� 0Ű�� ��������.)" << endl << endl;
					}
				}
				catch (bool exitButton) { break; }
				catch(int k)
				{
					cout << "��ݿϷ� �Ǿ����ϴ�." << endl << endl;
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