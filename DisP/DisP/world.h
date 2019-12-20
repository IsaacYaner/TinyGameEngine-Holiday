#pragma once
//仅针对单屏单世界游戏
#include "Fairy.h"
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

class World2D : public World
{
public:
	Fairy* **square;	//content of World
	int wid();		//Getter function for width.
	int hei();		//Getter function for height.
	Fairy* space(int a, int b);	//Getter function for pixel on certain point of the square
	World2D(int wid, int hei);	//Constructor, return a 2D World withs
	World2D();
};

//Need 删除Fairy