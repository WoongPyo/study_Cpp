#include <iostream>
#include <cstring>

using namespace std;

/* 정적지역변수 C언어 */
void Counter()
{
	// 정적지역변수
	static int cnt;
	cnt++;
	cout << "Current cnt : " << cnt << endl;
}

/*static 변수(클래스 변수)*/

int main()
{
	/* 정적지역변수 */
	for (int i = 0; i < 10; i++)
	{
		Counter();
	}


	return 0;
}
