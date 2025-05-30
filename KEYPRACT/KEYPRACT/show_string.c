#include "key.h"
void show_string(char *p,int stage) {
	int i;
	if (stage < 1)
	{
		for (i = 0; i < SIZE+stage*2; i++)
			p[i] = 'a' + rand() % 26;
	}
	else
	{
		for (i = 0;i < SIZE + stage * 2;i++) //2단계 이상에서 대소문자로
		{
			if(rand()%2==0)
				p[i] = 'a' + rand() % 26;
			else
				p[i] = 'A' + rand() % 26;
		}
	}
	p[SIZE+stage*2] = 0;
	printf("%s\n", p);
}
