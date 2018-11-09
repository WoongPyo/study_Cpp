#include <iostream>
#include <cstring>
#include "car.h"

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