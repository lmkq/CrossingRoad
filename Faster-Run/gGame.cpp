﻿#include "gGame.h"

void gGame::GameSettings() {
	system("cls");
	const char* setting[5] = { "Mode", "Sound1", "Sound2","Sound All", "Back" };
	const char* currentSettting[5] = { "HARD", "ON", "ON", "ON", "" };

	if (constantVar::isHard)
		currentSettting[0] = "HARD";
	else
		currentSettting[0] = "EASY";

	if (constantVar::isMute1)
		currentSettting[1] = "OFF";
	else
		currentSettting[1] = "ON ";

	if (constantVar::isMute2)
		currentSettting[2] = "OFF";
	else
		currentSettting[2] = "ON ";

	if (constantVar::isMuteAll)
		currentSettting[3] = "OFF";
	else
		currentSettting[3] = "ON ";

	int pos1 = 0;
	const int y = 20;
	const int x = 25;
	int flag = 0;
	int color = rand() % 7 + 247;
	map.PrintMenu();
	bool currentKey = true;

	while (1) {
		if (currentKey) {
			color = rand() % 7 + 247;
			SetColor(color);
			for (int i = 0; i < 6 - 1; i++) {
				GotoXY(x, y + i);
				if (i == pos1)
					SetColor(241);
				else
					SetColor(240);

				cout << setting[i] << " " << currentSettting[i];
			}
			currentKey = false;
		}
		while (1) {
			if (_kbhit()) {
				currentKey = true;

				char key = _getch();
				if (key == 'W' || key == 'w') {
					pos1--;
					pos1 = (pos1 + 5) % 5;
					if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll) PlaySound(TEXT("Move.wav"), NULL, SND_ASYNC);
					break;
				}
				if (key == 'S' || key == 's') {
					pos1++;
					pos1 %= 5;
					if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll) PlaySound(TEXT("Move.wav"), NULL, SND_ASYNC);
					break;
				}
				if (key == 13) {
					switch (pos1) {
					case 0: {
						ToggleHard();
						if (constantVar::isHard) {
							currentSettting[0] = "HARD";
							if (!constantVar::isMute1) PlaySound(TEXT("Ring.wav"), NULL, SND_ASYNC);
						}
						else
						{
							currentSettting[0] = "EASY";
							if (!constantVar::isMute1) PlaySound(TEXT("Ring.wav"), NULL, SND_ASYNC);
						}
						break;
					}
					case 1: {
						ToggleMute();
						if (constantVar::isMute1) {
							currentSettting[1] = "OFF";
							if (!constantVar::isMute1) PlaySound(TEXT("Ring.wav"), NULL, SND_ASYNC);
						}
						else {
							currentSettting[1] = "ON ";
							if (!constantVar::isMute1) PlaySound(TEXT("Ring.wav"), NULL, SND_ASYNC);
						}
						break;
					}
					case 2: {
						ToggleMute2();
						if (constantVar::isMute2) {
							currentSettting[2] = "OFF";
							if (!constantVar::isMute1) PlaySound(TEXT("Ring.wav"), NULL, SND_ASYNC);
						}
						else {
							currentSettting[2] = "ON ";
							if (!constantVar::isMute1) PlaySound(TEXT("Ring.wav"), NULL, SND_ASYNC);
						}
						break;
					}
					case 3: {
						ToggleMute3();
						if (constantVar::isMuteAll) {
							currentSettting[3] = "OFF";
							if (!constantVar::isMute1) PlaySound(TEXT("Ring.wav"), NULL, SND_ASYNC);
						}
						else {
							currentSettting[3] = "ON ";
							if (!constantVar::isMute1) PlaySound(TEXT("Ring.wav"), NULL, SND_ASYNC);
						}
						break;
					}
					case 4: {
						system("cls");
						flag = 1;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						if (!constantVar::isMute1) PlaySound(TEXT("Ring.wav"), NULL, SND_ASYNC);
						return;
					}
					}
					break;
				}

			}
		}
	}
	return;
}

void gGame::Menu(bool& isFinish) {
}

