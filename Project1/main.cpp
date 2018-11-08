#include <iostream>
#include <cstring>

//#define SQUARE(x) ((x)*(x))

template <typename T> 

inline T SQUARE(T x)
{
	return x * x;
}

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
	std::cout << SQUARE(5) << std::endl;
	std::cout << SQUARE(5.5) << std::endl;

	/*
	AAA::BBB::CCC::num1 = 20;
	AAA::BBB::CCC::num2 = 30;

	using 
	using BestComImpl::SimpleFunc;
	SimpleFunc();
	ProgComImpl::SimpleFunc();
	*/
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