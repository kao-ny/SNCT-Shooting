#include "stdafx.h"
#include "ShootingApp.h"
#include "FlyingObject.h"

// Add: ââèK1
FlyingObject::FlyingObject(void) : x(0), vx(0), y(0), vy(0), radius(0), status(0)
{
}


FlyingObject::~FlyingObject(void)
{
}

void FlyingObject::init(void)
{
	x = 0;
	vx = 0;
	// Add: ââèK1
	y = 0;
	vy = 0;
	lap.reset();
}

void FlyingObject::cleanup(void)
{
}

void FlyingObject::update(void)
{
}

void FlyingObject::draw(void)
{
}
