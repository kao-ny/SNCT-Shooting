#include "stdafx.h"
#include "ShootingApp.h"
#include "FlyingObject.h"

// Add: 演習1
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
	// Add: 演習1
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
	HPEN rp = CreatePen(PS_DASH, 0.5, RGB(255, 0, 0));
	SelectObject(App::hDC, rp);
	SelectObject(App::hDC, GetStockObject(NULL_BRUSH));
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
	DeleteObject(rp);
}

#define sqr(x) ((x)*(x))
bool FlyingObject::checkCollision(FlyingObject* fo)
{
	if (!(fo->status & ACTIVE)) // 判定相手がアクティブでなければ
		return false; // falseを返す

	if (!(fo->status & COLLISION))
		return false; // falseを返す

	if (!(status & COLLISION)) { // 自分の衝突フラグがセットされていなければ、
		status = COLLISION; // 自分の衝突フラグをセット
		mtimer.reset(); // 自分の衝突アニメーション用タイマーリセット
	}

	// TODO
	if (!(fo->status & COLLISION)) { // 相手の衝突フラグがセットされていなければ、
		fo->status = COLLISION; // 相手の衝突フラグをセット
		fo->mtimer.reset(); // 相手の衝突アニメーション用タイマーリセット
	}

	return true;
}

void FlyingObject::drawExplosion(void)
{ // TODO: 各自オリジナルの爆発アニメーションを作ること。
	LPCWSTR c;
	double t = mtimer.get(); // 衝突してからの経過時間
	if (t > 0.4) {
		c = TEXT("*");
		TextOut(App::hDC, (int)x - 5, (int)y - 5, c, lstrlen(c));
	}
	else if (t > 0.3) {
		c = TEXT("***");
		TextOut(App::hDC, (int)x - 15, (int)y - 5, c, lstrlen(c));
	}
	else if (t > 0.1) {
		c = TEXT("(***)");
		TextOut(App::hDC, (int)x - 25, (int)y - 5, c, lstrlen(c));
	}
	else {
		c = TEXT("(*)");
		TextOut(App::hDC, (int)x - 15, (int)y - 5, c, lstrlen(c));
	}
}