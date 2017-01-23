#include "stdafx.h"
#define _USE_MATH_DEFINES	// Visual C++でM_PIを使えるように
#include <cmath>
#include "ShootingApp.h"
#include "EnemyB.h"

EnemyB::EnemyB(void) : Enemy()
{
}

EnemyB::~EnemyB(void)
{
}

void EnemyB::init(void)
{
	FlyingObject::init();

	phase = App::rand() * M_PI;	// M_PIはπ

	x = 400 + App::rand() * 300;
	y = 100 + App::rand() * 200;

	vx = 100 + 200 * App::rand();
	vy = 100 + 200 * App::rand();

	radius = 30;
	status = STATUS::ACTIVE;
}

void EnemyB::update(void)
{
	double dt = lap.get();
	double mt = mtimer.get();
	double dx, dy;

	// updateの間隔が長すぎるときは、強制的にdtを設定
	if (dt > 0.03)
		dt = 0.03;

	dx = vx * sin(2 * mt + phase) * dt;
	dy = vy * cos(5 * mt + phase) * dt;

	x += dx;
	y += dy;

	lap.reset();
}

void EnemyB::draw(void)
{
	HPEN gp = CreatePen(PS_SOLID, 0.5, RGB(0, 255, 0));
	SelectObject(App::hDC, gp);
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
	DeleteObject(gp);
}