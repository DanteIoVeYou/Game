#define _CRT_SECURE_NO_WARNINGS 1
#include "aircraftwar.h"

// Shoot rays
void isFired(int x, int y)
{
	int i = 0;
	int j = 0;
	for (j = 0; j < y - 1; j++)
	{
		for (i = 0; i < x; i++)
		{
			printf(" ");
		}
		printf("  |");

		printf("\n");
	}
}
void Game()
{
	srand((unsigned)time(NULL));
	//Board();
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 10;
	int score = 0;
	int isKilled = 0;
	int SetTarget = 0;
	int target_x = 5;
	while (1)
	{
		int isFired = 0;
		//Judge if a new target needs refleshing
		if (SetTarget % 2 == 0 && isKilled == 1)
		{
			target_x = rand() % TARGET_RANGE + 3;
			isKilled = 0;
			SetTarget++;
		}
		else if (isKilled == 1)
		{
			SetTarget++;
		}

		char input = _getch();
		system("cls");
		printf("==================================================\n");
		//Choose your next step
		switch (input)
		{
		case 'w':
			y--;
			break;
		case 's':
			y++;
			break;
		case 'a':
			x--;
			break;
		case 'd':
			x++;
			break;
		case ' ':
			isFired = 1;
			break;
		default:
			break;
		}
		//Show a target when isKilled == 0
		ShowTarget(isKilled,target_x);
		// Print the aircraft while not fired or fired
		ShowAircraft(isFired, &isKilled, target_x, &score, x, y);
		//Print current score
		printf("==================================================\n");
		printf("                                          Score:%d\n", score);
		if (score == 10)
		{
			printf("W i n!!!!!!!\n");
			printf("Wait 5 seconds......\n");
			Sleep(5000);
			system("cls");
			break;
		}
	}
}
void Rule()
{
	printf("+ ------ target\n");
	printf("Destroy 10 target and win the game\n");
	printf("w ------ up\ns ------ down\na ------ left\nd ------ right\nspace------shoot\n");
}
void menu()
{
	printf("========        Aircraft      War             ========\n");
	printf("======================================================\n");
	printf("========               1.play                 ========\n");
	printf("========               2.rule                 ========\n");
	printf("========               0.exit                 ========\n");
	printf("======================================================\n");
}
int main()
{
	int choose = 0;
	do {
		menu();
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			Game();
			break;
		case 2:
			Rule();
			break;
		case 0:
			printf("Exit!\n");
			break;
		default:
			printf("Illegal input!\n");
			break;
		}
	} while (choose);
	return 0;
}