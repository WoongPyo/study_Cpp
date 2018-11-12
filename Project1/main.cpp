#include <iostream>

using namespace std;

/*
	
	- ���� ����������� 5000�� ��ġ�� ����� �����Ѵ�.
	- Object �ĺ���
	�������, ���ϱ�����

*/

class FruitSeller
{
private:
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
private:
	// ������ �ܾ�
	int myMoney;
	// ���Ի������
	int numOfApples;

public:
	// int myMoney;
	/*�Լ�*/
	// ������� �ʱ�ȭ
	// member initialize�� ����� ����� �ʱ�ȭ
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

	void GetMoney(int money)
	{
		myMoney += money;
	}

	// ������� ��� �Լ�
	void ShowBuyResult() const
	{
		// numOfApples = 1000;
		// ����Լ��� ��� �Լ� �ڿ� const�� �ٿ� �Լ��� ���ȭ ��Ŵ, ���� ��� ������ �ٲܼ� ���� �� �� ����.
		cout << "��� ���� : " << numOfApples << endl;
		cout << "���� �ܾ� : " << myMoney << endl;
	}
};

int main(void)
{
	FruitSeller seller(100, 100, 0);
	FruitBuyer buyer(1000);

	//��� �Ǹ� �� ���� �ŷ�
	buyer.BuyApples(seller, 570);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}
