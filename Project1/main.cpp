#include <iostream>
#include <cstring>

using namespace std;

/* ������������ C��� */
void Counter()
{
	// ������������
	static int cnt;
	cnt++;
	cout << "Current cnt : " << cnt << endl;
}

/*static ����(Ŭ���� ����)*/

int main()
{
	/* ������������ */
	for (int i = 0; i < 10; i++)
	{
		Counter();
	}


	return 0;
}
