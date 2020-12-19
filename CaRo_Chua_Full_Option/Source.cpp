#include "caro.h"
//Hằng số 
#define BOARD_SIZE 12 // Kích thức ma trận bàn cờ 
#define LEFT 3 // Tọa độ trái màn hình bàn cờ 
#define TOP 1 // Tọa độ trên màn hình bàn cờ 

static short lx = 0, lo = 0;
struct _POINT { int x, y, c; };// x: tọa độ dòng, y: tọa độ cột, c: đánh dấu 
_POINT _A[BOARD_SIZE][BOARD_SIZE];
//Ma trận bàn cờ 
bool _TURN; //true là lượt người thứ nhất và false là lượt người thứ hai 
int _COMMAND; // Biến nhận giá trị phím người dùng nhập 
int _X, _Y; //Tọa độ hiện hành trên màn hình bàn cờ 
int winx = 0, wino = 0;
//cac ham
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// thiet ke menu dung con tro
//Hàm khởi tạo dữ liệu mặc định ban đầu cho ma trận bàn cờ (hàm nhóm Model) 
void ResetData() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[i][j].x = 4 * j + LEFT + 2; // Trùng với hoành độ màn hình bàn cờ 
			_A[i][j].y = 2 * i + TOP + 1; // Trùng với tung độ màn hình bàn cờ 
			_A[i][j].c = 0; // 0 nghĩa là chưa ai đánh dấu, nếu đánh dấu phải theo quy định như sau: -1 là lượt true đánh, 1 là lượt false đánh
		}
	}
	_TURN = true; _COMMAND = -1; // Gán lượt và phím mặc định 
	_X = _A[0][0].x; _Y = _A[0][0].y; // Thiết lập lại tọa độ hiện hành ban đầu 
	lx = 0; lo = 0;
}
void DrawBoard(int pSize) {
	drawrect(1, 1, 94, 41,22);
	drawrect(2, 0, 48, 31,22);
	drawrect(53, 2, 41, 14,22);
	drawrect(53, 14, 41, 14,22);
	drawrect(2, 28, 92, 12,22);
	SetColor(2);
	GotoXY(40, 28); cout << "--INTRODUCTION--";
	GotoXY(8, 30); cout << "Di chuyen:            A-Phai    D-Trai    W-Len      S-Xuong";
	GotoXY(32, 32); cout << " ESC-Thoat       T-Save";
	
	
	SetColor(12);
	GotoXY(55, 2); cout << "X. Player 1";
	GotoXY(57, 4);
	cout << "So van da thang: " << winx;
	GotoXY(57, 6);
	cout << "So nuoc X da di: " << lx;
	
	SetColor(9);
	GotoXY(55, 14); cout << "O. Player 2";
	GotoXY(57, 16);
	cout << "So van da thang: " << wino;
	GotoXY(57, 18);
	cout << "So nuoc O da di: " << lo;

	GotoXY(0, 0);
	SetColor(0);
	for (int i = 1; i <= pSize; i++) {
		for (int j = 1; j <= pSize; j++) {
			GotoXY(LEFT + 4 * i - 3, TOP + 2 * j);
			cout << char(196) << char(196) << char(196) << char(179);
			GotoXY(LEFT + 4 * i, TOP + j + TOP + j - 2);
			cout << char(179);
			GotoXY(3, TOP + j - 1);
			cout << char(179) << endl;
			GotoXY(3, TOP + j + 11);
			cout << char(179) << endl;
			GotoXY(3, 25);
			cout << char(179);
		}
		GotoXY(LEFT + 4 * i, TOP + 1);
		cout << char(179);
		GotoXY(LEFT + 4 * i - 3, TOP);
		cout << char(196) << char(196) << char(196) << char(179);
	}
}
void StartGame(short pointer) {
	system("cls");
	ResetData(); // Khởi tạo dữ liệu gốc  
	if (pointer==1) Load();
	DrawBoard(BOARD_SIZE);// Vẽ màn hình game 
	GamePlay();
}
//Hàm dọn dẹp tài nguyên (hàm nhóm Model) 
void GabageCollect()
{
	// Dọn dẹp tài nguyên nếu có khai báo con trỏ 
}
//Hàm thoát game (hàm nhóm Control) 
void ExitGame() 
{
	system("cls");
	GabageCollect();
	_exit(0);
	//Có thể lưu game trước khi exit 
}
//Hàm xử lý khi người chơi thua 
int ProcessFinish(int pWhoWin) {
	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2); // Nhảy tới vị trí  
										 // thích hợp để in chuỗi thắng/thua/hòa 
	switch (pWhoWin) {
	case -1:
		P1();
		winx++;
		break;
	case 1:
		P2();
		wino++;
		break;
	case 0:
		Draw();
		break;
	case 2:
		_TURN = !_TURN; // Đổi lượt nếu không có gì xảy ra 
	}
	GotoXY(_X, _Y); // Trả về vị trí hiện hành của con trỏ màn hình bàn cờ 
	return pWhoWin;
}
int AskContinue() {
	GotoXY(31, 28);
	SetColor(0);
	cout << "Nhan 'Y/N' de tiep tuc/dung: ";
	return toupper(_getch());
}
void Save() {
	string filename, name, t;

	GotoXY(4, 36);
	cout << "Nhap ten file de save, ten file khong chua dau cach: ";
	cin >> filename;
	GotoXY(4, 36);
	cout << "                                                                          ";

	ofstream fileInput(filename + ".txt");
	fileInput << lx << " " << lo << " " << _TURN << " " << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			fileInput << _A[i][j].c << " ";
		}
		fileInput << endl;
	}
	fileInput.close();

	fstream fs;
	fs.open("filesave.txt");
	while (!fs.eof()) {
		fs >> name;
		if (name != filename) {
			t = t + " " + name + " ";
		}
	}
	fs.close();

	fs.open("filesave.txt");
	fs << t + filename;
	fs.close();
}
void Load() {
	LoadName();// in chu load ra man hinh
	SetColor(0);
	GotoXY(33, 30);
	cout << "Nhan ESC de quay lai Menu";
	GotoXY(45, 18);
	string filename, name;
	fstream fileOutput("filesave.txt");   // mở file để in ra tên những file đã lưu
	while (!fileOutput.eof()) {
		fileOutput >> name;
		cout << "< " + name + " >  ";
	}
	fileOutput.close();
	GotoXY(33, 28);
	cout << "Nhap ten File muon load: ";
	short t, t1, i = 0;
	char a[100];
	while (1) {                         // Nhap ten de load file
		t = _getch();
		if (t == 27) break;
		else if (t != 13) {
			if (t != 8) {
				a[i] = char(t);
				a[i + 1] = ' ';
				i++;
			}
			else {
				i--;
				i = i * (i >= 0);
				a[i] = '  ';
			}
			GotoXY(58, 28);
			for (t1 = 0; t1 <= i; t1++) cout << a[t1];
		}
		else {
			for (t1 = 0; t1 <= i - 1; t1++) if (a[t1] != ' ') filename = filename + a[t1];
			fstream fs(filename + ".txt");
			if (fs.fail()) {
				i = 0;
				filename = "";
				GotoXY(33, 32); cout << "File khong ton tai! Nhap lai!";
				GotoXY(58, 28); cout << "                                            ";
			}
			else break;
		}
	}
	if (t == 27) Menu();
	else {
		system("cls");
		fstream fileOutput(filename + ".txt");
		while (!fileOutput.eof()) {
			fileOutput >> lx;
			fileOutput >> lo;
			fileOutput >> _TURN;
			for (int i = 0; i < BOARD_SIZE; i++) {
				for (int j = 0; j < BOARD_SIZE; j++) {
					fileOutput >> _A[i][j].c;
					GotoXY(_A[i][j].x, _A[i][j].y);
					if (_A[i][j].c == 1) {
						SetColor(9); cout << "O";
					}
					else if (_A[i][j].c == -1) {
						SetColor(12); cout << "X";
					}
				}
			}
		}
		fileOutput.close();
	}
}
//Hàm kiểm tra xem có người thắng/thua hay hòa 
short A(int i, int j) {
	if (i < 0 || j < 0 || i >= BOARD_SIZE || j >= BOARD_SIZE) return 0;
	else return _A[i][j].c;
}
short TestBoard(int _X, int _Y) {
	short row = 0, col = 0, dial = 0, diar = 0;
	short i = (_Y - TOP - 1) / 2, j = (_X - 2 - LEFT) / 4, x = -4, y = -4;
	while (x <= 0) {
		row = A(i, j + x) + A(i, j + x + 1) + A(i, j + x + 2) + A(i, j + x + 3) + A(i, j + x + 4);
		col = A(i + x, j) + A(i + x + 1, j) + A(i + x + 2, j) + A(i + x + 3, j) + A(i + x + 4, j);
		dial = A(i + x, j + y) + A(i + x + 1, j + y + 1) + A(i + x + 2, j + y + 2) + A(i + x + 3, j + y + 3) + A(i + x + 4, j + y + 4);
		diar = A(i + x, j - y) + A(i + x + 1, j - y - 1) + A(i + x + 2, j - y - 2) + A(i + x + 3, j - y - 3) + A(i + x + 4, j - y - 4);
		if (row == 5 || col == 5 || row == -5 || col == -5 || diar == 5 || diar == -5 || dial == 5 || dial == -5) break;
		x++; y++;
	}
	if (x < 1) return _A[i][j].c;
	else {
		bool draw = true;
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				if (_A[i][j].c == 0) {   // su dung _A[i][j].c la giong thay, con giong MAIN_1_FILE la _pArr[i][j].setCheck() hay gi aws!
					draw = false; break;
				}
			}
			if (!draw) break;
		}
		if (draw) return 0;   // 0 la hoa
		else  return 2;   // 2 la chua co gi xay ra
	}
}
int CheckBoard(int pX, int pY) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
				if (_TURN == true) {
					_A[i][j].c = -1; // Nếu lượt hiện hành là true thì c = -1 
					lx++;
				}
				else {
					_A[i][j].c = 1; // Nếu lượt hiện hành là false thì c = 1 
					lo++;
				}
				return _A[i][j].c;
			}
		}
	}
	return 0;
}
void MoveRight() {
	if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x)
	{
		PlaySound(L"glitched_tones_household_gaming_video_game_cartridge_console_extract_2_532.wav", NULL, SND_ASYNC);
		_X += 4;
		GotoXY(_X, _Y);
	}
}
void MoveLeft() {
	if (_X > _A[0][0].x) 
	{
		PlaySound(L"glitched_tones_household_gaming_video_game_cartridge_console_extract_2_532.wav", NULL, SND_ASYNC);
		_X -= 4;
		GotoXY(_X, _Y);
	}
}
void MoveDown() {
	if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y)
	{
		PlaySound(L"glitched_tones_household_gaming_video_game_cartridge_console_extract_2_532.wav", NULL, SND_ASYNC);
		_Y += 2;
		GotoXY(_X, _Y);
	}
}
void MoveUp() {
	if (_Y > _A[0][0].y)
	{
		PlaySound(L"glitched_tones_household_gaming_video_game_cartridge_console_extract_2_532.wav", NULL, SND_ASYNC);
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}
void GamePlay()
{
	bool validEnter = true;
	if (lx > lo) _TURN = false;
	else _TURN = true;
	while (1)
	{
		if (_TURN) {
			SetColor(12);
			GotoXY(66, 9);
			cout << "!!! LUOT X !!!";
			GotoXY(66, 21);
			cout << "              ";
		}
		else {
			SetColor(9);
			GotoXY(66, 21);
			cout << "!!! LUOT O !!!";
			GotoXY(66, 9);
			cout << "              ";
		}
		GotoXY(_X,_Y);

		_COMMAND = toupper(_getch());
		if (_COMMAND == 'A') MoveLeft();
		else if (_COMMAND == 'W') MoveUp();
		else if (_COMMAND == 'S') MoveDown();
		else if (_COMMAND == 'D') MoveRight();
		else if (_COMMAND == 13) {// Người dùng đánh dấu trên màn hình bàn cờ 
			PlaySound(L"glitched_tones_household_gaming_video_game_cartridge_console_extract_2_532.wav", NULL, SND_ASYNC);
			switch (CheckBoard(_X, _Y)) {

			case -1:
				SetColor(12);
				cout << "X";
				GotoXY(74, 6);
				cout << lx;
				break;
			case 1:
				SetColor(9);
				cout << "O";
				GotoXY(74, 18);
				cout << lo;
				break;
			case 0: validEnter = false; break; // Khi đánh vào ô đã đánh rồi 
			}
			if (validEnter) {
				switch (ProcessFinish(TestBoard(_X,_Y))) {
				case -1: case 1: case 0:
					while (1) {
						if (AskContinue() == 'N') {
							ExitGame();
							break;
						}
						if (AskContinue() == 'Y') {
							StartGame(0);
							break;
						}
					}
				}
			}
			validEnter = true; // Mở khóa  
		}
	if (_COMMAND == 27) {                                                                               
		GotoXY(4, 34);
		cout << "BAN CO MUON LUU LAI KHONG? NHAN PHIM T/N DE SAVE/THOAT!" << endl;
		short c = toupper(_getch());
		if (c == 'T') {
			Save(); break;
		}
		else break;
	}
	else if (toupper(_COMMAND) == 'T') {
		Save();
		GotoXY(_X, _Y);
		continue;
		}
	}
}
// ham mau sac
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}