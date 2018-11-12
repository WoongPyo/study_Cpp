#include <iostream>

using namespace std;

/*
	
	- 나는 과일장수에게 5000원 어치의 사과를 구매한다.
	- Object 후보군
	과일장수, 과일구매자

*/

class FruitSeller
{
	// 사과의 판매단가
	// int applePrice;
	const int APPLE_PRICE;
	// 사과의 재고수량
	int numOfApples;
	// 판매 수익금
	int myMoney;

public:
	/* 함수 */
	// 멤버변수 초기화 -> 생성자
	FruitSeller(int price, int num, int money): APPLE_PRICE(price)
	{
		//APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
		
	}
	/*
	FruitSeller(int price, int num, int money) : APPLE_PRICE(price), numOfApples(num), myMoney(money)
	{
		
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
		
	}
	*/

	// 사과 판매 함수
	int SalesApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	// 현재상태 출력 함수
	void ShowSalesResult()
	{
		cout << "사과 재고 : " << numOfApples << endl;
		cout << "판매 수익 : " << myMoney << endl;
	}
};

class FruitBuyer
{
	// 구입후 잔액
	int myMoney;
	// 구입사과수량
	int numOfApples;

public:
	/*함수*/
	// 멤버변수 초기화
	FruitBuyer(int money) : myMoney(money), numOfApples(0)
	{
		/*
		myMoney = money;
		numOfApples = 0;
		*/
	}
	// 사과 구매함수
	void BuyApples(FruitSeller &seller, int money)
	{
		myMoney -= money;
		numOfApples += seller.SalesApples(money);
	}

	// 현재상태 출력 함수
	void ShowBuyResult()
	{
		cout << "사과 개수 : " << numOfApples << endl;
		cout << "현재 잔액 : " << myMoney << endl;
	}
};

int main(void)
{
	FruitSeller seller(100, 100, 0);
	FruitBuyer buyer(1000);

	//사과 판매 및 구매 거래
	buyer.BuyApples(seller, 500);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();
	return 0;
}
