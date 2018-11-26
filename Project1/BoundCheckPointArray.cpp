#include "BoundCheckPointArray.h"
template <class T>
BoundCheckPointArray<T>::BoundCheckPointArray(int maxNum) : accNum(0)
{
	accArr = new T[maxNum];
}

template <class T>
BoundCheckPointArray<T>::~BoundCheckPointArray()
{
	delete[] accArr;
}

template <class T>
T BoundCheckPointArray<T>::SelectAccount(int accNum)
{
	return accArr[accNum];
}

template <class T>
void BoundCheckPointArray<T>::AddAccount(T account)
{
	accArr[accNum++] = account;
}

template <class T>
void BoundCheckPointArray<T>::ShowAccountsInfo() const
{
	for (int i = 0; i < accNum; i++)		accArr[i]->PrintAccount();
}

template <class T>
int BoundCheckPointArray<T>::CheckingID(int ID)
{
	for (int i = 0; i < accNum; i++)
		if (ID == accArr[i]->GetID())			return i;
	return NO_MATCH;
}

template <class T>
int BoundCheckPointArray<T>::GetAccountNumber(void)
{
	return accNum;
}
