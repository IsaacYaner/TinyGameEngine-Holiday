#include "FairyList.h"
#include <iostream> //delete
using namespace std;
Fairy * FairyList::job()
{
	//clear();
	return nullptr;
}

Fairy * FairyList::last()
{
	if (fairyList.empty())
		return nullptr;
	return fairyList.back();
}

Fairy * FairyList::first()
{
	if (fairyList.empty())
		return nullptr;
	return fairyList.front();
}

void FairyList::append(Fairy * newFairy)
{
	fairyList.push_back(newFairy);
}

void FairyList::clear()
{
	std::vector<Fairy *>().swap(fairyList);
}

FairyList::FairyList()
{
	fairyList = std::vector<Fairy *>();
}

FairyList::~FairyList()
{
	std::vector<Fairy *>().swap(fairyList);
}

void SortedPixelList::append(Pixel * newFairy)
{
	if (fairyList.empty())
	{
		fairyList.push_back(newFairy);
		return;
	}
	std::vector<Pixel*>::iterator i;
	for (i = fairyList.begin(); i < fairyList.end(); i++) //Insert at first element that is no less than newFairy, otherwise, push back.
	{
		if ((*i)->height() == newFairy->height())//Rewrite//TOBECHANGED
		{
			*i = newFairy;
			return;
		}
		else if ((*i)->height() > newFairy->height())//Rewrite
		{
			fairyList.insert(i, newFairy);//Insert newFairy before it.
			return;
		}
	}
	fairyList.push_back(newFairy);
}

SortedPixelList::SortedPixelList()
{
	fairyList = std::vector<Pixel *>();
}


SortedPixelList::~SortedPixelList()
{
	std::vector<Pixel *>().swap(fairyList);
}

Fairy * SortedPixelList::last()
{
	if (fairyList.empty())
		return nullptr;
	return fairyList.back();
}

Fairy * SortedPixelList::first()
{
	if (fairyList.empty())
		return nullptr;
	return fairyList.front();
}

void SortedPixelList::clear()
{
	fairyList.clear();
	//std::vector<Pixel *>().swap(fairyList);
}

Fairy * SortedPixelList::job()
{
	clear();
	return nullptr;
}