#pragma once
#include "world.h"

class bouncer : public Fairy
{
public:
	bouncer(World* a);
};

class biu : public Fairy
{
public:
	PixelWorld2D * map;
	Fairy* job();
	biu(PixelWorld2D* a);
};
