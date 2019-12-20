#pragma once
#include "display.h"
class frame 
{
protected:
	int Go;//Value of Go determines whether there is one frame shoud be executed at this time.
	int SetFps = 1000;//Fps default to be 30.
	int FrameTime = 1;
	int Endo = 0;//If Endo = 1, It will stop after currently executing Cycle.
	int Skip();	 //Skip upcoming frame.
	int setFps(unsigned int a);	//Set FPS to a certain number.
	void FPS();	 //To ensure the FPS is no more than FrameTime.
	int Inis();
	int RES();
	int ReadIn();
	int AnaIn();
	int Entry();
	int Work();
	int Outro();
	int Termi();		
	void EndFrame();	//End loop after completing this frame.
	World scene;
	keyset keys;
	canvas canv;
	Timer timer;
	virtual int Frame();
public:
	virtual void start();
};

class TestFrame : public frame
{
protected:
	int Inis();
	int Frame();
	World2D scene;
public:
	int Test();
};