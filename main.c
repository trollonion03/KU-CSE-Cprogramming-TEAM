/************************************************************
*C programming Team project(Treasure hunt Game) by Team 7
*https://github.com/trollonion03/Cpre_Tp1
*First build: May 3rd, 2022
*Last build: May 9th, 2022
*
*Target: Windows(x86-64)
*Language : C(MSVC, v142)
************************************************************/

//#pragma warning(disable:6031) //for scanf, test
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdint.h>

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
void Create_Ground(short, short);
void movekey();
void sel_lv();
void PrintStory();
void LoadScreen();


int main() {
	/***********************************************
	*Modularize it as much as possible
	*Use this function to import other functions
	***********************************************/
	int gch;
	
	init();
	LoadScreen();
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
	char* ch;
	int i;
	system("cls");
	printf("\n\n\n\n");
	printf("         #   #   #####   #       #       #####\n");
	printf("         #   #   #       #       #       #   #\n");
	printf("         #####   ####    #       #       #   #\n");
	printf("         #   #   #       #       #       #   #\n");
	printf("         #   #   #####   #####   #####   #####\n");
	gotoxy(16, 10);

	//Print one character per 0.1 second
	ch = "Press 'Y' key to start!";
	int length = strlen(ch);
	for (i = 0; i < length; i++) {
		printf("%c", ch[i]);
		Sleep(100);
	}
}

void LoadScreen() {
	char* ch;
	int i;
	system("cls");
	gotoxy(26, 7); printf("LOADING...");
	gotoxy(12, 8); printf("-------------------------------------");
	gotoxy(12, 9); printf("|                                   |");
	gotoxy(12, 10); printf("-------------------------------------");
	gotoxy(13, 9);
	ch = "###################################";
	int length = strlen(ch);
	for (i = 0; i < length; i++) {
		printf("%c", ch[i]);
		Sleep(50);
	}
	Sleep(200);
}


void PrintStory() {

}

void sel_lv() {
	//TODO: New design needed
	int gch1, y = 4, count = 1;
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

	gotoxy(2, 15);

	while (1) {
		gotoxy(15, y);
		printf("◀");
		gch1 = _getch();
		printf("\b\b  ");
		switch (gch1) {
		case DOWN:
			count++;
			break;
		case UP:
			count--;
			break;
		default:
			break;
		}

		if (count == 4) {
			count = 1;
		}
		else if (count < 1) {
			count = 3;
		}
		
		switch (count){
		case 1:
			y = 4;
			break;
		case 2:
			y = 7;
			break;
		case 3:
			y = 10;
			break;

		default:
			break;
		}
		
		if (gch1 == '\r') {
			lv = count;
			break;
		}
	}
}

void Game_Core(int lvs) {
	//TODO: Implementation of core functionality
	//int ground[25][15];
	system("cls");
	printf("--------------------------------------------------------\n");
	if (lvs == 1) {
		gotoxy(23, 1);
		printf("Stage %d\n", lvs);
	}	
	else if (lvs == 2) {
		gotoxy(23, 1);
		printf("Stage %d\n", lvs);
	}
	else if (lvs == 3) {
		gotoxy(23, 1);
		printf("Stage %d\n", lvs);
	}	
	printf("--------------------------------------------------------\n");
	Create_Ground(40, 16);
	gotoxy(2, 4);
	
	while (1) {
		movekey();
	}
	
}

void movekey() {
	//TODO: Move function to another function
	static int x, y, count;
	int ch;
	
	if (count == 0) {
		x = 2; y = 4;
		count++;
	}
	else {
		gotoxy(x, y);
		ch = _getch();
		switch (ch) {
		case DOWN:
			y++;
			break;

		case UP:
			y--;
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

void Create_Ground(short x, short y) {
	/******************************************************************
	*if you use a emoji like '◁', the emojis consume 2 spaces.
	*If you want to move one coordinate, you have to move two spaces.
	*TODO: Find the right ground size
	******************************************************************/
	int i, j;
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

}
