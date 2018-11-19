#include <iostream>
#include <cstring>

using namespace std;

/* static ����(Ŭ���� ����) */

//int simObjCnt = 0;
//int cmxObjCnt = 0;

class SoSimple
{
private:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "��° SoSimple ��ü" << endl;
	}
};

class SoComplx
{
private:
	static int cmxObjCnt;
public:
	SoComplx()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "��° SoComplx ��ü" << endl;
	}
};

int SoSimple::simObjCnt = 0;
int SoComplx::cmxObjCnt = 0;

int main()
{
	/* static ����(Ŭ���� ����) */
	SoSimple sim1;
	SoSimple sim2;

	SoComplx com1;
	SoComplx com2;
	SoComplx com3;

	return 0;
}
