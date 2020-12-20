#ifndef __CARO_H__
#define _CARO_H__
#include<iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <mmsystem.h>
//am thanh
#pragma comment(lib, "winmm.lib")
// khai bao std
using namespace std;
// Cac ki tu trong game
void GotoXY(int x, int y);
void About();
void P1();
void P2();
void Draw();
void LoadName();

void drawl(int n, char b);
void drawl1(int X, int Y, int n);
void drawrect(int X, int Y, int m, int n, short c);
//ham di chuyen
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
// Cac ham cua tro choi
int Menu();
short TestBoard(int _X, int _Y);
void FixConsoleWindow();
void ResetData();
void DrawBoard(int pSize);
void StartGame(short pPointer);
void GabageCollect();
void ExitGame();
int ProcessFinish(int pWhoWin);
int AskContinue();
int CheckBoard(int pX, int pY);
void Save();
void Load();
void GamePlay();
// mau sac 
void SetColor(WORD color);
#endif // !__CARO_H__



