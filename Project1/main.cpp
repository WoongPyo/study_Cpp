#include <iostream>

using namespace std;

/* ���
	- ���谡 �������� ������ �Ǿ�� ����̶�� ���� �� �ִ�.
	- is A ����, has A ����
	- is A ����
	��Ʈ���� ��ǻ���̴�. Notebook is a computer.
	- has A ����
	������ ���� ������. Police has a gun.

	- ����� ����
	class ���� ���踦 ü�������� ���� �� �����ϱ� ���ؼ��̴�.
	�����ϱ� ���ؼ� <- ���谡 ü�����̾.

	����) - is A ���� : �л��� ����̴�. Student is a person.������������
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
// is a ������ police class

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

// has a ������ police class

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
	/* ��¥ ���� */
	Police policeMan(5, 3);
	policeMan.Shot();
	policeMan.PutHandcuff();
	cout << endl;

	/* ���� ���� */
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