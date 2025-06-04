#include "key.h"
int show_menu(int* difficulty)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int sel; //sel에 사용자가 입력한 메뉴 번호 저장
	char ch, * difficulty_list[] = {"Easy", "Normal", "Hard", "INFINITE"}; //난이도 리스트
	while (1)
	{
		printf("현재 난이도: %s\n", difficulty_list[*difficulty-1]);
		printf("===============\n");
		printf("[1]게임 시작\n");
		printf("[2]난이도 설정\n");
		printf("[3]게임 방법\n");
		printf("[4]끝내기\n");
		printf("===============\n");
		printf("선택 ▶ ");
		scanf("%d", &sel);
		getchar();
		switch (sel)
		{
			case 1:
			{
				printf("3초 뒤 게임을 시작합니다.\n");
				for (int i = 0; i < 3; i++)
				{
					printf("%d", 3 - i);
					Sleep(1000);
					printf("\b \b");
				}
				system("cls");
				return 1; //main 함수에 1 반환 시 게임 시작
				break;
			}
			case 2:
			{
				printf("현재 난이도:%s\n", difficulty_list[*difficulty-1]);
				printf("================================\n");
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("[1]Easy   ");
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				printf("[2]Normal   ");
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("[3]Hard   ");
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				printf("[4]INFINITE\n");
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				printf("================================\n");
				printf("난이도를 선택하세요 ▶ ");
				scanf("%d", difficulty); //difficulty 값 수정
				system("cls");
				return 0; //main함수에 0반환 시 메뉴 다시 표시
				break;
			}
			case 3:
			{
				printf("~~~\n\n");
				printf("메뉴로 돌아가려면 y를 입력하세요 ▶ ");
				while ((ch = getchar()) == '\n');
				if (ch == 'y')
				{
					system("cls");
					return 0;
				}
				break;
			}
			case 4:
				return -1;
				break;
			default:
				printf("잘못된 입력입니다.\n");
				Sleep(1000);
				system("cls");
				return 0;
		}
		if (sel != 3)
			break;
	}
	
}