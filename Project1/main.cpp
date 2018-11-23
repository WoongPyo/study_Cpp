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
	String &operator==(const String &s);
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
String &String::operator=(const String &s);
{
	String buf;
	buf.len = s.len;
	strcpy(buf.str, s.str);
	return buf;
}

//operator+

//operator+=

//operator==

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