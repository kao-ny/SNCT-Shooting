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
	y = 400;
	vx = 200;
	// Add: 演習1
	vy = 200;
	radius = 50;
}

void Fighter::cleanup(void)
{
	FlyingObject::cleanup();
	missilesA.clear();
}

void Fighter::loadMissileA(MissileA* m)
{
	missilesA.push_back(m);
}

void Fighter::loadMissileB(MissileB* m)
{
	missilesB.push_back(m);
}

void Fighter::update(void)
{
	if (status & COLLISION) { // 衝突していたら座標を更新しない
		if (etimer.get() > 0.5) // 衝突期間が終わったら、
			cleanup(); // 終了手続き
		return;
	}

	FlyingObject::update();

	double dx = 0;
	// Add: 演習1
	double dy = 0;
	double dt = lap.get();

	if(dir & LEFT)
		dx -= vx * dt;
	if(dir & RIGHT)
		dx += vx * dt;
	// Add: 演習1
	if(dir & FORE)
		dy -= vy * dt;
	if(dir & BACK)
		dy += vy * dt;

	x += dx;
	// Add: 演習1
	y += dy;
	lap.reset();
}

void Fighter::draw(void)
{
	LPCWSTR c;

	if (status & COLLISION) { // 衝突していたら爆発アニメーション
		drawExplosion();
		return;
	}

	RECT objArea;
	objArea.left = x - radius;
	objArea.top = y-30;
	objArea.right = x + radius;
	objArea.bottom = y+30;

	DrawText(App::hDC, L"|\n--+--\n-+-", -1, &objArea, DT_CENTER);

	drawDebug();	
}


void Fighter::move(DIRECTION dir)
{
	this->dir |= dir;
}

void Fighter::stop(DIRECTION dir)
{
	this->dir &= ~dir;
}

void Fighter::shootA(void)
{
	for (size_t i = 0; i < missilesA.size(); i++)
		if (!(missilesA[i]->status & ACTIVE)) {
			missilesA[i]->init();
			missilesA[i]->fire(x, y - radius, 0, -400);
			return;
		}
}

void Fighter::shootB(void)
{
	for(size_t i = 0; i < missilesB.size(); i++)
		if(!(missilesB[i]->status & ACTIVE)) {
			missilesB[i]->init();
			missilesB[i]->fire(x, y - radius, 0, -400);
			return;
		}
}