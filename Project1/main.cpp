#include <iostream>
#include <cstring>
#include "car.h"

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