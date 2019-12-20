#include <Windows.h>
#include <map>
#include <string>
#include <iostream>
#include <thread>
#include "Coord.h"
#include "WindowsCommando.h"
#include "Inps.h"
using namespace std;

int key(char c)//Check whether certain key is pressed.
{
	return 0x8000 & GetAsyncKeyState(c);
}

char keyset::value(string s)
{
	return schema[s];
}

KeyState *keyset::state(string s)
{
	return keys[schema[s]];
}

void keyset::refresh()
{
	span = timer.stop();
	map<char, KeyState *>::iterator i;
	for (i = keys.begin(); i != keys.end(); i++)
	{
		i->second = i->second->nextState();
	}
}

int keyset::press(string a)
{
	return state(a)->pressed();
}

int keyset::click(string a)
{
	return state(a)->click();
}

int keyset::hold(string a)
{
	return state(a)->hold();
}

int keyset::dbclick(string a)
{
	return state(a)->doubleClick();
}

int keyset::duoclick(string a)
{
	return state(a)->doubleClick();
}

int keyset::doubleClick(string a)
{
	return state(a)->doubleClick();
}

int keyset::hdclick(string a)
{
	return state(a)->holdClick();
}

int keyset::holdClick(string a)
{
	return state(a)->holdClick();
}

void keyset::setSpan(int a)
{
	span = a;
}

void keyset::setHold(int a)
{
	holdTime = a;
}

void keyset::setDouble(int a)
{
	dbclickTime = a;
}

void keyset::setPeak(int a)
{
	maxClickTime = a;
}

Coord keyset::position()
{
	return 	Coord((int)mouse.Pos.X / 2, (int)mouse.Pos.Y);
}

Coord keyset::pos()
{
	return 	Coord((int)mouse.Pos.X / 2, (int)mouse.Pos.Y);
}

void sense(Key* key, Mouse* mouse)//Not being used yet, but may be helpful in later version.
{
	Input input;
	while (1)
	{
		input = ReadInput();
		if (input.eventtype == KEY_EVENT)
			*key = input.key;
			*mouse = input.mouse;
	}
	return;
}

void keyset::sense(Mouse* mou)
{
	while (1)
	{
		*mou = ReadMouse();
	}
	return;
}

void keyset::capture()
{
	thread any(&keyset::sense, this, &mouse);
	any.detach();
}

keyset::keyset() 
{
	//auto func = bind(&keyset::sense, this);
	span = 1;
	maxClickTime = 200;
	holdTime = 300;
	dbclickTime = 100;
	//Set projection from "alphabet" to 'Capital letter'
	for (int i = 0x41; i <= 0x5A; i++)
	{
		char c = (char)i;
		string temp(1,c);
		schema[temp] = (char)i;
		c += 32;
		temp.pop_back();
		temp.push_back(c);
		schema[temp] = (char)i;
	}
	//Map for numbers
	for (int i = 0x30; i <= 0x39; i++)
	{
		char c = (char)i;
		char *temp = &c;
		schema[temp] = (char)i;
	}
	schema["LeftClick"] = VK_LBUTTON;
	schema["LClick"] = VK_LBUTTON;
	schema["RightClick"] = VK_RBUTTON;
	schema["RClick"] = VK_RBUTTON;
	schema["MiddleClick"] = VK_MBUTTON;
	schema["MClick"] = VK_MBUTTON;
	schema["Leftclick"] = VK_LBUTTON;
	schema["Lclick"] = VK_LBUTTON;
	schema["Rightclick"] = VK_RBUTTON;
	schema["Rclick"] = VK_RBUTTON;
	schema["Middleclick"] = VK_MBUTTON;
	schema["Mclick"] = VK_MBUTTON;
	schema["Backspace"] = VK_BACK;
	schema["Tab"] = VK_TAB;
	schema["TAB"] = VK_TAB;
	schema["tab"] = VK_TAB;
	schema["Enter"] = VK_RETURN;
	schema["ENTER"] = VK_RETURN;
	schema["enter"] = VK_RETURN;
	schema["Shift"] = VK_SHIFT;
	schema["SHIFT"] = VK_SHIFT;
	schema["shift"] = VK_SHIFT;
	schema["LShift"] = VK_LSHIFT;
	schema["LSHIFT"] = VK_LSHIFT;
	schema["Lshift"] = VK_LSHIFT;
	schema["RShift"] = VK_RSHIFT;
	schema["RSHIFT"] = VK_RSHIFT;
	schema["Rshift"] = VK_RSHIFT;
	schema["Control"] = VK_CONTROL;
	schema["CONTROL"] = VK_CONTROL;
	schema["control"] = VK_CONTROL;
	schema["Ctrl"] = VK_CONTROL;
	schema["CTRL"] = VK_CONTROL;
	schema["ctrl"] = VK_CONTROL;
	schema["Alt"] = VK_MENU;
	schema["alt"] = VK_MENU;
	schema["ALT"] = VK_MENU;
	schema["LAlt"] = VK_LMENU;
	schema["RAlt"] = VK_RMENU;
	schema["Esc"] = VK_ESCAPE;
	schema["ESC"] = VK_ESCAPE;
	schema["esc"] = VK_ESCAPE;
	schema["ESCAPE"] = VK_ESCAPE;
	schema["Capital"] = VK_CAPITAL;
	schema["Caps"] = VK_CAPITAL;
	schema["Cap"] = VK_CAPITAL;
	schema["CAP"] = VK_CAPITAL;
	schema["Space"] = VK_SPACE;
	schema["SPACE"] = VK_SPACE;
	schema["space"] = VK_SPACE;
	schema["Left"] = VK_LEFT;
	schema["LEFT"] = VK_LEFT;
	schema["left"] = VK_LEFT;
	schema["Right"] = VK_RIGHT;
	schema["RIGHT"] = VK_RIGHT;
	schema["right"] = VK_RIGHT;
	schema["Up"] = VK_UP;
	schema["UP"] = VK_UP;
	schema["up"] = VK_UP;
	schema["Down"] = VK_DOWN;
	schema["DOWN"] = VK_DOWN;
	schema["down"] = VK_DOWN;
	schema["NUM0"] = VK_NUMPAD0;
	schema["NUM1"] = VK_NUMPAD1;
	schema["NUM2"] = VK_NUMPAD2;
	schema["NUM3"] = VK_NUMPAD3;
	schema["NUM4"] = VK_NUMPAD4;
	schema["NUM5"] = VK_NUMPAD5;
	schema["NUM6"] = VK_NUMPAD6;
	schema["NUM7"] = VK_NUMPAD7;
	schema["NUM8"] = VK_NUMPAD8;
	schema["NUM9"] = VK_NUMPAD9;
	schema["num0"] = VK_NUMPAD0;
	schema["num1"] = VK_NUMPAD1;
	schema["num2"] = VK_NUMPAD2;
	schema["num3"] = VK_NUMPAD3;
	schema["num4"] = VK_NUMPAD4;
	schema["num5"] = VK_NUMPAD5;
	schema["num6"] = VK_NUMPAD6;
	schema["num7"] = VK_NUMPAD7;
	schema["num8"] = VK_NUMPAD8;
	schema["num9"] = VK_NUMPAD9;
	map<string, int>::iterator i;
	for (i = schema.begin(); i != schema.end(); i++)
	{
		if (keys.end() == keys.find(i->second))//If not found
		{
			keys[i->second] = new Idle(i->second, &Timer());//Create a new state
		}
	}
}

keyset::~keyset()
{
}
