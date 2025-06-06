#include "key.h"
void GotoXY(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

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

void update(LIST* ppre, LIST* p, LINE l[],int *life) //최초 호출 : (NULL, head, l)
{
	if (p->x >= LETTER - 6)
	{
		delete_node(ppre, p);
		(*life)--;
	}
	else
	{
		GotoXY((int)(p->x), p->y);
		printf("%s", p->word);
		GotoXY(0, 4);
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

LIST* generate(LIST* head) //동적할당할 것, p는 기존 head 값
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

// 가정 : 동일한 문자열이 여러개 있으면 모두 지운다
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
	GotoXY(0, 5);
	GotoXY(0, 4);
	cmp_all(ptr, ptr->p, ar);

}

void clear(int wave)
{
	system("cls");
	GotoXY(0, 0);
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

void tower_deffence() 
{
	int wave = 1, sttime = clock(), last_update_time = clock(),life=3;
	int j = 0;
	char ch, input[20] = { 0 };
	LINE l[TRACK];
	for (int i = 0; i < TRACK; i++)
	{
		l[i].last_generate_time = clock();
		l[i].cooltime = 1000 * i;
		l[i].speed = 2+wave/5;
	}
	l[0].cooltime = 5000;
	LIST* head = generate(NULL);
	head->y = 0;
	head->x = 0;
	update(NULL, head, l,&life);
	while (1) {
		GotoXY(0, 4);
		printf("%s         ", input);
		GotoXY(0, 4);
		if (life <= 0)
		{
			system("cls");
			printf("game over\n");
			return;
		}
		if (END < clock() - sttime)
		{
			clear(++wave);
			for (int i = 0; i < TRACK; i++)
			{
				l[i].last_generate_time = clock();
				l[i].cooltime = 3000 * i + rand() % 2000;
				l[i].speed = 2+wave/5;
			}
			//1번 노드 생성
			head = generate(NULL);
			head->y = 0;
			head->x = 0;
			update(NULL, head, l,&life);
			sttime = clock();

			//입력 내용 초기화
			memset(input, 0, sizeof(input));
			for (int i = 0; i < j - 1; i++)
				printf("\b");
			j = 0;
			fflush(stdin);

		}
		if (UPDATETIME < clock() - last_update_time)
		{
			system("cls");
			update(NULL, head, l,&life);
			GotoXY(0, 3);
			for (int i = 0; i < LETTER; i++)
				printf("-");

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
				break;
			}
			if (((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) && j < 10)
			{
				printf("%c", ch);
				input[j] = ch;
				j++;
			}
			if (ch == 8 && j > 0) //백스페이스에 해당
			{
				input[j] = '\0';
				j--;
				printf("\b \b");
			}
			if (ch == 8 && j == 0) // 추가
			{
				input[j] = '\0';
				printf("\b \b");
			}
			if (ch == 13) //엔터키
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
