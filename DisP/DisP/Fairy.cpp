#include "Fairy.h"
#include <stdio.h>

Fairy * Fairy::append(Fairy * newFairy)
{
	Fairy* ptr = newFairy;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = newFairy;
	newFairy->prev = ptr;
	return this;
}

Fairy * Fairy::end()
{
	Fairy *ptr = this;
	while (ptr->next)
		ptr = ptr->next;
	return ptr;
}

Fairy::Fairy()
{
	prev = this;
	next = nullptr;
}
Fairy::~Fairy()
{
}
