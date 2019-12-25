#pragma once
class Fairy
{
public:
	virtual Fairy * job() = 0;
	Fairy* next;
	Fairy* prev;
	virtual void append(Fairy* newFairy);
	virtual Fairy* end();
	virtual Fairy* head();
	Fairy();
	~Fairy();
};