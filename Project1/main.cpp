#include <iostream>

int main(void)
{
	int val1;
	std::cout << "ù��° ���ڸ� �Է� : ";
	std::cin >> val1;

	int val2;
	std::cout << "�ι�° ���ڸ� �Է� : ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "���� ��� : " << result << std::endl;

	/*
	int num = 20;
	std::cout << "Hello World~!!" << std::endl;
	std::cout << "Hello " << "World~!!" << std::endl;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;
	*/
	return 0;
}