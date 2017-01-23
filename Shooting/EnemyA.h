#pragma once
#include "Enemy.h"

class EnemyA : public Enemy
{
	double phase;

public:
	EnemyA(void);
	~EnemyA(void);

	void init(void);
	void update(void);
	void draw(void);
};

