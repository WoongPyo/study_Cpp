#include <iostream>

using namespace std;

/* 상속
	- 관계가 논리적으로 성립이 되어야 상속이라고 말할 수 있다.
	- is A 관계, has A 관계
	- is A 관계
	노트북은 컴퓨터이다. Notebook is a computer.
	- has A 관계
	경찰은 총을 가진다. Police has a gun.

	- 상속의 목적
	class 간의 관계를 체계적으로 유지 및 관리하기 위해서이다.
	재사용하기 위해서 <- 관계가 체계적이어서.

	예시) - is A 관계 : 학생은 사람이다. Student is a person.ㄴㅁㅇㄹㅋㅌ
*/

class Gun
{
private:
	int bullet;
public:
	Gun(int bulletNum) : bullet(bulletNum)
	{}
	void Shot()
	{
		cout << "BANG~!" << endl;
		bullet--;
	}
};

/*
// is a 관계의 police class

class Police : public Gun
{
private:
	int handcuffs;
public:
	Police(int bulletNum, int handcuffsNum) : Gun(bulletNum), handcuffs(handcuffsNum)
	{}
	void PutHandcuff()
	{
		cout << "SNAP!!" << endl;
	}
};
*/

// has a 관계의 police class

class Police
{
private:
	int handcuffs;
	Gun *pistol;
public:
	Police(int bulletNum, int handcuffsNum) : handcuffs(handcuffsNum)
	{
		if (bulletNum > 0)
			pistol = new Gun(bulletNum);
		else
			pistol = NULL;
	}
	void PutHandcuff()
	{
		cout << "SNAP!!" << endl;
		handcuffs--;
	}
	void Shot()
	{
		if (pistol == NULL)
			cout << "Hut BBANG~!" << endl;
		else
			pistol->Shot();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};


int main()
{
	/* 진짜 경찰 */
	Police policeMan(5, 3);
	policeMan.Shot();
	policeMan.PutHandcuff();
	cout << endl;

	/* 교통 경찰 */
	Police trafficPolice(0, 3);
	trafficPolice.Shot();
	trafficPolice.PutHandcuff();

	/*
	Police policeman(5, 3);
	policeman.Shot();
	policeman.PutHandcuff();
	*/
	return 0;
}