void gGame::Menu() {
	int pos = 0;
	int width = 167;
	int height = 37;

	int x = 35, y = 20;
	if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
	bool changeInput = true;
	UINT old = GetConsoleOutputCP();
	while (true) {
		changeInput = true;
		map.PrintMenu();
		while (true) {
			if (pos == 0)
			{

				SetConsoleOutputCP(CP_UTF8);
				GotoXY(10, 2); cout << u8" ▄████████    ▄████████  ▄██████▄     ▄████████    ▄████████  ▄█  ███▄▄▄▄      ▄██████▄                ▄████████  ▄██████▄     ▄████████ ████████▄  ";
				GotoXY(10, 3); cout << u8"███    ███   ███    ███ ███    ███   ███    ███   ███    ███ ███  ███▀▀▀██▄   ███    ███              ███    ███ ███    ███   ███    ███ ███   ▀███ ";
				GotoXY(10, 4); cout << u8"███    █▀    ███    ███ ███    ███   ███    █▀    ███    █▀  ███▌ ███   ███   ███    █▀               ███    ███ ███    ███   ███    ███ ███    ███ ";
				GotoXY(10, 5); cout << u8"███         ▄███▄▄▄▄██▀ ███    ███   ███          ███        ███▌ ███   ███  ▄███                    ▄███▄▄▄▄██▀ ███    ███   ███    ███ ███    ███ ";
				GotoXY(10, 6); cout << u8"███        ▀▀███▀▀▀▀▀   ███    ███ ▀███████████ ▀███████████ ███▌ ███   ███ ▀▀███ ████▄             ▀▀███▀▀▀▀▀   ███    ███ ▀███████████ ███    ███ ";
				GotoXY(10, 7); cout << u8"███    █▄  ▀███████████ ███    ███          ███          ███ ███  ███   ███   ███    ███            ▀███████████ ███    ███   ███    ███ ███    ███ ";
				GotoXY(10, 8); cout << u8"███    ███   ███    ███ ███    ███    ▄█    ███    ▄█    ███ ███  ███   ███   ███    ███              ███    ███ ███    ███   ███    ███ ███   ▄███ ";
				GotoXY(10, 9); cout << u8"████████▀    ███    ███  ▀██████▀   ▄████████▀   ▄████████▀  █▀    ▀█   █▀    ████████▀               ███    ███  ▀██████▀    ███    █▀  ████████▀  ";
				GotoXY(10, 10); cout << u8"             ███    ███                                                                               ███    ███                                    ";
				SetConsoleOutputCP(old);
			}
			changeInput = false;

			switch (InputKey()) {
				changeInput = true;
				//PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
			case 'd': case 'D':	//Phím D
				SetConsoleOutputCP(CP_UTF8);
				changeInput = true;
				pos++;
				if (pos > 4)
					pos -= 4;
				if (pos == 1)
				{
					GotoXY(3, 2); cout << "                                                                                                                                                                  ";
					GotoXY(3, 3); cout << "                                                                                                                                                                  ";
					GotoXY(3, 4); cout << "                                                                                                                                                                  ";
					GotoXY(3, 5); cout << "                                                                                                                                                                  ";
					GotoXY(3, 6); cout << "                                                                                                                                                                  ";
					GotoXY(3, 7); cout << "                                                                                                                                                                  ";
					GotoXY(3, 8); cout << "                                                                                                                                                                  ";
					GotoXY(3, 9); cout << "                                                                                                                                                                  ";
					GotoXY(3, 10); cout << "                                                                                                                                                                  ";
					GotoXY(3, 11); cout << "                                                                                                                                                                  ";


					GotoXY(4, height / 2 - 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2);      cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 7);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 8);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 9);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 10); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 11); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 12); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 13); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 14); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 15); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 16); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 17); cout << "                                                                                                                                                                  ";


					SetColor(nColor::BorderColor);
					GotoXY(36, 2); cout << u8"███▄▄▄▄      ▄████████  ▄█     █▄                ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████ ";
					GotoXY(36, 3); cout << u8"███▀▀▀██▄   ███    ███ ███     ███              ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ";
					GotoXY(36, 4); cout << u8"███   ███   ███    █▀  ███     ███              ███    █▀    ███    ███ ███   ███   ███   ███    █▀  ";
					GotoXY(36, 5); cout << u8"███   ███  ▄███▄▄▄     ███     ███             ▄███          ███    ███ ███   ███   ███  ▄███▄▄▄     ";
					GotoXY(36, 6); cout << u8"███   ███ ▀▀███▀▀▀     ███     ███            ▀▀███ ████▄  ▀███████████ ███   ███   ███ ▀▀███▀▀▀     ";
					GotoXY(36, 7); cout << u8"███   ███   ███    █▄  ███     ███              ███    ███   ███    ███ ███   ███   ███   ███    █▄  ";
					GotoXY(36, 8); cout << u8"███   ███   ███    ███ ███ ▄█▄ ███              ███    ███   ███    ███ ███   ███   ███   ███    ███ ";
					GotoXY(36, 9); cout << u8" ▀█   █▀    ██████████  ▀███▀███▀               ████████▀    ███    █▀   ▀█   ███   █▀    ██████████ ";

					SetColor(247);
					GotoXY(6, height / 2 + 5);  cout << u8"  ▄▄▄▄▄▄▄   ▄████▄         " << endl;
					GotoXY(6, height / 2 + 6);  cout << u8"  █    ██   ▀████▀         " << endl;
					GotoXY(6, height / 2 + 7);      cout << u8"  █    ██                  " << endl;
					GotoXY(6, height / 2 + 8);  cout << u8"  █    ██  ▄███████████▄   " << endl;
					GotoXY(6, height / 2 + 9);  cout << u8"  █    ██ ███████████ ▀██▄ " << endl;
					GotoXY(6, height / 2 + 10);  cout << u8"  █  ██████▀   ███████  ▀██" << endl;
					GotoXY(6, height / 2 + 11);  cout << u8"  █    ██       ███████    " << endl;
					GotoXY(6, height / 2 + 12);  cout << u8"  █    ██      ████████    " << endl;
					GotoXY(6, height / 2 + 13);  cout << u8"  █    ██     ████  ████   " << endl;
					GotoXY(6, height / 2 + 14);  cout << u8"  █    ██    ████    █████████" << endl;
					GotoXY(6, height / 2 + 15); cout << u8"  █    ██   ████       ▀▀▀▀▀▀▀" << endl;
					GotoXY(6, height / 2 + 16);  cout << u8"  █    ██  ████               " << endl;
					GotoXY(6, height / 2 + 17); cout << u8"  ▀▀▀▀▀▀▀ ███              " << endl;

					SetColor(nColor::BorderColor);
					GotoXY(width / 3 + 10, height / 2 - 2);      cout << u8"  ▄██████████▄         ▄██████████▄  " << endl;
					GotoXY(width / 3 + 10, height / 2 - 1);  cout << u8" ▄█          ▀█████████▀          █▄ " << endl;
					GotoXY(width / 3 + 10, height / 2);  cout << u8"██   ▄███▄                 ▄███▄   ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 1);  cout << u8"██   █   █                 █   █   ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 2);  cout << u8"██   ▀███▀                 ▀███▀   ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 3);  cout << u8"██                                 ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 4);  cout << u8"██              ▄████▄             ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 5);  cout << u8"██           ▄██████████▄          ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 6);  cout << u8"██         ▄██▀▀      ▀▀██▄        ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 7);  cout << u8"██       ▄█▀▀           ▀▀█▄       ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 8); cout << u8"▀▄███████▀▀               ▀▀███████▄▀" << endl;

					SetColor(247);
					GotoXY(width - 35, height / 2 + 7);  cout << u8"          ▄▄▄▄▄▄▄▄▄▄          " << endl;
					GotoXY(width - 35, height / 2 + 8);  cout << u8"          ██      ██          " << endl;
					GotoXY(width - 35, height / 2 + 9);  cout << u8"          ██      ██          " << endl;
					GotoXY(width - 35, height / 2 + 10);  cout << u8"          ██      ██          " << endl;
					GotoXY(width - 35, height / 2 + 11);  cout << u8"          ██      ██          " << endl;
					GotoXY(width - 35, height / 2 + 12);  cout << u8"       ██▀▀▀      ▀▀▀██       " << endl;
					GotoXY(width - 35, height / 2 + 13);  cout << u8"        ██          ██        " << endl;
					GotoXY(width - 35, height / 2 + 14);  cout << u8"▄▄▄▄▄▄▄  ██        ██  ▄▄▄▄▄▄▄" << endl;
					GotoXY(width - 35, height / 2 + 15);  cout << u8"██    █▄▄ ▀▄▄▄▄▄▄▄▄▀ ▄▄█    ██" << endl;
					GotoXY(width - 35, height / 2 + 16);  cout << u8"██                          ██" << endl;
					GotoXY(width - 35, height / 2 + 17); cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;


				}
				if (pos == 2)
				{
					GotoXY(3, 2); cout << "                                                                                                                                                                  ";
					GotoXY(3, 3); cout << "                                                                                                                                                                  ";
					GotoXY(3, 4); cout << "                                                                                                                                                                  ";
					GotoXY(3, 5); cout << "                                                                                                                                                                  ";
					GotoXY(3, 6); cout << "                                                                                                                                                                  ";
					GotoXY(3, 7); cout << "                                                                                                                                                                  ";
					GotoXY(3, 8); cout << "                                                                                                                                                                  ";
					GotoXY(3, 9); cout << "                                                                                                                                                                  ";
					GotoXY(3, 10); cout << "                                                                                                                                                                  ";
					GotoXY(3, 11); cout << "                                                                                                                                                                  ";

					GotoXY(4, height / 2 - 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2);      cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 7);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 8);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 9);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 10); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 11); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 12); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 13); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 14); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 15); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 16); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 17); cout << "                                                                                                                                                                  ";


					SetColor(nColor::BorderColor);
					GotoXY(32, 2); cout << u8" ▄█        ▄██████▄     ▄████████ ████████▄                ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████ ";
					GotoXY(32, 3); cout << u8"███       ███    ███   ███    ███ ███   ▀███              ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ";
					GotoXY(32, 4); cout << u8"███       ███    ███   ███    ███ ███    ███              ███    █▀    ███    ███ ███   ███   ███   ███    █▀  ";
					GotoXY(32, 5); cout << u8"███       ███    ███   ███    ███ ███    ███             ▄███          ███    ███ ███   ███   ███  ▄███▄▄▄     ";
					GotoXY(32, 6); cout << u8"███       ███    ███ ▀███████████ ███    ███            ▀▀███ ████▄  ▀███████████ ███   ███   ███ ▀▀███▀▀▀     ";
					GotoXY(32, 7); cout << u8"███       ███    ███   ███    ███ ███    ███              ███    ███   ███    ███ ███   ███   ███   ███    █▄  ";
					GotoXY(32, 8); cout << u8"███▌    ▄ ███    ███   ███    ███ ███   ▄███              ███    ███   ███    ███ ███   ███   ███   ███    ███ ";
					GotoXY(32, 9); cout << u8"█████▄▄██  ▀██████▀    ███    █▀  ████████▀               ████████▀    ███    █▀   ▀█   ███   █▀    ██████████ ";

					SetColor(247);
					GotoXY(6, height / 2 + 7);      cout << u8"  ▄██████████▄         ▄██████████▄  " << endl;
					GotoXY(6, height / 2 + 8);  cout << u8" ▄█          ▀█████████▀          █▄ " << endl;
					GotoXY(6, height / 2 + 9);  cout << u8"██   ▄███▄                 ▄███▄   ██" << endl;
					GotoXY(6, height / 2 + 10);  cout << u8"██   █   █                 █   █   ██" << endl;
					GotoXY(6, height / 2 + 11);  cout << u8"██   ▀███▀                 ▀███▀   ██" << endl;
					GotoXY(6, height / 2 + 12);  cout << u8"██                                 ██" << endl;
					GotoXY(6, height / 2 + 13);  cout << u8"██              ▄████▄             ██" << endl;
					GotoXY(6, height / 2 + 14);  cout << u8"██           ▄██████████▄          ██" << endl;
					GotoXY(6, height / 2 + 15);  cout << u8"██         ▄██▀▀      ▀▀██▄        ██" << endl;
					GotoXY(6, height / 2 + 16);  cout << u8"██       ▄█▀▀           ▀▀█▄       ██" << endl;
					GotoXY(6, height / 2 + 17); cout << u8"▀▄███████▀▀               ▀▀███████▄▀" << endl;

					SetColor(nColor::BorderColor);
					GotoXY(width / 3 + 13, height / 2 - 2);      cout << u8"          ▄▄▄▄▄▄▄▄▄▄          " << endl;
					GotoXY(width / 3 + 13, height / 2 - 1);  cout << u8"          ██      ██          " << endl;
					GotoXY(width / 3 + 13, height / 2);  cout << u8"          ██      ██          " << endl;
					GotoXY(width / 3 + 13, height / 2 + 1);  cout << u8"          ██      ██          " << endl;
					GotoXY(width / 3 + 13, height / 2 + 2);  cout << u8"          ██      ██          " << endl;
					GotoXY(width / 3 + 13, height / 2 + 3);  cout << u8"       ██▀▀▀      ▀▀▀██       " << endl;
					GotoXY(width / 3 + 13, height / 2 + 4);  cout << u8"        ██          ██        " << endl;
					GotoXY(width / 3 + 13, height / 2 + 5);  cout << u8"▄▄▄▄▄▄▄  ██        ██  ▄▄▄▄▄▄▄" << endl;
					GotoXY(width / 3 + 13, height / 2 + 6);  cout << u8"██    █▄▄ ▀▄▄▄▄▄▄▄▄▀ ▄▄█    ██" << endl;
					GotoXY(width / 3 + 13, height / 2 + 7);  cout << u8"██                          ██" << endl;
					GotoXY(width / 3 + 13, height / 2 + 8); cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;

					SetColor(247);
					GotoXY(width - 43, height / 2 + 3);  cout << u8"             ▄█████▀▀       ▄██████     " << endl;
					GotoXY(width - 43, height / 2 + 4);  cout << u8"          ▄████▀           █████    " << endl;
					GotoXY(width - 43, height / 2 + 5);  cout << u8"        ▄█████            ██████    ███ " << endl;
					GotoXY(width - 43, height / 2 + 6);  cout << u8"      ▄████████           █████████████ " << endl;
					GotoXY(width - 43, height / 2 + 7);		 cout << u8"    ▄████▀  ████        ▄██████████▀ " << endl;
					GotoXY(width - 43, height / 2 + 8);  cout << u8"  ▄████      ▀████▄   ▄█████▀      " << endl;
					GotoXY(width - 43, height / 2 + 9);  cout << u8"  █████         ▀███▄████▀     " << endl;
					GotoXY(width - 43, height / 2 + 10);  cout << u8"                 ▀████▄    " << endl;
					GotoXY(width - 43, height / 2 + 11);  cout << u8"               ▄██▄ ▀███▄  " << endl;
					GotoXY(width - 43, height / 2 + 12);  cout << u8"           ▄██████▀   ▀███▄   " << endl;
					GotoXY(width - 43, height / 2 + 13);  cout << u8"     ▄█████████▀        ▀███▄  " << endl;
					GotoXY(width - 43, height / 2 + 14);  cout << u8"  ▄████████████           ▀███▄ " << endl;
					GotoXY(width - 43, height / 2 + 15);  cout << u8"  ███    █████▀             ▀███▄ " << endl;
					GotoXY(width - 43, height / 2 + 16);  cout << u8"        ██████                ▀███▄" << endl;
					GotoXY(width - 43, height / 2 + 17); cout << u8"      █████▀                    ▀███▄  " << endl;
				}
				if (pos == 3)
				{
					GotoXY(3, 2); cout << "                                                                                                                                                                  ";
					GotoXY(3, 3); cout << "                                                                                                                                                                  ";
					GotoXY(3, 4); cout << "                                                                                                                                                                  ";
					GotoXY(3, 5); cout << "                                                                                                                                                                  ";
					GotoXY(3, 6); cout << "                                                                                                                                                                  ";
					GotoXY(3, 7); cout << "                                                                                                                                                                  ";
					GotoXY(3, 8); cout << "                                                                                                                                                                  ";
					GotoXY(3, 9); cout << "                                                                                                                                                                  ";
					GotoXY(3, 10); cout << "                                                                                                                                                                  ";
					GotoXY(3, 11); cout << "                                                                                                                                                                  ";


					GotoXY(4, height / 2 - 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2);      cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 7);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 8);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 9);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 10); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 11); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 12); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 13); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 14); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 15); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 16); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 17); cout << "                                                                                                                                                                  ";


					SetColor(nColor::BorderColor);
					GotoXY(47, 2); cout << u8"   ▄████████    ▄████████     ███         ███      ▄█  ███▄▄▄▄      ▄██████▄  ";
					GotoXY(47, 3); cout << u8"  ███    ███   ███    ███ ▀█████████▄ ▀█████████▄ ███  ███▀▀▀██▄   ███    ███ ";
					GotoXY(47, 4); cout << u8"  ███    █▀    ███    █▀     ▀███▀▀██    ▀███▀▀██ ███▌ ███   ███   ███    █▀  ";
					GotoXY(47, 5); cout << u8"  ███         ▄███▄▄▄         ███   ▀     ███   ▀ ███▌ ███   ███  ▄███        ";
					GotoXY(47, 6); cout << u8"▀███████████ ▀▀███▀▀▀         ███         ███     ███▌ ███   ███ ▀▀███ ████▄  ";
					GotoXY(47, 7); cout << u8"         ███   ███    █▄      ███         ███     ███  ███   ███   ███    ███ ";
					GotoXY(47, 8); cout << u8"   ▄█    ███   ███    ███     ███         ███     ███  ███   ███   ███    ███ ";
					GotoXY(47, 9); cout << u8" ▄████████▀    ██████████    ▄████▀      ▄████▀   █▀    ▀█   █▀    ████████▀  ";

					SetColor(247);
					GotoXY(6, height / 2 + 7);      cout << u8"          ▄▄▄▄▄▄▄▄▄▄          " << endl;
					GotoXY(6, height / 2 + 8);  cout << u8"          ██      ██          " << endl;
					GotoXY(6, height / 2 + 9);  cout << u8"          ██      ██          " << endl;
					GotoXY(6, height / 2 + 10);  cout << u8"          ██      ██          " << endl;
					GotoXY(6, height / 2 + 11);  cout << u8"          ██      ██          " << endl;
					GotoXY(6, height / 2 + 12);  cout << u8"       ██▀▀▀      ▀▀▀██       " << endl;
					GotoXY(6, height / 2 + 13);  cout << u8"        ██          ██        " << endl;
					GotoXY(6, height / 2 + 14);  cout << u8"▄▄▄▄▄▄▄  ██        ██  ▄▄▄▄▄▄▄" << endl;
					GotoXY(6, height / 2 + 15);  cout << u8"██    █▄▄ ▀▄▄▄▄▄▄▄▄▀ ▄▄█    ██" << endl;
					GotoXY(6, height / 2 + 16);  cout << u8"██                          ██" << endl;
					GotoXY(6, height / 2 + 17); cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;

					SetColor(nColor::BorderColor);
					GotoXY(width / 3 + 10, height / 2 - 6);  cout << u8"             ▄█████▀▀       ▄██████     " << endl;
					GotoXY(width / 3 + 10, height / 2 - 5);  cout << u8"          ▄████▀           █████    " << endl;
					GotoXY(width / 3 + 10, height / 2 - 4);  cout << u8"        ▄█████            ██████    ███ " << endl;
					GotoXY(width / 3 + 10, height / 2 - 3);  cout << u8"      ▄████████           █████████████ " << endl;
					GotoXY(width / 3 + 10, height / 2 - 2);		 cout << u8"    ▄████▀  ████        ▄██████████▀ " << endl;
					GotoXY(width / 3 + 10, height / 2 - 1);  cout << u8"  ▄████      ▀████▄   ▄█████▀      " << endl;
					GotoXY(width / 3 + 10, height / 2);  cout << u8"  █████         ▀███▄████▀     " << endl;
					GotoXY(width / 3 + 10, height / 2 + 1);  cout << u8"                 ▀████▄    " << endl;
					GotoXY(width / 3 + 10, height / 2 + 2);  cout << u8"               ▄██▄ ▀███▄  " << endl;
					GotoXY(width / 3 + 10, height / 2 + 3);  cout << u8"           ▄██████▀   ▀███▄   " << endl;
					GotoXY(width / 3 + 10, height / 2 + 4);  cout << u8"     ▄█████████▀        ▀███▄  " << endl;
					GotoXY(width / 3 + 10, height / 2 + 5);  cout << u8"  ▄████████████           ▀███▄ " << endl;
					GotoXY(width / 3 + 10, height / 2 + 6);  cout << u8"  ███    █████▀             ▀███▄ " << endl;
					GotoXY(width / 3 + 10, height / 2 + 7);  cout << u8"        ██████                ▀███▄" << endl;
					GotoXY(width / 3 + 10, height / 2 + 8); cout << u8"      █████▀                    ▀███▄  " << endl;

					SetColor(247);
					GotoXY(width - 35, height / 2 + 5);  cout << u8"  ▄▄▄▄▄▄▄   ▄████▄         " << endl;
					GotoXY(width - 35, height / 2 + 6);  cout << u8"  █    ██   ▀████▀         " << endl;
					GotoXY(width - 35, height / 2 + 7);      cout << u8"  █    ██                  " << endl;
					GotoXY(width - 35, height / 2 + 8);  cout << u8"  █    ██  ▄███████████▄   " << endl;
					GotoXY(width - 35, height / 2 + 9);  cout << u8"  █    ██ ███████████ ▀██▄ " << endl;
					GotoXY(width - 35, height / 2 + 10);  cout << u8"  █  ██████▀   ███████  ▀██" << endl;
					GotoXY(width - 35, height / 2 + 11);  cout << u8"  █    ██       ███████    " << endl;
					GotoXY(width - 35, height / 2 + 12);  cout << u8"  █    ██      ████████    " << endl;
					GotoXY(width - 35, height / 2 + 13);  cout << u8"  █    ██     ████  ████   " << endl;
					GotoXY(width - 35, height / 2 + 14);  cout << u8"  █    ██    ████    █████████" << endl;
					GotoXY(width - 35, height / 2 + 15); cout << u8"  █    ██   ████       ▀▀▀▀▀▀▀" << endl;
					GotoXY(width - 35, height / 2 + 16);  cout << u8"  █    ██  ████               " << endl;
					GotoXY(width - 35, height / 2 + 17); cout << u8"  ▀▀▀▀▀▀▀ ███              " << endl;

				}
				if (pos == 4)
				{
					GotoXY(3, 2); cout << "                                                                                                                                                                  ";
					GotoXY(3, 3); cout << "                                                                                                                                                                  ";
					GotoXY(3, 4); cout << "                                                                                                                                                                  ";
					GotoXY(3, 5); cout << "                                                                                                                                                                  ";
					GotoXY(3, 6); cout << "                                                                                                                                                                  ";
					GotoXY(3, 7); cout << "                                                                                                                                                                  ";
					GotoXY(3, 8); cout << "                                                                                                                                                                  ";
					GotoXY(3, 9); cout << "                                                                                                                                                                  ";
					GotoXY(3, 10); cout << "                                                                                                                                                                  ";
					GotoXY(3, 11); cout << "                                                                                                                                                                  ";


					GotoXY(4, height / 2 - 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2);      cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 7);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 8);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 9);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 10); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 11); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 12); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 13); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 14); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 15); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 16); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 17); cout << "                                                                                                                                                                  ";


					SetColor(nColor::BorderColor);
					GotoXY(30, 2); cout << u8"   ▄████████ ▀████    ▐████▀  ▄█      ███                   ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████ ";
					GotoXY(30, 3); cout << u8"  ███    ███   ███▌   ████▀  ███  ▀█████████▄              ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ";
					GotoXY(30, 4); cout << u8"  ███    █▀     ███  ▐███    ███▌    ▀███▀▀██              ███    █▀    ███    ███ ███   ███   ███   ███    █▀  ";
					GotoXY(30, 5); cout << u8" ▄███▄▄▄        ▀███▄███▀    ███▌     ███   ▀             ▄███          ███    ███ ███   ███   ███  ▄███▄▄▄     ";
					GotoXY(30, 6); cout << u8"▀▀███▀▀▀        ████▀██▄     ███▌     ███                ▀▀███ ████▄  ▀███████████ ███   ███   ███ ▀▀███▀▀▀     ";
					GotoXY(30, 7); cout << u8"  ███    █▄    ▐███  ▀███    ███      ███                  ███    ███   ███    ███ ███   ███   ███   ███    █▄  ";
					GotoXY(30, 8); cout << u8"  ███    ███  ▄███     ███▄  ███      ███                  ███    ███   ███    ███ ███   ███   ███   ███    ███ ";
					GotoXY(30, 9); cout << u8"  ██████████ ████       ███▄ █▀      ▄████▀                ████████▀    ███    █▀   ▀█   ███   █▀    ██████████ ";

					SetColor(247);
					GotoXY(6, height / 2 + 3);  cout << u8"             ▄█████▀▀       ▄██████     " << endl;
					GotoXY(6, height / 2 + 4);  cout << u8"          ▄████▀           █████    " << endl;
					GotoXY(6, height / 2 + 5);  cout << u8"        ▄█████            ██████    ███ " << endl;
					GotoXY(6, height / 2 + 6);  cout << u8"      ▄████████           █████████████ " << endl;
					GotoXY(6, height / 2 + 7);		 cout << u8"    ▄████▀  ████        ▄██████████▀ " << endl;
					GotoXY(6, height / 2 + 8);  cout << u8"  ▄████      ▀████▄   ▄█████▀      " << endl;
					GotoXY(6, height / 2 + 9);  cout << u8"  █████         ▀███▄████▀     " << endl;
					GotoXY(6, height / 2 + 10);  cout << u8"                 ▀████▄    " << endl;
					GotoXY(6, height / 2 + 11);  cout << u8"               ▄██▄ ▀███▄  " << endl;
					GotoXY(6, height / 2 + 12);  cout << u8"           ▄██████▀   ▀███▄   " << endl;
					GotoXY(6, height / 2 + 13);  cout << u8"     ▄█████████▀        ▀███▄  " << endl;
					GotoXY(6, height / 2 + 14);  cout << u8"  ▄████████████           ▀███▄ " << endl;
					GotoXY(6, height / 2 + 15);  cout << u8"  ███    █████▀             ▀███▄ " << endl;
					GotoXY(6, height / 2 + 16);  cout << u8"        ██████                ▀███▄" << endl;
					GotoXY(6, height / 2 + 17); cout << u8"      █████▀                    ▀███▄  " << endl;

					SetColor(nColor::BorderColor);
					GotoXY(width / 3 + 13, height / 2 - 4);  cout << u8"  ▄▄▄▄▄▄▄   ▄████▄         " << endl;
					GotoXY(width / 3 + 13, height / 2 - 3);  cout << u8"  █    ██   ▀████▀         " << endl;
					GotoXY(width / 3 + 13, height / 2 - 2);      cout << u8"  █    ██                  " << endl;
					GotoXY(width / 3 + 13, height / 2 - 1);  cout << u8"  █    ██  ▄███████████▄   " << endl;
					GotoXY(width / 3 + 13, height / 2);  cout << u8"  █    ██ ███████████ ▀██▄ " << endl;
					GotoXY(width / 3 + 13, height / 2 + 1);  cout << u8"  █  ██████▀   ███████  ▀██" << endl;
					GotoXY(width / 3 + 13, height / 2 + 2);  cout << u8"  █    ██       ███████    " << endl;
					GotoXY(width / 3 + 13, height / 2 + 3);  cout << u8"  █    ██      ████████    " << endl;
					GotoXY(width / 3 + 13, height / 2 + 4);  cout << u8"  █    ██     ████  ████   " << endl;
					GotoXY(width / 3 + 13, height / 2 + 5);  cout << u8"  █    ██    ████    █████████" << endl;
					GotoXY(width / 3 + 13, height / 2 + 6); cout << u8"  █    ██   ████       ▀▀▀▀▀▀▀" << endl;
					GotoXY(width / 3 + 13, height / 2 + 7);  cout << u8"  █    ██  ████               " << endl;
					GotoXY(width / 3 + 13, height / 2 + 8); cout << u8"  ▀▀▀▀▀▀▀ ███              " << endl;

					SetColor(247);
					GotoXY(width - 40, height / 2 + 7);      cout << u8"  ▄██████████▄         ▄██████████▄  " << endl;
					GotoXY(width - 40, height / 2 + 8);  cout << u8" ▄█          ▀█████████▀          █▄ " << endl;
					GotoXY(width - 40, height / 2 + 9);  cout << u8"██   ▄███▄                 ▄███▄   ██" << endl;
					GotoXY(width - 40, height / 2 + 10);  cout << u8"██   █   █                 █   █   ██" << endl;
					GotoXY(width - 40, height / 2 + 11);  cout << u8"██   ▀███▀                 ▀███▀   ██" << endl;
					GotoXY(width - 40, height / 2 + 12);  cout << u8"██                                 ██" << endl;
					GotoXY(width - 40, height / 2 + 13);  cout << u8"██              ▄████▄             ██" << endl;
					GotoXY(width - 40, height / 2 + 14);  cout << u8"██           ▄██████████▄          ██" << endl;
					GotoXY(width - 40, height / 2 + 15);  cout << u8"██         ▄██▀▀      ▀▀██▄        ██" << endl;
					GotoXY(width - 40, height / 2 + 16);  cout << u8"██       ▄█▀▀           ▀▀█▄       ██" << endl;
					GotoXY(width - 40, height / 2 + 17); cout << u8"▀▄███████▀▀               ▀▀███████▄▀" << endl;
				}
				SetConsoleOutputCP(old);
				break;
			case 65: case 97:	//Phím A
				SetConsoleOutputCP(CP_UTF8);
				changeInput = true;
				pos--;
				if (pos == -1) pos++;
				if (pos < 1)
					pos += 4;
				if (pos == 1)
				{
					GotoXY(3, 2); cout << "                                                                                                                                                                  ";
					GotoXY(3, 3); cout << "                                                                                                                                                                  ";
					GotoXY(3, 4); cout << "                                                                                                                                                                  ";
					GotoXY(3, 5); cout << "                                                                                                                                                                  ";
					GotoXY(3, 6); cout << "                                                                                                                                                                  ";
					GotoXY(3, 7); cout << "                                                                                                                                                                  ";
					GotoXY(3, 8); cout << "                                                                                                                                                                  ";
					GotoXY(3, 9); cout << "                                                                                                                                                                  ";
					GotoXY(3, 10); cout << "                                                                                                                                                                  ";
					GotoXY(3, 11); cout << "                                                                                                                                                                  ";



					GotoXY(4, height / 2 - 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2);      cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 7);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 8);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 9);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 10); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 11); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 12); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 13); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 14); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 15); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 16); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 17); cout << "                                                                                                                                                                  ";


					SetColor(nColor::BorderColor);
					GotoXY(36, 2); cout << u8"███▄▄▄▄      ▄████████  ▄█     █▄                ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████ ";
					GotoXY(36, 3); cout << u8"███▀▀▀██▄   ███    ███ ███     ███              ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ";
					GotoXY(36, 4); cout << u8"███   ███   ███    █▀  ███     ███              ███    █▀    ███    ███ ███   ███   ███   ███    █▀  ";
					GotoXY(36, 5); cout << u8"███   ███  ▄███▄▄▄     ███     ███             ▄███          ███    ███ ███   ███   ███  ▄███▄▄▄     ";
					GotoXY(36, 6); cout << u8"███   ███ ▀▀███▀▀▀     ███     ███            ▀▀███ ████▄  ▀███████████ ███   ███   ███ ▀▀███▀▀▀     ";
					GotoXY(36, 7); cout << u8"███   ███   ███    █▄  ███     ███              ███    ███   ███    ███ ███   ███   ███   ███    █▄  ";
					GotoXY(36, 8); cout << u8"███   ███   ███    ███ ███ ▄█▄ ███              ███    ███   ███    ███ ███   ███   ███   ███    ███ ";
					GotoXY(36, 9); cout << u8" ▀█   █▀    ██████████  ▀███▀███▀               ████████▀    ███    █▀   ▀█   ███   █▀    ██████████ ";

					SetColor(247);
					GotoXY(6, height / 2 + 5);  cout << u8"  ▄▄▄▄▄▄▄   ▄████▄         " << endl;
					GotoXY(6, height / 2 + 6);  cout << u8"  █    ██   ▀████▀         " << endl;
					GotoXY(6, height / 2 + 7);      cout << u8"  █    ██                  " << endl;
					GotoXY(6, height / 2 + 8);  cout << u8"  █    ██  ▄███████████▄   " << endl;
					GotoXY(6, height / 2 + 9);  cout << u8"  █    ██ ███████████ ▀██▄ " << endl;
					GotoXY(6, height / 2 + 10);  cout << u8"  █  ██████▀   ███████  ▀██" << endl;
					GotoXY(6, height / 2 + 11);  cout << u8"  █    ██       ███████    " << endl;
					GotoXY(6, height / 2 + 12);  cout << u8"  █    ██      ████████    " << endl;
					GotoXY(6, height / 2 + 13);  cout << u8"  █    ██     ████  ████   " << endl;
					GotoXY(6, height / 2 + 14);  cout << u8"  █    ██    ████    █████████" << endl;
					GotoXY(6, height / 2 + 15); cout << u8"  █    ██   ████       ▀▀▀▀▀▀▀" << endl;
					GotoXY(6, height / 2 + 16);  cout << u8"  █    ██  ████               " << endl;
					GotoXY(6, height / 2 + 17); cout << u8"  ▀▀▀▀▀▀▀ ███              " << endl;

					SetColor(nColor::BorderColor);
					GotoXY(width / 3 + 10, height / 2 - 2);      cout << u8"  ▄██████████▄         ▄██████████▄  " << endl;
					GotoXY(width / 3 + 10, height / 2 - 1);  cout << u8" ▄█          ▀█████████▀          █▄ " << endl;
					GotoXY(width / 3 + 10, height / 2);  cout << u8"██   ▄███▄                 ▄███▄   ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 1);  cout << u8"██   █   █                 █   █   ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 2);  cout << u8"██   ▀███▀                 ▀███▀   ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 3);  cout << u8"██                                 ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 4);  cout << u8"██              ▄████▄             ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 5);  cout << u8"██           ▄██████████▄          ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 6);  cout << u8"██         ▄██▀▀      ▀▀██▄        ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 7);  cout << u8"██       ▄█▀▀           ▀▀█▄       ██" << endl;
					GotoXY(width / 3 + 10, height / 2 + 8); cout << u8"▀▄███████▀▀               ▀▀███████▄▀" << endl;

					SetColor(247);
					GotoXY(width - 35, height / 2 + 7);  cout << u8"          ▄▄▄▄▄▄▄▄▄▄          " << endl;
					GotoXY(width - 35, height / 2 + 8);  cout << u8"          ██      ██          " << endl;
					GotoXY(width - 35, height / 2 + 9);  cout << u8"          ██      ██          " << endl;
					GotoXY(width - 35, height / 2 + 10);  cout << u8"          ██      ██          " << endl;
					GotoXY(width - 35, height / 2 + 11);  cout << u8"          ██      ██          " << endl;
					GotoXY(width - 35, height / 2 + 12);  cout << u8"       ██▀▀▀      ▀▀▀██       " << endl;
					GotoXY(width - 35, height / 2 + 13);  cout << u8"        ██          ██        " << endl;
					GotoXY(width - 35, height / 2 + 14);  cout << u8"▄▄▄▄▄▄▄  ██        ██  ▄▄▄▄▄▄▄" << endl;
					GotoXY(width - 35, height / 2 + 15);  cout << u8"██    █▄▄ ▀▄▄▄▄▄▄▄▄▀ ▄▄█    ██" << endl;
					GotoXY(width - 35, height / 2 + 16);  cout << u8"██                          ██" << endl;
					GotoXY(width - 35, height / 2 + 17); cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
				}
				if (pos == 2)
				{
					GotoXY(3, 2); cout << "                                                                                                                                                                  ";
					GotoXY(3, 3); cout << "                                                                                                                                                                  ";
					GotoXY(3, 4); cout << "                                                                                                                                                                  ";
					GotoXY(3, 5); cout << "                                                                                                                                                                  ";
					GotoXY(3, 6); cout << "                                                                                                                                                                  ";
					GotoXY(3, 7); cout << "                                                                                                                                                                  ";
					GotoXY(3, 8); cout << "                                                                                                                                                                  ";
					GotoXY(3, 9); cout << "                                                                                                                                                                  ";
					GotoXY(3, 10); cout << "                                                                                                                                                                  ";
					GotoXY(3, 11); cout << "                                                                                                                                                                  ";



					GotoXY(4, height / 2 - 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2);      cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 7);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 8);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 9);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 10); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 11); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 12); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 13); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 14); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 15); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 16); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 17); cout << "                                                                                                                                                                  ";


					SetColor(nColor::BorderColor);
					GotoXY(32, 2); cout << u8" ▄█        ▄██████▄     ▄████████ ████████▄                ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████ ";
					GotoXY(32, 3); cout << u8"███       ███    ███   ███    ███ ███   ▀███              ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ";
					GotoXY(32, 4); cout << u8"███       ███    ███   ███    ███ ███    ███              ███    █▀    ███    ███ ███   ███   ███   ███    █▀  ";
					GotoXY(32, 5); cout << u8"███       ███    ███   ███    ███ ███    ███             ▄███          ███    ███ ███   ███   ███  ▄███▄▄▄     ";
					GotoXY(32, 6); cout << u8"███       ███    ███ ▀███████████ ███    ███            ▀▀███ ████▄  ▀███████████ ███   ███   ███ ▀▀███▀▀▀     ";
					GotoXY(32, 7); cout << u8"███       ███    ███   ███    ███ ███    ███              ███    ███   ███    ███ ███   ███   ███   ███    █▄  ";
					GotoXY(32, 8); cout << u8"███▌    ▄ ███    ███   ███    ███ ███   ▄███              ███    ███   ███    ███ ███   ███   ███   ███    ███ ";
					GotoXY(32, 9); cout << u8"█████▄▄██  ▀██████▀    ███    █▀  ████████▀               ████████▀    ███    █▀   ▀█   ███   █▀    ██████████ ";

					SetColor(247);
					GotoXY(6, height / 2 + 7);      cout << u8"  ▄██████████▄         ▄██████████▄  " << endl;
					GotoXY(6, height / 2 + 8);  cout << u8" ▄█          ▀█████████▀          █▄ " << endl;
					GotoXY(6, height / 2 + 9);  cout << u8"██   ▄███▄                 ▄███▄   ██" << endl;
					GotoXY(6, height / 2 + 10);  cout << u8"██   █   █                 █   █   ██" << endl;
					GotoXY(6, height / 2 + 11);  cout << u8"██   ▀███▀                 ▀███▀   ██" << endl;
					GotoXY(6, height / 2 + 12);  cout << u8"██                                 ██" << endl;
					GotoXY(6, height / 2 + 13);  cout << u8"██              ▄████▄             ██" << endl;
					GotoXY(6, height / 2 + 14);  cout << u8"██           ▄██████████▄          ██" << endl;
					GotoXY(6, height / 2 + 15);  cout << u8"██         ▄██▀▀      ▀▀██▄        ██" << endl;
					GotoXY(6, height / 2 + 16);  cout << u8"██       ▄█▀▀           ▀▀█▄       ██" << endl;
					GotoXY(6, height / 2 + 17); cout << u8"▀▄███████▀▀               ▀▀███████▄▀" << endl;

					SetColor(nColor::BorderColor);
					GotoXY(width / 3 + 13, height / 2 - 2);      cout << u8"          ▄▄▄▄▄▄▄▄▄▄          " << endl;
					GotoXY(width / 3 + 13, height / 2 - 1);  cout << u8"          ██      ██          " << endl;
					GotoXY(width / 3 + 13, height / 2);  cout << u8"          ██      ██          " << endl;
					GotoXY(width / 3 + 13, height / 2 + 1);  cout << u8"          ██      ██          " << endl;
					GotoXY(width / 3 + 13, height / 2 + 2);  cout << u8"          ██      ██          " << endl;
					GotoXY(width / 3 + 13, height / 2 + 3);  cout << u8"       ██▀▀▀      ▀▀▀██       " << endl;
					GotoXY(width / 3 + 13, height / 2 + 4);  cout << u8"        ██          ██        " << endl;
					GotoXY(width / 3 + 13, height / 2 + 5);  cout << u8"▄▄▄▄▄▄▄  ██        ██  ▄▄▄▄▄▄▄" << endl;
					GotoXY(width / 3 + 13, height / 2 + 6);  cout << u8"██    █▄▄ ▀▄▄▄▄▄▄▄▄▀ ▄▄█    ██" << endl;
					GotoXY(width / 3 + 13, height / 2 + 7);  cout << u8"██                          ██" << endl;
					GotoXY(width / 3 + 13, height / 2 + 8); cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;

					SetColor(247);
					GotoXY(width - 43, height / 2 + 3);  cout << u8"             ▄█████▀▀       ▄██████     " << endl;
					GotoXY(width - 43, height / 2 + 4);  cout << u8"          ▄████▀           █████    " << endl;
					GotoXY(width - 43, height / 2 + 5);  cout << u8"        ▄█████            ██████    ███ " << endl;
					GotoXY(width - 43, height / 2 + 6);  cout << u8"      ▄████████           █████████████ " << endl;
					GotoXY(width - 43, height / 2 + 7);		 cout << u8"    ▄████▀  ████        ▄██████████▀ " << endl;
					GotoXY(width - 43, height / 2 + 8);  cout << u8"  ▄████      ▀████▄   ▄█████▀      " << endl;
					GotoXY(width - 43, height / 2 + 9);  cout << u8"  █████         ▀███▄████▀     " << endl;
					GotoXY(width - 43, height / 2 + 10);  cout << u8"                 ▀████▄    " << endl;
					GotoXY(width - 43, height / 2 + 11);  cout << u8"               ▄██▄ ▀███▄  " << endl;
					GotoXY(width - 43, height / 2 + 12);  cout << u8"           ▄██████▀   ▀███▄   " << endl;
					GotoXY(width - 43, height / 2 + 13);  cout << u8"     ▄█████████▀        ▀███▄  " << endl;
					GotoXY(width - 43, height / 2 + 14);  cout << u8"  ▄████████████           ▀███▄ " << endl;
					GotoXY(width - 43, height / 2 + 15);  cout << u8"  ███    █████▀             ▀███▄ " << endl;
					GotoXY(width - 43, height / 2 + 16);  cout << u8"        ██████                ▀███▄" << endl;
					GotoXY(width - 43, height / 2 + 17); cout << u8"      █████▀                    ▀███▄  " << endl;
				}
				if (pos == 3)
				{
					GotoXY(3, 2); cout << "                                                                                                                                                                  ";
					GotoXY(3, 3); cout << "                                                                                                                                                                  ";
					GotoXY(3, 4); cout << "                                                                                                                                                                  ";
					GotoXY(3, 5); cout << "                                                                                                                                                                  ";
					GotoXY(3, 6); cout << "                                                                                                                                                                  ";
					GotoXY(3, 7); cout << "                                                                                                                                                                  ";
					GotoXY(3, 8); cout << "                                                                                                                                                                  ";
					GotoXY(3, 9); cout << "                                                                                                                                                                  ";
					GotoXY(3, 10); cout << "                                                                                                                                                                  ";
					GotoXY(3, 11); cout << "                                                                                                                                                                  ";


					GotoXY(4, height / 2 - 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2);      cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 7);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 8);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 9);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 10); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 11); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 12); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 13); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 14); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 15); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 16); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 17); cout << "                                                                                                                                                                  ";


					SetColor(nColor::BorderColor);
					GotoXY(47, 2); cout << u8"   ▄████████    ▄████████     ███         ███      ▄█  ███▄▄▄▄      ▄██████▄  ";
					GotoXY(47, 3); cout << u8"  ███    ███   ███    ███ ▀█████████▄ ▀█████████▄ ███  ███▀▀▀██▄   ███    ███ ";
					GotoXY(47, 4); cout << u8"  ███    █▀    ███    █▀     ▀███▀▀██    ▀███▀▀██ ███▌ ███   ███   ███    █▀  ";
					GotoXY(47, 5); cout << u8"  ███         ▄███▄▄▄         ███   ▀     ███   ▀ ███▌ ███   ███  ▄███        ";
					GotoXY(47, 6); cout << u8"▀███████████ ▀▀███▀▀▀         ███         ███     ███▌ ███   ███ ▀▀███ ████▄  ";
					GotoXY(47, 7); cout << u8"         ███   ███    █▄      ███         ███     ███  ███   ███   ███    ███ ";
					GotoXY(47, 8); cout << u8"   ▄█    ███   ███    ███     ███         ███     ███  ███   ███   ███    ███ ";
					GotoXY(47, 9); cout << u8" ▄████████▀    ██████████    ▄████▀      ▄████▀   █▀    ▀█   █▀    ████████▀  ";

					SetColor(247);
					GotoXY(6, height / 2 + 7);      cout << u8"          ▄▄▄▄▄▄▄▄▄▄          " << endl;
					GotoXY(6, height / 2 + 8);  cout << u8"          ██      ██          " << endl;
					GotoXY(6, height / 2 + 9);  cout << u8"          ██      ██          " << endl;
					GotoXY(6, height / 2 + 10);  cout << u8"          ██      ██          " << endl;
					GotoXY(6, height / 2 + 11);  cout << u8"          ██      ██          " << endl;
					GotoXY(6, height / 2 + 12);  cout << u8"       ██▀▀▀      ▀▀▀██       " << endl;
					GotoXY(6, height / 2 + 13);  cout << u8"        ██          ██        " << endl;
					GotoXY(6, height / 2 + 14);  cout << u8"▄▄▄▄▄▄▄  ██        ██  ▄▄▄▄▄▄▄" << endl;
					GotoXY(6, height / 2 + 15);  cout << u8"██    █▄▄ ▀▄▄▄▄▄▄▄▄▀ ▄▄█    ██" << endl;
					GotoXY(6, height / 2 + 16);  cout << u8"██                          ██" << endl;
					GotoXY(6, height / 2 + 17); cout << u8"▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;

					SetColor(nColor::BorderColor);
					GotoXY(width / 3 + 10, height / 2 - 6);  cout << u8"             ▄█████▀▀       ▄██████     " << endl;
					GotoXY(width / 3 + 10, height / 2 - 5);  cout << u8"          ▄████▀           █████    " << endl;
					GotoXY(width / 3 + 10, height / 2 - 4);  cout << u8"        ▄█████            ██████    ███ " << endl;
					GotoXY(width / 3 + 10, height / 2 - 3);  cout << u8"      ▄████████           █████████████ " << endl;
					GotoXY(width / 3 + 10, height / 2 - 2);		 cout << u8"    ▄████▀  ████        ▄██████████▀ " << endl;
					GotoXY(width / 3 + 10, height / 2 - 1);  cout << u8"  ▄████      ▀████▄   ▄█████▀      " << endl;
					GotoXY(width / 3 + 10, height / 2);  cout << u8"  █████         ▀███▄████▀     " << endl;
					GotoXY(width / 3 + 10, height / 2 + 1);  cout << u8"                 ▀████▄    " << endl;
					GotoXY(width / 3 + 10, height / 2 + 2);  cout << u8"               ▄██▄ ▀███▄  " << endl;
					GotoXY(width / 3 + 10, height / 2 + 3);  cout << u8"           ▄██████▀   ▀███▄   " << endl;
					GotoXY(width / 3 + 10, height / 2 + 4);  cout << u8"     ▄█████████▀        ▀███▄  " << endl;
					GotoXY(width / 3 + 10, height / 2 + 5);  cout << u8"  ▄████████████           ▀███▄ " << endl;
					GotoXY(width / 3 + 10, height / 2 + 6);  cout << u8"  ███    █████▀             ▀███▄ " << endl;
					GotoXY(width / 3 + 10, height / 2 + 7);  cout << u8"        ██████                ▀███▄" << endl;
					GotoXY(width / 3 + 10, height / 2 + 8); cout << u8"      █████▀                    ▀███▄  " << endl;

					SetColor(247);
					GotoXY(width - 35, height / 2 + 5);  cout << u8"  ▄▄▄▄▄▄▄   ▄████▄         " << endl;
					GotoXY(width - 35, height / 2 + 6);  cout << u8"  █    ██   ▀████▀         " << endl;
					GotoXY(width - 35, height / 2 + 7);      cout << u8"  █    ██                  " << endl;
					GotoXY(width - 35, height / 2 + 8);  cout << u8"  █    ██  ▄███████████▄   " << endl;
					GotoXY(width - 35, height / 2 + 9);  cout << u8"  █    ██ ███████████ ▀██▄ " << endl;
					GotoXY(width - 35, height / 2 + 10);  cout << u8"  █  ██████▀   ███████  ▀██" << endl;
					GotoXY(width - 35, height / 2 + 11);  cout << u8"  █    ██       ███████    " << endl;
					GotoXY(width - 35, height / 2 + 12);  cout << u8"  █    ██      ████████    " << endl;
					GotoXY(width - 35, height / 2 + 13);  cout << u8"  █    ██     ████  ████   " << endl;
					GotoXY(width - 35, height / 2 + 14);  cout << u8"  █    ██    ████    █████████" << endl;
					GotoXY(width - 35, height / 2 + 15); cout << u8"  █    ██   ████       ▀▀▀▀▀▀▀" << endl;
					GotoXY(width - 35, height / 2 + 16);  cout << u8"  █    ██  ████               " << endl;
					GotoXY(width - 35, height / 2 + 17); cout << u8"  ▀▀▀▀▀▀▀ ███              " << endl;

				}
				if (pos == 4)
				{
					GotoXY(3, 2); cout << "                                                                                                                                                                  ";
					GotoXY(3, 3); cout << "                                                                                                                                                                  ";
					GotoXY(3, 4); cout << "                                                                                                                                                                  ";
					GotoXY(3, 5); cout << "                                                                                                                                                                  ";
					GotoXY(3, 6); cout << "                                                                                                                                                                  ";
					GotoXY(3, 7); cout << "                                                                                                                                                                  ";
					GotoXY(3, 8); cout << "                                                                                                                                                                  ";
					GotoXY(3, 9); cout << "                                                                                                                                                                  ";
					GotoXY(3, 10); cout << "                                                                                                                                                                  ";
					GotoXY(3, 11); cout << "                                                                                                                                                                  ";


					GotoXY(4, height / 2 - 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 - 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2);      cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 1);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 2);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 3);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 4);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 5);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 6);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 7);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 8);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 9);  cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 10); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 11); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 12); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 13); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 14); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 15); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 16); cout << "                                                                                                                                                                  ";
					GotoXY(4, height / 2 + 17); cout << "                                                                                                                                                                  ";


					SetColor(nColor::BorderColor);
					GotoXY(30, 2); cout << u8"   ▄████████ ▀████    ▐████▀  ▄█      ███                   ▄██████▄     ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████ ";
					GotoXY(30, 3); cout << u8"  ███    ███   ███▌   ████▀  ███  ▀█████████▄              ███    ███   ███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ";
					GotoXY(30, 4); cout << u8"  ███    █▀     ███  ▐███    ███▌    ▀███▀▀██              ███    █▀    ███    ███ ███   ███   ███   ███    █▀  ";
					GotoXY(30, 5); cout << u8" ▄███▄▄▄        ▀███▄███▀    ███▌     ███   ▀             ▄███          ███    ███ ███   ███   ███  ▄███▄▄▄     ";
					GotoXY(30, 6); cout << u8"▀▀███▀▀▀        ████▀██▄     ███▌     ███                ▀▀███ ████▄  ▀███████████ ███   ███   ███ ▀▀███▀▀▀     ";
					GotoXY(30, 7); cout << u8"  ███    █▄    ▐███  ▀███    ███      ███                  ███    ███   ███    ███ ███   ███   ███   ███    █▄  ";
					GotoXY(30, 8); cout << u8"  ███    ███  ▄███     ███▄  ███      ███                  ███    ███   ███    ███ ███   ███   ███   ███    ███ ";
					GotoXY(30, 9); cout << u8"  ██████████ ████       ███▄ █▀      ▄████▀                ████████▀    ███    █▀   ▀█   ███   █▀    ██████████ ";

					SetColor(247);
					GotoXY(6, height / 2 + 3);  cout << u8"             ▄█████▀▀       ▄██████     " << endl;
					GotoXY(6, height / 2 + 4);  cout << u8"          ▄████▀           █████    " << endl;
					GotoXY(6, height / 2 + 5);  cout << u8"        ▄█████            ██████    ███ " << endl;
					GotoXY(6, height / 2 + 6);  cout << u8"      ▄████████           █████████████ " << endl;
					GotoXY(6, height / 2 + 7);		 cout << u8"    ▄████▀  ████        ▄██████████▀ " << endl;
					GotoXY(6, height / 2 + 8);  cout << u8"  ▄████      ▀████▄   ▄█████▀      " << endl;
					GotoXY(6, height / 2 + 9);  cout << u8"  █████         ▀███▄████▀     " << endl;
					GotoXY(6, height / 2 + 10);  cout << u8"                 ▀████▄    " << endl;
					GotoXY(6, height / 2 + 11);  cout << u8"               ▄██▄ ▀███▄  " << endl;
					GotoXY(6, height / 2 + 12);  cout << u8"           ▄██████▀   ▀███▄   " << endl;
					GotoXY(6, height / 2 + 13);  cout << u8"     ▄█████████▀        ▀███▄  " << endl;
					GotoXY(6, height / 2 + 14);  cout << u8"  ▄████████████           ▀███▄ " << endl;
					GotoXY(6, height / 2 + 15);  cout << u8"  ███    █████▀             ▀███▄ " << endl;
					GotoXY(6, height / 2 + 16);  cout << u8"        ██████                ▀███▄" << endl;
					GotoXY(6, height / 2 + 17); cout << u8"      █████▀                    ▀███▄  " << endl;

					SetColor(nColor::BorderColor);
					GotoXY(width / 3 + 13, height / 2 - 4);  cout << u8"  ▄▄▄▄▄▄▄   ▄████▄         " << endl;
					GotoXY(width / 3 + 13, height / 2 - 3);  cout << u8"  █    ██   ▀████▀         " << endl;
					GotoXY(width / 3 + 13, height / 2 - 2);      cout << u8"  █    ██                  " << endl;
					GotoXY(width / 3 + 13, height / 2 - 1);  cout << u8"  █    ██  ▄███████████▄   " << endl;
					GotoXY(width / 3 + 13, height / 2);  cout << u8"  █    ██ ███████████ ▀██▄ " << endl;
					GotoXY(width / 3 + 13, height / 2 + 1);  cout << u8"  █  ██████▀   ███████  ▀██" << endl;
					GotoXY(width / 3 + 13, height / 2 + 2);  cout << u8"  █    ██       ███████    " << endl;
					GotoXY(width / 3 + 13, height / 2 + 3);  cout << u8"  █    ██      ████████    " << endl;
					GotoXY(width / 3 + 13, height / 2 + 4);  cout << u8"  █    ██     ████  ████   " << endl;
					GotoXY(width / 3 + 13, height / 2 + 5);  cout << u8"  █    ██    ████    █████████" << endl;
					GotoXY(width / 3 + 13, height / 2 + 6); cout << u8"  █    ██   ████       ▀▀▀▀▀▀▀" << endl;
					GotoXY(width / 3 + 13, height / 2 + 7);  cout << u8"  █    ██  ████               " << endl;
					GotoXY(width / 3 + 13, height / 2 + 8); cout << u8"  ▀▀▀▀▀▀▀ ███              " << endl;

					SetColor(247);
					GotoXY(width - 40, height / 2 + 7);      cout << u8"  ▄██████████▄         ▄██████████▄  " << endl;
					GotoXY(width - 40, height / 2 + 8);  cout << u8" ▄█          ▀█████████▀          █▄ " << endl;
					GotoXY(width - 40, height / 2 + 9);  cout << u8"██   ▄███▄                 ▄███▄   ██" << endl;
					GotoXY(width - 40, height / 2 + 10);  cout << u8"██   █   █                 █   █   ██" << endl;
					GotoXY(width - 40, height / 2 + 11);  cout << u8"██   ▀███▀                 ▀███▀   ██" << endl;
					GotoXY(width - 40, height / 2 + 12);  cout << u8"██                                 ██" << endl;
					GotoXY(width - 40, height / 2 + 13);  cout << u8"██              ▄████▄             ██" << endl;
					GotoXY(width - 40, height / 2 + 14);  cout << u8"██           ▄██████████▄          ██" << endl;
					GotoXY(width - 40, height / 2 + 15);  cout << u8"██         ▄██▀▀      ▀▀██▄        ██" << endl;
					GotoXY(width - 40, height / 2 + 16);  cout << u8"██       ▄█▀▀           ▀▀█▄       ██" << endl;
					GotoXY(width - 40, height / 2 + 17); cout << u8"▀▄███████▀▀               ▀▀███████▄▀" << endl;
				}
				SetConsoleOutputCP(old);
				break;
			case 13:
				if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll)PlaySound(TEXT("Move.wav"), NULL, SND_ASYNC);
				switch (pos) {
				case 1:
					while (1) {
						Loading();
						if (NewGame()) {
							Sleep(1000);
							CLRSCR();
							map.PrintMenu();
							if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
							changeInput = true;
							break; 
							Sleep(1000);
						}
						else if (!ContinueMenu()) {
							if (isLoaded) {
								map.~nMap();
								new(&map) nMap;
							}
							Sleep(1000);
							CLRSCR();
							map.PrintMenu();
							if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
							changeInput = true;
							break; //thua nhung khong choi tiep
						}
					}
					pos = 0;
					map.PrintMenu();
					break;
				case 2: {
					Sleep(1000);
					if (LoadGameMenu()) {
						while (1) {
							Loading();
							if (NewGame()) {
								Sleep(1000);
								CLRSCR();
								map.PrintMenu();
								if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
								changeInput = true;
								break; // thang nhung k choi tiep
								Sleep(1000);
							}
							else if (!ContinueMenu()) {
								Sleep(1000);
								SetColor(240);
								CLRSCR();
								map.PrintMenu();
								if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
								changeInput = true;
								break; //thua nhung khong choi tiep
							}
						}
					}
					else {
						changeInput = true;
						map.PrintMenu();
					}
				}
					  pos = 0;
					  break;
				case 3: {
					Sleep(500);
					GameSettings();
					changeInput = true;
					map.PrintMenu();
				}
					  pos = 0;
					  break;
				case 4:
					CLRSCR();
					return;
				}
				break;
			}
		}
	}
}

