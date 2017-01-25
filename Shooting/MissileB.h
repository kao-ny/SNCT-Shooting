#pragma once
#include "Missile.h"

class MissileB : public Missile
{
public:
	MissileB();
	~MissileB();
	void init(void);
	void update(void);
	void draw(void);
	void fire(double x, double y, double vx, double vy);
};

