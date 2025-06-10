#include "key.h"

void game_ready()
{
	screen_deco();
	gotoxy(57, 15);
	printf("Ready?");
	Sleep(1000);
	system("cls");
	screen_deco();
	gotoxy(57, 15);
	printf("Start!");
	Sleep(500);
	system("cls");
}

void corr_sound()
{
	gotoxy(30, 7);
	printf("정답입니다!");
	Beep(440, 500);
	Beep(554, 500);
	Beep(659, 500); //딩동댕
	Sleep(500);
}

void timeover_sound()
{
	gotoxy(30, 7);
	printf("시간초과입니다.");
	Beep(880, 500); //땡
	Sleep(500);
}

void wrong_sound()
{
	gotoxy(30, 7);
	printf("틀렸습니다.");
	Beep(880, 500); //땡
	Sleep(500);
}

void game_over_screen()
{
	system("cls");
	screen_deco();
	gotoxy(57, 15);
	printf("Game Over");
	Sleep(1500);
	system("cls");
}

void game_start(int d) 
{
	game_ready();
	int stage=d-1;
	char word[30] = {0}, input[30] = {0}, ch;
	int s_time = clock(), j = 0, score=0,problem_num=0, x=0;
	int time_limit, size, goal_score, time_bonus, problem_count;

	system("cls");
	screen_deco();
	gotoxy(2, 1);

	if (d == 1)
	{
		time_limit = EASY_TIME_LIMIT;
		size = EASY_SIZE;
		goal_score = EASY_GOAL;
		time_bonus = EASY_TIME_BONUS;
		problem_count = EASY_AND_NORMAL_COUNT;
		printf("난이도: Easy | 점수: %d | 목표 점수: %d | 단어 수: %d/%d", score, goal_score, problem_num + 1, problem_count);
	}

	else if (d == 2)
	{
		time_limit = NORMAL_TIME_LIMIT;
		size = NORMAL_SIZE;
		goal_score = NORMAL_GOAL;
		time_bonus = NORMAL_TIME_BONUS;
		problem_count = EASY_AND_NORMAL_COUNT;
		printf("난이도: Normal | 점수: %d | 목표 점수: %d | 단어 수: %d/%d", score, goal_score, problem_num + 1, problem_count);
	}

	else if (d == 3)
	{
		time_limit = HARD_TIME_LIMIT;
		size = HARD_SIZE;
		goal_score = HARD_GOAL;
		time_bonus = HARD_TIME_BONUS;
		problem_count = HARD_COUNT;
		printf("난이도: Hard | 점수: %d | 목표 점수: %d | 단어 수: %d/%d", score, goal_score, problem_num + 1, problem_count);
	}

	else
	{
		printf("잘못된 난이도입니다.\n");
		return;
	}

	show_string(word,d);
	gotoxy(2, 2);
	printf("남은 시간: %d초", (time_limit - (clock() - s_time)) / 1000);
	gotoxy(5, 5);


	while (1)
	{
		if ((clock() - s_time) % 1000 == 0)
		{
			if (clock() - s_time >= time_limit) //시간 종료에 따른 자동판정 후 정답처리
			{
				if (j >= size)
				{
					input[size] = 0;
					if (!strcmp(word, input))
					{
						score += CORRECT + (((time_limit - (clock() - s_time)) / 1000) * time_bonus);
						corr_sound();
						problem_num++;
						if ((goal_score - score) >= 0)
						{
							gotoxy(30, 7);
							printf("남은 점수: %d", goal_score - score);
						}
						Sleep(1500);
						if (score >= goal_score) {
							gotoxy(30, 7);
							printf("축하합니다. 이번 단계를 클리어 하셨습니다.");
							Sleep(1000);
							gotoxy(30, 8);
							printf("잠시 후에 다음 단계로 이어집니다.");
							d++;
							Sleep(1000);
							system("cls");
							fflush(stdin);
							memset(input, 0, sizeof(input)); //타이머 구현을 위해 비우기
						}
						if (problem_num >= problem_count)
						{
							gotoxy(30, 7);
							printf("정해진 문제 수 내에 깨지 못했습니다. 안타깝네요.");
							Sleep(1000);
							x = 1;
						}
					}
				}
				else
				{
					timeover_sound();
					problem_num++;
					if ((goal_score - score) >= 0)
					{
						gotoxy(30, 7);
						printf("남은 점수: %d", goal_score - score);
					}
					Sleep(1500);
					if (problem_num >= problem_count)
					{
						gotoxy(30, 7);
						printf("정해진 문제 수 내에 깨지 못했습니다. 안타깝네요.");
						Sleep(1000);
						x = 1;
					}
					Sleep(1000);
				}
				system("cls");
				memset(input, 0, sizeof(input));
				screen_deco();
				gotoxy(2, 1);
				if(d==1)
					printf("난이도: Easy | 점수: %d | 목표 점수: %d | 단어 수: %d/%d", score, goal_score, problem_num + 1, problem_count);
				if(d==2)
					printf("난이도: Normal | 점수: %d | 목표 점수: %d | 단어 수: %d/%d", score, goal_score, problem_num + 1, problem_count);
				if(d==3)
					printf("난이도: Hard | 점수: %d | 목표 점수: %d | 단어 수: %d/%d", score, goal_score, problem_num + 1, problem_count);
				show_string(word, d);
				s_time = clock();
				j = 0;
				gotoxy(2, 2);
				printf("남은 시간: %d초", (time_limit - (clock() - s_time)) / 1000);
				gotoxy(5, 5);
			}
			else
			{
				system("cls");
				screen_deco();
				gotoxy(2, 1);
				if (d == 1)
					printf("난이도: Easy | 점수: %d | 목표 점수: %d | 단어 수: %d/%d", score, goal_score, problem_num + 1, problem_count);
				if (d == 2)
					printf("난이도: Normal | 점수: %d | 목표 점수: %d | 단어 수: %d/%d", score, goal_score, problem_num + 1, problem_count);
				if (d == 3)
					printf("난이도: Hard | 점수: %d | 목표 점수: %d | 단어 수: %d/%d", score, goal_score, problem_num + 1, problem_count);
				gotoxy(5, 4);
				printf("%s", word);
				gotoxy(2, 2);
				printf("남은 시간: %d초", (time_limit - (clock() - s_time)) / 1000);
				gotoxy(5, 5);
				printf("%s", input);
				
			}
		}
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 27)
			{
				int game_result;
				int so_time = clock();
				game_result = game_pause(d);
				int sq_time = clock();
				if (game_result == 2 || game_result == 1)
					return 0;
				if (game_result == 0)
					s_time += 1000+(sq_time - so_time); //게임 재개시 시간 보정
			}
			if (j < size)
			{
				if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
				{
					printf("%c", ch);
					input[j] = ch;
					j++;
				}
			}
			if (ch == 8 && j >= 0) //백스페이스에 해당
			{
				if (j > 0)
					j--;
				input[j] = '\0';
				printf("\b \b");
			}
			if (ch == 13)
			{					//엔터키에 해당
				if (j >= size)
				{
					input[size] = 0;
					if (!strcmp(word, input))
					{
						score += CORRECT + (((time_limit - (clock() - s_time)) / 1000) * time_bonus);
						corr_sound();
						problem_num++;
						if ((goal_score - score) >= 0)
						{
							gotoxy(30, 7);
							printf("남은 점수: %d", goal_score - score);
						}
							
						Sleep(1500);
						if (score >= goal_score)
						{
							gotoxy(30, 7);
							printf("축하합니다. 이번 단계를 클리어 하셨습니다.");
							Sleep(1000);
							gotoxy(30, 8);
							printf("잠시 후에 다음 단계로 이어집니다.");
							d++;
							Sleep(1000);
							system("cls");
							memset(input, 0, sizeof(input));
						}
						if (problem_num >= problem_count)
						{
							gotoxy(30, 7);
							printf("정해진 문제 수 내에 깨지 못했습니다. 안타깝네요.");
							Sleep(1000);
							x = 1;
						}
					}
					else
					{
						wrong_sound();
						problem_num++;
						if ((goal_score - score) >= 0)
						{
							gotoxy(30, 7);
							printf("남은 점수: %d", goal_score - score);
						}
						Sleep(1500);
						if (problem_num >= problem_count)
						{
							gotoxy(30, 7);
							printf("정해진 문제 수 내에 깨지 못했습니다. 안타깝네요.");
							Sleep(1000);
							x = 1;
						}
						Sleep(1000);
					}
					system("cls");
					memset(input, 0, sizeof(input));
					fflush(stdin);
					system("cls");
					screen_deco();
					gotoxy(2, 1);
					if (d == 1)
						printf("난이도: Easy | 점수: %d | 목표 점수: %d | 단어 수: %d/%d", score, goal_score, problem_num + 1, problem_count);
					if (d == 2)
						printf("난이도: Normal | 점수: %d | 목표 점수: %d | 단어 수: %d/%d", score, goal_score, problem_num + 1, problem_count);
					if (d == 3)
						printf("난이도: Hard | 점수: %d | 목표 점수: %d | 단어 수: %d/%d", score, goal_score, problem_num + 1, problem_count);
					gotoxy(2, 2);
					printf("남은 시간: %d초", (time_limit - (clock() - s_time)) / 1000);
					show_string(word, d);
					gotoxy(5, 5);
					printf("%s", input);
					s_time = clock();
					j = 0;
				}
				else
				{
					gotoxy(30, 7);
					printf("글자수가 부족합니다.");
					gotoxy(5, 5);
				}
			}
		}

		if (x == 1)
		{
			game_over_screen();
			break;
		}

		if(x ==0 && goal_score <= score)
		{
			system("cls");
			if (d <= 3)
				game_start(d);
			else
				game_start_infinite();
			break;
		}
	}

	return 0;
}
