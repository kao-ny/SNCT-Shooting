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

	Timer lap;		// �O���update����̌o�ߎ��Ԍv���p

public:
	FlyingObject(void);
	virtual ~FlyingObject(void);

	virtual void init(void);
	virtual void cleanup(void);
	virtual void update(void);
	virtual void draw(void);
};

