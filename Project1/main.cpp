#include <iostream>
#include <cstring>

using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{}
	SoSimple &AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData() const
	{
		cout << "num : " << num << endl;
	}
};

int main()
{
	/* const 객체 
		- const 객체는 const 함수만 호출 가능.
		객체의 멤버변수의 변경을 허용하지 않음.
	*/
	SoSimple generalObj(10);
	generalObj.AddNum(10);
	generalObj.ShowData();

	const SoSimple constObj(100);
	constObj.ShowData(); // const 객체는 const 함수만 호출 할 수 있다.
	//constObj.AddNum(200);

	/* const  함수 오버로딩 */
	/* friend 선언 */

	return 0;
}