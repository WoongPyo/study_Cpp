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

//�Ű������� �ִ� ������
String::String(const char *s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str,s);
}
//���� ������
String::String(const String &s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}
//�Ҹ���
String::~String()
{
	if(str != NULL)
		delete[] str;
}
//operator= ������ �����ε�
String &String::operator=(const String &s)
{
	if (str != NULL)
		delete[] str;

	len = s.len;
	str = new char[len];
	strcpy(str, s.str);

	return *this;
}
//operator+ ������ �����ε�
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
	������� ���ؼ� iostream ��������� ���
	�Է� : istream class
	��� : ostream class
*/

//����� ���� << ������ �����ε�
ostream &operator<<(ostream &os, const String &s)
{
	os << s.str;
	return os;
}

//�Է��� ���� >> ������ �����ε�
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

	String str4;

	cout << "���ڿ� �Է� : ";
	cin >> str4;
	cout << "�Է��� ���ڿ� : " << str4 << str4.GetLen() << endl;

	return 0;
}