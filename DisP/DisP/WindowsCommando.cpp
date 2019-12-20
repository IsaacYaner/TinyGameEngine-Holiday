#include <Windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;

struct posi { int x; int y; };

int  IniWindow(char* name)
{
	HWND hwnd;
	SetConsoleTitle((LPCSTR)name);
	Sleep(40);
	hwnd = FindWindow(NULL, name);


	int ScrWid, ScrHei;
	ScrHei = GetSystemMetrics(SM_CYSCREEN);
	ScrWid = GetSystemMetrics(SM_CXSCREEN);
	SetWindowPos(hwnd, HWND_TOPMOST, -4, -4, ScrWid, ScrHei, SWP_SHOWWINDOW);
	RECT rect;
	GetWindowRect(hwnd, &rect);
	SetWindowPos(hwnd, HWND_TOPMOST, (ScrWid - (rect.right - rect.left)) / 2, (ScrHei - (rect.bottom - rect.top)) / 2, ScrWid, ScrHei, SWP_SHOWWINDOW);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cci);



	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	mode &= ~ENABLE_INSERT_MODE;
	//	mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin, mode);
	return  0;
}

void curse(posi po)
{

	CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;
	HANDLE    hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = 2 * po.x;
	csbiInfo.dwCursorPosition.Y = po.y;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void curse(COORD po)
{

	CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;
	HANDLE    hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = po.X / 2 * 2;//To avoid printing on odd numbers LOL
	csbiInfo.dwCursorPosition.Y = po.Y;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

struct Mouse {
	BOOL moved;
	COORD Pos;
	DWORD State;
	DWORD Flag;
};
struct Key {
	bool pressed;
	DWORD count;
	DWORD code;
	DWORD scancode;
	DWORD control;
	union {
		WCHAR Unicode;
		char Ascii;
	}Uchar;
};
struct Input {
	DWORD	eventtype;
	Mouse mouse;
	Key key;
};
Mouse ReadMouse()
{
	Mouse mouse;
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD Rec;
	DWORD res;
	ReadConsoleInput(hIn, &Rec, 1, &res);
	mouse.Pos = Rec.Event.MouseEvent.dwMousePosition;
	mouse.State = Rec.Event.MouseEvent.dwButtonState;
	mouse.Flag = Rec.Event.MouseEvent.dwEventFlags;
	return mouse;
}
Key ReadKey()
{
	Key key;
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD Rec;
	DWORD res;
	ReadConsoleInput(hIn, &Rec, 1, &res);
	key.pressed = Rec.Event.KeyEvent.bKeyDown;
	key.count = Rec.Event.KeyEvent.wRepeatCount;
	key.code = Rec.Event.KeyEvent.wVirtualKeyCode;
	key.scancode = Rec.Event.KeyEvent.wVirtualScanCode;
	key.control = Rec.Event.KeyEvent.dwControlKeyState;
	return key;
}
Input ReadInput()
{
	Input input;
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD Rec;
	DWORD res;
	//DWORD Eventtype;
	ReadConsoleInput(hIn, &Rec, 1, &res);
	input.eventtype = Rec.EventType;
	input.mouse.Pos = Rec.Event.MouseEvent.dwMousePosition;
	input.mouse.State = Rec.Event.MouseEvent.dwButtonState;
	input.mouse.Flag = Rec.Event.MouseEvent.dwEventFlags;
	input.key.pressed = Rec.Event.KeyEvent.bKeyDown;
	input.key.count = Rec.Event.KeyEvent.wRepeatCount;
	input.key.code = Rec.Event.KeyEvent.wVirtualKeyCode;
	input.key.scancode = Rec.Event.KeyEvent.wVirtualScanCode;
	input.key.control = Rec.Event.KeyEvent.dwControlKeyState;

	return input;
}//为什么这时mouse坐标会重置


void curse(int x, int y)
{

	CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;
	HANDLE    hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = 2 * x;
	csbiInfo.dwCursorPosition.Y = y;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}