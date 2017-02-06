#pragma once
#include "Enemy.h"
#include "MissileA.h"

class EnemyB : public Enemy
{
private:
	double phase;
	std::vector<MissileA*> missilesA;

public:
	EnemyB(void);
	~EnemyB(void);

	void init(void);
	void loadMissileA(MissileA * m);
	void shootA(void);
	void update(void);
	void draw(void);
};

