#include <iostream>
#include <string>

using namespace std;

int main()
{
	/* C++ 표준 string class*/
	string str1 = "I like string class. ";
	string str2 = "Me too.";
	string str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;

	if (str1 == str3)
		cout << "동일문자열" << endl;
	else
		cout << "다른문자열" << endl;

	string str4;

	cout << "문자열 입력 : ";
	cin >> str4;
	cout << "입력한 문자열 : " << str4 << endl;

	return 0;
}