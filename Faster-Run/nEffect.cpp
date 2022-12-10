#include "nEffect.h"

void ConvertImage(const char* fname, int a, int b, int x, int y)
{
	//const char * fname là tên file truyền vào
	//a là màu sắc của hình ảnh (0 < a < 255)
	//b là tốc độ xuất ảnh
	//x và y là tọa độ ảnh sẽ được xuất ra

	vector <int> A;
	A.push_back(a);				//Lựa chọn các số từ 1 - 255 sẽ tương ứng với mỗi màu sắc cho TOÀN BỘ bức ảnh
	int i = 0;
	SetColor(A.at(i++ % A.size()));

	ifstream file;
	file.open(fname, ios_base::in);
	string line;

	while (getline(file, line))
	{
		GotoXY(x, y);
		cout << line << endl;
		y++;
		Sleep(b);
	}
	SetColor(65);
	file.close();
}
void ShowIntro()
{

	UINT old = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	SetColor(241);
	for (int i = 0; i <= 51; i++) {
		for (int j = 0; j <= 209; j++) {
			cout << " ";
		}
	}

	const char* f1 = "Effect//Intro 1.txt";	//Cách khai báo khi chèn 1 ảnh bất kì (Tên khai báo chính là tên file ảnh txt)
	const char* f2 = "Effect//Intro 2.txt";
	const char* f3 = "Effect//Intro 3.txt";
	const char* f4 = "Effect//Intro 4.txt";
	const char* f5 = "Effect//Intro 5.txt";
	const char* f6 = "Effect//Intro 6.txt";

	const char* f7 = "Effect//Group 1.txt";
	const char* f8 = "Effect//Group 2.txt";
	const char* f9 = "Effect//Group 3.txt";
	const char* f10 = "Effect//Group 4.txt";

	const char* f11 = "Effect//Blank.txt";


	Sleep(4000);
	HideCursor();
	ConvertImage(f2, 244, 0, 0, 10);
	Sleep(300);

	ConvertImage(f3, 244, 0, 0, 10);
	Sleep(300);

	ConvertImage(f4, 244, 0, 0, 10);
	Sleep(300);

	ConvertImage(f1, 244, 0, 0, 10);
	Sleep(300);
	ConvertImage(f11, 240, 0, 0, 0);

	for (int i = 1; i <= 89; i++)
	{
		ConvertImage(f1, 244, 0, i, 10);
		Sleep(10);
		ConvertImage(f11, 240, 0, 0, 0);
	}

	ConvertImage(f1, 244, 0, 90, 10);  //end
	ConvertImage(f10, 241, 0, 10, 15);
	Sleep(300);
	ConvertImage(f11, 240, 0, 0, 0);

	ConvertImage(f5, 244, 0, 134, 10);
	ConvertImage(f8, 241, 0, 20, 15);
	Sleep(300);
	ConvertImage(f11, 240, 0, 0, 0);

	ConvertImage(f6, 244, 0, 174, 10);
	ConvertImage(f9, 241, 0, 30, 15);
	Sleep(300);
	ConvertImage(f11, 240, 0, 0, 0);

	ConvertImage(f7, 241, 0, 45, 15);
	HideCursor();
	ConvertImage(f11, 240, 100, 0, 0);

	SetColor(242);

	//Group 8

	GotoXY(63, 43);    cout << u8"               ███    ███                                           ▀███████▀" << endl;
	Sleep(100);

	//SetColor(12);
	GotoXY(63, 42);    cout << u8"  ████████▀    ███    ███  ▀██████▀  ████████▀   ▄████▀            ███     ███" << endl;
	Sleep(100);

	//SetColor(11);
	GotoXY(63, 41);    cout << u8"  ███    ███   ███    ███ ███    ███ ███    ███   ███              ███     ███" << endl;
	Sleep(100);

	//SetColor(9);
	GotoXY(63, 40);    cout << u8"  ███    ███ ▀███████████ ███    ███ ███    ███   ███              ███▀▀▀▀▀███" << endl;
	Sleep(100);

	//SetColor(6);
	GotoXY(63, 39);    cout << u8"▀▀███ ████▄  ▀▀███▀▀▀▀▀   ███    ███ ███    ███ ▀█████████▀        ███▄▄▄▄▄███" << endl;
	Sleep(100);

	//SetColor(12);
	GotoXY(63, 38);    cout << u8" ▄███         ▄███▄▄▄▄██▀ ███    ███ ███    ███   ███    ███       ███     ███  " << endl;
	Sleep(100);

	//SetColor(11);
	GotoXY(63, 37);    cout << u8"  ███    █▀    ███    ███ ███    ███ ███    ███   ███    ███       ███     ███        " << endl;
	Sleep(100);

	//SetColor(9);
	GotoXY(63, 36);     cout << u8"  ███    ███   ███    ███ ███    ███ ███    ███   ███    ███       ███     ███  " << endl;
	Sleep(100);

	//SetColor(6);
	GotoXY(63, 35);     cout << u8"   ▄██████▄     ▄████████  ▄██████▄  ███    █▄     ▄███████▄        ▄███████▄" << endl;
	Sleep(100);


	SetColor(248); //183
	//From
	GotoXY(77, 28);    cout << u8"               ███    ███                            " << endl;
	Sleep(200);

	//SetColor(12);
	GotoXY(77, 27);    cout << u8"  ███          ███    ███  ▀██████▀   ▀█   ███   █▀  " << endl;
	Sleep(100);

	//SetColor(11);
	GotoXY(77, 26);    cout << u8"  ███          ███    ███ ███    ███ ███   ███   ███ " << endl;
	Sleep(100);

	//SetColor(9);
	GotoXY(77, 25);    cout << u8"  ███        ▀███████████ ███    ███ ███   ███   ███ " << endl;
	Sleep(100);

	//SetColor(6);
	GotoXY(77, 24);    cout << u8"▀▀███▀▀▀     ▀▀███▀▀▀▀▀   ███    ███ ███   ███   ███ " << endl;
	Sleep(100);

	//SetColor(12);
	GotoXY(77, 23);    cout << u8" ▄███▄▄▄      ▄███▄▄▄▄██▀ ███    ███ ███   ███   ███ " << endl;
	Sleep(100);

	//SetColor(11);
	GotoXY(77, 22);    cout << u8"  ███    █▀    ███    ███ ███    ███ ███   ███   ███ " << endl;
	Sleep(100);

	//SetColor(9);
	GotoXY(77, 21);     cout << u8"  ███    ███   ███    ███ ███    ███ ▄██▀▀▀███▀▀▀██▄ " << endl;
	Sleep(100);

	//SetColor(9);
	GotoXY(77, 20);     cout << u8"   ▄████████    ▄████████  ▄██████▄    ▄▄▄▄███▄▄▄▄   " << endl;
	Sleep(100);


	SetColor(252);
	//A Project
	//SetColor(6);
	GotoXY(80, 13);     cout << u8"               ███    ███            ▀▀▀▀▀▀                                      " << endl;
	Sleep(100);

	GotoXY(53, 12);     cout << u8"  ███    █▀  " << endl;
	GotoXY(80, 12);     cout << u8" ▄████▀        ███    ███  ▀██████▀  █▄ ▄███   ██████████ ████████▀     ▄████▀   " << endl;
	Sleep(100);

	//SetColor(6);
	GotoXY(53, 11);     cout << u8"  ███    ███ " << endl;
	GotoXY(80, 11);     cout << u8"  ███          ███    ███ ███    ███     ███   ███    ███ ███    ███     ███     " << endl;
	Sleep(100);

	//SetColor(6);
	GotoXY(53, 10);     cout << u8"  ███    ███ " << endl;
	GotoXY(80, 10);     cout << u8"  ███        ▀███████████ ███    ███     ███   ███    █▄  ███    █▄      ███     " << endl;
	Sleep(100);

	//SetColor(6);
	GotoXY(53, 9);     cout << u8"▀███████████ " << endl;
	GotoXY(80, 9);     cout << u8"▀█████████▀  ▀▀███▀▀▀▀▀   ███    ███     ███ ▀▀███▀▀▀     ███            ███     " << endl;
	Sleep(100);

	//SetColor(6);
	GotoXY(53, 8);     cout << u8"  ███    ███ " << endl;
	GotoXY(80, 8);     cout << u8"  ███    ███  ▄███▄▄▄▄██▀ ███    ███     ███  ▄███▄▄▄     ███            ███   ▀ " << endl;
	Sleep(100);

	//SetColor(6);
	GotoXY(53, 7);     cout << u8"  ███    ███ " << endl;
	GotoXY(80, 7);     cout << u8"  ███    ███   ███    ███ ███    ███     ███   ███    █▀  ███    █▀     ▀███▀▀██ " << endl;
	Sleep(100);

	//SetColor(6);
	GotoXY(53, 6);     cout << u8"  ███    ███ " << endl;
	GotoXY(80, 6);     cout << u8"  ███    ███   ███    ███ ███    ███     ███   ███    ███ ███    ███ ▀█████████▄ " << endl;
	Sleep(100);

	//SetColor(6);
	GotoXY(53, 5);     cout << u8"   ▄████████ " << endl;
	GotoXY(80, 5);     cout << u8"   ▄███████▄    ▄████████  ▄██████▄       ▄█    ▄████████  ▄████████     ███     " << endl;
	Sleep(2000);
	system("cls");

	SetColor(244);
	GotoXY(8, 8);    cout << u8" ▄████████    ▄████████  ▄██████▄     ▄████████    ▄████████  ▄█  ███▄▄▄▄      ▄██████▄ " << endl;
	GotoXY(8, 9);    cout << u8"███    ███   ███    ███ ███    ███   ███    ███   ███    ███ ███  ███▀▀▀██▄   ███    ███" << endl;
	GotoXY(8, 10);    cout << u8"███    █▀    ███    ███ ███    ███   ███    █▀    ███    █▀  ███▌ ███   ███   ███    █▀  " << endl;
	GotoXY(8, 11);    cout << u8"███         ▄███▄▄▄▄██▀ ███    ███   ███          ███        ███▌ ███   ███  ▄███        " << endl;
	GotoXY(8, 12);    cout << u8"███        ▀▀███▀▀▀▀▀   ███    ███ ▀███████████ ▀███████████ ███▌ ███   ███ ▀▀███ ████▄  " << endl;
	GotoXY(8, 13);    cout << u8"███    █▄  ▀███████████ ███    ███          ███          ███ ███  ███   ███   ███    ███ " << endl;
	GotoXY(8, 14);    cout << u8"███    ███   ███    ███ ███    ███    ▄█    ███    ▄█    ███ ███  ███   ███   ███    ███ " << endl;
	GotoXY(8, 15);    cout << u8"████████▀    ███    ███  ▀██████▀   ▄████████▀   ▄████████▀  █▀    ▀█   █▀    ████████▀  " << endl;
	GotoXY(8, 16);    cout << u8"             ███    ███                                                                  " << endl;
	Sleep(1000);

	SetColor(240);
	GotoXY(92, 21);    cout << u8"    ███        ▄█    █▄       ▄████████ " << endl;
	GotoXY(92, 22);    cout << u8"▀█████████▄   ███    ███     ███    ███ " << endl;
	GotoXY(92, 23);    cout << u8"   ▀███▀▀██   ███    ███     ███    █▀  " << endl;
	GotoXY(92, 24);    cout << u8"    ███   ▀  ▄███▄▄▄▄███▄▄  ▄███▄▄▄     " << endl;
	GotoXY(92, 25);    cout << u8"    ███     ▀▀███▀▀▀▀███▀  ▀▀███▀▀▀     " << endl;
	GotoXY(92, 26);    cout << u8"    ███       ███    ███     ███    █▄  " << endl;
	GotoXY(92, 27);    cout << u8"    ███       ███    ███     ███    ███ " << endl;
	GotoXY(92, 28);    cout << u8"   ▄████▀     ███    █▀      ██████████ " << endl;
	Sleep(1000);

	SetColor(241);
	GotoXY(132, 33);    cout << u8"     ▄████████  ▄██████▄     ▄████████ ████████▄  " << endl;
	GotoXY(132, 34);    cout << u8"    ███    ███ ███    ███   ███    ███ ███   ▀███ " << endl;
	GotoXY(132, 35);    cout << u8"    ███    ███ ███    ███   ███    ███ ███    ███ " << endl;
	GotoXY(132, 36);    cout << u8"   ▄███▄▄▄▄██▀ ███    ███   ███    ███ ███    ███ " << endl;
	GotoXY(132, 37);    cout << u8"  ▀▀███▀▀▀▀▀   ███    ███ ▀███████████ ███    ███ " << endl;
	GotoXY(132, 38);    cout << u8"  ▀███████████ ███    ███   ███    ███ ███    ███ " << endl;
	GotoXY(132, 39);    cout << u8"    ███    ███ ███    ███   ███    ███ ███   ▄███ " << endl;
	GotoXY(132, 40);    cout << u8"    ███    ███  ▀██████▀    ███    █▀  ████████▀  " << endl;
	GotoXY(132, 41);    cout << u8"    ███    ███                                    " << endl;
	Sleep(2000);

	ConvertImage(f11, 240, 0, 0, 0);

	for (int i = 0; i <= 5; i++)
	{
		SetColor(244);
		GotoXY(8 + 4 * i, 8 - i);     cout << u8" ▄████████    ▄████████  ▄██████▄     ▄████████    ▄████████  ▄█  ███▄▄▄▄      ▄██████▄ " << endl;
		GotoXY(8 + 4 * i, 9 - i);     cout << u8"███    ███   ███    ███ ███    ███   ███    ███   ███    ███ ███  ███▀▀▀██▄   ███    ███" << endl;
		GotoXY(8 + 4 * i, 10 - i);    cout << u8"███    █▀    ███    ███ ███    ███   ███    █▀    ███    █▀  ███▌ ███   ███   ███    █▀  " << endl;
		GotoXY(8 + 4 * i, 11 - i);    cout << u8"███         ▄███▄▄▄▄██▀ ███    ███   ███          ███        ███▌ ███   ███  ▄███        " << endl;
		GotoXY(8 + 4 * i, 12 - i);    cout << u8"███        ▀▀███▀▀▀▀▀   ███    ███ ▀███████████ ▀███████████ ███▌ ███   ███ ▀▀███ ████▄  " << endl;
		GotoXY(8 + 4 * i, 13 - i);    cout << u8"███    █▄  ▀███████████ ███    ███          ███          ███ ███  ███   ███   ███    ███ " << endl;
		GotoXY(8 + 4 * i, 14 - i);    cout << u8"███    ███   ███    ███ ███    ███    ▄█    ███    ▄█    ███ ███  ███   ███   ███    ███ " << endl;
		GotoXY(8 + 4 * i, 15 - i);    cout << u8"████████▀    ███    ███  ▀██████▀   ▄████████▀   ▄████████▀  █▀    ▀█   █▀    ████████▀  " << endl;
		GotoXY(8 + 4 * i, 16 - i);    cout << u8"             ███    ███                                                                  " << endl;

		SetColor(241);
		GotoXY(132, 33 - 6 * i);    cout << u8"     ▄████████  ▄██████▄     ▄████████ ████████▄  " << endl;
		GotoXY(132, 34 - 6 * i);    cout << u8"    ███    ███ ███    ███   ███    ███ ███   ▀███ " << endl;
		GotoXY(132, 35 - 6 * i);    cout << u8"    ███    ███ ███    ███   ███    ███ ███    ███ " << endl;
		GotoXY(132, 36 - 6 * i);    cout << u8"   ▄███▄▄▄▄██▀ ███    ███   ███    ███ ███    ███ " << endl;
		GotoXY(132, 37 - 6 * i);    cout << u8"  ▀▀███▀▀▀▀▀   ███    ███ ▀███████████ ███    ███ " << endl;
		GotoXY(132, 38 - 6 * i);    cout << u8"  ▀███████████ ███    ███   ███    ███ ███    ███ " << endl;
		GotoXY(132, 39 - 6 * i);    cout << u8"    ███    ███ ███    ███   ███    ███ ███   ▄███ " << endl;
		GotoXY(132, 40 - 6 * i);    cout << u8"    ███    ███  ▀██████▀    ███    █▀  ████████▀  " << endl;
		GotoXY(132, 41 - 6 * i);    cout << u8"    ███    ███                                    " << endl;

		Sleep(250);

		if (i != 5)
		{
			GotoXY(8 + 4 * i, 8 - i);     cout << u8"                                                                                        " << endl;
			GotoXY(8 + 4 * i, 9 - i);     cout << u8"                                                                                        " << endl;
			GotoXY(8 + 4 * i, 10 - i);    cout << u8"                                                                                         " << endl;
			GotoXY(8 + 4 * i, 11 - i);    cout << u8"                                                                                         " << endl;
			GotoXY(8 + 4 * i, 12 - i);    cout << u8"                                                                                         " << endl;
			GotoXY(8 + 4 * i, 13 - i);    cout << u8"                                                                                         " << endl;
			GotoXY(8 + 4 * i, 14 - i);    cout << u8"                                                                                         " << endl;
			GotoXY(8 + 4 * i, 15 - i);    cout << u8"                                                                                         " << endl;
			GotoXY(8 + 4 * i, 16 - i);    cout << u8"                                                                                         " << endl;

			GotoXY(132, 33 - 6 * i);    cout << u8"                                                  " << endl;
			GotoXY(132, 34 - 6 * i);    cout << u8"                                                  " << endl;
			GotoXY(132, 35 - 6 * i);    cout << u8"                                                  " << endl;
			GotoXY(132, 36 - 6 * i);    cout << u8"                                                  " << endl;
			GotoXY(132, 37 - 6 * i);    cout << u8"                                                  " << endl;
			GotoXY(132, 38 - 6 * i);    cout << u8"                                                  " << endl;
			GotoXY(132, 39 - 6 * i);    cout << u8"                                                  " << endl;
			GotoXY(132, 40 - 6 * i);    cout << u8"                                                  " << endl;
			GotoXY(132, 41 - 6 * i);    cout << u8"                                                  " << endl;
		}
	}

	SetConsoleOutputCP(old);

	GotoXY(20, 40);
}