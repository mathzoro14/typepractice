#include "key.h"
int game_start_infinite()
{
	char word[30] = { 0 }, input[30] = { 0 }, ch;
	int s_time, j=0, fail = 0, score = 0, count_infinite = 0;
	int time_limit = INFINITE_TIME_LIMIT_1;
	int size = INFINITE_SIZE;
	int time_bonus = INFINITE_TIME_BONUS;
	while (1) {
		if (count_infinite < 8) time_limit = INFINITE_TIME_LIMIT_1;
		else if (count_infinite < 16) time_limit = INFINITE_TIME_LIMIT_2;
		else if (count_infinite < 24) time_limit = INFINITE_TIME_LIMIT_3;
		else if (count_infinite < 32) time_limit = INFINITE_TIME_LIMIT_4;
		else time_limit = INFINITE_TIME_LIMIT_5;
		
		system("cls");
		printf("INFINITE_MODE | 점수: %d | 문제 번호: %d | 실패: %d/3\n", score, count_infinite + 1, fail);
		show_string(word, 4);
		printf("\n");
		memset(input, 0, sizeof(input));
		j = 0;
		s_time = clock();
		while (1) 
		{
			if ((clock() - s_time) % 1000 == 0) 
			{
				system("cls");
				printf("INFINITE_MODE | 점수: %d | 문제 번호: %d | 실패: %d/3\n", score, count_infinite + 1, fail);
				printf("%s", word);
				printf("남은 시간: %d초\n", (time_limit - clock() + s_time) / 1000);
				printf("%s", input);
			}
			if (clock() - s_time >= time_limit)
			{
				if(!strcmp(word, input)) 
				{
					printf("\n정답입니다!\n");
					score += CORRECT + ((time_limit - clock() + s_time) / 1000) * time_bonus;
					count_infinite++;
				}
				else 
				{
					printf("\n시간 초과!\n");
					fail++;
				}
				Sleep(1000);
				break;
			}
			if (_kbhit()) 
			{
				ch = _getch();
				if (ch == 27)
				{
					return -1;
					break;
				}
				if (ch == 8 && j > 0) 
				{
					*(input + --j) = '\0';
					printf("\b \b");
					continue;
				}
				if (ch == 13 && j == size) 
				{
					*(input + size) = '\0';
					if (!strcmp(word, input)) 
					{
						printf("\n정답!\n");
						score += CORRECT + ((time_limit - clock() + s_time) / 1000) * time_bonus;
						count_infinite++;
					}
					else 
					{
						printf("\n오답!\n");
						fail++;
					}
					Sleep(1000);
					break;
				}
				if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
				{
					if (j < size)
					{
						*(input + j) = ch;
						printf("%c", ch);
						j++;
					}
				}
			}
		}
		if (fail > 3) 
		{
			system("cls");
			printf("게임 오버!\n최종 점수:%d\n", score);
			printf("메인 메뉴로 돌아가려면 y를 누르세요: ");
			ch = getchar();
			if (ch == 'y' || ch == 'Y') {
				system("cls");
				return 0;
			}
			else return -1;
		}
	}

}