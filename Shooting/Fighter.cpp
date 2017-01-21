#include "stdafx.h"
#include "ShootingApp.h"
#include "Fighter.h"

Fighter::Fighter(void) : FlyingObject(), dir(STOP)
{
}

Fighter::~Fighter(void)
{
}

void Fighter::init(void)
{
	FlyingObject::init();

	x = 400;
	vx = 200;
	// Add: ‰‰K1
	vy = 200;
}

void Fighter::cleanup(void)
{
	FlyingObject::cleanup();
}

void Fighter::update(void)
{
	FlyingObject::update();

	double dx = 0;
	// Add: ‰‰K1
	double dy = 0;
	double dt = lap.get();

	if(dir & LEFT)
		dx -= vx * dt;
	if(dir & RIGHT)
		dx += vx * dt;
	// Add: ‰‰K1
	if(dir & FORE)
		dy -= vy * dt;
	if(dir & BACK)
		dy += vy * dt;

	x += dx;
	// Add: ‰‰K1
	y += dy;
	lap.reset();
}

void Fighter::draw(void)
{
	LPCWSTR c;

	c = TEXT("*");
	// Add: ‰‰K1
	TextOut(App::hDC, (int) x, y, c, lstrlen(c));
}


void Fighter::move(DIRECTION dir)
{
	this->dir |= dir;
}

void Fighter::stop(DIRECTION dir)
{
	this->dir &= ~dir;
}
