#include "stdafx.h"
#define _USE_MATH_DEFINES	// Visual C++��M_PI���g����悤��
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

	phase = App::rand() * M_PI;	// M_PI�̓�

	x = 400 + App::rand() * 300;
	y = 100 + App::rand() * 200;

	vx = 100 + 200 * App::rand();
	vy = 100 + 200 * App::rand();

	radius = 10;

	point = 346;
}

void EnemyA::update(void)
{
	if (status & COLLISION) { // �Փ˂��Ă�������W���X�V���Ȃ�
		if (etimer.get() >0.50) // �Փˊ��Ԃ��I�������A
			cleanup(); // �I���葱��
		return;
	}

	double dt = lap.get();
	double mt = mtimer.get();
	double dx, dy;

	// update�̊Ԋu����������Ƃ��́A�����I��dt��ݒ�
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
	if (this->status & COLLISION) { // �Փ˂��Ă����甚���A�j���[�V����
		drawExplosion();
		return;
	}

	HPEN bp = CreatePen(PS_SOLID, 0.5, RGB(0, 0, 255));
	SelectObject(App::hDC, bp);
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
	DeleteObject(bp);

	
}