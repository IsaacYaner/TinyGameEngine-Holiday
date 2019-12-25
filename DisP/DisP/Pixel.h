#pragma once
#include "Fairy.h"
#include "Coord.h"
#include <string>
class Pixel :
	public Fairy
{
	int colorCode;
	std::string colorName;
	Coord position;
public:
	Fairy * job();
	Pixel(Coord coord, std::string name);
	Pixel(int x, int y, std::string name);
	Pixel(Coord coord, int color = 0);
	Pixel(int x, int y, int color = 0);
	void setColor(int c);
	void setPosition(Coord coord);
	Coord getPosition();
	std::string getName();
	int getColor();
	int height();
	Pixel();
	~Pixel();
};

