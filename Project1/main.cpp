#include <iostream>
#include <cstring>

using namespace std;

/* friend ���� */
class Girl;

class Boy
{
private:
	int height;
	friend class Girl;	// private�� �־ public�� �־ ���� ����� �Ѵ�.
public:
	Boy(int len) : height(len)
	{}
	void ShowYourFriendInfo(Girl &frn);
};

class Girl
{
private:
	char phNum[20];
public:
	friend class Boy; // public�� �־ private�� �־ ���� ����� �Ѵ�.
	Girl(const char *num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy &frn);
};

void Boy::ShowYourFriendInfo(Girl &frn)
{
	cout << "Her phone number : " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy &frn)
{
	cout << "His Height : " << frn.height << endl;
}

int main()
{
	/* friend ���� 
		- friend ������ ��ü������ ĸ��ȭ���� ���������� �����ϴ� ������.
		- ����, friend ������ �ʿ��� ��Ȳ������ ����ؾ� ��.
		- ������ �����ε����� �����Լ��� ����� ���.
	*/
	Boy boy(180);
	Girl girl("010-1111-1111");

	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);

	/*friend ���� - �Լ��� ��� */


	return 0;
}