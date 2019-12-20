#include "Coord.h"



Coord::Coord(int hori, int vert)
{
	x = hori;
	y = vert;
}

Coord::Coord()
{
}

Coord::~Coord()
{
}

void Coord::xChange(int a)
{
	x += a;
}

void Coord::yChange(int b)
{
	y += b;
}

void Coord::moveTo(int a, int b)
{
	x = a;
	y = b;
}