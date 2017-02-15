#pragma once
#include "Enemy.h"
#include <vector>
#include "MissileEnemy.h"

class EnemyA : public Enemy
{
private:
	double phase;
	std::vector<MissileEnemy*> missilesEnemy;
	Timer shootTimer;	// ���˗p�^�C�}�[

public:
	EnemyA(void);
	~EnemyA(void);

	void init(void);
	void update(void);
	void draw(void);
	void loadMissileEnemy(MissileEnemy* m); // �~�T�C��m��o�^����
	void shootEnemy(void); // �~�T�C���𔭎˂���
};

