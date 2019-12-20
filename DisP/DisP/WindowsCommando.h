#pragma once
#include <Windows.h>//为啥display里面就可以不用include
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
struct posi;
void curse(int x, int y);
void curse(posi P);
void curse(COORD P);
Mouse ReadMouse();
Key ReadKey();
int IniWindow(char* name);
Input ReadInput();