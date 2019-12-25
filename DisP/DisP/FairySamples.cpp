#include "FairySamples.h"
#include "Particle.h"
biu::biu(PixelWorld2D* a)
{
	map = a;
}

Fairy* biu::job()
{
	map->square[40][40] = new Painter((SortedPixelList*)map->space(40, 40), 40, 40, "ºì");
	return nullptr;
}

bouncer::bouncer(World * a)
{
}
