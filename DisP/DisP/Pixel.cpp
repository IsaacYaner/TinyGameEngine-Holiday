#include "Pixel.h"



Fairy * Pixel::job()
{
	return nullptr;
}

Pixel::Pixel(Coord coord, std::string name)
{
	colorCode = -1;
	colorName = name;
	position = coord;
}

Pixel::Pixel(int x, int y, std::string name)
{
	colorCode = -1;
	colorName = name;
	position = Coord(x, y);
}

Pixel::Pixel(Coord coord, int color)
{
	position = coord;
	colorCode = color;
}

Pixel::Pixel(int x, int y, int color)
{
	position = Coord(x, y);
	colorCode = color;
}

Pixel::Pixel()
{
}


Pixel::~Pixel()
{
}


void Pixel::setColor(int c)
{
	colorCode = c;
}

void Pixel::setPosition(Coord coord)
{
	position = coord;
}

Coord Pixel::getPosition()
{
	return position;
}

std::string Pixel::getName()
{
	return colorName;
}

int Pixel::getColor()
{
	return colorCode;
}

int Pixel::height()
{
	return position.z;
}
