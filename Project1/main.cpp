#include <iostream>
#include <cstring>

using namespace std;

/* ����� ������ String class*/

class String
{
private:
	int len;
	char *str;
public:
	String();					//�Ű������� ���� ������
	String(const char *s);		//�Ű������� �ִ� ������
	String(const String &s);	//���� ������
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

//�Ű������� �ִ� ������
String::String(const char *s)
{
	len = strlen(s);
	strcpy(str,s);
}

//���� ������
String::String(const String &s)
{
	len = s.len;
	strcpy(str, s.str);
}

//�Ҹ���
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
	/* C++ ǥ�� string class*/
	String str1 = "I like string class. ";
	String str2 = "Me too.";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;

	if (str1 == str3)
		cout << "���Ϲ��ڿ�" << endl;
	else
		cout << "�ٸ����ڿ�" << endl;

	string str4;

	cout << "���ڿ� �Է� : ";
	cin >> str4;
	cout << "�Է��� ���ڿ� : " << str4 << endl;

	return 0;
}