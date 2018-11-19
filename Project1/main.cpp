#include <iostream>
#include <cstring>

using namespace std;

/* static 변수(클래스 변수) */

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};

class SoComplx
{
public:
	SoComplx()
	{
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplx 객체" << endl;
	}
};

int main()
{
	/* static 변수(클래스 변수) */
	SoSimple sim1;
	SoSimple sim2;

	SoComplx com1;
	SoComplx com2;
	SoComplx com3;

	return 0;
}
