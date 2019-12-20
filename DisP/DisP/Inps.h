#pragma once
#include <Windows.h>
#include <map>
#include <string>
#include "Coord.h"
#include "WindowsCommando.h"
#include "KeyState.h"
#include "Timer.h"
using namespace std;
class keyset
{
private:
	map<char, KeyState*> keys;
	map<string, int>schema;
	int span;//time that should be added between two refresh()es.
	int keyId;
	int maxClickTime;//Max time permitted to hold to be considered to be a clock rather than holding.
	int holdTime;//The time kept for a key to show that it is being held. 
	int dbclickTime;//The time permitted to perform a double click between to seccessive clicks.
	Mouse mouse;
	Timer timer;
public:
	void setSpan(int a);//Setter function for span.
	void setHold(int a);//Setter function for hold.
	void setPeak(int a);//Setter function for peak.
	void setDouble(int a);//Setter function for dbclick.
	void refresh();
	char value(string a);//getter function  of schema[], return key code of given name.
	KeyState *state(string a);//direct get key state from given name of key.
	int press(string a);
	int click(string a);
	int hold(string a);
	int dbclick(string a);
	int duoclick(string a);//Could I use alias? #######
	int doubleClick(string a);
	int hdclick(string a);
	int holdClick(string a);
	Coord position();//Return position of mouse.
	Coord pos();//Return position of mouse.
	void sense(Mouse *mouse);//Function placed in capture to detect Mouse movement.
	void capture();	//Detach a thread to capture inputs from std_input.
	keyset();
	~keyset();
};
