/************************************************************
C programming Team project(Treasure hunt Game) by Team 7
https://github.com/trollonion03/Cpre_Tp1
First build: May 3rd, 2022
Last build: May 3rd, 2022

Target: Windows(x86-64)
Language : C(MSVC, v142)
************************************************************/

#pragma warning(disable:6031)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

//functions
void gotoxy(int x, int y);
void init();
void CreateTitleScreen();
void Game_Core();
void movekey();


int main() {
	init();
	CreateTitleScreen();
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
	printf("\n                press 'A' key to start\n\n\n\n\n");
}

void Game_Core() {

}

void movekey() {
	int x = 0, y = 0, ch;
	gotoxy(x, y);
	ch = _getch();
	if (ch == 224) {
		ch = _getch();
		switch (ch) {
		case 72:
			printf("\0");
			y--;
			break;

		case 80:
			y++;
			break;

		case 75:
			x--;
			break;

		case 77:
			x++;
			break;

		default:
			break;
		}
	}
}