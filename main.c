/************************************************************
*C programming Team project(Treasure hunt Game) by Team 7
*https://github.com/trollonion03/Cpre_Tp1
*First build: May 3rd, 2022
*Latest build: May 30th, 2022
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
#define MAP_WIDTH 40
#define MAP_HEIGHT 16
#define PY_MIN 3
#define PY_MAX 19
#define PX_MIN 1
#define PX_MAX 40
#define POS_S1 4
#define POS_S2 7
#define POS_S3 10
#define POS_S4 13

//Global variables

//functions
void gotoxy(int, int);
void init();
void CreateTitleScreen();
void Game_Core(int);
void Create_Ground(short, short);
void movekey(int*, int*);
void sel_lv(int*);
void PrintStory();
void LoadScreen();
void CreateObstacle();
void Endgame();

int main() {
	/***********************************************
	*Modularize it as much as possible
	*Use this function to import other functions
	***********************************************/
	int gch, lv;
	
	init();
	//LoadScreen();
	CreateTitleScreen();
	
	gch = _getch();
	if (gch == 'y' || gch == 'Y')
		sel_lv(&lv);
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
	srand((unsigned int)time(NULL));
}

void CreateTitleScreen() {
	//TODO: New design required!
	//x : 56, y : 20
	char* ch;
	int i;
	system("cls");
	gotoxy(11, 6); printf("|□ game.konkuk.ac.kr   |");
	gotoxy(59, 6); printf("◀|▶ |X|");
	gotoxy(11, 7); printf("---------------------------------------------------------");
	gotoxy(11, 8); printf("|           <건대 새내기의 슬기로운 대학생활>           |");
	gotoxy(11, 9); printf("|                      -0439  7팀-                      |");
	gotoxy(11, 10); printf("|                                                       |");
	gotoxy(11, 11); printf("|                       Loading..                       |");
	gotoxy(11, 12); printf("|                                                       |");
	gotoxy(11, 13); printf("---------------------------------------------------------");

	gotoxy(22, 12);
	ch = "■■■■■■■■■■■■■■■■■■";      
	int length = strlen(ch);
	for (i = 0; i < length; i++) {
		printf("%c", ch[i]);
		Sleep(50);
	}
	Sleep(200);

	gotoxy(28, 14);
	Sleep(100);

	//Print one character per 0.1 second
	ch = "Press 'Y' key to start!";
	length = strlen(ch);
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

void sel_lv(int *lv) {
	//TODO: New design needed
	int gch1, y = 4, count = 1;
	system("cls");
	printf("--------------------------------------------------------\n");
	gotoxy(24, 1);
	printf("레벨 선택\n");
	printf("--------------------------------------------------------\n");
	gotoxy(2, 4); printf("▷ 1학년");
	gotoxy(2, 5); printf("◆◇◇◇\n");

	gotoxy(2, 7); printf("▷ 2학년");
	gotoxy(2, 8); printf("◆◆◇◇");

	gotoxy(2, 10);printf("▷ 3학년");
	gotoxy(2, 11); printf("◆◆◆◇");

	gotoxy(2, 13); printf("▷ 4학년");
	gotoxy(2, 14); printf("◆◆◆◆");

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

		if (count == 5) {
			count = 1;
		}
		else if (count < 1) {
			count = 4;
		}
		
		switch (count){
		case 1:
			y = POS_S1;
			break;
		case 2:
			y = POS_S2;
			break;
		case 3:
			y = POS_S3;
			break;
		case 4:
			y = POS_S4;
			break;
		default:
			break;
		}
		
		if (gch1 == '\r') {
			*lv = count;
			break;
		}
	}
}

void Game_Core(int lvs) {
	//TODO: Implementation of core functionality
	//int ground[25][15];
	int px = 0, py = 0, count = 0;
	system("cls");
	printf("--------------------------------------------------------\n");
	if (lvs == 1) {
		gotoxy(23, 1);
		printf("%d 학년\n", lvs);
	}	
	else if (lvs == 2) {
		gotoxy(23, 1);
		printf("%d 학년\n", lvs);
	}
	else if (lvs == 3) {
		gotoxy(23, 1);
		printf("%d 학년\n", lvs);
	}
	else if (lvs == 4) {
		gotoxy(23, 1);
		printf("%d 학년\n", lvs);
	}
	printf("--------------------------------------------------------\n");
	Create_Ground(MAP_WIDTH, MAP_HEIGHT);
	CreateObstacle();
	gotoxy(7, 7);
	printf("●");

	while (1) {
		movekey(&px, &py);
		if (px == 7 && py == 7) {
			printf("\b   ");
			gotoxy(0, 18);
			break;
		}
	}	
}

void movekey(int *x, int *y) {
	//TODO: Move function to another function
	static int count, px, py;
	int ch;
	
	if (count == 0) {
		px = 1; py = 4;
		count++;
	}
	else {
		printf("\b ");
		gotoxy(px, py);
		printf("!");
		ch = _getch();
		switch (ch) {
		case DOWN:
			if (py > PY_MIN && py < PY_MAX && py + 1 != PY_MAX-1)
				py++;
			break;

		case UP:
			if (py > PY_MIN && py < PY_MAX && py - 1 != PY_MIN)
				py--;
			break;

		case LEFT:
			if (px >= PX_MIN && px < PX_MAX && px - 1 != PX_MIN-1)
				px--;		
			break;

		case RIGHT:
			if (px >= PX_MIN && px < PX_MAX && px + 1 != PX_MAX-1)
				px++;
			break;

		default:
			break;
		}
		*x = px;
		*y = py;
	}

}

void Create_Ground(short x, short y) {
	/******************************************************************
	*if you use a emoji like '◁', the emojis consume 2 spaces.
	*If you want to move one coordinate, you have to move two spaces.
	*TODO: Find the right ground size
	*TODO: Create random obstacle....
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
	printf("\n");

}

void CreateObstacle() {
	/***********************************************************************
	*Emoji test list
	*◈
	*TODO: Add the function to verify that obstacles are created correctly
	***********************************************************************/
	int wall[MAP_WIDTH - 2][MAP_HEIGHT - 2] = { 0, };
	int i, j, k, x, y, col, row;
	for (i = 0; i <= 10; i++) {
		x = rand() % MAP_WIDTH-2;
		y = rand() % MAP_HEIGHT - 2;
		
		if (wall[x][y] != 1) wall[x][y] = 1;
		else i--;
	}
	
	col = sizeof(wall[0]) / sizeof(int);
	row = sizeof(wall) / sizeof(wall[0]);
	//verify	
	/*for (j = 0; j < row; j++) {
		for (k = 0; k < col; k++) {
			if (wall[j][k] == 1) {
				
			}
		}
	}*/
	//print
	for (j = 0; j < row; j++) {
		for (k = 0; k < col; k++) {
			if (wall[j][k] == 1) {
				gotoxy(j+1, k+4);
				printf("@");
			}
		}
	}	
}

void Endgame() {
	
}