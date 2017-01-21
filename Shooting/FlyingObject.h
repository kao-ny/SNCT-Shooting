#pragma once
#include "Timer.h"

class FlyingObject
{
protected:
	double x;		// ���݂̈ʒu (pixel)
	// Add: ���K1
	double y;
	double vx;		// ���݂̈ړ����x (pixel/s)
	// Add: ���K1
	double vy;

	double radius;	// ���a
	Timer mtimer;	// �ړ��o�H�v�Z�p

	Timer lap;		// �O���update����̌o�ߎ��Ԍv���p

public:
	unsigned int status;	// ��ԃt���O

	enum STATUS {
		ACTIVE = 1,		// �A�N�e�B�u (update()��draw()���Ă�)
		COLLISION = 2	// �Փˏ��
	};

	FlyingObject(void);
	virtual ~FlyingObject(void);

	virtual void init(void);
	virtual void cleanup(void);
	virtual void update(void);
	virtual void draw(void);
};

