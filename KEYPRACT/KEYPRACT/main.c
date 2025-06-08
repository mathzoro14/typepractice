#include "key.h"

int main() 
{
	srand((unsigned)time(0));
	int run = 1;
	int difficulty = 1;

	while (run)
	{
		int result = show_menu(&difficulty);
		if (result == -1)
			run = 0;
		
		if (result == 1)
		{
			if (difficulty == 4)
			{
				int infinite_result = game_start_infinite();
				if (infinite_result == 0) continue;
				else break;
			}
			else if (difficulty < 4)
				game_start(difficulty);
			else
				tower_defence();
		}
	}
}

//difficulty 1 = 쉬움
//difficulty 2 = 보통
//difficulty 3 = 어려움

// 화이팅