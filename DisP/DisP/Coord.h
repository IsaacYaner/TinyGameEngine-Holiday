#pragma once
class Coord
{
public:
	Coord(int a, int b, int c = 0);
	Coord();
	~Coord();
	void xChange(int a);
	void yChange(int b);
	void moveTo(int a, int b, int c = 0);
	int x;
	int y;
	int z;
};

