#include <iostream>

using namespace std;

/*ĸ��ȭ - ���� (����ȯ��, �����) */
//�๰�� ĸ��
class SinivelCap
{
public:
	void Take() { cout << "�๰�� �ܽ��ϴ�." << endl; }
};

//��ħ�� ĸ��
class SneezeCap
{
public:
	void Take() { cout << "��ä�Ⱑ �ܽ��ϴ�." << endl; }
};

//�ڸ����� ĸ��
class SunffleCap
{
public:
	void Take() { cout << "�ڸ����� �ո��ϴ�." << endl; }
};

class AllInOne : SinivelCap, SneezeCap, SunffleCap
{
public:
	void Take() {};
};

//����ȯ��
class ColdPatient
{
public:
	//�๰ ����� ���� �Լ�
	void TakeSinivelCap(SinivelCap &cap)
	{
		cap.Take();
	}

	//��ħ�� ���� �Լ�
	void TakeSneezeCap(SneezeCap &cap)
	{
		cap.Take();
	}

	//�ڸ����� ���� �Լ�
	void TakeSunffleCap(SunffleCap &cap)
	{
		cap.Take();
	}

	void Takeall(AllInOne)
	{

	}
};

int main(void)
{
	SinivelCap scap;
	SneezeCap zcap;
	SunffleCap ncap;

	ColdPatient patient;

	patient.TakeSinivelCap(scap);
	patient.TakeSneezeCap(zcap);
	patient.TakeSunffleCap(ncap);

	return 0;
}
