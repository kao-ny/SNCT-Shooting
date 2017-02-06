#include "stdafx.h"
#define _USE_MATH_DEFINES	// Visual C++でM_PIを使えるように
#include <cmath>
#include "ShootingApp.h"
#include "EnemyB.h"
#include "Sound.h"

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
	y = 325 + App::rand() * 100;

	vx = 250 + 200 * App::rand();
	vy = 50 + 200 * App::rand();

	radius = 30;
	status = STATUS::ACTIVE;

	point = 765;
}

void EnemyB::loadMissileA(MissileA* m)
{
	missilesA.push_back(m);
}

void EnemyB::shootA(void)
{
	for(size_t i = 0; i < missilesA.size(); i++)
		if(!(missilesA[i]->status & ACTIVE)) {
			missilesA[i]->init();
			missilesA[i]->fire(x, y - radius, 10, +400);
			Sound::getInstance()->request(TEXT("shoot"));
			return;
		}
}

void EnemyB::update(void)
{
	if (status & COLLISION) { // 衝突していたら座標を更新しない
		radius = 50;
		if (etimer.get() > 0.5) // 衝突期間が終わったら、
			cleanup(); // 終了手続き
		return;
	}

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
	if (this->status & COLLISION) { // 衝突していたら爆発アニメーション
		if(etimer.get() > 0.5) // 衝突期間が終わったら、
			drawExplosion();
		//drawDebug();
		return;
	}

	/*
	HPEN gp = CreatePen(PS_SOLID, 0.5, RGB(0, 255, 0));
	SelectObject(App::hDC, gp);
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
	DeleteObject(gp);	*/	RECT objArea;
	objArea.left = x - 80;
	objArea.top = y - 70;
	objArea.right = x + 80;
	objArea.bottom = y + 70;
	
	HFONT hFont = CreateFont(19, 0, 0, 0, FW_DONTCARE,
		FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
		TEXT("ＭＳ Ｐゴシック"));

	SelectObject(App::hDC, hFont);
	SetTextColor(App::hDC, RGB(0, 0, 0));

	DrawText(App::hDC, L"_∧＿∧\n| ｡　｡ 　　iヽ\n| ｨ‐ｭ. 　　!| \n| ￣ 　 　 !| \nl　　 　 　 !| \n| ＿＿＿__!| \nﾚﾚ' 　 VV\n", -1, &objArea, DT_CENTER);
	//drawDebug();
}