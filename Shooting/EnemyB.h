#pragma once
#include "Enemy.h"

class EnemyB : public Enemy
{
	double phase;

public:
	EnemyB(void);
	~EnemyB(void);

	void init(void);
	void update(void);
	void draw(void);
};

