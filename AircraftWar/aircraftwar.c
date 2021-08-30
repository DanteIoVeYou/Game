#define _CRT_SECURE_NO_WARNINGS 1
#include "aircraftwar.h"


void ShowTarget(int isKilled,int target_x)
{
	int i = 0;
	if (isKilled == 0)
	{
		for (i = 0; i < target_x; i++)
		{
			printf(" ");
		}
		printf("+");
		printf("\n");
	}
}


void ShowAircraft(int isFired, int* isKilled, int target_x, int* score, int x,int y)
{
	int i = 0;
	int j = 0;
	if (isFired == 0)
	{
		for (j = 0; j < y; j++)
		{
			printf("\n");
		}


		for (i = 0; i < x; i++)
		{
			printf(" ");
		}
		printf("  *\n");
		for (i = 0; i < x; i++)
		{
			printf(" ");
		}
		printf("*****\n");
		for (i = 0; i < x; i++)
		{
			printf(" ");
		}
		printf(" * *");
		printf("\n");
	}

	//Fire 
	else
	{
		for (j = 0; j < y; j++)
		{
			for (i = 0; i < x; i++)
			{
				printf(" ");
			}
			printf("  |");
			printf("\n");
		}


		for (i = 0; i < x; i++)
		{
			printf(" ");
		}
		printf("  *\n");
		for (i = 0; i < x; i++)
		{
			printf(" ");
		}
		printf("*****\n");
		for (i = 0; i < x; i++)
		{
			printf(" ");
		}
		printf(" * *");
		printf("\n");
		//Judge if the target is targeted.
		if (x + 2 == target_x && *isKilled == 0)
		{
			*isKilled = 1;
			(*score)++;
		}
	}
}