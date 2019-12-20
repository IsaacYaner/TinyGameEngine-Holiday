#pragma once
class Fairy
{
public:
	virtual Fairy * job() = 0;
	Fairy* next;
	Fairy* prev;
	Fairy* append(Fairy* newFairy);
	virtual Fairy* end();
	Fairy();
	~Fairy();
};