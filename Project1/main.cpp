#include <iostream>
#include <cstring>

using namespace std;

/* ����ó�� - Exception Handling */



int main(void)
{
	/* ����ó�� - Exception Handling */
	
	/* C++������ ����ó�� */
	//try ...���		���ܸ� �߰�
	//catch ...���		���ܸ� �����ؼ� ó��
	//throw ...���		���� ó���� ����
	int num1, num2;
	cout << "�� ���� ���� �Է� : ";
	cin >> num1 >> num2;	// ���� �߻�

	try
	{
		if (num2 == 0)
			throw num2; // catch�� �Ѿ.
		else
		{
			cout << "�������� �� : " << num1 / num2 << endl;
			cout << "�������� ������ : " << num1 % num2 << endl;
		}
	}
	catch(int expn)
	{
		cout << "�� ���� " << expn << "�� �� �� �����ϴ�." << endl;
		cout << "���α׷��� �ٽ� �����ϼ���." << endl;
	}



	/* �������� C����� ����ó�� */
	//int num1, num2;
	//cout << "�� ���� ���� �Է� : ";
	//cin >> num1 >> num2;	// ���� �߻�

	//if (num2 == 0)			//���� üũ
	//{						//���� ó��
	//	cout << "�� ���� 0�� �� �� �����ϴ�." << endl;
	//	cout << "���α׷��� �ٽ� �����ϼ���." << endl;
	//}
	//else
	//{
	//	cout << "�������� �� : " << num1 / num2 << endl;
	//	cout << "�������� ������ : " << num1 % num2 << endl;
	//}


	return 0;
}
