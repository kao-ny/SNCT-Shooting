#include "stdafx.h"
#define _USE_MATH_DEFINES	// Visual C++��M_PI���g����悤��
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

	phase = App::rand() * M_PI;	// M_PI�̓�

	x = 400 + App::rand() * 300;
	y = 100 + App::rand() * 200;

	vx = 100 + 200 * App::rand();
	vy = 100 + 200 * App::rand();

	radius = 30;
	status = STATUS::ACTIVE;

	point = 765;
}

void EnemyB::update(void)
{
	if (status & COLLISION) { // �Փ˂��Ă�������W���X�V���Ȃ�
		if (etimer.get() > 100000000000.0) // �Փˊ��Ԃ��I�������A
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

void EnemyB::draw(void)
{
	if (this->status & COLLISION) { // �Փ˂��Ă����甚���A�j���[�V����
		drawExplosion();
		return;
	}

	HPEN gp = CreatePen(PS_SOLID, 0.5, RGB(0, 255, 0));
	SelectObject(App::hDC, gp);
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
	DeleteObject(gp);
}