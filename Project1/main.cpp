#include <iostream>

namespace BestSomImpl {
	void SimpleFunc(void)
	{
		std::cout << "BestCom�� �Լ�." << std::endl;
	}
}

namespace ProgComImpl {
	void SimpleFunc(void)
	{
		std::cout << "ProgCom�� �Լ�." << std::endl;
	}
}

int main(void)
{
	BestSomImpl::SimpleFunc();
	ProgComImpl::SimpleFunc();

	return 0;
}
