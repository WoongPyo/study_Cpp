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
		handler.PrintSelect();											// 선택 메뉴 출력

		switch (handler.GetInt("[선택] : "))								// case 선택 하기
		{
		case 1:
			//계좌를 개설
			try
			{
				while (1)
				{
					accSel = handler.GetInt("필요로 하는 계좌의 형태는 무엇입니까?(1.보통예금계좌 2.신용계좌 3.메뉴나가기)");	// ID를 받음
					if (accSel == NORMAL || accSel == CREDIT || accSel == EXIT)
						throw accSel;
					cout << "필요로 하는 계좌의 형태가 존재하지 않습니다." << endl;
				}
			}
			catch (int accSel)
			{
				try
				{
					cout << endl << "[계좌 개설]" << endl;
					iDbuf = handler.GetInt("계좌 ID		: ");					// ID를 받음

					if (handler.CheckingID(iDbuf) == NO_MATCH)					// 공통된 ID가 있는지 확인 이후 계좌개설
						throw iDbuf;

					cout << "같은 ID가 존재 합니다." << endl;
				}
				catch(int iDbuf)
				{
					interestbuf = handler.GetInt("기본이율(%)	: ");
					if(accSel == NORMAL)
					{
						cout << "이름		: ";
						cin >> namebuf;
						moneybuf = handler.GetInt("입금액		: ");
						handler.AddAccount(new NormalAccount(iDbuf, moneybuf, namebuf, interestbuf));
					}
					else if (accSel == CREDIT)
					{
						cout << "당신의 신용등급은 얼마입니까?" << endl;
						creditbuf = handler.GetInt("(1.LEVEL_A, 2.LEVEL_B=4, 3.LEVEL_C)	: ");
						additionalRate = handler.TranlateCreditGrade(creditbuf);
						cout << "이름		: ";
						cin >> namebuf;
						moneybuf = handler.GetInt("입금액		: ");
						handler.AddAccount(new HighCreditAccount(iDbuf, moneybuf, namebuf, interestbuf, additionalRate));
					}
				}
			}
			break;
		case 2:
			//입금
			cout << endl << "[입금]" << endl;
			iDbuf = handler.GetInt("계좌 ID		: ");
			accNum = handler.CheckingID(iDbuf);
			if (accNum == NO_MATCH)										// 같은 ID를 가진 계좌가 존재하지 않음
			{
				cout << "같은 ID가 존재 하지 않습니다." << endl;
			}
			else
			{
				moneybuf = handler.GetInt("입금액		: ");
				handler.SelectAccount(accNum)->InputMoney(moneybuf);					// 지정 계좌에 돈을 입금
				cout << "입금완료 되었습니다." << endl << endl;
			}
			break;
		case 3:
			//출금
			cout << endl << "[출금]" << endl;
			iDbuf = handler.GetInt("계좌 ID		: ");
			accNum = handler.CheckingID(iDbuf);
			if (accNum == NO_MATCH)										// 같은 ID를 가진 계좌가 존재하지 않음
			{
				cout << "같은 ID가 존재 하지 않습니다." << endl;
			}
			else
			{
				moneybuf = handler.GetInt("출금액		: ");
				if (handler.SelectAccount(accNum)->OutputMoney(moneybuf))			// 지정 계좌에 입력한 돈을 출금가능 확인
				{
					cout << "출금완료 되었습니다." << endl << endl;
				}
				else
				{
					cout << "출금액이 잔액보다 많습니다." << endl << endl;
				}
			}
			break;
		case 4:
			//계좌정보출력
			cout << endl << "[전체출력]" << endl;						// 계좌 전부 출력
			handler.ShowAccountsInfo();
			break;
		case 5:
			//프로그램 종료
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