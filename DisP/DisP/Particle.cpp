#include "Particle.h"
#include <string>
#include <stdio.h>
#include <iostream>
Fairy* Particle::job()
{

	Fairy *ptr = components;
	while (ptr)
	{
		ptr->job();
		ptr = ptr->next;
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
	paint();
	return nullptr;
}

Painter::Painter()
{
	pixel = nullptr;
}

Painter::Painter(Pixel * p)
{
	pixel = p;
}

void Painter::paint()//Bug occurs here, delete the comment when fixed.
{
	if (pixel == nullptr)
		return;
	space->append(pixel);
}

void Painter::paint(Pixel* p)
{
	space->append(p);
}

Painter::~Painter()
{
}

Painter::Painter(SortedPixelList* s, Coord coord, std::string name)
{
	space = s;
	pixel = new Pixel(coord, name);
}

Painter::Painter(SortedPixelList* s, int x, int y, std::string name)
{
	space = s;
	pixel = new Pixel(x, y, name);
}

Painter::Painter(SortedPixelList* s, Coord coord, int color)
{
	space = s;
	pixel = new Pixel(coord, color);
}

Painter::Painter(SortedPixelList* s, int x, int y, int color)
{
	space = s;
	pixel = new Pixel(x, y, color);
}
