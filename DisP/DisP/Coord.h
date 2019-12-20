#pragma once
class Coord
{
public:
	Coord(int a, int b);
	Coord();
	~Coord();
	void xChange(int a);
	void yChange(int b);
	void moveTo(int a, int b);
	int x;
	int y;
};

