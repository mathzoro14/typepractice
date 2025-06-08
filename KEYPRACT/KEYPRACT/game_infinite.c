#include "key.h"

int game_pause(int d)
{
	int num = 0;
	system("cls");
	screen_deco();
	gotoxy(50, 10);
	printf("��� �ϱ�");
	gotoxy(50, 13);
	printf("�ٽ� �ϱ�");
	gotoxy(50, 16);
	printf("������");

	gotoxy(2, 2);
	printf("����: Ȯ��, ��, �Ʒ� ����Ű: �̵�");
	gotoxy(48, 10);
	printf(">");
	while (1)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 72) // �� ����Ű
			{
				if (num > 0)
				{
					gotoxy(48, 10 + num * 3);
					printf(" ");
					num--;
					gotoxy(48, 10 + num * 3);
					printf(">");
				}
			}
			else if (ch == 80) // �Ʒ� ����Ű
			{
				if (num < 2)
				{
					gotoxy(48, 10 + num * 3);
					printf(" ");
					num++;
					gotoxy(48, 10 + num * 3);
					printf(">");
				}
			}
			else if (ch == 13) // Enter Ű
			{
				if (num == 0)
					return 0;
				
				else if (num == 1)
				{
					if (d == 4)
					{
						system("cls");
						game_start_infinite();
						return 1;
					}
						
					else if (d == 5)
					{
						system("cls");
						tower_defence();
						return 1;
					}
					else
					{
						system("cls");
						game_start(d);
						return 1;
					}
				}
				else if (num == 2)
				{
					system("cls");
					return 2;
				}
			}
		}
		Sleep(100);
	}
}

int game_start_infinite()
{
	game_ready();
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
		screen_deco();
		gotoxy(2, 1);
		printf("INFINITE_MODE | ����: %d | ���� ��ȣ: %d | ����: %d/3", score, count_infinite + 1, fail);
		show_string(word, 4);
		memset(input, 0, sizeof(input));
		j = 0;
		s_time = clock();
		while (1) 
		{
			if ((clock() - s_time) % 1000 == 0) 
			{
				system("cls");
				screen_deco();
				gotoxy(2, 1);
				printf("INFINITE_MODE | ����: %d | ���� ��ȣ: %d | ����: %d/3", score, count_infinite + 1, fail);
				gotoxy(2, 2);
				printf("���� �ð�: %d��", (time_limit - clock() + s_time) / 1000);
				gotoxy(5, 4);
				printf("%s", word);
				gotoxy(5, 5);
				printf("%s", input);
			}
			if (clock() - s_time >= time_limit)
			{
				if(!strcmp(word, input)) 
				{
					score += CORRECT + ((time_limit - clock() + s_time) / 1000) * time_bonus;
					count_infinite++;
					corr_sound();
				}
				else 
				{
					fail++;
					count_infinite++;
					timeover_sound();
				}
				Sleep(1000);
				break;
			}
			if (_kbhit()) 
			{
				ch = _getch();
				if (ch == 27)
				{
					int game_result;
					int so_time = clock();
					game_result = game_pause(4);
					int sq_time = clock();
					if (game_result == 2 || game_result == 1)
						return 0;
					if(game_result == 0)
						s_time += 1000+(sq_time - so_time);
				}
				if (ch == 8 && j > 0) 
				{
					*(input + --j) = '\0';
					printf("\b \b");
					continue;
				}
				if (ch == 13) 
				{
					if (j == size)
					{
						*(input + size) = '\0';
						if (!strcmp(word, input)) 
						{
							score += CORRECT + ((time_limit - clock() + s_time) / 1000) * time_bonus;
							count_infinite++;
							corr_sound();
						}
						else 
						{
							fail++;
							count_infinite++;
							wrong_sound();
						}
						Sleep(1000);
						break;
					}
					else
					{
						gotoxy(30, 7);
						printf("���ڼ��� �����մϴ�.");
					}
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
		if (fail >= 3) 
		{
			gotoxy(30, 7);
			printf("���� ����! ���� ����: %d", score);
			Sleep(2000);
			system("cls");
			
			game_over_screen();
			return 0;
		}
	}

}