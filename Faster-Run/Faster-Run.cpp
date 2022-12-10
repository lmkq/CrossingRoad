#include <iostream>
#include <iomanip>
#include <thread>
#include <cstdlib>
#include <ctime>

#include "nMap.h"
#include "gGame.h"

bool constantVar::isMute1 = false;
bool constantVar::isMute2 = false;
bool constantVar::isMuteAll = true;
bool constantVar::isHard = true;

int nColor::BorderColor = 240;
int nColor::EnemyColor = 240;
int nColor::PlayerColor = 240;


using namespace std;

int main() {
	srand(time(NULL));
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1400, 720, TRUE);
	FixConsoleWindow();
	gGame game;
	//game.getAllFilename("data");
	game.Menu();
	system("pause");


	/*for (int i = 0; i <= 300; i++) {
		SetColor(i);
		cout << "i = " << i << endl;
	}*/
}