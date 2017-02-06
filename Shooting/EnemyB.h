#pragma once
#include "Enemy.h"
#include <vector>
#include "MissileEnemy.h"

class EnemyB : public Enemy
{
private:
	double phase;
	std::vector<MissileEnemy*> missilesEnemy;
	Timer shootTimer;	// ���˗p�^�C�}�[

public:
	EnemyB(void);
	~EnemyB(void);

	void init(void);
	void update(void);
	void draw(void);

	void loadMissileEnemy(MissileEnemy* m); // �~�T�C��m��o�^����
	void shootEnemy(void); // �~�T�C���𔭎˂���
};

