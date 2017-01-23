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

	radius = 0;
	status = ACTIVE;
	mtimer.reset();

}

void FlyingObject::cleanup(void)
{
	status = 0;
}

void FlyingObject::update(void)
{
}

void FlyingObject::draw(void)
{
}

void FlyingObject::drawDebug(void) {
	HPEN hpen = CreatePen(PS_DASH, 0.5, RGB(255, 0, 0));
	SelectObject(App::hDC, hpen);
	SelectObject(App::hDC, GetStockObject(NULL_BRUSH));
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
}
