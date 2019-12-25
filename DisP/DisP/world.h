#pragma once
//仅针对单屏单世界游戏
#include "Fairy.h"
#include "Particle.h"
#include "FairyList.h"
class World : public Fairy
{
protected:
	int width;
	int height;
public:
	Fairy * fairy;	//List of Fairy
	World();
	~World();
	Fairy* job();	//Invoke each Fairy's job().
	void addFairy(Fairy* a);	//Add a fairy to the end of Fairy list.
};

class PixelWorld2D : public World
{
public:
	SortedPixelList* ** content; //content of World *NEW*
	Fairy* **square;	//content of World
	Fairy* Last;
	int wid();		//Getter function for width.
	int hei();		//Getter function for height.
	/*
	Add painter
	pass to Canvas
	delete painters
	Need to rewrite destroy function.
	*/
	Fairy* job();	//Invoke each Fairy's job().
	Fairy* tempCamera(int a, int b);
	SortedPixelList* space(int a, int b);	//Getter function for pixel on certain point of the square//Get a 2D space later
	PixelWorld2D(int wid, int hei);	//Constructor, return a 2D World withs
	PixelWorld2D();
};

//Need 删除Fairy