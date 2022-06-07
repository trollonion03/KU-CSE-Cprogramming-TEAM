/************************************************************
*C programming Team project(Treasure hunt Game) by Team 7
*https://github.com/trollonion03/Cpre_Tp1
*First build: May. 3rd, 2022
*Latest build:JUN. 8th, 2022
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
#include <time.h>
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
#define POS_S1 12
#define POS_S2 27
#define POS_S3 42
#define POS_S4 57

//Global variables
int32_t map_g[MAP_WIDTH-2][MAP_HEIGHT-2];

//functions
void gotoxy(int32_t, int32_t);
void init();
void CreateTitleScreen();
void Game_Core(int32_t);
void Create_Ground(int16_t, int16_t);
void movekey(int32_t*, int32_t*);
void sel_lv(int32_t*);
void Story();
void LoadScreen(uint16_t);
void CreateObstacle(int32_t lv);
void Endgame();

int32_t main() {
	/***********************************************
	*Modularize it as much as possible
	*Use this function to import other functions
	***********************************************/
	int32_t gch, lv;
	
	init();
	//LoadScreen(1);
	CreateTitleScreen();
	
	
	//TODO: getch() -> kbhit()
	gch = _getch();
	if (gch == 'y' || gch == 'Y') {
		//Automatically move on to the next function
		Story();
	}
	else
		return 0;
	
	while (1) {
		sel_lv(&lv);
		LoadScreen(2);
		Game_Core(lv);
	}
}

void gotoxy(int32_t x, int32_t y) {
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
	uint8_t* ch;
	int32_t i;

	system("cls");
	gotoxy(11, 6);  printf("|□ game.konkuk.ac.kr:23   |");
	gotoxy(59, 6);  printf("◀|▶ |X|");
	gotoxy(11, 7);  printf("---------------------------------------------------------");
	gotoxy(11, 8);  printf("|           <건대 새내기의 슬기로운 대학생활>           |");
	gotoxy(11, 9);  printf("|                      -0439  7팀-                      |");
	gotoxy(11, 10); printf("|                                                       |");
	gotoxy(11, 11); printf("|                       Loading..                       |");
	gotoxy(11, 12); printf("|                                                       |");
	gotoxy(11, 13); printf("---------------------------------------------------------");

	gotoxy(22, 12);
	ch = "■■■■■■■■■■■■■■■■■■";      
	int32_t length = strlen(ch);
	for (i = 0; i < length; i++) {
		printf("%c", ch[i]);
		Sleep(50);
	}
	Sleep(200);

	gotoxy(28, 14);
	Sleep(100);

	//Print one character per 0.1 second
	//TODO: change "press y key" to "press any key"
	ch = "Press 'Y' key to start!";
	length = strlen(ch);
	for (i = 0; i < length; i++) {
		printf("%c", ch[i]);
		Sleep(100);
	}
}

void LoadScreen(uint16_t sc) {
	uint8_t* ch;
	int32_t i, length;
	
	system("cls");
	switch (sc) {
	case 1:
		gotoxy(26, 7); printf("LOADING...");
		gotoxy(12, 8); printf("-------------------------------------");
		gotoxy(12, 9); printf("|                                   |");
		gotoxy(12, 10); printf("-------------------------------------");
		gotoxy(13, 9);
		ch = "###################################";
		length = strlen(ch);
		for (i = 0; i < length; i++) {
			printf("%c", ch[i]);
			Sleep(50);
		} break;
	case 2:
		gotoxy(11, 6);  printf("|□ game.konkuk.ac.kr:23/loading/tips   |");
		gotoxy(59, 6);  printf("◀|▶ |X|");
		gotoxy(11, 7);  printf("---------------------------------------------------------");
		gotoxy(11, 8);  printf("|                                                       |");
		gotoxy(11, 9);  printf("|                                                       |");
		gotoxy(11, 10); printf("|                                                       |");
		gotoxy(11, 11); printf("|                       Loading..                       |");
		gotoxy(11, 12); printf("|                                                       |");
		gotoxy(11, 13); printf("---------------------------------------------------------");

		gotoxy(22, 12);
		ch = "■■■■■■■■■■■■■■■■■■";
		length = strlen(ch);
		for (i = 0; i < length; i++) {
			printf("%c", ch[i]);
			Sleep(50);
		}break;

	default:
		break;
	}
	Sleep(200);
}


