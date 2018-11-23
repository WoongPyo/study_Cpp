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
	friend ostream &operator<<(ostream &os, const String &s);
	friend istream &operator>>(istream &is, String &s);
	int GetLen()
	{
		return len;
	}
};

String::String()
{
	len = 0;
	str = NULL;
}

//매개변수가 있는 생성자
String::String(const char *s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str,s);
}
//복사 생성자
String::String(const String &s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}
//소멸자
String::~String()
{
	if(str != NULL)
		delete[] str;
}
//operator= 연산자 오버로딩
String &String::operator=(const String &s)
{
	if (str != NULL)
		delete[] str;

	len = s.len;
	str = new char[len];
	strcpy(str, s.str);

	return *this;
}
//operator+ 연산자 오버로딩
String String::operator+(const String &s)
{
	String buf;

	buf.len = len + s.len - 1;
	buf.str = new char[buf.len];
	strcpy(buf.str, str);
	strcat(buf.str, s.str);

	return buf;
}
//operator+=
String &String::operator+=(const String &s)
{
	len = len + s.len - 1;
	char *buf = new char[len];
	strcpy(buf, str);
	strcat(buf, s.str);
	if(str != NULL)
		delete[] str;
	str = buf;

	return *this;
}

//operator==
bool String::operator==(const String &s)
{
	return strcmp(str, s.str) ? false : true;
	/*
	int cmp = strcmp(str, s.str);
	if (cmp == 0)
		return true;
	else
		return false;
	*/
}

/*
	입출력을 위해서 iostream 헤더파일을 사용
	입력 : istream class
	출력 : ostream class
*/

//출력을 위한 << 연산자 오버로딩
ostream &operator<<(ostream &os, const String &s)
{
	os << s.str;
	return os;
}

//입력을 위한 >> 연산자 오버로딩
istream & operator>> (istream &is, String &s)
{
	char str[100];
	cout << endl << strlen(str) << endl;
	is >> str;
	cout << strlen(str) << endl;
	s = String(str);

	return is;
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

	String str4;

	cout << "문자열 입력 : ";
	cin >> str4;
	cout << "입력한 문자열 : " << str4 << str4.GetLen() << endl;

	return 0;
}