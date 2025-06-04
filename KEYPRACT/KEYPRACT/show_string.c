#include "key.h"
void show_string(char *p,int difficulty) 
{
	int size = 0;
	
	if (difficulty == 1)
		size = EASY_SIZE;
	else if (difficulty == 2)
		size = NORMAL_SIZE;
	else if (difficulty == 3)
		size = HARD_SIZE;
	else
		size = INFINITE_SIZE;

	for (int i = 0;i < size;i++)
	{
		if (difficulty == 1 || difficulty == 2)
			p[i] = 'a' + rand() % 26;
		else
		{
			if(rand()%2==0)
				p[i] = 'A' + rand() % 26; // Lowercase letters
			else
				p[i] = 'a' + rand() % 26; // Uppercase letters
		}
	}
	
	printf("%s\n", p);
}
