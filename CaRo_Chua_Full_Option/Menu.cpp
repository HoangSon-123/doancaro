#include"caro.h"
#define MAX 4 // Gia tri cua menu
//khai bao cac kieu du lieu
static int flag;
void About()
{
	while (1) {
		system("cls");
		SetColor(4);
		GotoXY(20, 8);
		cout << "     |       ||||||||    |||||||||  ||     ||  ||||||||||";
		GotoXY(20, 9);
		cout << "    |||      ||     ||   ||     ||  ||     ||      ||";
		GotoXY(20, 10);
		cout << "   || ||     ||||||||    ||     ||  ||     ||      ||";
		GotoXY(20, 11);
		cout << "  |||||||    ||     ||   ||     ||  ||     ||      ||";
		GotoXY(20, 12);
		cout << " ||     ||   ||      ||  ||     ||  ||     ||      ||";
		GotoXY(20, 13);
		cout << "||       ||  ||||||||    |||||||||  |||||||||      ||";
		GotoXY(12, 18);
		SetColor(13);
		cout << "De chien thang, nguoi choi can co 5 quan co cung loai tren mot duong thang.";
		GotoXY(20, 20);
		cout << "            Kich thuoc ban co la 12x12";
		GotoXY(18, 22);
		cout << "Su dung cac phim W S A D de di chuyen den vi tri mong muon";
		GotoXY(20, 24);
		cout << "          Nhan phim Enter de xac nhan o danh";
		GotoXY(20, 26);
		cout << "     Do an cuoi ky Nhap mon lap trinh nhom 5 20CTT3";
		GotoXY(20,28);
		cout << "      Giao vien huong dan: Thay Truong Toan Thinh";
		GotoXY(20, 30);
		cout << "                Sinh vien thuc hien:";
		GotoXY(20, 31);
		cout << "                Pham Phu Hoang Son";
		GotoXY(20, 32);
		cout << "                Thai Ngoc Vinh Hien";
		GotoXY(20, 33);
		cout << "                  Tran Trong Dai";
		GotoXY(20, 34);
		cout << "                   Phan Duy Dat";
		GotoXY(20, 35);
		cout << "                   Vo Minh Thai";
		GotoXY(20, 39);
		cout << "          Nhan phim ESC de quay lai menu";
		char a = _getch();
		if (a == 27)
			break;
	}
}
void LoadName()
{
	system("cls");
	SetColor(12);
	GotoXY(13, 10);
	cout << "||         |||||||||       |       |||||||     ||  ||     ||    ||||||||";
	GotoXY(13, 11);
	cout << "||         ||     ||      |||      ||     ||   ||  ||||   ||   ||";
	GotoXY(13, 12);
	cout << "||         ||     ||     || ||     ||      ||  ||  || ||  ||  ||";
	GotoXY(13, 13);
	cout << "||         ||     ||    |||||||    ||      ||  ||  ||  || ||  ||   |||||";
	GotoXY(13, 14);
	cout << "||         ||     ||   ||     ||   ||     ||   ||  ||   ||||   ||     ||";
	GotoXY(13, 15);
	cout << "|||||||||  |||||||||  ||       ||  |||||||     ||  ||     ||    ||||||||";
	SetColor(12);
	GotoXY(13, 18);
	cout << "          File da luu:  ";
}
void P1()
{
	system("cls");
	PlaySound(L"winner.wav", NULL, SND_ASYNC);
	for (int a = 1; a < 35; a++)
	{
		SetColor(a);
		int i = 2, j = 15;
		GotoXY(i, j);     cout << "  XXXXXXXX      XXXXXXXX     XXXXXXX               XXXXXXX    XXXXXXX    XXXXXXXX      XXXXXX ";
		GotoXY(i, j + 1); cout << "  XXXXXXXX      XXXXXXXX     XXXXXXX               XXXXXXX    XXXXXXX    XXXXXXXXX     XXXXXX ";
		GotoXY(i, j + 2); cout << "      XXXXXX   XXXXX         XXXXXXX               XXXXXXX    XXXXXXX    XXXXXXXXXX    XXXXXX ";
		GotoXY(i, j + 3); cout << "        XXXXXXXXXX           XXXXXXX     XXXXX     XXXXXXX    XXXXXXX    XXXXXXXXXXX   XXXXXX ";
		GotoXY(i, j + 4); cout << "          XXXXXX             XXXXXXXX   XXXXXXX   XXXXXXXX    XXXXXXX    XXXXXXX XXXXX XXXXXX ";
		GotoXY(i, j + 5); cout << "        XXXXXXXXXX            XXXXXXXX XXXXXXXXX XXXXXXXX     XXXXXXX    XXXXXXX  XXXXXXXXXXX ";
		GotoXY(i, j + 6); cout << "      XXXXXX  XXXXXX           XXXXXXXXXXXX XXXXXXXXXXXX      XXXXXXX    XXXXXXX   XXXXXXXXXX ";
		GotoXY(i, j + 7); cout << "  XXXXXXXX      XXXXXXXX        XXXXXXXXXX   XXXXXXXXXX       XXXXXXX    XXXXXXX    XXXXXXXXX ";
		GotoXY(i, j + 8); cout << "  XXXXXXXX      XXXXXXXX         XXXXXXXX     XXXXXXXX        XXXXXXX    XXXXXXX     XXXXXXXX ";
		Sleep(200);
	}
	SetColor(7);
}
void P2()
{
	system("cls");
	PlaySound(L"winner.wav", NULL, SND_ASYNC);
	for (int a = 1; a < 35; a++)
	{
		SetColor(a);
		int i = 2, j = 15;
		GotoXY(i, j);     cout << "  OOOOOOOOOOOOOOOOOOOOOO     OOOOOOO              OOOOOOO   OOOOOOO   OOOOOOOOO      OOOOOO   ";
		GotoXY(i, j + 1); cout << "  OOOOOOOOOOOOOOOOOOOOOO     OOOOOOO              OOOOOOO   OOOOOOO   OOOOOOOOOO     OOOOOO   ";
		GotoXY(i, j + 2); cout << "  OOOOOOOOOOOOOOOOOOOOOO     OOOOOOO              OOOOOOO   OOOOOOO   OOOOOOOOOOO    OOOOOO   ";
		GotoXY(i, j + 3); cout << "  OOOOOOOO      OOOOOOOO     OOOOOOO    OOOOOO    OOOOOOO   OOOOOOO   OOOOOOOOOOOO   OOOOOO   ";
		GotoXY(i, j + 4); cout << "  OOOOOOOO      OOOOOOOO     OOOOOOO   OOOOOOOO   OOOOOOO   OOOOOOO   OOOOOOO OOOOO  OOOOOO   ";
		GotoXY(i, j + 5); cout << "  OOOOOOOO      OOOOOOOO      OOOOOOO OOOOOOOOOO OOOOOOOO   OOOOOOO   OOOOOOO  OOOOO OOOOOO   ";
		GotoXY(i, j + 6); cout << "  OOOOOOOOOOOOOOOOOOOOOO       OOOOOOOOOOOO OOOOOOOOOOOO    OOOOOOO   OOOOOOO   OOOOOOOOOOO   ";
		GotoXY(i, j + 7); cout << "  OOOOOOOOOOOOOOOOOOOOOO        OOOOOOOOOO   OOOOOOOOOO     OOOOOOO   OOOOOOO    OOOOOOOOOO   ";
		GotoXY(i, j + 8); cout << "  OOOOOOOOOOOOOOOOOOOOOO         OOOOOOOO     OOOOOOOO      OOOOOOO   OOOOOOO     OOOOOOOOO   ";
		Sleep(200);
	}
	SetColor(7);
}
void Draw()
{
	system("cls");
	PlaySound(L"drawngame.wav", NULL, SND_ASYNC);
	for (int a = 1; a < 15; a++)
	{
		SetColor(a);
		int i = 2, j = 15;
		GotoXY(i, j);     cout << " DDDDDDDDDDDDDDDDD     DDDDDDDDDDDDDDDDDD              DDDDD          DDDDDD                DDDDDD  ";
		GotoXY(i, j + 1); cout << " DDDDDDDDDDDDDDDDDDD   DDDDDDDDDDDDDDDDDDD            DDDDDDD         DDDDDD                DDDDDD  ";
		GotoXY(i, j + 2); cout << " DDDDDDDDDDDDDDDDDDDD  DDDDDDDD      DDDDD           DDDDDDDDD        DDDDDD                DDDDDD  ";
		GotoXY(i, j + 3); cout << " DDDDDDD      DDDDDDD    DDDDDD     DDDDD           DDDDDDDDDDD       DDDDDD     DDDDDDD    DDDDDD  ";
		GotoXY(i, j + 4); cout << " DDDDDDD       DDDDDD    DDDDDDDDDDDDDDDD          DDDDDD  DDDDD      DDDDDD    DDDDDDDDD   DDDDDD  ";
		GotoXY(i, j + 5); cout << " DDDDDDD      DDDDDDD    DDDDDDDDDDDDD            DDDDDD    DDDDDD     DDDDDD  DDDDDDDDDDD DDDDDDD  ";
		GotoXY(i, j + 6); cout << " DDDDDDDDDDDDDDDDDDDD    DDDDDD  DDDDDD          DDDDDDDDDDDDDDDDDD     DDDDDDDDDDDD DDDDDDDDDDDD   ";
		GotoXY(i, j + 7); cout << " DDDDDDDDDDDDDDDDDDD   DDDDDDDD    DDDDDDD      DDDDDDDDDDDDDDDDDDDD     DDDDDDDDDD   DDDDDDDDDD    ";
		GotoXY(i, j + 8); cout << " DDDDDDDDDDDDDDDDD     DDDDDDDD      DDDDDDD   DDDDDDD         DDDDDD     DDDDDDDD     DDDDDDDD     ";
		Sleep(200);
	}
	SetColor(7);
}
// menu man hinh chinh
int Menu()
{
	short pointer = 0;
	string Menu[] = { "NEW GAME", "LOAD GAME", "ABOUT", "EXIT" };
	flag = 1;
	while (1) {
		system("cls");
		SetColor(12);
		GotoXY(0, 0); 
		cout << endl << endl << endl << endl << endl;
		cout << "         |||||||||||||||||          |||||          |||||||||||||||||       ||||||||||||||||        " << endl;
		cout << "       ||||||||||||||||||          |||||||         |||||||||||||||||||   ||||||||||||||||||||      " << endl;
		cout << "      ||||||||||||||||||          |||||||||        |||||||     |||||||  ||||||||||||||||||||||     " << endl;
		cout << "     ||||||||                    |||||||||||       |||||||     |||||||  ||||||||      ||||||||     " << endl;
		cout << "     ||||||||                   |||||| ||||||      ||||||||||||||||||   ||||||||      ||||||||     " << endl;
		cout << "     ||||||||                  ||||||   ||||||     ||||||||||||||||     ||||||||      ||||||||     " << endl;
		cout << "      ||||||||||||||||||      |||||||||||||||||    |||||||   |||||||    ||||||||||||||||||||||     " << endl;
		cout << "       ||||||||||||||||||    |||||||||||||||||||   |||||||    |||||||    ||||||||||||||||||||      " << endl;
		cout << "         |||||||||||||||||  |||||||       |||||||  |||||||     ||||||||    ||||||||||||||||        " << endl << endl << endl << endl << endl << endl;
		drawrect(1, 1, 94, 41, 0);
		SetColor(5);
		for (int i = 0; i < MAX; i++)
		{
			GotoXY(46, 19+i);
			if (pointer == i)
			{
				cout << char(242) << Menu[i] << char(243) << endl;
			}
			else {
				cout << Menu[i] << endl;
			}
		}
		while (1)
		{
			if (_kbhit())
			{
				char key = toupper(_getch());
				if (key == 72 || key == 'W')
				{
					if (pointer > 0) {
						--pointer;
					}
					else
					{
						pointer = MAX - 1;
					}
					PlaySound(L"zapsplat_technology_electronic_device_beep_tone_002_54689.wav", NULL, SND_ASYNC);
					break;
				}
				if (key == 80 || key == 'S')
				{
					if (pointer < MAX - 1)
					{
						++pointer;
					}
					else {
						pointer = 0;
					}
					PlaySound(L"zapsplat_technology_electronic_device_beep_tone_002_54689.wav", NULL, SND_ASYNC);
					break;
				}
		
				if (key == 13)
				{
					switch (pointer)
					{
					case 0: case 1:
						StartGame(pointer);
						break;
					case 2:
						//in quy tac choi o day
						About();
						break;
					case 3:
						GotoXY(40, 28);
						cout << "Ban co muon thoat Y/N:";
						if (toupper(_getch()) == 'Y') {
							ExitGame();
							flag = -1;
							break;
						}
					}
					break;
				}

			}

		}
		if (flag == -1)
		{
			break;
		}
		Sleep(200);
	}
	
	return pointer;
}
void drawl(int n,char b) {
	if (b == 0) {
		cout << char(218);
		for (int i = 0; i <= n; i++) cout << char(196);
		cout << char(191);
	}
	else if (b == 1) {
		cout << char(192);
		for (int i = 0; i <= n; i++) cout << char(196);
		cout << char(217);
	}
}
void drawl1(int X, int Y, int n) {
	for (int i = 0; i < n-5; i++) {
		GotoXY(X, Y + i); cout << char(179);
	}
}
void drawrect(int X, int Y, int m, int n, short c) {
	SetColor(c);
	GotoXY(X, Y);
	drawl(m, 0);
	GotoXY(X, Y +1);
	drawl1(X, Y+1,n);
	drawl1(m + 2 + X, Y + 1,n);
	GotoXY(X, Y + n -5);
	drawl(m, 1);
}
