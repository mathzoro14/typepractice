#include "key.h"

typedef struct line {
	int cooltime, last_generate_time;
	float speed;
}LINE;

typedef struct node {
	int y;
	float x;
	char word[15];
	struct node* p;
}LIST;

void delete_node(LIST* ppre, LIST* ptr) //free!
{
	if (ppre != NULL)
		ppre->p = ptr->p;
	free(ptr);
}

void update(LIST* ppre, LIST* p, LINE l[],int *life) //���� ȣ�� : (NULL, head, l)
{
	if (p->x >= LETTER - 6)
	{
		delete_node(ppre, p);
		(*life)--;
	}
	else
	{
		gotoxy((int)((p->x)+1), p->y+1);
		printf("%s", p->word);
		gotoxy(8, 5);
		p->x += l[p->y].speed;
		if (p->p != NULL)
			update(p, p->p, l,life);
	}


}

char* last(LIST* p)
{
	if (p->p == NULL)
		return p->word;
	return last(p->p);
}

LIST* generate(LIST* head) //�����Ҵ��� ��, p�� ���� head ��
{
	LIST* pnew = (LIST*)malloc(sizeof(LIST));
	pnew->p = head;
	int size = rand() % 3 + 3; //4~6
	for (int i = 0; i < size; i++)
	{
		if (rand() % 2 == 0)
			pnew->word[i] = 'A' + rand() % 26; // Lowercase letters
		else
			pnew->word[i] = 'a' + rand() % 26; // Uppercase letters
	}
	pnew->word[size] = '\0';
	return pnew;
}

// ���� : ������ ���ڿ��� ������ ������ ��� �����
void cmp_all(LIST* ppre, LIST* ptr, char ar[])
{
	if (ptr == NULL)
		return;
	if (!strcmp(ar, ptr->word))
	{
		LIST* aa = ptr->p;
		delete_node(ppre, ptr);
		cmp_all(ppre, aa, ar);
		return;
	}
	gotoxy(1, 5);
	gotoxy(1, 4);
	cmp_all(ptr, ptr->p, ar);

}

void clear(int wave)
{
	system("cls");
	screen_deco();
	gotoxy(43, 15);
	printf("clear! wave %d will start soon.", wave);
	Sleep(2000);

	system("cls");
	printf("\n\n\n");
	for (int i = 0; i < LETTER; i++)
		printf("-");
	printf("\n");
}
int count_node(LIST* head)
{
	if (head->p != NULL)
		return count_node(head->p) + 1;
	return 1;
}

void tower_defence() 
{
	game_ready();
	int wave = 1, sttime = clock(), last_update_time = clock(),life=3;
	int j = 0;
	char ch, input[20] = { 0 };
	LINE l[TRACK];
	for (int i = 0; i < TRACK; i++)
	{
		l[i].last_generate_time = clock();
		l[i].cooltime = 1000 * i;
		l[i].speed = 3+wave/5;
	}
	l[0].cooltime = 5000;
	LIST* head = generate(NULL);
	head->y = 0;
	head->x = 0;
	update(NULL, head, l,&life);
	gotoxy(2, 5);
	printf("�Է�:");
	while (1) {
		gotoxy(8, 5);
		printf("%s", input);
		gotoxy(8, 5);
		if (life <= 0)
		{
			system("cls");
			game_over_screen();
			return;
		}
		if (END < clock() - sttime)
		{
			clear(++wave);
			for (int i = 0; i < TRACK; i++)
			{
				l[i].last_generate_time = clock();
				l[i].cooltime = 3000 * i + rand() % 2000;
				l[i].speed = 3+wave/5;
			}
			//1�� ��� ����
			head = generate(NULL);
			head->y = 0;
			head->x = 0;
			update(NULL, head, l,&life);
			sttime = clock();

			//�Է� ���� �ʱ�ȭ
			memset(input, 0, sizeof(input));
			for (int i = 0; i < j - 1; i++)
				printf("\b");
			j = 0;
			fflush(stdin);

		}
		if (UPDATETIME < clock() - last_update_time)
		{
			system("cls");
			screen_deco();
			gotoxy(2, 5);
			printf("�Է�:");
			gotoxy(1, 4);
			for (int i = 1; i < LETTER - 1; i++)
			{
				if (i == LETTER - 6)
					printf("O");
				else
					printf("-");
			}

			gotoxy(100, 19);
			printf("Wave: %d", wave);
			gotoxy(100, 20);
			printf("Life: %d", life);
			gotoxy(60, 25);
			printf("�ܾ �Է��ϰ� ���͸� ���� �ܾ �����ϼ���.");
			update(NULL, head, l, &life);
			last_update_time = clock();
		}
		for (int i = 0; i < TRACK; i++)
		{
			if (clock() - l[i].last_generate_time > l[i].cooltime)
			{
				head = generate(head);
				head->y = i;
				head->x = 0;
				l[i].last_generate_time = clock();
				l[i].cooltime = 3000 + rand() % 3000;
			}
		}
		if (_kbhit())
		{

			ch = _getch();
			if (ch == 27)
			{
				int game_result;
				int so_time = clock();
				game_result = game_pause(5);
				int sq_time = clock();
				if (game_result == 2 || game_result == 1)
					return 0;
				if(game_result == 0)
					sttime += 1000+(sq_time - so_time);
			}
			if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && j < 10)
			{
				printf("%c", ch);
				input[j] = ch;
				j++;
			}
			if (ch == 8 && j > 0) //�齺���̽��� �ش�
			{
				input[j] = '\0';
				j--;
				printf("\b \b");
			}
			if (ch == 8 && j == 0) // �߰�
			{
				input[j] = '\0';
				printf("\b \b");
			}
			if (ch == 13) //����Ű
			{
				input[++j] = '\0';
				cmp_all(head, head->p, input);

				memset(input, 0, sizeof(input));

				for (int i = 0; i < j - 1; i++)
					printf("\b");
				j = 0;
			}
		}
	}
}
