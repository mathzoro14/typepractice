#include "key.h"
void game_start(int d) 
{
	int stage=d-1;
	char word[30], input[30] = {'\0'}, ch;
	int s_time = clock(), j = 0,cnt=0,score=0;
	const int PASS_SCORE[3] = { 7000,10000,10000 }, SCORE_WEIGHT[3] = { 1500,3000,6000 };
	show_string(word,stage);
	printf("남은 시간: %d초\n", (TIME_LIMIT - ((stage) * 1000) - (clock() - s_time)) / 1000);
	while (1)
	{
		if ((clock() - s_time) % 1000 == 0)
		{
			if (clock() - s_time >= TIME_LIMIT - (stage) * 1000) //시간 종료에 따른 자동판정 후 정답처리
			{
				if (j >= SIZE + (stage) * 2)
				{
					input[SIZE + (stage) * 2] = 0;
					if (!strcmp(word, input))
					{
						printf("\n정답입니다!\n");
						Sleep(500);
						cnt++;
						score += (TIME_LIMIT - clock() + s_time) * SCORE_WEIGHT[stage] / 1000;
						if ((PASS_SCORE[stage] - score) >= 0)
							printf("단계: %d,맞춘 문제: %d, 남은 점수: %d", d, cnt, PASS_SCORE[stage] - score);
						else
							printf("단계: %d,맞춘 문제: %d,점수 조건은 클리어했습니다.", d, cnt);
						Sleep(1500);
						if (cnt >= 10 && score > PASS_SCORE[stage]) {
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
							memset(input, 0, sizeof(input)); //타이머 구현을 위해 비우기
							game_start(d);
						}
					}
				}
				else
				{
					printf("\n시간초과입니다.");
					Sleep(500);
				}
				system("cls");
				memset(input, 0, sizeof(input));
				show_string(word, stage);
				s_time = clock();
				j = 0;
			}
			else
			{
				system("cls");
				printf("%s\n", word);
				printf("남은 시간: %d초\n", (TIME_LIMIT - (stage) * 1000 - (clock() - s_time)) / 1000);
				printf("%s", input);
				
			}
		}
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 27)
				break;
			if (j < SIZE + (stage) * 2)
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
			if (ch == 13) //엔터키에 해당
				if (j >= SIZE+(stage)*2)
				{
					input[SIZE+(stage)*2] = 0;
					if (!strcmp(word, input))
					{
						printf("\n정답입니다!\n");
						Sleep(500);
						cnt++;
						score += (TIME_LIMIT - clock() + s_time) * SCORE_WEIGHT[stage] / 1000;
						if((PASS_SCORE[stage] - score)>=0)
							printf("단계: %d,맞춘 문제: %d, 남은 점수: %d", d, cnt, PASS_SCORE[stage] - score);
						else
							printf("단계: %d,맞춘 문제: %d,점수 조건은 클리어했습니다.", d, cnt);
						Sleep(1500);
						if (cnt >= 10 && score > PASS_SCORE[stage]){
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
					}
					system("cls");
					memset(input, 0, sizeof(input));
					show_string(word,stage);
					s_time = clock();
					j = 0;
				}
		}

	}
}
