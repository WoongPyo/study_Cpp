#include <iostream>

using namespace std;


/*자동차 (소유자, 연료량, 현재속도)*/
#define ID_LEN		20
#define MAX_SPD		200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

struct Car
{
	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;

	void ShowCarState()
	{
		cout << "소유자 : " << gamerID << endl;
		cout << "연료량 : " << fuelGauge << endl;
		cout << "속  도 : " << curSpeed << endl;
	}

	void Accel()
	{
		//연료량 체크
		if (fuelGauge <= 0)
			return;
		else
			fuelGauge -= FUEL_STEP;

		//최고 속도 체크
		if (curSpeed + ACC_STEP >= MAX_SPD)
		{
			curSpeed = MAX_SPD;
			return;
		}
		curSpeed += ACC_STEP;
	}

	void Break()
	{
		if (curSpeed < BRK_STEP)
		{
			curSpeed = 0;
			return;
		}
		curSpeed -= BRK_STEP;

	}
};


int main(void)
{
	Car run77 = { "run77", 100 , 0 };
	run77.Accel();
	run77.Accel();
	run77.ShowCarState();
	run77.Break();
	run77.ShowCarState();
	
	Car run88 = { "run88", 100, 0 };
	run88.Accel();
	run88.Break();
	run88.ShowCarState();

	return 0;
}