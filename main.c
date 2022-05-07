/************************************************************
*C programming Team project(Treasure hunt Game) by Team 7
*https://github.com/trollonion03/Cpre_Tp1
*First build: May 3rd, 2022
*Last build: May 7th, 2022
*
*Target: Windows(x86-64)
*Language : C(MSVC, v142)
************************************************************/

#pragma warning(disable:6031) //for scanf
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

//Constants
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

//Global Variables
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
	/***********************************************
	*Modularize it as much as possible
	*Use this function to import other functions
	***********************************************/
	int gch;
	
	init();
	CreateTitleScreen();
	
	gch = _getch();
	if (gch == 'y' || gch == 'Y')
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
	//system("mode con cols=56 lines=20 | title test"); //Display option and windows name - for release
}

void CreateTitleScreen() {
	//TODO: New design required!
	//x : 56, y : 20
	printf("\n\n\n\n");
	printf("         #   #   #####   #       #       #####\n");
	printf("         #   #   #       #       #       #   #\n");
	printf("         #####   ####    #       #       #   #\n");
	printf("         #   #   #       #       #       #   #\n");
	printf("         #   #   #####   #####   #####   #####\n");
	gotoxy(16, 10);
	printf("press 'Y' key to start");
}

void sel_lv() {
	//TODO: New design needed
	int gch1;
	system("cls");
	printf("--------------------------------------------------------\n");
	gotoxy(24, 1);
	printf("레벨 선택\n");
	printf("--------------------------------------------------------\n");
	gotoxy(2, 4); printf("▷ Stage 1");
	gotoxy(2, 5); printf("◆◇◇\n");

	gotoxy(2, 7); printf("▷ Stage 2");
	gotoxy(2, 8); printf("◆◆◇");

	gotoxy(2, 10);printf("▷ Stage 3");
	gotoxy(2, 11); printf("◆◆◆");
	
	while (1) {
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
	//TODO: Implementation of core functionality
	int ground[25][15];
	system("cls");
	printf("--------------------------------------------------------\n");
	if (lvs == 1) {
		gotoxy(25, 1);
		printf("쉬움\n");
	}	
	else if (lvs == 2) {
		gotoxy(25, 1);
		printf("보통\n");
	}
	else if (lvs == 3) {
		gotoxy(24, 1);
		printf("어려움\n");
	}	
	printf("--------------------------------------------------------\n");
	Create_Ground();

	
}

void movekey() {
	//TODO: Move function to another function
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
	/******************************************************************
	*if you use a emoji like '◁', the emojis consume 2 spaces.
	*If you want to move one coordinate, you have to move two spaces.
	*TODO: Find the right ground size
	******************************************************************/
	int i, j;
	int x = 40; //width (max 40)
	int y = 16; //height(max 16)
	for (i = 1; i <= x; i++) {
		printf("#");
	}
	printf("\n");
	for (i = 1; i <= y - 2; i++) {
		printf("#");
		for (j = 1; j <= x - 2; j++) {
			printf(" ");
		}
		printf("#\n");
	}
	for (i = 1; i <= x; i++) {
		printf("#");
	}
	return 0;
}
