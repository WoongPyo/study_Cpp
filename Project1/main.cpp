#include <iostream>

using namespace std;

/*
	
	- ���� ����������� 5000�� ��ġ�� ����� �����Ѵ�.
	- Object �ĺ���
	�������, ���ϱ�����

*/

class FruitSeller
{
	// ����� �ǸŴܰ�
	// int applePrice;
	const int APPLE_PRICE;
	// ����� ������
	int numOfApples;
	// �Ǹ� ���ͱ�
	int myMoney;

public:
	/* �Լ� */
	// ������� �ʱ�ȭ -> ������
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

	// ��� �Ǹ� �Լ�
	int SalesApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	// ������� ��� �Լ�
	void ShowSalesResult()
	{
		cout << "��� ��� : " << numOfApples << endl;
		cout << "�Ǹ� ���� : " << myMoney << endl;
	}
};

class FruitBuyer
{
	// ������ �ܾ�
	int myMoney;
	// ���Ի������
	int numOfApples;

public:
	/*�Լ�*/
	// ������� �ʱ�ȭ
	FruitBuyer(int money) : myMoney(money), numOfApples(0)
	{
		/*
		myMoney = money;
		numOfApples = 0;
		*/
	}
	// ��� �����Լ�
	void BuyApples(FruitSeller &seller, int money)
	{
		myMoney -= money;
		numOfApples += seller.SalesApples(money);
	}

	// ������� ��� �Լ�
	void ShowBuyResult()
	{
		cout << "��� ���� : " << numOfApples << endl;
		cout << "���� �ܾ� : " << myMoney << endl;
	}
};

int main(void)
{
	FruitSeller seller(100, 100, 0);
	FruitBuyer buyer(1000);

	//��� �Ǹ� �� ���� �ŷ�
	buyer.BuyApples(seller, 500);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}
