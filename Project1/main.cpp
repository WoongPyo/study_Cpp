#include <iostream>
#include <cstring>

char *MakeStrAdr(int len)
{
	//char *str = (char *)malloc(sizeof(char) * len);
	char *str = new char[len];
	return str;
}

int main(void)
{
	char *str = MakeStrAdr(30);
	strcpy_s(str, 30, "I am happy~.");
	std::cout << str << std::endl;
	//free(str);
	delete(str);
	return 0;
}
