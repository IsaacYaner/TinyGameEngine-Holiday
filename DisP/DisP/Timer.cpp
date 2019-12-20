#include <time.h>
#include "Timer.h"

int Timer::now()
{
	return clock();
}

//Functionality: return the time span since last stop(n)
int Timer::stop()//N is objective number, an attribute of any element in this Sys
{
	if (last_stop)
	{
		int this_stop = clock();
		this_stop -= last_stop;
		last_stop += this_stop;
		return this_stop;
	}
	last_stop = clock();
	return 0;
}

int Timer::rstop()
{
	if (last_stop)
	{
		int this_stop = clock();
		this_stop -= last_stop;
		return this_stop;
	}
	last_stop = clock();
	return 0;
}

int Timer::reach(int t)
{
	if (last_stop)
	{
		int this_stop = clock();
		if (this_stop - last_stop >= t)
		{
			last_stop = this_stop;//0 And this_stop, which is better?
			return 1;
		}
		else 
			return 0;
	}
	last_stop = clock();
	return 0;
}

int Timer::reset()
{
	last_stop = 0;
	return 0;
}

int Timer::Fps(int n)
{
	return reach(n);
}

Timer::Timer()
{
		last_stop = 0;
}

Timer::~Timer()
{
}