bool gGame::ContinueMenu() {
	CLRSCR();
	map.PrintMap();
	map.DeleteOldPlayer();
	UINT old_cp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	//Game
	TextColor(10); GotoXY(20, 5); cout << u8"   ██  █"; TextColor(0); GotoXY(28, 5); cout << u8"████████"; TextColor(4); GotoXY(36, 5); cout << u8"█     ";
	TextColor(10); GotoXY(42, 5); cout << u8"████"; TextColor(0); GotoXY(46, 5); cout << u8"██████████"; TextColor(4); GotoXY(56, 5); cout << u8"█";
	TextColor(10); GotoXY(61, 5); cout << u8"█"; TextColor(0); GotoXY(62, 5); cout << u8"████"; TextColor(4); GotoXY(66, 5); cout << u8"█";
	TextColor(10); GotoXY(71, 5); cout << u8"█"; TextColor(0); GotoXY(72, 5); cout << u8"████"; TextColor(4); GotoXY(76, 5); cout << u8"█";
	TextColor(10); GotoXY(80, 5); cout << u8"█"; TextColor(0); GotoXY(81, 5); cout << u8"███████████████"; TextColor(4); GotoXY(96, 5); cout << u8"█" << endl;

	TextColor(10); GotoXY(20, 6); cout << u8"     █"; TextColor(0); GotoXY(26, 6); cout << u8"████████████"; TextColor(4); GotoXY(38, 6); cout << u8"█";
	TextColor(10); GotoXY(45, 6); cout << u8"█"; TextColor(0); GotoXY(46, 6); cout << u8"██████████"; TextColor(4); GotoXY(56, 6); cout << u8"█";
	TextColor(10); GotoXY(61, 6); cout << u8"█"; TextColor(0); GotoXY(62, 6); cout << u8"████"; TextColor(4); GotoXY(66, 6); cout << u8"█";
	TextColor(10); GotoXY(71, 6); cout << u8"█"; TextColor(0); GotoXY(72, 6); cout << u8"████"; TextColor(4); GotoXY(76, 6); cout << u8"██";
	TextColor(10); GotoXY(80, 6); cout << u8"█"; TextColor(0); GotoXY(81, 6); cout << u8"███████████████"; TextColor(4); GotoXY(96, 6); cout << u8"█" << endl;

	TextColor(10); GotoXY(20, 7); cout << u8"   █"; TextColor(0); GotoXY(24, 7); cout << u8"████"; TextColor(4); GotoXY(28, 7); cout << u8"█";
	TextColor(10); GotoXY(42, 7); cout << u8"█"; TextColor(0); GotoXY(43, 7); cout << u8"████"; TextColor(4); GotoXY(47, 7); cout << u8"█";
	TextColor(10); GotoXY(53, 7); cout << u8"█"; TextColor(0); GotoXY(54, 7); cout << u8"████"; TextColor(4); GotoXY(58, 7); cout << u8"█";
	TextColor(0); GotoXY(63, 7); cout << u8"█████"; TextColor(0); GotoXY(70, 7); cout << u8"███████"; TextColor(4); GotoXY(77, 7); cout << u8"█";
	TextColor(10); GotoXY(80, 7); cout << u8"█"; TextColor(0); GotoXY(81, 7); cout << u8"████████████"; TextColor(4); GotoXY(93, 7); cout << u8"█" << endl;

	TextColor(10); GotoXY(20, 8); cout << u8"   █"; TextColor(0); GotoXY(24, 8); cout << u8"██";
	TextColor(10); GotoXY(42, 8); cout << u8"█"; TextColor(0); GotoXY(43, 8); cout << u8"████"; TextColor(4); GotoXY(47, 8); cout << u8"███";
	TextColor(10); GotoXY(53, 8); cout << u8"█"; TextColor(0); GotoXY(54, 8); cout << u8"████"; TextColor(4); GotoXY(58, 8); cout << u8"█";
	TextColor(10); GotoXY(61, 8); cout << u8"█"; TextColor(0); GotoXY(62, 8); cout << u8"██████████████"; TextColor(4); GotoXY(76, 8); cout << u8"█";
	TextColor(10); GotoXY(80, 8); cout << u8"█"; TextColor(0); GotoXY(81, 8); cout << u8"████"; TextColor(4); GotoXY(85, 8); cout << u8"█" << endl;

	TextColor(10); GotoXY(20, 9); cout << u8"   █"; TextColor(0); GotoXY(24, 9); cout << u8"████"; TextColor(4); GotoXY(28, 9); cout << u8"█";
	TextColor(10); GotoXY(42, 9); cout << u8"█"; TextColor(0); GotoXY(43, 9); cout << u8"████"; TextColor(4); GotoXY(47, 9); cout << u8"█";
	TextColor(10); GotoXY(53, 9); cout << u8"█"; TextColor(0); GotoXY(54, 9); cout << u8"████"; TextColor(4); GotoXY(58, 9); cout << u8"█";
	TextColor(10); GotoXY(61, 9); cout << u8"█"; TextColor(0); GotoXY(62, 9); cout << u8"████"; TextColor(4); GotoXY(66, 9); cout << u8"█"; GotoXY(68, 9); cout << u8"██";
	TextColor(10); GotoXY(71, 9); cout << u8"█"; TextColor(0); GotoXY(72, 9); cout << u8"████"; TextColor(4); GotoXY(76, 9); cout << u8"█";
	TextColor(10); GotoXY(80, 9); cout << u8"█"; TextColor(0); GotoXY(81, 9); cout << u8"████"; TextColor(4); GotoXY(85, 9); cout << u8"█" << endl;

	TextColor(10); GotoXY(20, 10); cout << u8"   █"; TextColor(0); GotoXY(24, 10); cout << u8"████"; TextColor(4); GotoXY(28, 10); cout << u8"█";
	TextColor(10); GotoXY(31, 10); cout << u8"█"; TextColor(0); GotoXY(32, 10); cout << u8"██████"; TextColor(4); GotoXY(38, 10); cout << u8"█";
	TextColor(10); GotoXY(42, 10); cout << u8"█"; TextColor(0); GotoXY(43, 10); cout << u8"███████████████"; TextColor(4); GotoXY(58, 10); cout << u8"█";
	TextColor(10); GotoXY(61, 10); cout << u8"█"; TextColor(0); GotoXY(62, 10); cout << u8"████"; TextColor(4); GotoXY(66, 10); cout << u8"█"; GotoXY(68, 10); cout << u8"██";
	TextColor(10); GotoXY(71, 10); cout << u8"█"; TextColor(0); GotoXY(72, 10); cout << u8"████"; TextColor(4); GotoXY(76, 10); cout << u8"█";
	TextColor(10); GotoXY(80, 10); cout << u8"█"; TextColor(0); GotoXY(81, 10); cout << u8"████████████"; TextColor(4); GotoXY(93, 10); cout << u8"█" << endl;

	TextColor(10); GotoXY(20, 11); cout << u8"   █"; TextColor(0); GotoXY(24, 11); cout << u8"████"; TextColor(4); GotoXY(28, 11); cout << u8"█";
	TextColor(10); GotoXY(33, 11); cout << u8"█"; TextColor(0); GotoXY(34, 11); cout << u8"████"; TextColor(4); GotoXY(38, 11); cout << u8"█";
	TextColor(10); GotoXY(41, 11); cout << u8"█"; TextColor(0); GotoXY(42, 11); cout << u8"███"; TextColor(4); GotoXY(45, 11); cout << u8"█";
	TextColor(10); GotoXY(52, 11); cout << u8"█"; TextColor(0); GotoXY(53, 11); cout << u8"█████"; TextColor(4); GotoXY(58, 11); cout << u8"█";
	TextColor(10); GotoXY(61, 11); cout << u8"█"; TextColor(0); GotoXY(62, 11); cout << u8"███"; TextColor(4); GotoXY(65, 11); cout << u8"█";
	TextColor(10); GotoXY(71, 11); cout << u8"█"; TextColor(0); GotoXY(72, 11); cout << u8"████"; TextColor(4); GotoXY(76, 11); cout << u8"█";
	TextColor(10); GotoXY(80, 11); cout << u8"█"; TextColor(0); GotoXY(81, 11); cout << u8"████"; TextColor(4); GotoXY(85, 11); cout << u8"█"; cout << endl;

	TextColor(10); GotoXY(20, 12); cout << u8"  █"; TextColor(0); GotoXY(23, 12); cout << u8"████"; TextColor(4); GotoXY(27, 12); cout << u8"█";
	TextColor(10); GotoXY(32, 12); cout << u8"█"; TextColor(0); GotoXY(33, 12); cout << u8"████"; TextColor(4); GotoXY(37, 12); cout << u8"█";
	TextColor(10); GotoXY(41, 12); cout << u8"█"; TextColor(0); GotoXY(42, 12); cout << u8"████"; TextColor(4); GotoXY(46, 12); cout << u8"█";
	TextColor(10); GotoXY(52, 12); cout << u8"█"; TextColor(0); GotoXY(53, 12); cout << u8"████"; TextColor(4); GotoXY(57, 12); cout << u8"█";
	TextColor(10); GotoXY(60, 12); cout << u8"█"; TextColor(0); GotoXY(61, 12); cout << u8"███"; TextColor(4); GotoXY(64, 12); cout << u8"█";
	TextColor(10); GotoXY(70, 12); cout << u8"█"; TextColor(0); GotoXY(71, 12); cout << u8"████"; TextColor(4); GotoXY(75, 12); cout << u8"█";
	TextColor(10); GotoXY(79, 12); cout << u8"█"; TextColor(0); GotoXY(80, 12); cout << u8"████"; TextColor(4); GotoXY(84, 12); cout << u8"█";  TextColor(4); GotoXY(86, 12); cout << u8"██" << endl;

	TextColor(10); GotoXY(20, 13); cout << u8"██  █"; TextColor(0); GotoXY(25, 13); cout << u8"████"; TextColor(4); GotoXY(29, 13); cout << u8"█";
	TextColor(10); GotoXY(32, 13); cout << u8"█"; TextColor(0); GotoXY(33, 13); cout << u8"████"; TextColor(4); GotoXY(37, 13); cout << u8"█";
	TextColor(10); GotoXY(41, 13); cout << u8"█"; TextColor(0); GotoXY(42, 13); cout << u8"██";
	TextColor(10); GotoXY(52, 13); cout << u8"█"; TextColor(0); GotoXY(53, 13); cout << u8"████"; TextColor(4); GotoXY(57, 13); cout << u8"█";
	TextColor(10); GotoXY(60, 13); cout << u8"█"; TextColor(0); GotoXY(61, 13); cout << u8"███"; TextColor(4); GotoXY(64, 13); cout << u8"███";
	TextColor(10); GotoXY(70, 13); cout << u8"█"; TextColor(0); GotoXY(71, 13); cout << u8"████"; TextColor(4); GotoXY(75, 13); cout << u8"█";
	TextColor(10); GotoXY(79, 13); cout << u8"█"; TextColor(0); GotoXY(80, 13); cout << u8"████████████████"; TextColor(4); GotoXY(96, 13); cout << u8"█" << endl;

	TextColor(10); GotoXY(20, 14); cout << u8"      █"; TextColor(0); GotoXY(27, 14); cout << u8"████████"; TextColor(4); GotoXY(35, 14); cout << u8"█";
	TextColor(10); GotoXY(41, 14); cout << u8"█"; TextColor(0); GotoXY(42, 14); cout << u8"████"; TextColor(4); GotoXY(46, 14); cout << u8"█";
	TextColor(10); GotoXY(50, 14); cout << u8"███"; TextColor(0); GotoXY(53, 14); cout << u8"████"; TextColor(4); GotoXY(57, 14); cout << u8"█";
	TextColor(10); GotoXY(60, 14); cout << u8"█"; TextColor(0); GotoXY(61, 14); cout << u8"███"; TextColor(4); GotoXY(64, 14); cout << u8"█";
	TextColor(10); GotoXY(70, 14); cout << u8"█"; TextColor(0); GotoXY(71, 14); cout << u8"████"; TextColor(4); GotoXY(75, 14); cout << u8"█";
	TextColor(0); GotoXY(82, 14); cout << u8"██████████████"; TextColor(4); GotoXY(96, 14); cout << u8"███" << endl;

	//OVER
	TextColor(10); GotoXY(20, 16); cout << u8"       █"; TextColor(0); GotoXY(28, 16); cout << u8"██████"; TextColor(4); GotoXY(34, 16); cout << u8"█";
	TextColor(10); GotoXY(41, 16); cout << u8"█"; TextColor(0); GotoXY(42, 16); cout << u8"████"; TextColor(4); GotoXY(46, 16); cout << u8"█";
	TextColor(10); GotoXY(51, 16); cout << u8"█"; TextColor(0); GotoXY(52, 16); cout << u8"████"; TextColor(4); GotoXY(56, 16); cout << u8"█";
	TextColor(10); GotoXY(59, 16); cout << u8"█"; TextColor(0); GotoXY(60, 16); cout << u8"████████████████"; TextColor(4); GotoXY(76, 16); cout << u8"█";
	TextColor(10); GotoXY(82, 16); cout << u8"█"; TextColor(0); GotoXY(83, 16); cout << u8"██████████"; TextColor(4); GotoXY(93, 16); cout << u8"█";

	TextColor(10); GotoXY(20, 17); cout << u8"     █"; TextColor(0); GotoXY(26, 17); cout << u8"████  ████"; TextColor(4); GotoXY(36, 17); cout << u8"█";
	TextColor(10); GotoXY(41, 17); cout << u8"█"; TextColor(0); GotoXY(42, 17); cout << u8"████"; TextColor(4); GotoXY(46, 17); cout << u8"██";
	TextColor(10); GotoXY(51, 17); cout << u8"█"; TextColor(0); GotoXY(52, 17); cout << u8"████"; TextColor(4); GotoXY(56, 17); cout << u8"█";
	TextColor(10); GotoXY(59, 17); cout << u8"█"; TextColor(0); GotoXY(60, 17); cout << u8"████████████████"; TextColor(4); GotoXY(76, 17); cout << u8"█";
	TextColor(10); GotoXY(80, 17); cout << u8"█"; TextColor(0); GotoXY(81, 17); cout << u8"██████████████"; TextColor(4); GotoXY(95, 17); cout << u8"█  ██";

	TextColor(10); GotoXY(20, 18); cout << u8"   █"; TextColor(0); GotoXY(24, 18); cout << u8"████"; TextColor(4); GotoXY(28, 18); cout << u8"█";
	TextColor(10); GotoXY(33, 18); cout << u8"█"; TextColor(0); GotoXY(34, 18); cout << u8"████"; TextColor(4); GotoXY(38, 18); cout << u8"█";
	TextColor(10); GotoXY(41, 18); cout << u8"█"; TextColor(0); GotoXY(42, 18); cout << u8"████"; TextColor(4); GotoXY(46, 18); cout << u8"█";
	TextColor(10); GotoXY(51, 18); cout << u8"█"; TextColor(0); GotoXY(52, 18); cout << u8"████"; TextColor(4); GotoXY(56, 18); cout << u8"█";
	TextColor(10); GotoXY(58, 18); cout << u8"██"; TextColor(0); GotoXY(60, 18); cout << u8"████"; TextColor(4); GotoXY(64, 18); cout << u8"█";
	TextColor(10); GotoXY(80, 18); cout << u8"█"; TextColor(0); GotoXY(81, 18); cout << u8"████"; TextColor(4); GotoXY(85, 18); cout << u8"█";
	TextColor(10); GotoXY(91, 18); cout << u8"█"; TextColor(0); GotoXY(92, 18); cout << u8"█████"; TextColor(4); GotoXY(97, 18); cout << u8"█";

	TextColor(10); GotoXY(20, 19); cout << u8"   █"; TextColor(0); GotoXY(24, 19); cout << u8"████"; TextColor(4); GotoXY(28, 19); cout << u8"███";
	TextColor(10); GotoXY(33, 19); cout << u8"█"; TextColor(0); GotoXY(34, 19); cout << u8"████"; TextColor(4); GotoXY(38, 19); cout << u8"█";
	TextColor(10); GotoXY(41, 19); cout << u8"█"; TextColor(0); GotoXY(42, 19); cout << u8"████"; TextColor(4); GotoXY(46, 19); cout << u8"█";
	TextColor(10); GotoXY(51, 19); cout << u8"█"; TextColor(0); GotoXY(52, 19); cout << u8"████"; TextColor(4); GotoXY(56, 19); cout << u8"█";
	TextColor(10); GotoXY(58, 19); cout << u8"██"; TextColor(0); GotoXY(60, 19); cout << u8"████"; TextColor(4); GotoXY(64, 19); cout << u8"███";
	TextColor(10); GotoXY(77, 19); cout << u8"████"; TextColor(0); GotoXY(81, 19); cout << u8"████"; TextColor(4); GotoXY(85, 19); cout << u8"█";
	TextColor(10); GotoXY(91, 19); cout << u8"█"; TextColor(0); GotoXY(92, 19); cout << u8"████";

	TextColor(0); GotoXY(20, 20); cout << u8"     ███"; TextColor(4); GotoXY(28, 20); cout << u8"█";
	TextColor(10); GotoXY(33, 20); cout << u8"█"; TextColor(0); GotoXY(34, 20); cout << u8"████"; TextColor(4); GotoXY(38, 20); cout << u8"█";
	TextColor(10); GotoXY(41, 20); cout << u8"█"; TextColor(0); GotoXY(42, 20); cout << u8"██";
	TextColor(10); GotoXY(51, 20); cout << u8"█"; TextColor(0); GotoXY(52, 20); cout << u8"████"; TextColor(4); GotoXY(56, 20); cout << u8"█";
	TextColor(10); GotoXY(59, 20); cout << u8"█"; TextColor(0); GotoXY(60, 20); cout << u8"████"; TextColor(4); GotoXY(64, 20); cout << u8"█";
	TextColor(10); GotoXY(80, 20); cout << u8"█"; TextColor(0); GotoXY(81, 20); cout << u8"████"; TextColor(4); GotoXY(85, 20); cout << u8"█";
	TextColor(10); GotoXY(91, 20); cout << u8"█"; TextColor(0); GotoXY(92, 20); cout << u8"█████"; TextColor(4); GotoXY(97, 20); cout << u8"█";

	TextColor(10); GotoXY(20, 21); cout << u8"   █"; TextColor(0); GotoXY(24, 21); cout << u8"████"; TextColor(4); GotoXY(28, 21); cout << u8"█";
	TextColor(10); GotoXY(33, 21); cout << u8"█"; TextColor(0); GotoXY(34, 21); cout << u8"████"; TextColor(4); GotoXY(38, 21); cout << u8"█";
	TextColor(10); GotoXY(41, 21); cout << u8"█"; TextColor(0); GotoXY(42, 21); cout << u8"████"; TextColor(4); GotoXY(46, 21); cout << u8"█";
	TextColor(10); GotoXY(51, 21); cout << u8"█"; TextColor(0); GotoXY(52, 21); cout << u8"████"; TextColor(4); GotoXY(56, 21); cout << u8"█";
	TextColor(10); GotoXY(59, 21); cout << u8"█"; TextColor(0); GotoXY(60, 21); cout << u8"████████████"; TextColor(4); GotoXY(72, 21); cout << u8"█";
	TextColor(10); GotoXY(80, 21); cout << u8"█"; TextColor(0); GotoXY(81, 21); cout << u8"████"; TextColor(4); GotoXY(85, 21); cout << u8"█";
	TextColor(10); GotoXY(91, 21); cout << u8"█"; TextColor(0); GotoXY(92, 21); cout << u8"████"; TextColor(4); GotoXY(96, 21); cout << u8"█";

	TextColor(10); GotoXY(20, 22); cout << u8"  █"; TextColor(0); GotoXY(23, 22); cout << u8"████"; TextColor(4); GotoXY(27, 22); cout << u8"█";
	TextColor(10); GotoXY(32, 22); cout << u8"█"; TextColor(0); GotoXY(33, 22); cout << u8"████"; TextColor(4); GotoXY(37, 22); cout << u8"█";
	TextColor(10); GotoXY(40, 22); cout << u8"█"; TextColor(0); GotoXY(41, 22); cout << u8"████"; TextColor(4); GotoXY(45, 22); cout << u8"█";
	TextColor(10); GotoXY(50, 22); cout << u8"█"; TextColor(0); GotoXY(51, 22); cout << u8"████"; TextColor(4); GotoXY(55, 22); cout << u8"█";
	TextColor(10); GotoXY(58, 22); cout << u8"█"; TextColor(0); GotoXY(59, 22); cout << u8"████████████"; TextColor(4); GotoXY(71, 22); cout << u8"█";
	TextColor(10); GotoXY(79, 22); cout << u8"█"; TextColor(0); GotoXY(80, 22); cout << u8"████"; TextColor(4); GotoXY(84, 22); cout << u8"█";
	TextColor(10); GotoXY(90, 22); cout << u8"█"; TextColor(0); GotoXY(91, 22); cout << u8"████"; TextColor(4); GotoXY(95, 22); cout << u8"█";

	TextColor(10); GotoXY(20, 23); cout << u8"  █"; TextColor(0); GotoXY(23, 23); cout << u8"████"; TextColor(4); GotoXY(27, 23); cout << u8"█";
	TextColor(10); GotoXY(32, 23); cout << u8"█"; TextColor(0); GotoXY(33, 23); cout << u8"████"; TextColor(4); GotoXY(37, 23); cout << u8"█";
	TextColor(10); GotoXY(42, 23); cout << u8"█"; TextColor(0); GotoXY(43, 23); cout << u8"███"; TextColor(4); GotoXY(46, 23); cout << u8"█";
	TextColor(10); GotoXY(49, 23); cout << u8"█"; TextColor(0); GotoXY(50, 23); cout << u8"███"; TextColor(4); GotoXY(53, 23); cout << u8"█";
	TextColor(10); GotoXY(58, 23); cout << u8"█"; TextColor(0); GotoXY(59, 23); cout << u8"████"; TextColor(4); GotoXY(63, 23); cout << u8"█";
	TextColor(10); GotoXY(79, 23); cout << u8"█"; TextColor(0); GotoXY(80, 23); cout << u8"██████████████"; TextColor(4); GotoXY(94, 23); cout << u8"█";

	TextColor(10); GotoXY(20, 24); cout << u8"██  █"; TextColor(0); GotoXY(25, 24); cout << u8"████";
	TextColor(0); GotoXY(31, 24); cout << u8"████"; TextColor(4); GotoXY(35, 24); cout << u8"█";
	TextColor(10); GotoXY(44, 24); cout << u8"█"; TextColor(0); GotoXY(45, 24); cout << u8"██████"; TextColor(4); GotoXY(51, 24); cout << u8"█";
	TextColor(10); GotoXY(56, 24); cout << u8"███"; TextColor(0); GotoXY(59, 24); cout << u8"████"; TextColor(4); GotoXY(63, 24); cout << u8"█";
	TextColor(10); GotoXY(79, 24); cout << u8"█"; TextColor(0); GotoXY(80, 24); cout << u8"████"; TextColor(4); GotoXY(84, 24); cout << u8"█";
	TextColor(10); GotoXY(89, 24); cout << u8"█"; TextColor(0); GotoXY(90, 24); cout << u8"███████"; TextColor(4); GotoXY(97, 24); cout << u8"█";

	TextColor(10); GotoXY(20, 25); cout << u8"      █"; TextColor(0); GotoXY(27, 25); cout << u8"██████"; TextColor(4); GotoXY(33, 25); cout << u8"█  ██";
	TextColor(10); GotoXY(46, 25); cout << u8"█"; TextColor(0); GotoXY(47, 25); cout << u8"██"; TextColor(4); GotoXY(49, 25); cout << u8"█  ██";
	TextColor(10); GotoXY(58, 25); cout << u8"█"; TextColor(0); GotoXY(59, 25); cout << u8"█████████████████"; TextColor(4); GotoXY(76, 25); cout << u8"█";
	TextColor(10); GotoXY(79, 25); cout << u8"█"; TextColor(0); GotoXY(80, 25); cout << u8"████"; TextColor(4); GotoXY(84, 25); cout << u8"█";
	TextColor(10); GotoXY(91, 25); cout << u8"█"; TextColor(0); GotoXY(92, 25); cout << u8"█████"; TextColor(4); GotoXY(97, 25); cout << u8"█";
	SetConsoleOutputCP(old_cp);

	int pos = 0, x1 = 30, y = 27, x2 = 65;
	SetColor(240);

	while (1) {
		SetColor(240);
		for (int i = 0; i < 2; i++) {
			if (pos == 0) {
				UINT old_cp = GetConsoleOutputCP();
				SetConsoleOutputCP(CP_UTF8);
				TextColor(0); GotoXY(x1, y); cout << u8"                ██";
				TextColor(0); GotoXY(x1, y + 1); cout << u8"              ██"; TextColor(10); GotoXY(x1 + 16, y + 1); cout << u8"██"; TextColor(0); GotoXY(x1 + 18, y + 1); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 2); cout << u8"    ██      ██"; TextColor(10); GotoXY(x1 + 14, y + 2); cout << u8"██████"; TextColor(0); GotoXY(x1 + 20, y + 2); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 3); cout << u8"  ██"; TextColor(10); GotoXY(x1 + 4, y + 3); cout << u8"██"; TextColor(0); GotoXY(x1 + 6, y + 3); cout << u8"██  ██"; TextColor(10); GotoXY(x1 + 12, y + 3); cout << u8"██████"; TextColor(0); GotoXY(x1 + 18, y + 3); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 4); cout << u8"██"; TextColor(10); GotoXY(x1 + 2, y + 4); cout << u8"██████"; TextColor(0); GotoXY(x1 + 8, y + 4); cout << u8"██"; TextColor(10); GotoXY(x1 + 10, y + 4); cout << u8"██████"; TextColor(0); GotoXY(x1 + 16, y + 4); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 5); cout << u8"  ██"; TextColor(10); GotoXY(x1 + 4, y + 5); cout << u8"██████████"; TextColor(0); GotoXY(x1 + 14, y + 5); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 6); cout << u8"    ██"; TextColor(10); GotoXY(x1 + 6, y + 6); cout << u8"██████"; TextColor(0); GotoXY(x1 + 12, y + 6); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 7); cout << u8"      ██"; TextColor(10); GotoXY(x1 + 8, y + 7); cout << u8"██"; TextColor(0); GotoXY(x1 + 10, y + 7); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 8); cout << u8"        ██";


				TextColor(0); GotoXY(x2, y); cout << u8"    ██      ██    ";
				TextColor(0); GotoXY(x2, y + 1); cout << u8"  ██"; TextColor(8); GotoXY(x2 + 4, y + 1); cout << u8"██"; TextColor(0); GotoXY(x2 + 6, y + 1); cout << u8"██  ██"; TextColor(8); GotoXY(x2 + 12, y + 1); cout << u8"██"; TextColor(0); GotoXY(x2 + 14, y + 1); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 2); cout << u8"██"; TextColor(8); GotoXY(x2 + 2, y + 2); cout << u8"██████"; TextColor(0); GotoXY(x2 + 8, y + 2); cout << u8"██"; TextColor(8); GotoXY(x2 + 10, y + 2); cout << u8"██████"; TextColor(0); GotoXY(x2 + 16, y + 2); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 3); cout << u8"  ██"; TextColor(8); GotoXY(x2 + 4, y + 3); cout << u8"██████████"; TextColor(0); GotoXY(x2 + 14, y + 3); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 4); cout << u8"    ██"; TextColor(8); GotoXY(x2 + 6, y + 4); cout << u8"██████"; TextColor(0); GotoXY(x2 + 12, y + 4); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 5); cout << u8"  ██"; TextColor(8); GotoXY(x2 + 4, y + 5); cout << u8"██████████"; TextColor(0); GotoXY(x2 + 14, y + 5); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 6); cout << u8"██"; TextColor(8); GotoXY(x2 + 2, y + 6); cout << u8"██████"; TextColor(0); GotoXY(x2 + 8, y + 6); cout << u8"██"; TextColor(8); GotoXY(x2 + 10, y + 6); cout << u8"██████"; TextColor(0); GotoXY(x2 + 16, y + 6); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 7); cout << u8"  ██"; TextColor(8); GotoXY(x2 + 4, y + 7); cout << u8"██"; TextColor(0); GotoXY(x2 + 6, y + 7); cout << u8"██  ██"; TextColor(8); GotoXY(x2 + 12, y + 7); cout << u8"██"; TextColor(0); GotoXY(x2 + 14, y + 7); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 8); cout << u8"    ██      ██    ";

				SetConsoleOutputCP(old_cp);
			}

			else {
				UINT old_cp = GetConsoleOutputCP();
				SetConsoleOutputCP(CP_UTF8);
				TextColor(0); GotoXY(x2, y); cout << u8"    ██      ██    ";
				TextColor(0); GotoXY(x2, y + 1); cout << u8"  ██"; TextColor(4); GotoXY(x2 + 4, y + 1); cout << u8"██"; TextColor(0); GotoXY(x2 + 6, y + 1); cout << u8"██  ██"; TextColor(4); GotoXY(x2 + 12, y + 1); cout << u8"██"; TextColor(0); GotoXY(x2 + 14, y + 1); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 2); cout << u8"██"; TextColor(4); GotoXY(x2 + 2, y + 2); cout << u8"██████"; TextColor(0); GotoXY(x2 + 8, y + 2); cout << u8"██"; TextColor(4); GotoXY(x2 + 10, y + 2); cout << u8"██████"; TextColor(0); GotoXY(x2 + 16, y + 2); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 3); cout << u8"  ██"; TextColor(4); GotoXY(x2 + 4, y + 3); cout << u8"██████████"; TextColor(0); GotoXY(x2 + 14, y + 3); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 4); cout << u8"    ██"; TextColor(4); GotoXY(x2 + 6, y + 4); cout << u8"██████"; TextColor(0); GotoXY(x2 + 12, y + 4); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 5); cout << u8"  ██"; TextColor(4); GotoXY(x2 + 4, y + 5); cout << u8"██████████"; TextColor(0); GotoXY(x2 + 14, y + 5); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 6); cout << u8"██"; TextColor(4); GotoXY(x2 + 2, y + 6); cout << u8"██████"; TextColor(0); GotoXY(x2 + 8, y + 6); cout << u8"██"; TextColor(4); GotoXY(x2 + 10, y + 6); cout << u8"██████"; TextColor(0); GotoXY(x2 + 16, y + 6); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 7); cout << u8"  ██"; TextColor(4); GotoXY(x2 + 4, y + 7); cout << u8"██"; TextColor(0); GotoXY(x2 + 6, y + 7); cout << u8"██  ██"; TextColor(4); GotoXY(x2 + 12, y + 7); cout << u8"██"; TextColor(0); GotoXY(x2 + 14, y + 7); cout << u8"██";
				TextColor(0); GotoXY(x2, y + 8); cout << u8"    ██      ██    ";

				TextColor(0); GotoXY(x1, y); cout << u8"                ██";
				TextColor(0); GotoXY(x1, y + 1); cout << u8"              ██"; TextColor(8); GotoXY(x1 + 16, y + 1); cout << u8"██"; TextColor(0); GotoXY(x1 + 18, y + 1); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 2); cout << u8"    ██      ██"; TextColor(8); GotoXY(x1 + 14, y + 2); cout << u8"██████"; TextColor(0); GotoXY(x1 + 20, y + 2); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 3); cout << u8"  ██"; TextColor(8); GotoXY(x1 + 4, y + 3); cout << u8"██";  TextColor(0); GotoXY(x1 + 6, y + 3); cout << u8"██  ██"; TextColor(8); GotoXY(x1 + 12, y + 3); cout << u8"██████"; TextColor(0); GotoXY(x1 + 18, y + 3); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 4); cout << u8"██"; TextColor(8); GotoXY(x1 + 2, y + 4); cout << u8"██████"; TextColor(0); GotoXY(x1 + 8, y + 4); cout << u8"██"; TextColor(8); GotoXY(x1 + 10, y + 4); cout << u8"██████"; TextColor(0); GotoXY(x1 + 16, y + 4); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 5); cout << u8"  ██"; TextColor(8); GotoXY(x1 + 4, y + 5); cout << u8"██████████"; TextColor(0); GotoXY(x1 + 14, y + 5); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 6); cout << u8"    ██"; TextColor(8); GotoXY(x1 + 6, y + 6); cout << u8"██████"; TextColor(0); GotoXY(x1 + 12, y + 6); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 7); cout << u8"      ██"; TextColor(8); GotoXY(x1 + 8, y + 7); cout << u8"██"; TextColor(0); GotoXY(x1 + 10, y + 7); cout << u8"██";
				TextColor(0); GotoXY(x1, y + 8); cout << u8"        ██";
				SetConsoleOutputCP(old_cp);
			}
		}

		switch (InputKey()) {

		case 'a': case 'A':
			pos--;
			pos = abs(pos);
			pos %= 2;
			if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll) PlaySound(TEXT("Move.wav"), NULL, SND_ASYNC);
			break;
		case 'd': case 'D':
			pos++;
			pos %= 2;
			if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll) PlaySound(TEXT("Move.wav"), NULL, SND_ASYNC);
			break;
		case 13:
			if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll) PlaySound(TEXT("Ring.wav"), NULL, SND_ASYNC);
			return !pos;
		}
	}

}

