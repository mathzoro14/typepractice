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
		printf("INFINITE_MODE | ����: %d | ���� ��ȣ: %d | ����: %d/3\n", score, count_infinite + 1, fail);
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
				printf("INFINITE_MODE | ����: %d | ���� ��ȣ: %d | ����: %d/3\n", score, count_infinite + 1, fail);
				printf("%s", word);
				printf("���� �ð�: %d��\n", (time_limit - clock() + s_time) / 1000);
				printf("%s", input);
			}
			if (clock() - s_time >= time_limit)
			{
				if(!strcmp(word, input)) 
				{
					printf("\n�����Դϴ�!\n");
					score += CORRECT + ((time_limit - clock() + s_time) / 1000) * time_bonus;
					count_infinite++;
				}
				else 
				{
					printf("\n�ð� �ʰ�!\n");
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
						printf("\n����!\n");
						score += CORRECT + ((time_limit - clock() + s_time) / 1000) * time_bonus;
						count_infinite++;
					}
					else 
					{
						printf("\n����!\n");
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
			printf("���� ����!\n���� ����:%d\n", score);
			printf("���� �޴��� ���ư����� y�� ��������: ");
			ch = getchar();
			if (ch == 'y' || ch == 'Y') {
				system("cls");
				return 0;
			}
			else return -1;
		}
	}

}