void Story() {
	uint8_t* ch;
	int32_t i;

	system("cls");
	gotoxy(64, 6); printf("◀|▶ |X|");
	gotoxy(6, 6);  printf("|□ game.konkuk.ac.kr:23/Story1   |");
	gotoxy(6, 7);  printf("-------------------------------------------------------------------");
	gotoxy(6, 8);  printf("|                                                                 |");
	gotoxy(6, 9);  printf("|                                                                 |");
	gotoxy(6, 10); printf("|                                                                 |");
	gotoxy(6, 11); printf("|                                                                 |");
	gotoxy(6, 12); printf("|                                                                 |");
	gotoxy(6, 13); printf("|                                                                 |");
	gotoxy(6, 14); printf("|                                                                 |");
	gotoxy(6, 15); printf("|                                                                 |");
	gotoxy(6, 16); printf("|                                                                 |");
	gotoxy(6, 17); printf("|                                                                 |");
	gotoxy(6, 18); printf("-------------------------------------------------------------------");
	
	gotoxy(8, 8);
	ch = "코로나 팬데믹이라는 상황에도 불구하고 열심히 공부하여";
	int32_t length = strlen(ch);
	for (i = 0; i < length; i++) {
		printf("%c", ch[i]);
		Sleep(50);
	}

	gotoxy(8, 10);
	ch = "건대 컴공에 합격한 당신!";
	length = strlen(ch);
	for (i = 0; i < length; i++) {
		printf("%c", ch[i]);
		Sleep(50);
	}

	gotoxy(8, 12);
	ch = "비대면 강의부터 대면 강의, 팀플, 과제 그리고";
	length = strlen(ch);
	for (i = 0; i < length; i++) {
		printf("%c", ch[i]);
		Sleep(50);
	}

	gotoxy(8, 14);
	ch = "건대에서만 볼 수 있는 특별한 동물들까지..!!";
	length = strlen(ch);
	for (i = 0; i < length; i++) {
		printf("%c", ch[i]);
		Sleep(50);
	}

	gotoxy(8, 16);
	ch = "건대 새내기의 슬기로운 학교생활이 지금 시작됩니다!";
	length = strlen(ch);
	for (i = 0; i < length; i++) {
		printf("%c", ch[i]);
		Sleep(50);
	}

	Sleep(500);
}

