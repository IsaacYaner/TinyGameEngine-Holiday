#pragma once
#include "Fairy.h"
#include <string>
#include "Coord.h"
#include "world.h"
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

class Painter : public Fairy
{
	World world;
	int colorCode;
	std::string colorName;
	Coord position;
public:
	Fairy* job();
	Painter();
	Painter(Coord coord, std::string name);
	Painter(int x, int y, std::string name);
	Painter(Coord coord, int color = 0);
	Painter(int x, int y, int color = 0);
	void setColor(int c);
	void setPosition(Coord coord);
	Coord getPosition();
	std::string getName();
	int getColor();
	~Painter();
};