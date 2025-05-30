#include "key.h"
int main() {
	srand((unsigned)time(0));
	int run = 1;
	int difficulty = 1;

	while (run)
	{
		int result = show_menu(&difficulty);
		if (result == -1) run = 0;
		if (result == 1)
		{
			game_start(difficulty);
			break;
		}
	}
}