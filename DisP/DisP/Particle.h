#pragma once
#include "Fairy.h"
#include <string>
#include <vector>
#include "Coord.h"
#include "FairyList.h"
class Particle : public Fairy//Particle is a container of other Fairies, especially integrates painter and collider.
{
	Fairy *components;
	Fairy *lastComponent;
public:
	Fairy * job();
	Fairy* end();
	void append(Fairy *fairy);
	Particle();
	~Particle();
};

class Painter : public Fairy//Change function later.
{
	Pixel* pixel;
	Coord position; //Useless up to now.
	SortedPixelList* space;
public:
	Fairy* job();
	Painter();
	Painter(Pixel* p);//Change later
	void paint();
	void paint(Pixel* p);
	~Painter();
	Painter(SortedPixelList* s, Coord coord, std::string name);
	Painter(SortedPixelList* s, int x, int y, std::string name);
	Painter(SortedPixelList* s, Coord coord, int color = 0);
	Painter(SortedPixelList* s, int x, int y, int color = 0);
};

