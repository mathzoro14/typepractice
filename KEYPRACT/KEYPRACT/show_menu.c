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
	printf("게임 시작\n");
	y += 3;
	gotoxy(x, y);
	printf("게임 방법\n");
	y += 3;
	gotoxy(x, y);
	printf("종료하기\n");
	x -= 13;
	gotoxy(x, 27);
	printf("위, 아래 방향키: 메뉴 조작, 엔터: 확인\n");
}

void menu2()
{
	screen_deco();
	int x = 40, y = 10;
	gotoxy(x, y);
	printf("모드 선택: ");
	y = 15;
	gotoxy(x, y);
	printf("난이도 선택: ");
	y = 20;
	gotoxy(x, y);
	printf("시작 (여기로 조작하고 엔터 클릭)");
	gotoxy(5, 27);
	printf("위, 아래 방향키: 메뉴 조작, 좌, 우 방향키: 모드/난이도 변경");
}

void game_method()
{
	int x = 3, y = 3;
	screen_deco();
	gotoxy(x, y++);
	printf("타자게임 KEYPRAC 하는 법!\n");
	gotoxy(x, y++);
	printf("이 게임에는 두 가지 모드가 있습니다.\n");
	gotoxy(x, y++);
	printf("첫번째는 일반적인 타자게임할 때 생각날 법한 모드입니다.\n");
	gotoxy(x, y++);
	printf("단어당 제한시간이 걸려있고, 제한 시간 안에 단어를 입력해서 점수를 얻어야 합니다.\n");
	gotoxy(x, y++);
	printf("이 모드에서는 판정을 빠르게 하기 위해서 엔터를 쓰는 것이 좋고\n");
	gotoxy(x, y++);
	printf("제한 시간안에 입력하지 못하면 시간초과됩니다.\n");
	y += 1;
	gotoxy(x, y++);
	printf("그리고 각 난이도는 목표 점수를 넘기면 클리어가 되어지고\n");
	gotoxy(x, y++);
	printf("하드 이상부터는 무한 모드에 돌입됩니다.\n");
	y += 1;
	gotoxy(x, y++);
	printf("두 번째 모드는 디펜스 형식의 모드입니다.\n");
	gotoxy(x, y++);
	printf("이 모드에서는 단어들이 화면 왼쪽에서 나타나 오른쪽으로 이동하는데\n");
	gotoxy(x, y++);
	printf("이 단어들이 오른쪽에 완전히 도달하기 전에 단어를 입력해 소멸시켜야 합니다.\n");
	gotoxy(x, y++);
	printf("이러한 걸 3번 안 해서 목숨이 다 날아가면 게임 오버가 됩니다.\n");
	y += 1;
	gotoxy(x, y++);
	printf("이상 설명이었습니다. 즐거운 게임 즐기셨으면 좋겠습니다.\n");
	y += 1;
	gotoxy(x, y++);
	printf("기타 기능들: ");
	gotoxy(x, y++);
	printf("게임 중 ESC 키: 잠시 중지 및 돌아가기 옵션 제공");
	Sleep(1000);
	gotoxy(2, 25);
	printf("  < [엔터를 눌러서 돌아가기]\n");
}

int show_menu(int* difficulty)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int screen=0, x = 53, y = 14,num=0, num1=0; // 스크린 번호, x,y 좌표, 메뉴 선택, 모드 선택
	char ch, * difficulty_list[] = {"Easy", "Normal", "Hard", "INFINITE"}; //난이도 리스트
	char* mode_list[] = { "일반 모드", "디펜스 모드" }; //모드 리스트

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
						if (num >= 1) // 위로 이동
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
						if (num <= 1) // 아래로 이동
							num++;
						gotoxy(x, y + num * (3+screen*2));
						printf(">");
						break;
					}
					case 75: // 왼쪽 화살표
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

					case 77: //오른쪽 화살표
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
					printf("게임을 시작합니다. 잠시만 기다려주세요.");
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