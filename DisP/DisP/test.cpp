#include "Inps.h"
#include "Timer.h"
#include "FairySamples.h"
#include "SysFrame.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
	TestFrame game;
	game.start();
	return 0;
}

int TestFrame::Test()//Later will have a outer interface to receive various parameters.
{
	scene.job();
	if (keys.press("LeftClick"))
	{
		if(scene.square[keys.pos().x][keys.pos().y] == nullptr)
			scene.square[keys.pos().x][keys.pos().y] = ( new Painter(keys.pos(), "À¶"));
		//scene.square[keys.Pos().X / 2 % canv.wid()][keys.Pos().Y % canv.hei()] = 6;
		//canv.Layer[keys.Pos().X / 2 % canv.wid()][keys.Pos().Y % canv.hei()] = 6;
	}
	if (keys.press("RClick"))
	{
		if (scene.square[keys.pos().x][keys.pos().y] == nullptr)
			scene.square[keys.pos().x][keys.pos().y] = (new Painter(keys.pos(), "ÂÌ"));
		//scene.square[keys.Pos().X / 2 % canv.wid()][keys.Pos().Y % canv.hei()] = 16;
	}
	if (keys.press("MClick"))
	{
		if (scene.square[keys.pos().x][keys.pos().y] != nullptr)
		{
			delete scene.square[keys.pos().x][keys.pos().y];
			scene.square[keys.pos().x][keys.pos().y] = nullptr;
		}
		//scene.square[keys.Pos().X / 2 % canv.wid()][keys.Pos().Y % canv.hei()] = 26;
	}
	canv.project(scene);//Would be deleted later.
	canv.dis();
	if (keys.hdclick("space"))
	{
		EndFrame();
	}
	return 0;
}

int TestFrame::Inis()
{
	IniWindow((char *)"Happy");//Set Console 
							   //setFps(0);			//Set Max FPS
	keys = keyset();		//Define input source.
	keys.capture();			//Start capturing keys.

	canv = canvas(320, 180);//Set canvas size.
	scene = World2D(320, 180);//Create a scene.
	timer = Timer();		//Initialise a timer.
	Fairy* ptr = new Painter(keys.pos(), "À¶");
	scene.addFairy(ptr);
	return 0;
}

int TestFrame::Frame()
{
	Inis();
	while (!Endo)
	{
		FPS();
		if (Go)
		{
			Test();
			Entry();
			Work();
			Outro();
		}
		RES();
	}
	Termi();
	return 0;
}