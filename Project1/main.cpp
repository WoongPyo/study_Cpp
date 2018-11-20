#include <iostream>
#include <cstring>

using namespace std;

/*배열 인덱스 연산자 오버로딩 */
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
	// 배열 인덱스 연산자 오버로딩
	int &operator[](int idx)
	{
		//배열의 범위 체크
		if (idx < 0 || idx >= arrLen)
		{
			cout << "배열의 범위를 벗어났습니다." << endl;
			exit(1);
		}

		return arr[idx];
	}
};

int main(void)
{
	/*배열 인덱스 연산자 오버로딩 */
	
	// arrObject[2];
	// 컴파일러는 어떻게 해석할지...
	// arrObject.oprator[](2)

	BoundCheckIntArray arr(5);

	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;

	for (int i = 0; i < 6; i++)
		cout << arr[i] << endl;

	//ShowAllData(arr);

	return 0;
}
