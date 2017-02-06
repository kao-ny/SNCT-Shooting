#include "stdafx.h"
#define _USE_MATH_DEFINES	// Visual C++でM_PIを使えるように
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

	phase = App::rand() * M_PI;	// M_PIはπ

	//x = 400 + App::rand() * 300;
	x = 80 + App::rand() * 2400;
	y = 100 + App::rand() * 200;

	vx = 400 + 2000 * App::rand();
	vy = 100 + 200 * App::rand();

	radius = 10;

	point = 346;
}

void EnemyA::update(void)
{
	if (status & COLLISION) { // 衝突していたら座標を更新しない
		if (etimer.get() >0.50) // 衝突期間が終わったら、
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

void EnemyA::draw(void)
{
	if (this->status & COLLISION) { // 衝突していたら爆発アニメーション
		drawExplosion();
		return;
	}

	/*
	HPEN bp = CreatePen(PS_SOLID, 0.5, RGB(0, 0, 255));
	SelectObject(App::hDC, bp);
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
	DeleteObject(bp);

	*/

	RECT objArea;
	objArea.left = x - 100;
	objArea.top = y - 250;
	objArea.right = x + 100;
	objArea.bottom = y + 250;

	HFONT defFont = CreateFont(18, 0, 0, 0, FW_DONTCARE,
		FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
		TEXT("ＭＳ Ｐゴシック"));

	SelectObject(App::hDC, defFont);
	SetTextColor(App::hDC, RGB(255, 69, 0));

	//DrawText(App::hDC, L"　　 ―　、\n/　　　 　ヽ\n{　f! f!, 　 __)\n >､´｀ \" ノ､\n‘ー' ￣`ー’\n", -1, &objArea, DT_CENTER);
	DrawText(App::hDC, L"		／ __ | __／⌒l\n 　 　 　 　 　 　 〉'´　 （　　 ,ﾉ\n,_<´⌒＼. 　 　 ,′　　　　 　 ＼\n ｛`^＼　　 ＼　　　　　　　　　　　|\n 丶､　　 　 　 ＼ｉ　　　　　　　　 〈__\n 　 丶､　 　 　 ＼　　　　　　　　　｝\n　　　　丶､　　　 ＼　 　 　 （_ ／\n　　　 　 ／＞ .._ /⌒＞─＜\n　 　 　 ／. : : : : : ∧　｛ 　 _/｀　＼\n 　 　 く . : : : ＼_,ｒ'´}　 ｀ﾏ: {_, ノ　　}\n　 　 ／｀ 　 .:, ; , _; _;)x 　 　 }; _; 人__彡'\n　 /　　　　　　　　 ｀ﾆﾆ゛　|\n　 {　　　　　 　 　 　 　 　 ｜\n　　　,　‐‐-ミ　　　　　　 /\n 　 ＼{　　　　 ＼　　　　ｲ\n　　 　 ＼　 　 　 }ニ´　 ﾉ\n　 　 　 ／` 　 ∠、.　イ\n　　　 （＿＿＿__ﾉ--‐′\n", -1, &objArea, DT_CENTER);


	DeleteObject(defFont);

	//drawDebug();

	
}