/************************************************************
C programming Team project(Treasure hunt Game) by Team 7
https://github.com/trollonion03/Cpre_Tp1
First build: May 3rd, 2022
Last build: May 4th, 2022

Target: Windows(x86-64)
Language : C(MSVC, v142)
************************************************************/

//#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

//vals
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int lv;

//functions
void gotoxy(int, int);
void init();
void CreateTitleScreen();
void Game_Core(int);
void Create_Ground();
void movekey();
void sel_lv();


int main() {
	int gch;
	
	init();
	CreateTitleScreen();
	
	gch = _getch();
	if (gch == 'Y' || gch == 'y')
		sel_lv();
	else
		return 0;
	Game_Core(lv);
	
}

void gotoxy(int x, int y) {
	COORD Cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void init() {
	system("mode con cols=56 lines=20 | title test");
}

void CreateTitleScreen() {
	printf("\n\n\n\n");
	printf("         #   #   #####   #       #       #####\n");
	printf("         #   #   #       #       #       #   #\n");
	printf("         #####   ####    #       #       #   #\n");
	printf("         #   #   #       #       #       #   #\n");
	printf("         #   #   #####   #####   #####   #####\n");
	printf("\n                press 'Y' key to start\n\n\n\n\n");
}

void sel_lv() {//Optimize needed
	int gch1;
	while (1) {
		system("cls");
		printf("--------------------------------------------------------\n");
		printf("                        레벨 선택\n");
		printf("--------------------------------------------------------\n");
		printf("\n\n\n\n                        1. 쉬움\n");
		printf("\n                        2. 보통\n");
		printf("\n                        3. 어려움\n");
		gch1 = _getch();
		switch (gch1) {
		case '1':
			lv = 1;
			break;
		case '2':
			lv = 2;
			break;
		case '3':
			lv = 3;
			break;

		default:
			break;
		}
		if (gch1 == '1' || gch1 == '2' || gch1 == '3') {
			break;
		}
	}
}

void Game_Core(int lvs) {
	int ground[25][15];
	system("cls");
	printf("--------------------------------------------------------\n");
	if (lvs == 1)
		printf("쉬움\n");
	else if (lvs == 2)
		printf("보통\n");
	else if (lvs == 3)
		printf("어려움\n");
	printf("--------------------------------------------------------\n");
	Create_Ground();

	
}

void movekey() {
	int x = 0, y = 0, ch;
	gotoxy(x, y);
	ch = _getch();
	if (ch == 224) {
		ch = _getch();
		switch (ch) {
		case UP:
			printf("\0");
			y--;
			break;

		case DOWN:
			y++;
			break;

		case LEFT:
			x--;
			break;

		case RIGHT:
			x++;
			break;

		default:
			break;
		}
	}
}

void Create_Ground() {
	int i, j;
	int x = 28;
	int y = 12;
	for (i = 0; i < x - 1; i++)
	{
		gotoxy(i * 2, 4);
		printf("#");
	}
	for (i = 0; i < x - 1; i++)
	{
		gotoxy(i * 2, y - 1 + 4);
		printf("#");
	}
	for (i = 0; i < y; i++)
	{
		gotoxy(0, i + 4);
		printf("#");
	}
	for (i = 0; i < y; i++)
	{
		gotoxy((x - 1) * 2, i + 4);
		printf("#");
	}
}