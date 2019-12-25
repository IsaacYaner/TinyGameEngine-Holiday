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

void Canvas::project(PixelWorld2D a)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (a.tempCamera(i, j) == nullptr)
			{
				Layer[i][j] = 0;
				continue;
			}
			Pixel* ptr = (Pixel *)(a.tempCamera(i, j));
			if (ptr->getColor() == -1)
				Layer[i][j] = color[ptr->getName()];
			else
				Layer[j][j] = ptr->getColor();
		}
	}
}

void Canvas::render(int a)
{
	int paint = 17 * (a % 10);//nth pure color in color code.
	if (a / 10 % 10 == 1)//brightness level
		paint += 136;
	set_color(paint);
}

void Canvas::dye(string s, int darken)
{
	if (darken || color[s] == 0)
		set_color(color[s]);
	else
		set_color(color[s] + 10);
}

void Canvas::pri(int a)//Add light and shade later
{
	render(a);
	printf("■");
}

Fairy *Canvas::job()
{
	dis();
	return nullptr;
}

void Canvas::dis()
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

Canvas::Canvas(int wid, int hei)//需不需要改成可变的
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

int Canvas::wid()
{
	return width;
}

int Canvas::hei()
{
	return height;
}

Canvas::Canvas()
{

}
//不知道为啥不能delete， 在这里内存已经被释放了
Canvas::~Canvas()
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
