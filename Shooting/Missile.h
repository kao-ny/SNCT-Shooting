#pragma once
#include "FlyingObject.h"
class Missile :
	public FlyingObject
{
public:
	Missile();
	~Missile();
	void init(void);
	void update(void);
	void draw(void);
	void fire(double x, double y, double vx, double vy);
};

