#pragma once
#include <Windows.h>

class Timer
{
	DWORD start;

public:
	Timer(void);
	virtual ~Timer(void);

	void reset(void);
	double get(void);
};

