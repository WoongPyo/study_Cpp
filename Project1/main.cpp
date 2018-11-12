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
	int applePrice;
	// ����� ������
	int numOfApples;
	// �Ǹ� ���ͱ�
	int myMoney;

	/* �Լ� */
	// ������� �ʱ�ȭ -> ������
	FruitSeller(int price, int num, int money)
	{
		applePrice = price;
		numOfApples = num;
		myMoney = money;
	}
	
	// ��� �Ǹ� �Լ�
	int SalesApples(int money)
	{
		int num = money / applePrice;
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

	/*�Լ�*/
	// ������� �ʱ�ȭ
	FruitBuyer(int money, int numOfApple)
	{
		myMoney = money;
		numOfApples = numOfApple;
	}
	// ��� �����Լ�
	void Buy(int money)
	{
		myMoney -= money;
	}

	// ������� ��� �Լ�
	void ShowBuyerResult()
	{
		cout << "��� ���� : " << numOfApples << endl;
		cout << "�ܾ� : " << myMoney << endl;
	}
};

int main(void)
{
	FruitSeller seller(100,100,0);
	FruitBuyer buyer(1000,0);

	return 0;
}
