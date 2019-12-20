#pragma once
#include "world.h"
#include "Particle.h"
#include <map>
using namespace std;
int set_color(int a);
class canvas
{
protected:
	int width;		//Width
	int height;		//Height
	int **preLayer;		//Content of Layer in previous frame.
	map<string, int>color;	//Mapping array for name and color code
	void render(int a);	//Choose a proper color according to color code.
	void pri(int a);//Print certain character  according to color code and illumination.
	/*int *temp;
	int tnum;*/
public:
	int **Layer;	//Later change to protected
	int wid();		//Getter function for width.
	int hei();		//Getter function for height.
	void dis();		//Print pixels to cmd console.
	void paint(Painter p);//Print given particle.
	void project(World2D a);		//Directly project 2D World to canvas.//////////Don't need it any more!!! Delete
	canvas(int width, int height);	//Construct a 2D canvas according to width and height
	canvas();
	~canvas();
	void dye(string s, int darken = 0);	//Set color according to color name and mapping array.
	//void draw();
};