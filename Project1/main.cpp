#include <iostream>

namespace BestComImpl {
	void SimpleFunc(void);
}

namespace ProgComImpl {
	void SimpleFunc(void);
}

int main(void)
{
	using BestComImpl::SimpleFunc;
	SimpleFunc();
	ProgComImpl::SimpleFunc();

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