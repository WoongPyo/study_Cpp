#pragma once
#include <iostream>
#include <cstring>

/* 자동차 (소유자, 연료량, 현재속도) */
namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}