bool gGame::NewGame() {
	char key;
	if (!isLoaded) {
		map.~nMap();
		new(&map) nMap();
		map.PrintMap();
	}
	bool isExist = true;
	isPausing = false;
	map.DrawPlayer();
	if (!isLoaded) map.InitializeNewState();
	isLoaded = false;

	const string choice[3] = { "Save Game","Load Game","  Quit!  " };
	int pos = 0;
	while (!map.IsEnd()) {
		if (!isPausing) {
			map.RandomNextState();
		}

		int x = 141, y = 19;
		if (isPausing) {
			SetColor(240);
			UINT old_cp = GetConsoleOutputCP();
			SetConsoleOutputCP(CP_UTF8);
			SetColor(244);
			GotoXY(142, 15); cout << u8"██  ██" << endl;
			GotoXY(142, 16); cout << u8"██  ██" << endl;
			GotoXY(142, 17); cout << u8"██  ██" << endl;
			SetColor(240);
			SetConsoleOutputCP(old_cp);
			for (int i = 0; i < 3; i++) {
				GotoXY(x, y + i);
				if (i == pos)
					SetColor(7);
				else
					SetColor(240);

				cout << choice[i] << endl;
			}
		}
		SetColor(240);
		if (_kbhit())
		{
			key = _getch();
			if (key == 'p')
			{
				GotoXY(128, 14); cout << "                                 ";
				GotoXY(128, 15); cout << "                                 ";
				GotoXY(128, 16); cout << "                                 ";
				GotoXY(128, 17); cout << "                                 ";
				GotoXY(128, 18); cout << "                                 ";
				GotoXY(128, 19); cout << "                                 ";
				GotoXY(128, 20); cout << "                                 ";
				GotoXY(128, 21); cout << "                                 ";
				GotoXY(128, 22); cout << "                                 ";
				map.DrawLightning();
				map.CleanWorm();
				map.DrawLiveWorm();
				TogglePauseGame();
				pos = 0; // reset pause menu selection
				if (!isPausing) {
					GotoXY(128, 14); cout << "                                 ";
					GotoXY(128, 15); cout << "                                 ";
					GotoXY(128, 16); cout << "                                 ";
					GotoXY(128, 17); cout << "                                 ";
					GotoXY(128, 18); cout << "                                 ";
					GotoXY(128, 19); cout << "                                 ";
					GotoXY(128, 20); cout << "                                 ";
					GotoXY(128, 21); cout << "                                 ";
					GotoXY(128, 22); cout << "                                 ";
					map.CleanLightning();
					map.CleanWorm();
					map.DrawTiredWorm();
				}
			}
			if (key == 'a' || key == 'A')
			{
				if (isExist == true) {
					map.CleanLightning();
					map.CleanWorm();
					map.DrawTiredWorm();
				}
				else {
					map.DrawLightning();
					map.CleanWorm();
					map.DrawLiveWorm();
				}

				if (!isPausing) {
					map.DrawInstruction();
					SetColor(241);
					map.DrawLeft();
					SetColor(240);
				}
				
				isExist = !isExist;
				if (!isPausing) map.UpdatePosPlayer('a');

			}
			if (key == 'w' || key == 'W')
			{
				if (isExist == true) {
					map.CleanLightning();
					map.CleanWorm();
					map.DrawTiredWorm();
				}
				else {
					map.DrawLightning();
					map.CleanWorm();
					map.DrawLiveWorm();
				}

				if (!isPausing) {
					map.DrawInstruction();
					SetColor(241);
					pPosition u(139,17);
					map.DrawUp(u);
					SetColor(240);
				}

				isExist = !isExist;
				if (!isPausing) map.UpdatePosPlayer('w');
				else {
					pos--;
					pos = (pos + 3) % 3;
				}
			}
			if (key == 's' || key == 'S')
			{
				if (isExist == true) {
					map.CleanLightning();
					map.CleanWorm();
					map.DrawTiredWorm();
				}
				else {
					map.DrawLightning();
					map.CleanWorm();
					map.DrawLiveWorm();
				}

				if (!isPausing) {
					map.DrawInstruction();
					SetColor(241);
					pPosition d(139,19);
					map.DrawDown(d);
					SetColor(240);
				}


				isExist = !isExist;
				if (!isPausing) map.UpdatePosPlayer('s');
				else {
					pos++;
					pos %= 3;
				}
			}
			if (key == 'd' || key == 'D')
			{
				if (isExist == true) {
					map.CleanLightning();
					map.CleanWorm();
					map.DrawTiredWorm();
				}
				else {
					map.DrawLightning();
					map.CleanWorm();
					map.DrawLiveWorm();
				}

				if (!isPausing) {
					map.DrawInstruction();
					SetColor(241);
					map.DrawRight();
					SetColor(240);
				}

				isExist = !isExist;
				if (!isPausing) map.UpdatePosPlayer('d');
			}
			if (isPausing && key == 13) {
				map.DrawLightning();
				switch (pos) {
				case 0:
					SaveGameMenu();
					break;
				case 1:
					LoadGameMenu();
					Loading();
					CLRSCR();
					map.RedrawMap();
					TogglePauseGame();
					isLoaded = false;
					break;
				case 2:
					SetColor(241);
					return true;
				}
			}
			SetColor(240);
			map.DrawPlayer();
			map.DrawMap();
		}
		if (!map.IsEnd() && map.IsWin()) {
			if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll)PlaySound(TEXT("Endgame.wav"), NULL, SND_ASYNC);
			if (map.PrintLevelUp()) {
				CLRSCR();
				map.NextLevel();
				map.PrintMap();
				map.DeleteOldPlayer();
				map.InitializeNewState();
				map.DrawPlayer();
			}
			else return true;
		}
	}
	return false;
}