void sel_lv(int32_t *lv) {
	//TODO: New design needed
	int32_t gch1, y = 12, count = 1;

	system("cls");
	gotoxy(34, 1); printf("==========");
	gotoxy(33, 2); printf("||레벨선택||");
	gotoxy(34, 3); printf("==========");
	gotoxy(64, 6); printf("◀|▶ |X|");
	gotoxy(6, 6);  printf("|□ game.konkuk.ac.kr:23/sel_lv   |");
	gotoxy(6, 7);  printf("-------------------------------------------------------------------");
	gotoxy(6, 8);  printf("|                                                                 |");
	gotoxy(6, 9);  printf("|                                                                 |");
	gotoxy(6, 10); printf("|     |Stage 1 |     |Stage 2 |     |Stage 3 |     |Stage 4 |     |");
	gotoxy(6, 11); printf("|     |1학년   |     |2학년   |     |3학년   |     |4학년   |     |");
	gotoxy(6, 12); printf("|                                                                 |");
	gotoxy(6, 13); printf("|     ■ 설명                                                     |");
	gotoxy(6, 14); printf("|     | 1. 클리어 조건 : 만족도 100 채우기                        |");
	gotoxy(6, 15); printf("|     | 2. 실패 조건   : 체력 100 모두 소모                       |");
	gotoxy(6, 16); printf("|     | 3. 랜덤으로 미니게임이 나타납니다?!!                      |");
	gotoxy(6, 17); printf("|                                                                 |");
	gotoxy(6, 18); printf("-------------------------------------------------------------------");

	/*
	printf("--------------------------------------------------------\n");
	gotoxy(2, 4); printf("▷ 1학년");
	gotoxy(2, 5); printf("◆◇◇◇\n");

	gotoxy(2, 7); printf("▷ 2학년");
	gotoxy(2, 8); printf("◆◆◇◇");

	gotoxy(2, 10);printf("▷ 3학년");
	gotoxy(2, 11); printf("◆◆◆◇");

	gotoxy(2, 13); printf("▷ 4학년");
	gotoxy(2, 14); printf("◆◆◆◆");
	*/
	while (1) {
		gotoxy(y, 9);
		printf("▣");
		gch1 = _getch();
		printf("\b\b  ");
		switch (gch1) {
		case RIGHT:
			count++;
			break;
		case LEFT:
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

void Game_Core(int32_t lvs) {
	//TODO: Implementation of core functionality
	//int ground[25][15];
	int32_t px = 0, py = 0, count = 0, count2 = 0;

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
	CreateObstacle(lvs);
	px = 1; py = 4;
	//gotoxy(7, 7);
	//printf("●");

	//if you use Debugger, Set a breakpoint on line 354
	//if you want status on another postion, use gotoxy(px, py); after new function ended!
	//TODO: Add game over & game clear conditions
	while (1) {
		if (count2 == 0)
			px = 1; py = 4; count2++;

		movekey(&px, &py);
		/*if (map_g[px - 1][py - 4] == 1) {
			map_g[px - 1][py - 4] = 0;
			count++;
			if (count == 10) {
				count = 0;
				count2= 0;
				break;
			}
		}*/

		/* for test
		if (px == 7 && py == 7) {
			printf("\b   ");
			gotoxy(0, 18);
			break;
		}*/
	}	
}

void movekey(int32_t *x, int32_t *y) {
	//TODO: Add Input-delay
	static int32_t count, px, py;
	int32_t ch;
	
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
			if (py > PY_MIN && py < PY_MAX && py + 1 != PY_MAX-1 && map_g[px-1][py-3] != 2)
				py++;
			break;

		case UP:
			if (py > PY_MIN && py < PY_MAX && py - 1 != PY_MIN && map_g[px-1][py-5] != 2)
				py--;
			break;

		case LEFT:
			if (px >= PX_MIN && px < PX_MAX && px - 1 != PX_MIN-1 && map_g[px-2][py-4] != 2)
				px--;		
			break;

		case RIGHT:
			if (px >= PX_MIN && px < PX_MAX && px + 1 != PX_MAX-1 && map_g[px][py-4] != 2)
				px++;
			break;

		default:
			break;
		}
		*x = px;
		*y = py;
	}

}

void Create_Ground(int16_t x, int16_t y) {
	/******************************************************************
	*if you use a emoji like '◁', the emojis consume 2 spaces.
	*If you want to move one coordinate, you have to move two spaces.
	*TODO: Find the right ground size
	******************************************************************/
	int32_t i, j;

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

void CreateObstacle(int32_t lv) {
	/***************************************************************************
	*Emoji test list
	*◈!@#$%^&*()_+|
	* -------------------------
	* MT: 1, wall: 2, drinking party: 3, class absence: 4
	* dining : 5, Team project: 6, homework: 7,  class: 8, online class: 9
	*TODO: Add the verification method to check obstacles are created correctly
	*TODO: Fix the bug where one more item is generated
	***************************************************************************/
	int32_t item[MAP_WIDTH - 2][MAP_HEIGHT - 2] = { 0, };
	int32_t i, j, k, x, y, col, row;
	uint16_t count = 0;
	int32_t mt, dp, ca, di, tp, hw, cl, oc; //without wall

	switch (lv) {
	case 1:
		mt = 1; dp = 2; ca = 3; di = 4; tp = 1; hw = 2; cl = 3; oc = 4;
		break;
	case 2:
		mt = 1; dp = 2; ca = 2; di = 4; tp = 1; hw = 2; cl = 4; oc = 3;
		break;
	case 3:
		mt = 1; dp = 2; ca = 2; di = 3; tp = 2; hw = 2; cl = 3; oc = 3;
		break;
	case 4:
		mt = 0; dp = 3; ca = 3; di = 2; tp = 2; hw = 3; cl = 3; oc = 3;
		break;
	
	default:
		break;
	}

	col = sizeof(item[0]) / sizeof(int32_t);
	row = sizeof(item) / sizeof(item[0]);
	
	//init
	memset(map_g, 0, sizeof(map_g));

	//Create random item
	for (i = 0; i <= mt; i++) {
		x = rand() % MAP_WIDTH-2;
		y = rand() % MAP_HEIGHT - 2;
		
		if (item[x][y] == 0) item[x][y] = 1;
		else i--;
	}
	
	for (i = 0; i <= dp; i++) {
		x = rand() % MAP_WIDTH - 2;
		y = rand() % MAP_HEIGHT - 2;

		if (item[x][y] == 0) item[x][y] = 3;
		else i--;
	}

	for (i = 0; i <= ca; i++) {
		x = rand() % MAP_WIDTH - 2;
		y = rand() % MAP_HEIGHT - 2;

		if (item[x][y] == 0) item[x][y] = 4;
		else i--;
	}

	for (i = 0; i <= di; i++) {
		x = rand() % MAP_WIDTH - 2;
		y = rand() % MAP_HEIGHT - 2;

		if (item[x][y] == 0) item[x][y] = 5;
		else i--;
	}

	for (i = 0; i <= tp; i++) {
		x = rand() % MAP_WIDTH - 2;
		y = rand() % MAP_HEIGHT - 2;

		if (item[x][y] == 0) item[x][y] = 6;
		else i--;
	}
	
	for (i = 0; i <= hw; i++) {
		x = rand() % MAP_WIDTH - 2;
		y = rand() % MAP_HEIGHT - 2;

		if (item[x][y] == 0) item[x][y] = 7;
		else i--;
	}
	
	for (i = 0; i <= cl; i++) {
		x = rand() % MAP_WIDTH - 2;
		y = rand() % MAP_HEIGHT - 2;

		if (item[x][y] == 0) item[x][y] = 8;
		else i--;
	}

	for (i = 0; i <= oc; i++) {
		x = rand() % MAP_WIDTH - 2;
		y = rand() % MAP_HEIGHT - 2;

		if (item[x][y] == 0) item[x][y] = 9;
		else i--;
	}

	//Create random wall
	for (i = 0; i <= 40; i++) {
		x = rand() % MAP_WIDTH - 2;
		y = rand() % MAP_HEIGHT - 2;

		if (item[x][y] == 0) item[x][y] = 2;
		else i--;
	}

	//Create random obstacle - for debug
	/*for (i = 0; i <= 10; i++) {
		x = rand() % MAP_WIDTH - 2;
		y = rand() % MAP_HEIGHT - 2;

		if (item[x][y] == 0) item[x][y] = 3;
		else i--;
	}*/
	
	//verify - for debug
	/*for (j = 0; j < row; j++) {
		for (k = 0; k < col; k++) {
			if (item[j][k] == 1) {
				count++;
			}
		}
	}*/

	//print
	for (j = 0; j < row; j++) {
		for (k = 0; k < col; k++) {
			if (item[j][k] != 0 && item[j][k] != 2) {
				gotoxy(j+1, k+4);
				printf("@");
			}
			else if (item[j][k] == 2) {
				gotoxy(j+1, k+4);
				printf("#");
			}
		}
	}

	//copy
	memmove(map_g, item, sizeof(item));
	memset(item, 0, sizeof(item));
}

void Endgame() {
	
}

/*TEST_BED
	-------------------------------------------------------------------------------

									  ==========
									 ||레벨선택||
									  ==========
																	◀|▶ |X|
		  -------------------------------------------------------------------
		  |                                                                 |
		  |     ▼                                                          |
		  |     |1학년   |     |2학년   |     |3학년   |     |4학년   |     |
		  |     |◆◇◇◇|     |◆◆◇◇|     |◆◆◆◇|     |◆◆◆◆|     |
		  |                                                                 |
		  |     ■설명                                                      |
		  |     |                                                           |
		  |     |                                                           |
		  |     |                                                           |
		  |                                                                 |
		  -------------------------------------------------------------------









	-------------------------------------------------------------------------------
	*/