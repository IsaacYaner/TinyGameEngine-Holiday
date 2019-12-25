#pragma once
#include "Fairy.h"
#include "Pixel.h"
#include <vector>
class FairyList : public Fairy
{
	std::vector<Fairy *> fairyList;
public:
	Fairy * job();
	virtual Fairy * last();
	virtual Fairy * first();
	virtual void append(Fairy* newFairy);
	virtual void clear();
	FairyList();
	~FairyList();
};

class SortedPixelList :
	public FairyList
{
	std::vector<Pixel *> fairyList;
public:
	Fairy * job();
	void append(Pixel * newFairy);
	Fairy * last();
	Fairy * first();
	void clear();
	SortedPixelList();
	~SortedPixelList();
};
