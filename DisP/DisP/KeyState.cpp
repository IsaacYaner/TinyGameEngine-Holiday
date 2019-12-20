#include "KeyState.h"
#include <Windows.h>
#include <iostream>
KeyState::KeyState(char n, Timer *t, int l, int p)
{
	keyCode = n;
	timer = t;
	lastHitTime = l;
	previousHit = p;
	holdThreshold = 300;
	doubleThreshold = 150;
}

int KeyState::pressed()
{
	return 0;
}
int KeyState::click()
{
	return 0;
}
int KeyState::hold()
{
	return 0;
}
int KeyState::dbclick()
{
	return 0;
}
int KeyState::doubleClick()
{
	return 0;
}
int KeyState::holdClick()
{
	return 0;
}
int Pressed::pressed()
{
	return 1;
}
int Click::click()
{
	return 1;
}
int DoubleClick::doubleClick()
{
	return 1;
}
int DoubleClick::dbclick()
{
	return 1;
}
int HoldClick::holdClick()
{
	return 1;
}
int HoldClick::hdlick()
{
	return 1;
}
int Hold::hold()
{
	return 1;
}

int KeyState::keyDown()
{
	return 0x8000 & GetAsyncKeyState(keyCode);
}

KeyState *Idle::nextState()
{
	if (keyDown())
	{
		timer->stop();
		return new Pressed(keyCode, timer, lastHitTime, previousHit);
	}
	else
		return this;
}

KeyState *Pressed::nextState()
{
	if (keyDown())
	{
		if (timer->rstop() >= holdThreshold)
			return new Hold(keyCode, timer, lastHitTime, previousHit);
		else
			return this;
	}
	else
	{		
		if (timer->now() - lastHitTime <= doubleThreshold)
		{
			if (previousHit == HOLD)
				return new HoldClick(keyCode, timer);
			else
				return new DoubleClick(keyCode, timer);
		}
		else
			return new Click(keyCode, timer, lastHitTime, previousHit);
	}
}

KeyState *Hold::nextState()
{
	if (keyDown())
		return this;
	return new Idle(keyCode, timer, timer->now(), HOLD);
}

KeyState *Click::nextState()
{
	return new Idle(keyCode, timer, timer->now(), CLICK);
}

KeyState *DoubleClick::nextState()
{
	return new Idle(keyCode, timer);
}

KeyState *HoldClick::nextState()
{
	return new Idle(keyCode, timer);
}

std::string Idle::name()
{
	return "";
}

std::string Pressed::name()
{
	return "Pres";
}

std::string Click::name()
{
	return "Click";
}

std::string Hold::name()
{
	return "Hold";
}

std::string DoubleClick::name()
{
	return "DoubleClick";
}

std::string HoldClick::name()
{
	return "HoldClick";
}