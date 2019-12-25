#include "Fairy.h"
#include <stdio.h>

void  Fairy::append(Fairy * newFairy)
{
	Fairy* ptr = end();
	ptr->next = newFairy->head();
	newFairy->head()->prev = ptr;
}

Fairy * Fairy::end()
{
	Fairy *ptr = this;
	while (ptr->next)
		ptr = ptr->next;
	return ptr;
}

Fairy * Fairy::head()
{
	Fairy *ptr = this;
	while (ptr->prev)
		ptr = ptr->prev;
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
