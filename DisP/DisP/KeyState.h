#pragma once
#include "Timer.h"
#include <string>

class KeyState
{
protected:
#define HOLD 1
#define CLICK 2
	char keyCode;
	Timer *timer;
	int lastHitTime;
	int previousHit;
	int holdThreshold; // Need a setter function or a default value.
	int doubleThreshold;
public:
	int keyDown();
	virtual std::string name() = 0;
	virtual int pressed();
	virtual int click();
	virtual int hold();
	virtual int dbclick();
	virtual int doubleClick();
	virtual int holdClick();
	virtual KeyState *nextState() = 0;
	KeyState(char code, Timer *tim, int lastTime = 0, int preHit = 0);
};

class Idle : public KeyState
{
	using KeyState::KeyState;
	KeyState *nextState();
	std::string name();
};

class Pressed : public KeyState
{
public:
	using KeyState::KeyState;
	int pressed();
	KeyState *nextState();
	std::string name();
};

class Hold : public Pressed
{
public:
	using Pressed::Pressed;
	int hold();
	KeyState *nextState();
	std::string name();
};

class Click : public Pressed
{
public:
	using Pressed::Pressed;
	int click();
	KeyState *nextState();
	std::string name();
};

class DoubleClick : public Click
{
public:
	using Click::Click;
	int doubleClick();
	int dbclick();
	KeyState *nextState();
	std::string name();
};

class HoldClick : public Click
{
public:
	using Click::Click;
	int holdClick();
	int hdlick();
	KeyState *nextState();
	std::string name();
};