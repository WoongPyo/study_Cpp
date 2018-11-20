#include <iostream>
#include <cstring>

using namespace std;

/* 예외클래스를 통한 예외처리 */
// 입금, 출금 예외 class의 부모 class
// 추상클래스 : 순수가상함수로 선언된 class
// 객체를 만들려고 하면 컴파일 에러가 발생.
class AccountException
{
public:
	//순수가상함수 : 함수의 몸체가 없는 가상함수.
	virtual void ShowExceptionReason() = 0;
	//가상함수
	//virtual void ShowExceptionReason() {}
};

class DepositException : public AccountException
{
private:
	int deMoney;
public:
	DepositException(int money) : deMoney(money)
	{}
	void ShowExceptionReason()
	{
		cout << "예외메세지 : " << deMoney << "는 입금불가합니다." << endl;
	}
};

//출금 예외처리 class
class WirhdrawException : public AccountException
{
private:
	int balance;
public:
	WirhdrawException(int money) : balance(money)
	{}
	void ShowExceptionReason()
	{
		cout << "예외메세지 : 계좌 잔액이 " << balance << "보다 작습니다." << endl;
	}
};

//계좌 class
class Account
{
private:
	char accNum[50];	//계좌번호
	int balance;		//계좌잔액
public:
	// 생성자
	Account(const char *acc, int money) : balance(money)
	{
		strcpy(accNum, acc);
	}
	//입금함수
	void Deposit(int money) //throw (DepositException) // 예외에 대한 클래스를 throw 함을 명시 <--없어도 가능
	{
		if (money < 0)
		{
			throw DepositException(money);
		}
		balance += money;
	}
	//출금함수
	void Withdraw(int money) throw (WirhdrawException) // 예외에 대한 클래스를 throw 함을 명시
	{
		if (money > balance)
			throw WirhdrawException(money);

		balance -= money;
	}
	//잔액출력함수
	void ShowMyMoney()
	{
		cout << "잔액 : " << balance << endl << endl;
	}
};

int main(void)
{

	/* 예외클래스를 통한 예외처리 */
	Account myAcc("77777-77777", 5000);
	try
	{
		myAcc.Deposit(2000);
		myAcc.Deposit(-300);
	}
	catch (AccountException &expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	try
	{
		myAcc.Withdraw(1000);
		myAcc.Withdraw(9000);
	}
	catch (AccountException &expn)
	{
		expn.ShowExceptionReason();
	}
	myAcc.ShowMyMoney();

	return 0;
}

/* 예외 처리를 위한 상속관계에서의 예외위임에 따른 주의사항 */
class AAA
{
public:
	void ShowYou()
	{
		cout << "AAA exception" << endl;
	}
};

class BBB : public AAA
{
public:
	void ShowYou()
	{
		cout << "BBB exception" << endl;
	}
};

class CCC: public BBB
{
public:
	void ShowYou()
	{
		cout << "BBB exception" << endl;
	}
};

void ExceptionGenerator(int expn)
{
	if (expn == 1)
		throw AAA();
	else if (expn == 2)
		throw BBB();
	else
		throw CCC();
}