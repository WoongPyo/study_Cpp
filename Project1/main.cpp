#include <iostream>

using namespace std;

/* self_reference 자기 참조의 이해 */
class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		cout << "객체생성" << endl;
	}
	SelfRef &Adder(int n)
	{
		num += n;
		return *this; // 자기자신을 참조하기 위해 *를 this 앞에 붙임.
	}
	SelfRef &ShowNumber()
	{
		cout << num << endl;
		return *this;
	}
};

int main(void)
{
	/* self_reference 자기 참조의 이해 */
	SelfRef obj(3);
	SelfRef &ref = obj.Adder(2);

	obj.ShowNumber();
	ref.ShowNumber();

	return 0;
}
