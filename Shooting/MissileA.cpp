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
	/*
	HPEN bp = CreatePen(PS_SOLID, 0.5, RGB(0, 255, 255));
	SelectObject(App::hDC, bp);
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
	DeleteObject(bp);
	*/

	RECT objArea;
	objArea.left = x - 18;
	objArea.top = y - 18;
	objArea.right = x + 18;
	objArea.bottom = y + 18;

	HFONT defFont = CreateFont(18, 0, 0, 0, FW_DONTCARE,
		FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
		TEXT("ＭＳ Ｐゴシック"));

	SelectObject(App::hDC, defFont);
	SetTextColor(App::hDC, RGB(20, 255, 20));

	DrawText(App::hDC, L"|\n▲", -1, &objArea, DT_CENTER);
	//drawDebug();


	DeleteObject(defFont);
}
void MissileA::fire(double x, double y, double vx, double vy)
{
	this->x = x;
	this->y = y;
	this->vx = vx;
	this->vy = vy;
}
