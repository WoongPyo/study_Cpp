#include <iostream>
#include <cstring>


using namespace std;

/* 자동차 (소유자, 연료량, 현재속도) */
namespace CAR_CONST
{
	enum
	{
		ID_LEN		= 20,
		MAX_SPD		= 200,
		FUEL_STEP	= 2,
		ACC_STEP	= 10,
		BRK_STEP	= 10
	};
}
/*
	Car 구조체를 class로 변경 및 적용.
	- 캡슐화(정보은닉, 범위설정)

	- 정보은닉을 위한 접근제어지시자
	public		: 어디서든 접근 가능
	private		: 클래스 내에서만 접근 가능
	protected	: 상속관계에서만 접근 가능
	
	- 범위설정
	개발자가 분석 후 정의하기 나름.
*/

class Car
{
private :
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

public :
	void InitMembers(const char *ID, int fuel);
	void ShowCarState();
	void Accel();
	void Break();
};

void Car::InitMembers(const char *ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarState()
{
	cout << "소유자 : " << gamerID << endl;
	cout << "연료량 : " << fuelGauge << endl;
	cout << "속  도 : " << curSpeed << endl;
}

void Car::Accel()
{
	//연료량 체크
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;

	//최고 속도 체크
	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
	{
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
	if (curSpeed < CAR_CONST::BRK_STEP)
	{
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;

}

int main(void)
{
	Car run77;
	run77.InitMembers("run77", 100);
	run77.Accel();
	run77.Accel();
	run77.ShowCarState();
	run77.Break();
	run77.ShowCarState();
	
	Car run88;
	run88.InitMembers("run88", 100);
	run88.Accel();
	run88.Break();
	run88.ShowCarState();

	return 0;
}