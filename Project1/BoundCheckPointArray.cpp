#include "BoundCheckPointArray.h"



BoundCheckPointArray::BoundCheckPointArray() : accNum(0)
{
}


BoundCheckPointArray::~BoundCheckPointArray()
{
	for (int i = 0; i < accNum; i++)			// 만들어진 계좌 제거
	{
		delete accArr[i];
	}
}

Account *BoundCheckPointArray::SelectAccount(int accNum)
{
	return accArr[accNum];
}
