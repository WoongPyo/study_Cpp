#include <iostream>

namespace BestSomImpl {
	void SimpleFunc(void);
}

namespace ProgComImpl {
	void SimpleFunc(void);
}

int main(void)
{
	BestSomImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();

	return 0;
}

void BestSomImpl::SimpleFunc(void)
{
	std::cout << "BestCom�� �Լ�." << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
	std::cout << "ProgCom�� �Լ�." << std::endl;
}