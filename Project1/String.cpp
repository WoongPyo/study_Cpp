#include "String.h"

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
	strcpy(str, s);
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
	if (str != NULL)
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
	if (str != NULL)
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

ostream &operator<<(ostream &os, const String &s)
{
	os << s.str;
	return os;
}

istream &operator>>(istream &is, String &s)
{
	char str[100];
	is >> str;
	s = String(str);
	return is;
}