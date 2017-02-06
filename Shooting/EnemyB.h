#pragma once
#include "Enemy.h"
#include <vector>
#include "MissileEnemy.h"

class EnemyB : public Enemy
{
private:
	double phase;
	std::vector<MissileEnemy*> missilesEnemy;
	Timer shootTimer;	// 発射用タイマー

public:
	EnemyB(void);
	~EnemyB(void);

	void init(void);
	void update(void);
	void draw(void);

	void loadMissileEnemy(MissileEnemy* m); // ミサイルmを登録する
	void shootEnemy(void); // ミサイルを発射する
};