bool gGame::ContinueGame()
{
	char key;
	isPausing = false;
	map.PrintMap();
	map.InitializeNewState();
	const string choice[3] = { "Save Game","Load Game","  Quit!  " };
	int pos = 0;
	while (!map.IsEnd()) {
		if (!isPausing) {
			map.RandomNextState();
		}

		SetColor(240);

		UINT old_cp = GetConsoleOutputCP();
		SetConsoleOutputCP(CP_UTF8);
		SetColor(244);
		GotoXY(142, 15); cout << u8"██  ██" << endl;
		GotoXY(142, 16); cout << u8"██  ██" << endl;
		GotoXY(142, 17); cout << u8"██  ██" << endl;
		SetColor(240);
		SetConsoleOutputCP(old_cp);
		int x = 141, y = 19;
		for (int i = 0; i < 3; i++) {
			GotoXY(x, y + i);
			if (isPausing && i == pos) {
				SetColor(7);
			}
			else {
				SetColor(240);
			}

			cout << choice[i] << endl;
		}

		if (_kbhit())
		{
			key = _getch();
			if (key == 'p')
			{
				TogglePauseGame();
				pos = 0;
			}
			if (key == 'a')
			{
				map.CleanLightning();
				if (!isPausing) map.UpdatePosPlayer('a');
				map.DrawLightning();
			}
			if (key == 'w')
			{
				map.CleanLightning();
				if (!isPausing) map.UpdatePosPlayer('w');
				else {
					pos--;
					pos = (pos + 3) % 3;
					if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll) PlaySound(TEXT("Move.wav"), NULL, SND_ASYNC);
				}
				map.DrawLightning();
			}
			if (key == 's')
			{
				map.CleanLightning();
				if (!isPausing) map.UpdatePosPlayer('s');
				else {
					pos++;
					pos %= 3;
					if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll) PlaySound(TEXT("Move.wav"), NULL, SND_ASYNC);
				}
				map.DrawLightning();
			}
			if (key == 'd')
			{
				map.CleanLightning();
				if (!isPausing) map.UpdatePosPlayer('d');
				map.DrawLightning();
			}
			if (isPausing && key == 13) {
				switch (pos) {
				case 0:
					SaveGameMenu();
					break;
				case 1:
					LoadGameMenu();
					break;
				case 2:
					SetColor(241);
					return true;
				}
			}
			SetColor(240);
			map.DrawPlayer();
			map.DrawMap();
		}
		if (map.IsWin()) {
			if ((!constantVar::isMute1 && !constantVar::isMuteAll) || !constantVar::isMuteAll)PlaySound(TEXT("Endgame.wav"), NULL, SND_ASYNC);
			if (map.PrintLevelUp()) {
				CLRSCR();
				map.NextLevel();
				map.PrintMap();
				map.DeleteOldPlayer();
				map.InitializeNewState();
				map.DrawPlayer();
			}
			else return true;
		}
	}
	return false;
}

