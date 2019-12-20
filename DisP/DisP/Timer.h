#pragma once

class Timer
{
private:
	int last_stop;
public:
	int now();
	int stop();//Return time span since last stop(a), if it's first time, return 0;
	int rstop();//rstop can examine time span while keeping stop unchanged.
	int reach(int b);//Record time until the time to call it is not less than b since last valid call, return 1 if succeed.
	int reset();//Reset timer for a.
	int Fps(int b);//Use a designated index for recording FPS to call reach().
	Timer();
	~Timer();
};