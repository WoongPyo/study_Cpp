#include <iostream>

using namespace std;

/*캡슐화 - 범위 (감기환자, 감기약) */
//콧물약 캡슐
class SinivelCap
{
public:
	void Take() { cout << "콧물이 멎습니다." << endl; }
};

//기침약 캡슐
class SneezeCap
{
public:
	void Take() { cout << "재채기가 멎습니다." << endl; }
};

//코막힘약 캡슐
class SunffleCap
{
public:
	void Take() { cout << "코막힘이 뚫립니다." << endl; }
};

class AllInOne : SinivelCap, SneezeCap, SunffleCap
{
public:
	void Take() {};
};

//감기환자
class ColdPatient
{
public:
	//콧물 감기약 복용 함수
	void TakeSinivelCap(SinivelCap &cap)
	{
		cap.Take();
	}

	//기침약 복용 함수
	void TakeSneezeCap(SneezeCap &cap)
	{
		cap.Take();
	}

	//코막힘약 복용 함수
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
