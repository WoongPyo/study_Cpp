#include <iostream>
#include <cstring>

using namespace std;

/* friend 선언 */
class Girl;

class Boy
{
private:
	int height;
	friend class Girl;	// private에 있어도 public에 있어도 같은 기능을 한다.
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
	friend class Boy; // public에 있어도 private에 있어도 같은 기능을 한다.
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
	/* friend 선언 
		- friend 선언은 객체지향의 캡슐화에서 정보은닉을 위배하는 문법임.
		- 따라서, friend 선언은 필요한 상황에서만 사용해야 함.
		- 연산자 오버로딩에서 전역함수를 선언시 사용.
	*/
	Boy boy(180);
	Girl girl("010-1111-1111");

	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);

	/*friend 선언 - 함수인 경우 */


	return 0;
}