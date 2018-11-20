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
	int GetArrLen() const
	{
		return arrLen;
	}
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

	// 배열 인덱스 연산자 오버로딩 
	//const키워드가 오버로딩 조건으로 들어감. 외부에서 const 배열을 쓰려면 다시 정의 해야 함.
	int &operator[](int idx) const
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

void ShowAllData(const BoundCheckIntArray &ref)
{
	for (int idx = 0; idx < ref.GetArrLen(); idx++)
	{
		cout << ref[idx] << endl;
	}
}

int main(void)
{
	/*배열 인덱스 연산자 오버로딩 */
	
	// arrObject[2];
	// 컴파일러는 어떻게 해석할지...
	// arrObject.oprator[](2)

	BoundCheckIntArray arr(5);

	for (int i = 0; i < 5; i++)
		arr[i] = (i + 1) * 11;

	//for (int i = 0; i < 6; i++)
	//	cout << arr[i] << endl;

	//ShowAllData(arr);

	return 0;
}
