#include "world.h"
//¡°inps¡±
#include <stdio.h>
#include <iostream>
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
int PixelWorld2D::wid()
{
	return width;
}
int PixelWorld2D::hei()
{
	return height;
}
PixelWorld2D::PixelWorld2D(int wid, int hei)
{
	width = wid;
	height = hei;
	fairy = NULL;
	square = new Fairy**[wid];
	content = new SortedPixelList**[wid];
	for (int i = 0; i < wid; i++)
	{
		square[i] = new Fairy*[hei];
		content[i] = new SortedPixelList*[hei];
	}
	for (int i = 0; i < wid; i++)
	{
		for (int j = 0; j < hei; j++)
		{
			square[i][j] = nullptr;
			content[i][j] = new SortedPixelList();
			addFairy(content[i][j]);
		}
	}
}
Fairy * PixelWorld2D::job()
{
	Fairy* ptr = fairy;
	while (ptr)
	{
		ptr->job();
		ptr = ptr->next;
	}
	return nullptr;
}
Fairy * PixelWorld2D::tempCamera(int a, int b)
{
	return content[a][b]->first();
}
SortedPixelList* PixelWorld2D::space(int a, int b)//Will change to abstract painter out.
{
	//return square[a][b];
	return content[a][b];
}
PixelWorld2D::PixelWorld2D()
{

}