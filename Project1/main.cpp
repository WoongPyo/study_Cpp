#include <iostream>
#include <cstring>

using namespace std;

/*�迭 �ε��� ������ �����ε� */
class BoundCheckIntArray
{
private:
	int *arr;
	int arrLen;
public:
	BoundCheckIntArray(int len) : arrLen(len)
	{
		arr = new int[len];
	}
	~BoundCheckIntArray()
	{
		delete[] arr;
	}
	// �迭 �ε��� ������ �����ε�
	int &operator[](int idx)
	{
		//�迭�� ���� üũ
		if (idx < 0 || idx >= arrLen)
		{
			cout << "�迭�� ������ ������ϴ�." << endl;
			exit(1);
		}

		return arr[idx];
	}
};

int main(void)
{
	/*�迭 �ε��� ������ �����ε� */
	
	// arrObject[2];
	// �����Ϸ��� ��� �ؼ�����...
	// arrObject.oprator[](2)

	BoundCheckIntArray arr(5);

	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;

	for (int i = 0; i < 6; i++)
		cout << arr[i] << endl;

	//ShowAllData(arr);

	return 0;
}
