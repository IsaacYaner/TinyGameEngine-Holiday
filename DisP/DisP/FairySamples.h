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
	World2D * map;
	Fairy* job();
	biu(World2D* a);
};
