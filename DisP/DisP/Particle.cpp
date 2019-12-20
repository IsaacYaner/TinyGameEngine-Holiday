#include "Particle.h"
#include <string>
#include <stdio.h>

Fairy* Particle::job()
{

	Fairy *ptr = components;
	while (ptr)
	{
		ptr->job();
	}
	return nullptr;
}

Fairy * Particle::end()
{
	return lastComponent;
}

void Particle::append(Fairy * fairy)
{
	if (components == nullptr)
	{
		components = fairy;
		lastComponent = fairy->end();
	}
	else
	{
		lastComponent->next = fairy;
		lastComponent = fairy->end();
	}
}

Particle::Particle()
{
}

Particle::~Particle()
{
}


Fairy* Painter::job()
{
	return nullptr;
}

Painter::Painter()
{
}

Painter::Painter(Coord coord, std::string name)
{
	colorCode = -1;
	colorName = name;
	position = coord;
}

Painter::Painter(int x, int y, std::string name)
{
	colorCode = -1;
	colorName = name;
	position = Coord(x, y);
}

Painter::Painter(Coord coord, int color)
{
	position = coord;
	colorCode = color;
}

Painter::Painter(int x, int y, int color)
{
	position = Coord(x, y);
	colorCode = color;
}

void Painter::setColor(int c)
{
	colorCode = c;
}

void Painter::setPosition(Coord coord)
{
	position = coord;
}

Coord Painter::getPosition()
{
	return position;
}

std::string Painter::getName()
{
	return colorName;
}

int Painter::getColor()
{
	return colorCode;
}


Painter::~Painter()
{
}
