#include <stdio.h>
#include <iostream>
#include <map>
#include "WindowsCommando.h"
#include "display.h"
#include "world.h"
using namespace std;

int color_contrast(int color_code)
{
	return color_code;
}

int set_color(int color_code)/*char* color_name*/
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color_contrast(color_code));
	return 0;
}

void canvas::project(World2D a)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (a.space(i, j) == nullptr)
			{
				Layer[i][j] = 0;
				continue;
			}
			Painter* ptr = (Painter *)(a.space(i, j));
			if (ptr->getColor() == -1)
				Layer[i][j] = color[ptr->getName()];
			else
				Layer[j][j] = ptr->getColor();
		}
	}
}

void canvas::render(int a)
{
	int paint = 17 * (a % 10);//nth pure color in color code.
	if (a / 10 % 10 == 1)//brightness level
		paint += 136;
	set_color(paint);
}

void canvas::dye(string s, int darken)
{
	if (darken || color[s] == 0)
		set_color(color[s]);
	else
		set_color(color[s] + 10);
}

void canvas::pri(int a)//Add light and shade later
{
	render(a);
	printf("■");
}

void canvas::dis()
{
	for(int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			if (Layer[j][i] != preLayer[j][i])
			{
				curse(j,i);
				pri(Layer[j][i]);
				preLayer[j][i] = Layer[j][i];
			}
		}
}

void canvas::paint(Painter p)
{
	Coord c = p.getPosition();
	Layer[c.x][c.y] = p.getColor();
}

canvas::canvas(int wid, int hei)//需不需要改成可变的
{
	width = wid;
	height = hei;
	Layer = new int *[width];
	preLayer = new int *[width];
	for (int i = 0; i < width; i++)
	{
		Layer[i] = new int[height];
		preLayer[i] = new int[height];
	}
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			preLayer[i][j] = Layer[i][j] = 0;
	color["黑"] = 0;
	color["蓝"] = 1;
	color["绿"] = 2;
	color["青"] = 3;
	color["红"] = 4;
	color["紫"] = 5;
	color["黄"] = 6;
	color["白"] = 7;
	color["black"] = 0;
	color["blue"] = 1;
	color["green"] = 2;
	color["cyan"] = 3;
	color["red"] = 4;
	color["purple"] = 5;
	color["yellow"] = 6;
	color["white"] = 7;
}

int canvas::wid()
{
	return width;
}

int canvas::hei()
{
	return height;
}

canvas::canvas()
{

}
//不知道为啥不能delete， 在这里内存已经被释放了
canvas::~canvas()
{
	/*
	for (int i = 0; i < width; i++)
	{
		delete[] Layer[i];
		delete[] preLayer[i];
	}
	delete[] Layer;
	delete[] preLayer;
	*/
}