void gGame::Loading()
{
	CLRSCR();
	map.PrintMap();
	map.DrawMus();
	map.DeleteOldPlayer();
	GotoXY(30, 25);
	cout << "[";
	for (int i = 0; i <= 50; i++)
	{
		Sleep(35);
		GotoXY(30 + i, 25);
		cout << "=>";
		GotoXY(30 + 25, 26);
		cout << i * 2 << "%";
	}
	GotoXY(30, 25); cout << "                                                        ";
	GotoXY(30, 26); cout << "                                                        ";
	GotoXY(44, 5);	cout << "                                                        ";
	GotoXY(44, 6);	cout << "                                                        ";
	GotoXY(44, 7);	cout << "                                                        ";
	GotoXY(44, 8);	cout << "                                                        ";
	GotoXY(44, 9);	cout << "                                                        ";
	GotoXY(44, 10); cout << "                                                        ";
	GotoXY(44, 11); cout << "                                                        ";
	GotoXY(44, 12); cout << "                                                        ";
	GotoXY(44, 13); cout << "                                                        ";
	GotoXY(44, 14); cout << "                                                        ";
	GotoXY(44, 15); cout << "                                                        ";
	GotoXY(44, 16); cout << "                                                        ";
	GotoXY(44, 17); cout << "                                                        ";
	GotoXY(44, 18); cout << "                                                        ";
	GotoXY(44, 19); cout << "                                                        ";
}

