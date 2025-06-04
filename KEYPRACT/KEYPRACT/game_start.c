#include "key.h"
void game_start(int d) 
{
	int stage=d-1;
	char word[30] = {0}, input[30] = {0}, ch;
	int s_time = clock(), j = 0,cnt=0,score=0;
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
						printf("\n정답입니다!\n");
						Sleep(500);
						cnt++;
						score += CORRECT + (((time_limit - (clock() - s_time)) / 1000) * time_bonus);
						if ((goal_score - score) >= 0)
							printf("단계: %d,맞춘 문제: %d, 남은 점수: %d", d, cnt, goal_score - score);
						else
							printf("단계: %d,맞춘 문제: %d,점수 조건은 클리어했습니다.", d, cnt);
						Sleep(1500);
						if (cnt >= problem_count && score > goal_score) {
							printf("\n축하합니다. %d단계를 클리어 하셨습니다.\n", d);
							Sleep(1000);
							printf("3초 뒤 %d단계를 시작합니다.\n", d + 1);
							d++;
							for (int i = 0; i < 3; i++)
							{
								printf("%d", 3 - i);
								Sleep(1000);
								printf("\b \b");
							}
							system("cls");
							fflush(stdin);
							memset(input, 0, sizeof(input)); //타이머 구현을 위해 비우기
							if (d < 3) game_start(d);
							else game_start_infinite();
						}
					}
				}
				else
				{
					printf("\n시간초과입니다.");
					Sleep(500);
					if ((goal_score - score) >= 0)
						printf("단계: %d,맞춘 문제: %d, 남은 점수: %d", d, cnt, goal_score - score);
					else
						printf("단계: %d,맞춘 문제: %d,점수 조건은 클리어했습니다.", d, cnt);
					Sleep(1500);
				}
				system("cls");
				memset(input, 0, sizeof(input));
				show_string(word, d);
				s_time = clock();
				j = 0;
			}
			else
			{
				system("cls");
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
						printf("\n정답입니다!\n");
						Sleep(500);
						cnt++;
						score += CORRECT + (((time_limit - (clock() - s_time))/ 1000)*time_bonus);
						if((goal_score - score)>=0)
							printf("단계: %d,맞춘 문제: %d, 남은 점수: %d", d, cnt, goal_score - score);
						else
							printf("단계: %d,맞춘 문제: %d,점수 조건은 클리어했습니다.", d, cnt);
						Sleep(1500);
						if (cnt >= problem_count && score > goal_score)
						{
							printf("\n축하합니다. %d단계를 클리어 하셨습니다.\n",d);
							Sleep(1000);
							printf("3초 뒤 %d단계를 시작합니다.\n", d + 1);
							d++;
							for (int i = 0; i < 3; i++)
							{
								printf("%d", 3 - i);
								Sleep(1000);
								printf("\b \b");
							}
							system("cls");
							memset(input, 0, sizeof(input));
							game_start(d);
						}
					}
					else
					{
						printf("\n틀렸습니다.\n");
						Sleep(500);
						if ((goal_score - score) >= 0)
							printf("단계: %d,맞춘 문제: %d, 남은 점수: %d", d, cnt, goal_score - score);
						else
							printf("단계: %d,맞춘 문제: %d,점수 조건은 클리어했습니다.", d, cnt);
						Sleep(1500);
					}
					system("cls");
					memset(input, 0, sizeof(input));
					fflush(stdin);
					show_string(word,d);
					s_time = clock();
					j = 0;
				}
		}

	}
}
