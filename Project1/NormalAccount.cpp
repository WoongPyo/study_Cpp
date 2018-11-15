#include "main.h"
#include "NormalAccount.h"



NormalAccount::NormalAccount(int ID, int money, char* name, int rate) : Account(ID, money, name), interRate(rate)
{}


NormalAccount::~NormalAccount()
{}
