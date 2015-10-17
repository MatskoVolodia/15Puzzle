#include <iostream>
#include <string>
#include <string.h>
#include "PlayDesk.h"
using namespace std;

void UFI(int temp);
/*
	0 - Program cap
	1 - Win
	2 - Make your step
	3 - Instruction
*/

int main()
{
	PlayDesk Game;
	//PlayDesk Game("almostdone.txt");
	/*UFI(3);
	while (!(Game.IsWin()))
	{
		UFI(0);
		Game.Show();
		int val ; char direc;
		do
		{
			UFI(1);
			cin >> val >> direc;
		} while (!Game.MakeStep(val, direc));
	}
	UFI(2);
	Game.Show();*/

	while (!(Game.IsWin()))
	{
		UFI(0);
		Game.Show();
		int val;
		do
		{
			UFI(1);
			cin >> val;
			if ((cin.fail() || (val < 1) || (val > 15)))
			{
				do
				{
					cout << "Incorrect input! \n";
					UFI(1);
					cin.clear();
					cin.sync();
					cin >> val;
				} while ((cin.fail() || (val < 1) || (val > 15)));
			}
		} while (!Game.MakeStep(val));
	}
	UFI(2);
	Game.Show();
	system("pause");
	return 0;
}

void UFI(int temp)
{
	switch (temp)
	{
	case 0: 
		cout << string(27, '=') << endl;
		cout << string(7, '=') << "  15 PUZZLE  " << string(7, '=') << endl;
		cout << string(27, '=') << endl;
		break;
	case 1:
		cout << string(5, '=') << " MAKE YOUR STEP: " << string(5, '=') << endl;
		cout << string(5, '=') << ' ';
		break;
	case 2:
		cout << string(27, '=') << endl;
		cout << string(7, '=') << "  YOU  WIN!  " << string(7, '=') << endl;
		cout << string(27, '=') << endl;
		break;
	case 3:
		UFI(0);
		cout << string(1, '\n');
		cout << string(7, '=') << " INSTRUCTION " << string(7, '=') << endl;
		cout << string(2, '\n');
		cout << "To make a step you should   \n";
		cout << " type two coordinates in    \n";
		cout << " correct order in format:    \n";
		cout << "Value, which you wanna turn,\n";
		cout << "  Direction, in which.         \n\n";
		cout << "      FOR EXAMPLE:       \n";
		cout << "  5 to Up    =     5 U    \n";
		cout << " 10 to Down  =     10 D   \n";
		cout << "  7 to Left  =     7 L    \n";
		cout << "  1 to Right =     1 R    \n\n";
		cout << "         WARNING!         \n";
		cout << "  Every time you ignore " << endl;
		cout << "   these instructions " << endl;
		cout << "somewhere dies one kitty!" << endl;
		cout << string(2, '\n') << string(7, '=') << " PRESS ANY KEY " << string(7, '=') << endl;
		system("pause");
		break;
	default:
		break;
	}
}