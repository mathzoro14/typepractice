#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

//�ð� ����
#define EASY_TIME_LIMIT 7000
#define NORMAL_TIME_LIMIT 6000
#define HARD_TIME_LIMIT 6000
#define INFINITE_TIME_LIMIT_1 6000
#define INFINITE_TIME_LIMIT_2 5000
#define INFINITE_TIME_LIMIT_3 4500
#define INFINITE_TIME_LIMIT_4 4000
#define INFINITE_TIME_LIMIT_5 3000

//���� ��
#define EASY_SIZE 5
#define NORMAL_SIZE 7
#define HARD_SIZE 7
#define INFINITE_SIZE 7

//Ŭ���� ���� ����
#define EASY_GOAL 8000
#define NORMAL_GOAL 9000
#define HARD_GOAL 12000


//���� �� ����
#define CORRECT 1000
#define EASY_TIME_BONUS 100
#define NORMAL_TIME_BONUS 500
#define HARD_TIME_BONUS 1000
#define INFINITE_TIME_BONUS 1000

//���� ��
#define EASY_AND_NORMAL_COUNT 10
#define HARD_COUNT 15

//Ÿ�� ���潺 ��
#define END 10000 // wave time
#define UPDATETIME 100 //1ȸ ������Ʈ �ð�
#define LETTER 120 //ȭ�� ������ ä��� �� �ʿ��� ���� ��
#define TRACK 3 //��� Ʈ�� ��

//�Լ� �����
void show_string(char *p,int s);
int show_menu(int* p);
void game_start(int d);
int game_start_infinite();
void gotoxy(int x, int y);
void tower_deffence();