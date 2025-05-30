#include "key.h"
void game_start(int d) 
{
	int stage=d-1;
	char word[30], input[30] = {'\0'}, ch;
	int s_time = clock(), j = 0,cnt=0,score=0;
	const int PASS_SCORE[3] = { 7000,10000,10000 }, SCORE_WEIGHT[3] = { 1500,3000,6000 };
	show_string(word,stage);
	printf("���� �ð�: %d��\n", (TIME_LIMIT - ((stage) * 1000) - (clock() - s_time)) / 1000);
	while (1)
	{
		if ((clock() - s_time) % 1000 == 0)
		{
			if (clock() - s_time >= TIME_LIMIT - (stage) * 1000) //�ð� ���ῡ ���� �ڵ����� �� ����ó��
			{
				if (j >= SIZE + (stage) * 2)
				{
					input[SIZE + (stage) * 2] = 0;
					if (!strcmp(word, input))
					{
						printf("\n�����Դϴ�!\n");
						Sleep(500);
						cnt++;
						score += (TIME_LIMIT - clock() + s_time) * SCORE_WEIGHT[stage] / 1000;
						if ((PASS_SCORE[stage] - score) >= 0)
							printf("�ܰ�: %d,���� ����: %d, ���� ����: %d", d, cnt, PASS_SCORE[stage] - score);
						else
							printf("�ܰ�: %d,���� ����: %d,���� ������ Ŭ�����߽��ϴ�.", d, cnt);
						Sleep(1500);
						if (cnt >= 10 && score > PASS_SCORE[stage]) {
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
							memset(input, 0, sizeof(input)); //Ÿ�̸� ������ ���� ����
							game_start(d);
						}
					}
				}
				else
				{
					printf("\n�ð��ʰ��Դϴ�.");
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
				printf("���� �ð�: %d��\n", (TIME_LIMIT - (stage) * 1000 - (clock() - s_time)) / 1000);
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
			if (ch == 8 && j > 0) //�齺���̽��� �ش�
			{
				input[j] = '\0';
				j--;
				printf("\b \b");
			}
			if (ch == 13) //����Ű�� �ش�
				if (j >= SIZE+(stage)*2)
				{
					input[SIZE+(stage)*2] = 0;
					if (!strcmp(word, input))
					{
						printf("\n�����Դϴ�!\n");
						Sleep(500);
						cnt++;
						score += (TIME_LIMIT - clock() + s_time) * SCORE_WEIGHT[stage] / 1000;
						if((PASS_SCORE[stage] - score)>=0)
							printf("�ܰ�: %d,���� ����: %d, ���� ����: %d", d, cnt, PASS_SCORE[stage] - score);
						else
							printf("�ܰ�: %d,���� ����: %d,���� ������ Ŭ�����߽��ϴ�.", d, cnt);
						Sleep(1500);
						if (cnt >= 10 && score > PASS_SCORE[stage]){
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
