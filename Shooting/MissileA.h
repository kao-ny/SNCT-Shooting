#pragma once
#include "Missile.h"

class MissileA : public Missile
{
public:
	MissileA();
	~MissileA();
	void init(void);
	void update(void);
	void draw(void);
	void fire(double x, double y, double vx, double vy);
};

