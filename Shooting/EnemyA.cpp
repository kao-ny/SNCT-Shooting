#include "stdafx.h"
#define _USE_MATH_DEFINES	// Visual C++‚ÅM_PI‚ðŽg‚¦‚é‚æ‚¤‚É
#include <cmath>
#include "ShootingApp.h"
#include "EnemyA.h"

EnemyA::EnemyA(void) : Enemy()
{
}

EnemyA::~EnemyA(void)
{
}

void EnemyA::init(void)
{
	FlyingObject::init();

	phase = App::rand() * M_PI;	// M_PI‚ÍƒÎ

	x = 400 + App::rand() * 300;
	y = 100 + App::rand() * 200;

	vx = 100 + 200 * App::rand();
	vy = 100 + 200 * App::rand();

	radius = 30;
}

void EnemyA::update(void)
{
	double dt = lap.get();
	double mt = mtimer.get();
	double dx, dy;

	// update‚ÌŠÔŠu‚ª’·‚·‚¬‚é‚Æ‚«‚ÍA‹­§“I‚Édt‚ðÝ’è
	if (dt > 0.03)
		dt = 0.03;

	dx = vx * sin(2 * mt + phase) * dt;
	dy = vy * cos(5 * mt + phase) * dt;

	x += dx;
	y += dy;

	lap.reset();
}

void EnemyA::draw(void)
{
	HPEN hpen = CreatePen(PS_DASH, 0.5, RGB(255, 0, 0));
	SelectObject(App::hDC, GetStockObject(DC_PEN));
	SetDCPenColor(App::hDC, RGB(0, 0, 255));
	//SelectObject(App::hDC, GetStockObject(NULL_BRUSH));
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
}