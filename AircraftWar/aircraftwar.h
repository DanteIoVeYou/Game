#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define X 20
#define Y 10
#define TARGET_RANGE 47


void ShowTarget(int isKilled, int target_x);
void ShowAircraft(int isFired, int* isKilled, int target_x, int* score, int x, int y);


