#pragma once
#include "Missile.h"

class MissileEnemy : public Missile
{
public:
	MissileEnemy();
	~MissileEnemy();
	void init(void);
	void update(void);
	void draw(void);
	void fire(double x, double y, double vx, double vy);
};

