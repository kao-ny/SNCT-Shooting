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
		TEXT("�l�r �o�S�V�b�N"));

	SelectObject(App::hDC, defFont);
	SetTextColor(App::hDC, RGB(255, 69, 0));

	//DrawText(App::hDC, L"�@�@ �\�@�A\n/�@�@�@ �@�R\n{�@f! f!, �@ __)\n >��L�M \" �m�\n�e�[' �P`�[�f\n", -1, &objArea, DT_CENTER);
	DrawText(App::hDC, L"		�^ __ | __�^��l\n �@ �@ �@ �@ �@ �@ �r'�L�@ �i�@�@ ,�\n,_<�L�܁_. �@ �@ ,���@�@�@�@ �@ �_\n �o`^�_�@�@ �_�@�@�@�@�@�@�@�@�@�@�@|\n ����@�@ �@ �@ �_���@�@�@�@�@�@�@�@ �q__\n �@ ����@ �@ �@ �_�@�@�@�@�@�@�@�@�@�p\n�@�@�@�@����@�@�@ �_�@ �@ �@ �i_ �^\n�@�@�@ �@ �^�� .._ /�܁�����\n�@ �@ �@ �^. : : : : : �ȁ@�o �@ _/�M�@�_\n �@ �@ �� . : : : �__,��'�L}�@ �M�: {_, �m�@�@}\n�@ �@ �^�M �@ .:, ; , _; _;)x �@ �@ }; _; �l__�c'\n�@ /�@�@�@�@�@�@�@�@ �M�ƁJ�@|\n�@ {�@�@�@�@�@ �@ �@ �@ �@ �@ �b\n�@�@�@,�@�]�]-�~�@�@�@�@�@�@ /\n �@ �_{�@�@�@�@ �_�@�@�@�@�\n�@�@ �@ �_�@ �@ �@ }�j�L�@ �\n�@ �@ �@ �^` �@ �ځA.�@�C\n�@�@�@ �i�Q�Q�Q__�--�]��\n", -1, &objArea, DT_CENTER);


	DeleteObject(defFont);

	//drawDebug();

	
}