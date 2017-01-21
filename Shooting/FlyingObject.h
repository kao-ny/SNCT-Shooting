#pragma once
#include "Timer.h"

class FlyingObject
{
protected:
	double x;		// 現在の位置 (pixel)
	// Add: 演習1
	double y;
	double vx;		// 現在の移動速度 (pixel/s)
	// Add: 演習1
	double vy;

	Timer lap;		// 前回のupdateからの経過時間計測用

public:
	FlyingObject(void);
	virtual ~FlyingObject(void);

	virtual void init(void);
	virtual void cleanup(void);
	virtual void update(void);
	virtual void draw(void);
};

