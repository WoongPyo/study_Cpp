#pragma once

#include <iostream>
#include "Account.h"
#include "AccountHandler.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"

#define NO_MATCH	101
using namespace std;

// 신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
// 계좌의 종류
enum { NORMAL = 1, CREDIT = 2 };