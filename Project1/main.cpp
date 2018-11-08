#include <iostream>
namespace AAA
{
	namespace BBB
	{
		namespace CCC
		{
			int num1;
			int num2;
		}
	}
}

namespace BestComImpl {
	void SimpleFunc(void);
}

namespace ProgComImpl {
	void SimpleFunc(void);
}

int main(void)
{
	namespace ABC = AAA::BBB::CCC;
	using BestComImpl::SimpleFunc;
	SimpleFunc();
	ProgComImpl::SimpleFunc();
	ABC::num1 = 20;
	ABC::num2 = 40;
	std::cout << ABC::num1 << std::endl;
	std::cout << ABC::num2 << std::endl;
	return 0;
}

void BestComImpl::SimpleFunc(void)
{
	std::cout << "BestCom의 함수." << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
	std::cout << "ProgCom의 함수." << std::endl;
}