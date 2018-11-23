#include <iostream>
#include <cstring>

using namespace std;

/* 사용자 정의의 String class*/

class String
{
private:
	int len;
	char *str;
public:
	String();					//매개변수가 없는 생성자
	String(const char *s);		//매개변수가 있는 생성자
	String(const String &s);	//복사 생성자
	~String();
	String &operator=(const String &s);
	String operator+(const String &s);
	String &operator+=(const String &s);
	bool operator==(const String &s);
};

String::String()
{
	len = 0;
	str = NULL;
}

//매개변수가 있는 생성자
String::String(const char *s)
{
	len = strlen(s);
	strcpy(str,s);
}

//복사 생성자
String::String(const String &s)
{
	len = s.len;
	strcpy(str, s.str);
}

//소멸자
String::~String()
{
	delete[] str;
}

//operator=
String &String::operator=(const String &s)
{
	len = s.len;
	str = s.str;

	return *this;
}

//operator+
String String::operator+(const String &s)
{
	String buf;
	len = len + s.len;
	buf.str = new char[len + 1];
	strcpy(buf.str, str);
	strcpy(buf.str + len, s.str);
	return *this;
}

//operator+=
String &String::operator+=(const String &s)
{
	len = len + s.len;
	char *buf = new char[len + 1];
	strcpy(buf, str);
	strcpy(buf + len, s.str);
	delete[] str;
	str = buf;
	return *this;
}

//operator==
bool String::operator==(const String &s)
{
	int cmp = strcmp(str, s.str);
	if (cmp == 0)
		return true;
	else
		return false;
}

int main()
{
	/* C++ 표준 string class*/
	String str1 = "I like string class. ";
	String str2 = "Me too.";
	String str3 = str1 + str2;

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