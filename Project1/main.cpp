#include <iostream>

int main(void)
{
	int val1;
	std::cout << "첫번째 숫자를 입력 : ";
	std::cin >> val1;

	int val2;
	std::cout << "두번째 숫자를 입력 : ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "덧셈 결과 : " << result << std::endl;

	/*
	int num = 20;
	std::cout << "Hello World~!!" << std::endl;
	std::cout << "Hello " << "World~!!" << std::endl;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;
	*/
	return 0;
}