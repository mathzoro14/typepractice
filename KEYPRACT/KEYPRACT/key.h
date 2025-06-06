#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

//시간 제한
#define EASY_TIME_LIMIT 7000
#define NORMAL_TIME_LIMIT 6000
#define HARD_TIME_LIMIT 6000
#define INFINITE_TIME_LIMIT_1 6000
#define INFINITE_TIME_LIMIT_2 5000
#define INFINITE_TIME_LIMIT_3 4500
#define INFINITE_TIME_LIMIT_4 4000
#define INFINITE_TIME_LIMIT_5 3000

//글자 수
#define EASY_SIZE 5
#define NORMAL_SIZE 7
#define HARD_SIZE 7
#define INFINITE_SIZE 7

//클리어 기준 점수
#define EASY_GOAL 8000
#define NORMAL_GOAL 9000
#define HARD_GOAL 12000


//정답 시 점수
#define CORRECT 1000
#define EASY_TIME_BONUS 100
#define NORMAL_TIME_BONUS 500
#define HARD_TIME_BONUS 1000
#define INFINITE_TIME_BONUS 1000

//문제 수
#define EASY_AND_NORMAL_COUNT 10
#define HARD_COUNT 15

//타워 디펜스 용
#define END 10000 // wave time
#define UPDATETIME 100 //1회 업데이트 시간
#define LETTER 120 //화면 끝까지 채우는 데 필요한 글자 수
#define TRACK 3 //출력 트랙 수

//함수 선언부
void show_string(char *p,int s);
int show_menu(int* p);
void game_start(int d);
int game_start_infinite();
void gotoxy(int x, int y);
void tower_deffence();