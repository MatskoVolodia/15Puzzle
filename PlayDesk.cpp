#include "PlayDesk.h"
#include <set>
#include <time.h> 
#include <string.h>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

PlayDesk::PlayDesk()
{
	curI = -1; curJ = -1;

	desk = new int*[size];
	for (int i = 0; i < size; i++)
	{
		desk[i] = new int[size];
	}
	set<int> used;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			srand((unsigned) time(NULL));
			int temp = rand() % 15;
			while (used.count(temp))
			{
				temp = rand() % 16;
			}
			if (temp == 0)
			{
				posI = i;
				posJ = j;
			}
			used.insert(temp);
			desk[i][j] = temp;
		}
	}
}

PlayDesk::PlayDesk(char *filename)    // suggest that input is correct!!! Use only for testing!!!
{
	fstream FILE;
	FILE.open(filename);
	curI = -1; curJ = -1;

	desk = new int*[size];
	for (int i = 0; i < size; i++)
	{
		desk[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			FILE >> desk[i][j];
			if (desk[i][j] == 0)
			{
				posI = i;
				posJ = j;
			}
		}
	}
	FILE.close();
}

void PlayDesk::Show()
{
	for (int i = 0; i < size; i++)
	{
		cout << string(27, '-') << endl;
		for (int k = 0; k < size; k++)
		{
			cout << '|' << string(4, ' ') << "| ";
		}
		cout << '\n';
		for (int j = 0; j < size; j++)
		{
			if (desk[i][j] != 0)
			{
				cout << "| " << setw(2) << desk[i][j] << " | ";
			} else
				cout << "| " << "  " << " | ";
		}
		cout << '\n';
		for (int k = 0; k < size; k++)
		{
			cout << '|' << string(4, ' ') << "| ";
		}
		cout << '\n';
		cout << string(27, '-') << endl;
	}
}

bool PlayDesk::MakeStep(int value, char direction)
{
	FindPos(value);
	switch (direction)
	{
	case 'U': 
		if (!((curI - posI == 1) && (curJ == posJ)))
		{
			cout << string(5, '=') << " INCORRECT STEP: " << string(5, '=') << endl;
			return false;
		}
		else return DoSwap();
	break;

	case 'D':
		if (!((curI - posI == -1) && (curJ == posJ)))
		{
			cout << string(5, '=') << " INCORRECT STEP: " << string(5, '=') << endl;
			return false;
		}
		else return DoSwap();
	break;

	case 'L':
		if (!((curJ - posJ == 1) && (curI == posI)))
		{
			cout << string(5, '=') << " INCORRECT STEP: " << string(5, '=') << endl;
			return false;
		}
		else return DoSwap();
	break;

	case 'R':
		if (!((curJ - posJ == -1) && (curI == posI)))
		{
			cout << string(5, '=') << " INCORRECT STEP: " << string(5, '=') << endl;
			return false;
		}
		else return DoSwap();
	break;

	default:
		cout << "Incorrect step!\n";
		return false;
		break;
	} 
}

bool PlayDesk::MakeStep(int value)
{
	FindPos(value);
	if (!((curI == posI) || (curJ == posJ)))
	{
		cout << "Incorrect step!\n";
		return 0;
	}

	if (curI == posI)
	{
		int temp = abs(curJ - posJ);
		if (curJ < posJ)
		{
			while (temp > 0)
			{
				DoSwap(posI, posJ - 1);
				temp--;
			}
		}

		if (curJ > posJ)
		{
			while (temp > 0)
			{
				DoSwap(posI, posJ + 1);
				temp--;
			}
		}
	}

	if (curJ == posJ)
	{
		int temp = abs(curI - posI);
		if (curI < posI)
		{
			while (temp > 0)
			{
				DoSwap(posI - 1, posJ);
				temp--;
			}
		}

		if (curI > posI)
		{
			while (temp > 0)
			{
				DoSwap(posI + 1, posJ);
				temp--;
			}
		}
	}
	return 1;
}

bool PlayDesk::IsWin()
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((i == size-1) && (j == size-1)) return true;
			++temp;
			if ((desk[i][j] != temp)) return false;
		}
	}
}

void PlayDesk::FindPos(int temp)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (temp == desk[i][j])
			{
				curI = i;
				curJ = j;
			}
		}
	}
}

inline bool PlayDesk::DoSwap()
{
	swap(desk[curI][curJ], desk[posI][posJ]);
	swap(curI, posI); swap(curJ, posJ);
	system("cls");
	return true;
}

inline bool PlayDesk::DoSwap(int i, int j)
{
	swap(desk[i][j], desk[posI][posJ]);
	swap(i, posI); swap(j, posJ);
	system("cls");
	return true;
}

PlayDesk::~PlayDesk()
{
	for (int i = 0; i < size; i++)
	{
		delete[]desk[i];
	}
	delete[]desk;
}
