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
		printf("�߸��� ���̵��Դϴ�.\n");
		return;
	}

	show_string(word,d);
	printf("���� �ð�: %d��\n", (time_limit - (clock() - s_time)) / 1000);


	while (1)
	{
		if ((clock() - s_time) % 1000 == 0)
		{
			if (clock() - s_time >= time_limit) //�ð� ���ῡ ���� �ڵ����� �� ����ó��
			{
				if (j >= size)
				{
					input[size] = 0;
					if (!strcmp(word, input))
					{
						printf("\n�����Դϴ�!\n");
						Sleep(500);
						cnt++;
						score += CORRECT + (((time_limit - (clock() - s_time)) / 1000) * time_bonus);
						if ((goal_score - score) >= 0)
							printf("�ܰ�: %d,���� ����: %d, ���� ����: %d", d, cnt, goal_score - score);
						else
							printf("�ܰ�: %d,���� ����: %d,���� ������ Ŭ�����߽��ϴ�.", d, cnt);
						Sleep(1500);
						if (cnt >= problem_count && score > goal_score) {
							printf("\n�����մϴ�. %d�ܰ踦 Ŭ���� �ϼ̽��ϴ�.\n", d);
							Sleep(1000);
							printf("3�� �� %d�ܰ踦 �����մϴ�.\n", d + 1);
							d++;
							for (int i = 0; i < 3; i++)
							{
								printf("%d", 3 - i);
								Sleep(1000);
								printf("\b \b");
							}
							system("cls");
							fflush(stdin);
							memset(input, 0, sizeof(input)); //Ÿ�̸� ������ ���� ����
							if (d < 3) game_start(d);
							else game_start_infinite();
						}
					}
				}
				else
				{
					printf("\n�ð��ʰ��Դϴ�.");
					Sleep(500);
					if ((goal_score - score) >= 0)
						printf("�ܰ�: %d,���� ����: %d, ���� ����: %d", d, cnt, goal_score - score);
					else
						printf("�ܰ�: %d,���� ����: %d,���� ������ Ŭ�����߽��ϴ�.", d, cnt);
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
				printf("���� �ð�: %d��\n", (time_limit - (clock() - s_time)) / 1000);
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
			if (ch == 8 && j > 0) //�齺���̽��� �ش�
			{
				input[j] = '\0';
				j--;
				printf("\b \b");
			}
			if (ch == 8 && j == 0) //�߰�
			{
				input[j] = '\0';
				printf("\b \b");
			}
			if (ch == 13) //����Ű�� �ش�
				if (j >= size)
				{
					input[size] = 0;
					if (!strcmp(word, input))
					{
						printf("\n�����Դϴ�!\n");
						Sleep(500);
						cnt++;
						score += CORRECT + (((time_limit - (clock() - s_time))/ 1000)*time_bonus);
						if((goal_score - score)>=0)
							printf("�ܰ�: %d,���� ����: %d, ���� ����: %d", d, cnt, goal_score - score);
						else
							printf("�ܰ�: %d,���� ����: %d,���� ������ Ŭ�����߽��ϴ�.", d, cnt);
						Sleep(1500);
						if (cnt >= problem_count && score > goal_score)
						{
							printf("\n�����մϴ�. %d�ܰ踦 Ŭ���� �ϼ̽��ϴ�.\n",d);
							Sleep(1000);
							printf("3�� �� %d�ܰ踦 �����մϴ�.\n", d + 1);
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
						printf("\nƲ�Ƚ��ϴ�.\n");
						Sleep(500);
						if ((goal_score - score) >= 0)
							printf("�ܰ�: %d,���� ����: %d, ���� ����: %d", d, cnt, goal_score - score);
						else
							printf("�ܰ�: %d,���� ����: %d,���� ������ Ŭ�����߽��ϴ�.", d, cnt);
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