vector<string> gGame::GetAllFilename(const string& name)
{
	vector<string> v;
	string pattern(name);
	pattern.append("\\*");
	std::wstring stemp = std::wstring(pattern.begin(), pattern.end());
	LPCWSTR sw = stemp.c_str();
	WIN32_FIND_DATA data;
	HANDLE hFind;
	if ((hFind = FindFirstFile(sw, &data)) != INVALID_HANDLE_VALUE) {
		do {
			wchar_t* txt = data.cFileName;
			wstring ws(txt);
			string str(ws.begin(), ws.end());
			if (str[0] == '.') continue;
			v.push_back(str);
		} while (FindNextFile(hFind, &data) != 0);
		FindClose(hFind);
	}
	return v;
}
bool gGame::LoadGameMenu() { // get file of cMap map
	int curPos = 0;
	//map.PrintBorder();
	map.PrintBoxLoad();

	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	UINT old_cp = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	SetColor(map.defaultcolor);
	int cl = 6;
	int x_title = map.GetWidth() / 2 - 10;
	int y_title = 3;
	TextColor(240);
	GotoXY(x_title, y_title++); cout << u8"██╗      ██████╗  █████╗ ██████╗ ██╗███╗   ██╗ ██████╗     ███████╗██╗██╗     ███████╗" << endl;
	GotoXY(x_title, y_title++); cout << u8"██║     ██╔═══██╗██╔══██╗██╔══██╗██║████╗  ██║██╔════╝     ██╔════╝██║██║     ██╔════╝" << endl;
	GotoXY(x_title, y_title++); cout << u8"██║     ██║   ██║███████║██║  ██║██║██╔██╗ ██║██║  ███╗    █████╗  ██║██║     █████╗  " << endl;
	GotoXY(x_title, y_title++); cout << u8"██║     ██║   ██║██╔══██║██║  ██║██║██║╚██╗██║██║   ██║    ██╔══╝  ██║██║     ██╔══╝  " << endl;
	GotoXY(x_title, y_title++); cout << u8"███████╗╚██████╔╝██║  ██║██████╔╝██║██║ ╚████║╚██████╔╝    ██║     ██║███████╗███████╗" << endl;
	GotoXY(x_title, y_title); cout << u8"╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝╚═╝  ╚═══╝ ╚═════╝     ╚═╝     ╚═╝╚══════╝╚══════╝" << endl;
	SetConsoleOutputCP(old_cp);

	vector <string> files = GetAllFilename("data");

	string s = "                                                   ";
	int Vani = 234;
	int x_hl = 70;
	int x_text = 60;
	int y_text = 20;
	if (files.size() == 0) {
		SetColor(Vani);
		GotoXY(x_hl, 16);
		cout << "  NO SAVED FILE TO LOAD.  ";
		Sleep(1000);
		return false;
	}

	pPosition pd(83, 23);
	pPosition pu(83, 17);

	GotoXY(x_text, y_text);
	SetColor(nColor::Loadline);
	cout <<files[0];
	cout << s;

	while (true) {
		if (_kbhit())
		{
			char key = _getch();
			if (key == 'w')
			{
				SetColor(102);
				map.DrawUp(pu);
				SetColor(238);
				map.DrawDown(pd);
				curPos--;
				curPos = (curPos + files.size()) % files.size();
				GotoXY(x_text, y_text);
				SetColor(nColor::Loadline);
				cout << s;
				GotoXY(x_text, y_text);
				cout <<files[curPos];

			}
			if (key == 's')
			{
				SetColor(102);
				map.DrawDown(pd);
				SetColor(238);
				map.DrawUp(pu);
				curPos++;
				curPos = (curPos + files.size()) % files.size();
				GotoXY(x_text, y_text);
				SetColor(nColor::Loadline);
				cout << s;
				GotoXY(x_text, y_text);
				cout <<files[curPos];
			}
			if (key == 13)
			{
				SetColor(map.defaultcolor);
				isLoaded = true;
				map.LoadGame(files[curPos]);
				CLRSCR();
				return true;
			}
			if (key == 27)
			{
				SetColor(map.defaultcolor);
				CLRSCR();
				return false;
			}
		}
		Sleep(200);
	}
}

