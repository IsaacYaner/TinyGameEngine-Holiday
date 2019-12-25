#include "Coord.h"



Coord::Coord(int hori, int vert, int deep)
{
	x = hori;
	y = vert;
	z = deep;
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

void Coord::moveTo(int a, int b, int c)
{
	x = a;
	y = b;
	z = c;
}