#include "FairySamples.h"
#include "Particle.h"
biu::biu(World2D* a)
{
	map = a;
}

Fairy* biu::job()
{
	map->square[40][40] = new Painter(40, 40, "ºì");
	return nullptr;
}

bouncer::bouncer(World * a)
{
}
