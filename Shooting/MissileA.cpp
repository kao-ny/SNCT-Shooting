#include "stdafx.h"
#include "MissileA.h"
#include "ShootingApp.h"


MissileA::MissileA()
{
}


MissileA::~MissileA()
{
}

void MissileA::init(void)
{
	FlyingObject::init();
	vx = vy = 0;
	radius = 10;
}
void MissileA::update(void)
{
	if(x < 0 || x > 1023 || y < 0 || y > 767) // 画面からはみ出たら、ミサイルはなくなる。
		cleanup();
	double dt = lap.get();
	x += vx * dt;
	y += vy * dt;
	lap.reset();
}
void MissileA::draw(void)
{
	HPEN bp = CreatePen(PS_SOLID, 0.5, RGB(0, 255, 255));
	SelectObject(App::hDC, bp);
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
	DeleteObject(bp);
}
void MissileA::fire(double x, double y, double vx, double vy)
{
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
}
