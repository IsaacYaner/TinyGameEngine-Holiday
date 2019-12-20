#include "world.h"
//¡°inps¡±
#include <stdio.h>
#include "Fairy.h"

World::World()
{
}
World::~World()
{
}
void World::addFairy(Fairy* a)
{
	if (fairy == nullptr)
		fairy = a;
	else
	{
		fairy->append(a);
	}
}
Fairy* World::job()
{
	Fairy* ptr = fairy;
	while (ptr)
	{
		ptr->job();
		ptr = ptr->next;
	}
	return nullptr;
}
int World2D::wid()
{
	return width;
}
int World2D::hei()
{
	return height;
}
World2D::World2D(int wid, int hei)
{
	width = wid;
	height = hei;
	fairy = NULL;
	square = new Fairy**[wid];
	for (int i = 0; i < wid; i++)
	{
		square[i] = new Fairy*[hei];
	}
	for (int i = 0; i < wid; i++)
	{
		for (int j = 0; j < hei; j++)
		{
			square[i][j] = nullptr;
		}
	}
}
Fairy* World2D::space(int a, int b)//Will change to abstract painter out.
{
	return square[a][b];
}
World2D::World2D()
{
}