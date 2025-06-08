#include "key.h"

void gotoxy(int x, int y) 
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void screen_deco()
{
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	for (int x = 0;x < 27;x++)
		printf("*                                                                                                                      *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
}

void menu1()
{
	int x = 35, y = 2;
	screen_deco();
	gotoxy(x, y++);
	printf("@   @  @@@@@   @   @   @@@@   @@@@    @@@    @@@\n");
	gotoxy(x, y++);
	printf("@  @   @       @   @   @   @  @   @  @   @  @   @\n");
	gotoxy(x, y++);
	printf("@ @    @        @ @    @   @  @   @  @   @  @\n");
	gotoxy(x, y++);
	printf("@@     @@@@@     @     @@@@   @@@@   @@@@@  @\n");
	gotoxy(x, y++);
	printf("@ @    @         @     @      @ @    @   @  @\n");
	gotoxy(x, y++);
	printf("@  @   @         @     @      @  @   @   @  @   @\n");
	gotoxy(x, y++);
	printf("@   @  @@@@@     @     @      @   @  @   @   @@@");
	x += 20;
	y += 5;
	gotoxy(x, y);
	printf("���� ����\n");
	y += 3;
	gotoxy(x, y);
	printf("���� ���\n");
	y += 3;
	gotoxy(x, y);
	printf("�����ϱ�\n");
	x -= 13;
	gotoxy(x, 27);
	printf("��, �Ʒ� ����Ű: �޴� ����, ����: Ȯ��\n");
}

void menu2()
{
	screen_deco();
	int x = 40, y = 10;
	gotoxy(x, y);
	printf("��� ����: ");
	y = 15;
	gotoxy(x, y);
	printf("���̵� ����: ");
	y = 20;
	gotoxy(x, y);
	printf("���� (����� �����ϰ� ���� Ŭ��)");
	gotoxy(5, 27);
	printf("��, �Ʒ� ����Ű: �޴� ����, ��, �� ����Ű: ���/���̵� ����");
}

void game_method()
{
	int x = 3, y = 3;
	screen_deco();
	gotoxy(x, y++);
	printf("Ÿ�ڰ��� KEYPRAC �ϴ� ��!\n");
	gotoxy(x, y++);
	printf("�� ���ӿ��� �� ���� ��尡 �ֽ��ϴ�.\n");
	gotoxy(x, y++);
	printf("ù��°�� �Ϲ����� Ÿ�ڰ����� �� ������ ���� ����Դϴ�.\n");
	gotoxy(x, y++);
	printf("�ܾ�� ���ѽð��� �ɷ��ְ�, ���� �ð� �ȿ� �ܾ �Է��ؼ� ������ ���� �մϴ�.\n");
	gotoxy(x, y++);
	printf("�� ��忡���� ������ ������ �ϱ� ���ؼ� ���͸� ���� ���� ����\n");
	gotoxy(x, y++);
	printf("���� �ð��ȿ� �Է����� ���ϸ� �ð��ʰ��˴ϴ�.\n");
	y += 1;
	gotoxy(x, y++);
	printf("�׸��� �� ���̵��� ��ǥ ������ �ѱ�� Ŭ��� �Ǿ�����\n");
	gotoxy(x, y++);
	printf("�ϵ� �̻���ʹ� ���� ��忡 ���Ե˴ϴ�.\n");
	y += 1;
	gotoxy(x, y++);
	printf("�� ��° ���� ���潺 ������ ����Դϴ�.\n");
	gotoxy(x, y++);
	printf("�� ��忡���� �ܾ���� ȭ�� ���ʿ��� ��Ÿ�� ���������� �̵��ϴµ�\n");
	gotoxy(x, y++);
	printf("�� �ܾ���� �����ʿ� ������ �����ϱ� ���� �ܾ �Է��� �Ҹ���Ѿ� �մϴ�.\n");
	gotoxy(x, y++);
	printf("�̷��� �� 3�� �� �ؼ� ����� �� ���ư��� ���� ������ �˴ϴ�.\n");
	y += 1;
	gotoxy(x, y++);
	printf("�̻� �����̾����ϴ�. ��ſ� ���� �������� ���ڽ��ϴ�.\n");
	y += 1;
	gotoxy(x, y++);
	printf("��Ÿ ��ɵ�: ");
	gotoxy(x, y++);
	printf("���� �� ESC Ű: ��� ���� �� ���ư��� �ɼ� ����");
	Sleep(1000);
	gotoxy(2, 25);
	printf("  < [���͸� ������ ���ư���]\n");
}

int show_menu(int* difficulty)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int screen=0, x = 53, y = 14,num=0, num1=0; // ��ũ�� ��ȣ, x,y ��ǥ, �޴� ����, ��� ����
	char ch, * difficulty_list[] = {"Easy", "Normal", "Hard", "INFINITE"}; //���̵� ����Ʈ
	char* mode_list[] = { "�Ϲ� ���", "���潺 ���" }; //��� ����Ʈ

	num = 0;
	num1 = 0;
	screen = 0;
	x = 53;
	y = 14;
	menu1();
	gotoxy(x, y + num * 3);
	printf(">");
	while (1)
	{
		if (_kbhit())
		{
			printf("\b ");
			ch = _getch();
			if (ch == 27)
				break;
			if (ch == 0 || ch == -32)
			{
				ch = _getch();
				switch (ch)
				{
					case 72:
					{
						if (screen == 1)
						{
							if (num == 2)
							{
								gotoxy(57, 15);
								if (num1 == 0)
								{
									switch (*difficulty)
									{
									case 1:
										SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
										break;
									case 2:
										SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
										break;
									case 3:
										SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
										break;
									case 4:
										SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
										break;
									}

									printf("< [%s] >", difficulty_list[*difficulty - 1]);
									SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
								}
								else
									printf("< [-] >                 ");
							}
							if (num == 1)
							{
								gotoxy(57, 15);
								if (num1 == 0)
								{
									switch (*difficulty)
									{
									case 1:
										SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
										break;
									case 2:
										SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
										break;
									case 3:
										SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
										break;
									case 4:
										SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
										break;
									}

									printf("  [%s]  ", difficulty_list[*difficulty - 1]);
									SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
								}
								else
									printf("  [-]                   ");
								if(num1 == 1)
									SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
								gotoxy(53, 10);
								printf("< [%s] >", mode_list[num1]);
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

							}
						}
						if (num >= 1) // ���� �̵�
							num--;
						gotoxy(x, y + num * (3+screen*2));
						printf(">");
						break;
					}
					case 80:
					{
						if (screen == 1)
						{
							if (num == 0)
							{
								if(num1 == 1)
									SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
								gotoxy(53, 10 + num * 5);
								printf("  [%s]    ", mode_list[num1]);
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
								gotoxy(57, 15);
								if (num1 == 0)
								{
									switch (*difficulty)
									{
									case 1:
										SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
										break;
									case 2:
										SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
										break;
									case 3:
										SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
										break;
									case 4:
										SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
										break;
									}

									printf("< [%s] >", difficulty_list[*difficulty - 1]);
									SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
								}
								else
									printf("< [-] >                 ");
							}
							if (num == 1)
							{
								gotoxy(57, 10 + num * 5);
								if (num1 == 0)
								{
									switch (*difficulty)
									{
									case 1:
										SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
										break;
									case 2:
										SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
										break;
									case 3:
										SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
										break;
									case 4:
										SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
										break;
									}

									printf("  [%s]  ", difficulty_list[*difficulty - 1]);
									SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
								}
								else
									printf("  [-]                   ");
							}
						}
						if (num <= 1) // �Ʒ��� �̵�
							num++;
						gotoxy(x, y + num * (3+screen*2));
						printf(">");
						break;
					}
					case 75: // ���� ȭ��ǥ
					{
						if (screen == 1)
						{
							if (num == 0 && num1 >= 1)
							{
								num1--;
								gotoxy(53, 10);
								printf("< [%s] >  ", mode_list[num1]);
								switch (*difficulty)
								{
								case 1:
									SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
									break;
								case 2:
									SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
									break;
								case 3:
									SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
									break;
								case 4:
									SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
									break;
								}

								gotoxy(57, 15);
								printf("  [%s]  ", difficulty_list[*difficulty - 1]);
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							}
							if (num == 1 && *difficulty >=2 && num1 == 0)
							{
								*difficulty -= 1;
								switch (*difficulty)
								{
								case 1:
									SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
									break;
								case 2:
									SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
									break;
								case 3:
									SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
									break;
								case 4:
									SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
									break;
								}

								gotoxy(57, 15);
								printf("< [%s] >     ", difficulty_list[*difficulty - 1]);
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							}
							gotoxy(x, y + num * (3 + screen * 2));
							printf(">");
						}
						break;
					}

					case 77: //������ ȭ��ǥ
					{
						if (screen == 1)
						{
							if (num == 0 && num1 <= 0)
							{
								num1++;
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_BLUE);
								gotoxy(53, 10);
								printf("< [%s] >  ", mode_list[num1]);
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
								gotoxy(57, 15);
								printf("  [-]                   ");
							}
							if (num == 1 && *difficulty <= 3 && num1 == 0)
							{
								*difficulty += 1;
								switch (*difficulty)
								{
								case 1:
									SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
									break;
								case 2:
									SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
									break;
								case 3:
									SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
									break;
								case 4:
									SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
									break;
								}

								gotoxy(57, 15);
								printf("< [%s] >  ", difficulty_list[*difficulty - 1]);
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							}
							gotoxy(x, y + num * (3 + screen * 2));
							printf(">");
						}
						break;
					}
				}
			}
			if (ch == 13)
			{
				if (screen == 0)
				{
					switch (num)
					{
						case 0:
							system("cls");
							menu2();
							x = 38;
							y = 10;
							screen = 1;
							gotoxy(53, 10);
							printf("< [%s] >", mode_list[num1]);
							gotoxy(57, 15);
							SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
							printf("[%s]", difficulty_list[*difficulty - 1]);
							SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
							gotoxy(x, y + num * (3 + screen * 2));
							printf(">");
							break;
						case 1:
							system("cls");
							game_method();
							screen = 2;
							break;
						case 2:
							system("cls");
							return -1;
							break;
					}
				}
				else if (screen == 2)
				{
					system("cls");
					menu1();
					num = 0;
					screen = 0;
					gotoxy(x, y + num * (3+screen*2));
					printf(">");
				}
				else if (screen == 1 && num==2)
				{
					system("cls");
					screen_deco();
					gotoxy(41, 15);
					printf("������ �����մϴ�. ��ø� ��ٷ��ּ���.");
					if (num1 == 1)
						*difficulty = 5;
					Sleep(1000);
					system("cls");
					return 1;
					break;
				}
			}
		}
	}
}