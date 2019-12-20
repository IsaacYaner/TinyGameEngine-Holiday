#include "WindowsCommando.h"
#include "Timer.h"
#include "Inps.h"
#include "SysFrame.h"
#include "display.h"
#include "world.h"
#include <Time.h>
#include <stdio.h>
#include <Windows.h>
#include <thread>
#include <iostream>
#define END_FRAME Endo = 1;

/*Test arguments*/
int lines = 50;
int cont = 0;


int frame::Skip()
{
	Go = 0;// ²»¼ÓthisÐÐÂð
	return 0;
}
int frame::setFps(unsigned int a)//To be called by another designed FPS setting function. So no further examinations needed here.
{
	SetFps = a;
	FrameTime = a ? 1000 / a : 1;
	return 0;
}
void frame::FPS()//To restrict the function perform Less frames than Fps set.
{
	if (!SetFps)//To reduce function calls. Actually can be deleted.
		return;
	if (!timer.Fps(FrameTime))
		Skip();
	return;
}
int frame::Inis()
{/*
	IniWindow((char *)"Happy");
	setFps(1000);
	keys = keyset();
	keys.setSpan(FrameTime);//Could change this by time costed every frame.
	//keys.capture();
	canv = canvas(320,180);
	scene = World(320,180);
	timer = Timer();
	keys.capture();*/

	/*for (int i = 0; i < 256; i++)
	{
		set_color(i);
		printf("%d%d%d%d%d¡ö¡ö  ¡õ  ¡ö¡ö¡ö\n", i, i, i, i, i);
	}*/
	/*canv.dye("ºÚ");
	Fairy* ptr = new biu(&scene);
	scene.addFairy(ptr);*/
	return 0;
}
int frame::ReadIn()
{
	keys.refresh(); 
	return 0;
}
int frame::AnaIn()
{

	return 0;
}
int frame::Entry()
{
	ReadIn();
	AnaIn();
	return 0;
}
int frame::Work()
{

	return 0;
}
int frame::Outro()
{
	return 0;
}
int frame::RES()
{
	Go = 1;
	return 0;
}//Recover fatal values.
int frame::Termi()
{
	//keys.~keyset();
	//canv.~canvas();
	return 0;
}
void frame::EndFrame()
{
	set_color(255);
	END_FRAME
}

int frame::Frame()
{
	Inis();
	while (!Endo)
	{
		FPS();
		if (Go)
		{
			Entry();
			Work();
			Outro();//Call outer functions in outro.
		}
		RES();
	}
	Termi();
	return 0;
}

void frame::start()
{
	Frame();
	return;
}
