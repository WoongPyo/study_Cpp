#include <iostream>

int main(void)
{
	char name[100];
	char lang[200];

	std::cout << "�̸��� �˷��ּ���. : ";
	std::cin >> name;
	
	std::cout << "�����ϴ� ����? : ";
	std::cin >> lang;

	std::cout << "�� �̸��� " << name << "�Դϴ�." << std::endl;
	std::cout << "���� �����ϴ� ���� " << lang << "�Դϴ�." << std::endl;

	/*
	int val1;
	std::cout << "ù��° ���ڸ� �Է� : ";
	std::cin >> val1;

	int val2;
	std::cout << "�ι�° ���ڸ� �Է� : ";
	std::cin >> val2;

	int result = val1 + val2;
	std::cout << "���� ��� : " << result << std::endl;
	*/
	/*
	int num = 20;
	std::cout << "Hello World~!!" << std::endl;
	std::cout << "Hello " << "World~!!" << std::endl;
	std::cout << num << ' ' << 'A';
	std::cout << ' ' << 3.14 << std::endl;
	*/
	return 0;
}