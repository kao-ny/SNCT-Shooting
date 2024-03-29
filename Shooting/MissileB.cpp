#include "stdafx.h"
#include "MissileB.h"
#include "ShootingApp.h"


MissileB::MissileB()
{
}


MissileB::~MissileB()
{
}

void MissileB::init(void)
{
	FlyingObject::init();
	vx = vy = 0;
	radius = 10;
}
void MissileB::update(void)
{
	if(x < 0 || x > 1023 || y < 0 || y > 767) // 画面からはみ出たら、ミサイルはなくなる。
		cleanup();
	double dt = lap.get();
	x += vx * dt;
	y += vy * dt;
	lap.reset();
}
void MissileB::draw(void)
{
	HPEN bp = CreatePen(PS_SOLID, 0.5, RGB(20, 20, 255));
	SelectObject(App::hDC, bp);
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
	DeleteObject(bp);
}
void MissileB::fire(double x, double y, double vx, double vy)
{
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
}
