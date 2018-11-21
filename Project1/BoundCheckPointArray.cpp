#include "BoundCheckPointArray.h"



BoundCheckPointArray::BoundCheckPointArray() : accNum(0)
{
}


BoundCheckPointArray::~BoundCheckPointArray()
{
	for (int i = 0; i < accNum; i++)			// ������� ���� ����
	{
		delete accArr[i];
	}
}

Account *BoundCheckPointArray::SelectAccount(int accNum)
{
	return accArr[accNum];
}