void gGame::SaveGameMenu() { // get file of cMap ma
	string filename;
	map.PrintBoxSave();
	map.DeleteOldPlayer();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	SetColor(112);
	GotoXY(21, 17);
	cout << "Hi there,";
	GotoXY(21, 19);
	SetColor(112);
	cout << "Please enter the name to save your game: ";
	rewind(stdin);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	char key;
	while ((key = _getch()) != 27) {
		switch (key) {
		case '\b':
			if (filename.size() != 0) {
				SetColor(112);
				GotoXY(63, 19);
				filename.pop_back();
				GotoXY(63, 19);
				cout << "                                      ";
				GotoXY(63, 19);
				cout << filename;
			}
			break;
		case 13:
			map.SaveGame(filename);
			break;
		default:
			SetColor(112);
			GotoXY(63, 19);
			if (filename.size() < 20) {
				filename.push_back(key);
			}
			cout << filename;
		}
		if (key == 13) break;
	}
	CLRSCR();
	map.RedrawMap();
	SetColor(255);
	pPosition u(139, 17);
	pPosition d(139, 19);
	map.DrawDown(d);
	map.DrawUp(u);
	map.DrawLeft();
	map.DrawRight();
}

void gGame::TogglePauseGame() { // toggle status of isPausing
	isPausing = !isPausing;
};

void gGame::GameOver() {
	cout << "Game over" << endl;
};

void gGame::ToggleMute() {
	constantVar::isMute1 = !constantVar::isMute1;
}
void gGame::ToggleMute2() {
	constantVar::isMute2 = !constantVar::isMute2;
}
void gGame::ToggleMute3() {
	constantVar::isMuteAll = !constantVar::isMuteAll;
}
void gGame::ToggleHard()
{
	constantVar::isHard = !constantVar::isHard;
}