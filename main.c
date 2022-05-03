/************************************************************
C programming Team project(Traser hunt Game) by Team 7
https://github.com/trollonion03/Cpre_Tp1
First build: May 3rd, 2022
Last build: May 3rd, 2022

Target: Windows(x86-64), v142
Language : C(MSVC)
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