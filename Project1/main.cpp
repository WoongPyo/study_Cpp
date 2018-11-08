#include <iostream>

void MyFunc(void)
{
	std::cout << "Myfunc(void) called" << std::endl;
}

void MyFunc(char c)
{
	std::cout << "void MyFunc( " << c << " ) called" << std::endl;
}

void MyFunc(int a, int b)
{
	std::cout << "void MyFunc( " << a << b << " ) called" << std::endl;
}

int main(void)
{
	MyFunc();
	MyFunc('A');
	MyFunc(12, 13);
	return 0;
}