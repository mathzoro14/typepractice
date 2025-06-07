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
	printf("\n정답입니다!\n");
	Beep(440, 500);
	Beep(554, 500);
	Beep(659, 500); //딩동댕
	Sleep(500);
}

void timeover_sound()
{
	printf("\n시간초과입니다.");
	Beep(880, 500); //땡
	Sleep(500);
}

void wrong_sound()
{
	printf("\n틀렸습니다.\n");
	Beep(880, 500); //땡
	Sleep(500);
}

void game_start(int d) 
{
	game_ready();
	int stage=d-1;
	char word[30] = {0}, input[30] = {0}, ch;
	int s_time = clock(), j = 0,cnt=0,score=0,problem_num=0, x=0;
	int time_limit, size, goal_score, time_bonus, problem_count;

	if (d == 1)
	{
		time_limit = EASY_TIME_LIMIT;
		size = EASY_SIZE;
		goal_score = EASY_GOAL;
		time_bonus = EASY_TIME_BONUS;
		problem_count = EASY_AND_NORMAL_COUNT;
	}

	else if (d == 2)
	{
		time_limit = NORMAL_TIME_LIMIT;
		size = NORMAL_SIZE;
		goal_score = NORMAL_GOAL;
		time_bonus = NORMAL_TIME_BONUS;
		problem_count = EASY_AND_NORMAL_COUNT;
	}

	else if (d == 3)
	{
		time_limit = HARD_TIME_LIMIT;
		size = HARD_SIZE;
		goal_score = HARD_GOAL;
		time_bonus = HARD_TIME_BONUS;
		problem_count = HARD_COUNT;
	}

	else
	{
		printf("잘못된 난이도입니다.\n");
		return;
	}

	printf("단어 수: %d/%d\n", problem_num+1,problem_count);
	show_string(word,d);
	printf("남은 시간: %d초\n", (time_limit - (clock() - s_time)) / 1000);


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
						corr_sound();
						cnt++;
						problem_num++;
						score += CORRECT + (((time_limit - (clock() - s_time)) / 1000) * time_bonus);
						if ((goal_score - score) >= 0)
							printf("단계: %d,맞춘 문제: %d, 남은 점수: %d", d, cnt, goal_score - score);
						else
							printf("단계: %d,맞춘 문제: %d,점수 조건은 클리어했습니다.", d, cnt);
						Sleep(1500);
						if (score >= goal_score) {
							printf("\n축하합니다. %d단계를 클리어 하셨습니다.\n", d);
							Sleep(1000);
							printf("잠시 후에 %d단계로 이어집니다.\n", d + 1);
							d++;
							system("cls");
							fflush(stdin);
							memset(input, 0, sizeof(input)); //타이머 구현을 위해 비우기
						}
						if (problem_num >= problem_count)
						{
							printf("\n정해진 문제 수 내에 깨지 못했습니다. 안타깝네요.\n");
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
						printf("단계: %d,맞춘 문제: %d, 남은 점수: %d", d, cnt, goal_score - score);
					if (problem_num >= problem_count)
					{
						printf("\n정해진 문제 수 내에 깨지 못했습니다. 안타깝네요.\n");
						Sleep(1000);
						x = 1;
					}
					Sleep(1000);
				}
				system("cls");
				memset(input, 0, sizeof(input));
				printf("단어 수: %d/%d\n", problem_num + 1, problem_count);
				show_string(word, d);
				s_time = clock();
				j = 0;
			}
			else
			{
				system("cls");
				printf("단어 수: %d/%d\n", problem_num + 1, problem_count);
				printf("%s\n", word);
				printf("남은 시간: %d초\n", (time_limit - (clock() - s_time)) / 1000);
				printf("%s", input);
				
			}
		}
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 27)
				break;
			if (j < size)
			{
				if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
				{
					printf("%c", ch);
					input[j] = ch;
					j++;
				}
			}
			if (ch == 8 && j > 0) //백스페이스에 해당
			{
				input[j] = '\0';
				j--;
				printf("\b \b");
			}
			if (ch == 8 && j == 0) //추가
			{
				input[j] = '\0';
				printf("\b \b");
			}
			if (ch == 13) //엔터키에 해당
				if (j >= size)
				{
					input[size] = 0;
					if (!strcmp(word, input))
					{
						corr_sound();
						cnt++;
						problem_num++;
						score += CORRECT + (((time_limit - (clock() - s_time)) / 1000) * time_bonus);
						if ((goal_score - score) >= 0)
							printf("단계: %d,맞춘 문제: %d, 남은 점수: %d", d, cnt, goal_score - score);
						else
							printf("단계: %d,맞춘 문제: %d,점수 조건은 클리어했습니다.", d, cnt);
						Sleep(1500);
						if (score >= goal_score)
						{
							printf("\n축하합니다. %d단계를 클리어 하셨습니다.\n", d);
							Sleep(1000);
							printf("잠시 후에 %d단계로 이어집니다.\n", d + 1);
							d++;
							system("cls");
							memset(input, 0, sizeof(input));
						}
						if (problem_num >= problem_count)
						{
							printf("\n정해진 문제 수 내에 깨지 못했습니다. 안타깝네요.\n");
							Sleep(1000);
							x = 1;
						}
					}
					else
					{
						wrong_sound();
						problem_num++;
						if ((goal_score - score) >= 0)
							printf("단계: %d,맞춘 문제: %d, 남은 점수: %d", d, cnt, goal_score - score);
						if (problem_num >= problem_count)
						{
							printf("\n정해진 문제 수 내에 깨지 못했습니다. 안타깝네요.\n");
							Sleep(1000);
							x = 1;
						}
						Sleep(1000);
					}
					system("cls");
					memset(input, 0, sizeof(input));
					fflush(stdin);
					printf("단어 수: %d/%d\n", problem_num + 1, problem_count);
					show_string(word, d);
					s_time = clock();
					j = 0;
				}
				else
					printf("\n글자수가 부족합니다.\n");
		}

		if (x == 1)
		{
			system("cls");
			break;
		}

		if(x ==0 && goal_score <= score)
		{
			system("cls");
			game_start(d + 1);
			break;
		}
	}

	return 0;
}
