#pragma once
#include <fstream>
#include <iostream>
using namespace std;
const int size = 4;

class PlayDesk
{
	int **desk;
	int posI, posJ;
	int curI, curJ;
public:
	PlayDesk();
	PlayDesk(char *filename);
	void Show();
	bool MakeStep(int value, char direction);
	bool IsWin();
	inline bool DoSwap();
	void FindPos(int temp);
	~PlayDesk();
};

