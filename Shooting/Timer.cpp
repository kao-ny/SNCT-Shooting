#include "stdafx.h"
#include "Timer.h"

Timer::Timer(void)
{
	start = GetTickCount();
}

Timer::~Timer(void)
{
}

void Timer::reset(void)
{
	start = GetTickCount();
}

double Timer::get(void)
{
	return (GetTickCount() - start) / 1000.0;
}
