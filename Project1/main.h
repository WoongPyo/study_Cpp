#pragma once

#include <iostream>

#define NO_MATCH	101

using namespace std;

// 신용등급
typedef enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2, NO_LEVEL = 0}LEVEL;

// 계좌의 종류
typedef enum { NORMAL = 1, CREDIT = 2, EXIT = 0}ACCOUNT_TYPE;
