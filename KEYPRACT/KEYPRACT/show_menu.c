#include "key.h"
int show_menu(int *difficulty)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int sel; //sel�� ����ڰ� �Է��� �޴� ��ȣ ����
	char ch;
	printf("===============\n");
	printf("[1]���� ����\n");
	printf("[2]���̵� ����\n");
	printf("[3]���� ���\n");
	printf("[4]������\n");
	printf("===============\n");
	printf("���� �� ");
	scanf("%d", &sel);
	switch (sel) {
	case 1:
	{
		printf("3�� �� ������ �����մϴ�.\n");
		for (int i = 0; i < 3; i++)
		{
			printf("%d", 3 - i);
			Sleep(1000);
			printf("\b \b");
		}
		system("cls");
		return 1; //main �Լ��� 1 ��ȯ �� ���� ����
		break;
	}
	case 2:
	{
		printf("���� ���̵�:%d\n", *difficulty);
		printf("================================\n");
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("[1]Easy   ");
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("[2]Normal   ");
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
		printf("[3]Hard\n");
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("================================\n");
		printf("���̵��� �����ϼ��� �� ");
		scanf("%d", difficulty); //difficulty �� ����
		system("cls");
		return 0; //main�Լ��� 0��ȯ �� �޴� �ٽ� ǥ��
		break;
	}
	case 3:
	{
		printf("~~~\n\n");
		printf("�޴��� ���ư����� y�� �Է��ϼ��� �� ");
		getchar();
		ch = getchar();
		if (ch == 'y') return 0;
		break;
	}
	case 4:
		return -1;
		break;
	}
}