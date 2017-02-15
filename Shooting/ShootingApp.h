#pragma once
#include "App.h"
#include "Fighter.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "MissileA.h"
#include "MissileB.h"
#include "MissileEnemy.h"
#include "Score.h"
#include <vector>

#define N_ENEMY_A 7
#define N_ENEMY_B 7
#define N_MISSILE_A 100
#define N_MISSILE_B 100
#define N_MISSILE_ENEMY 100
#define N_MISSILE_ENEMY_B 100


class ShootingApp : public App {
private:
	Fighter fighter;
	EnemyA enemyA[N_ENEMY_A];
	EnemyB enemyB[N_ENEMY_B];
	MissileA missileA[N_MISSILE_A];
	MissileB missileB[N_MISSILE_B];
	MissileEnemy missileEnemy[N_MISSILE_ENEMY];
	MissileEnemy missileEnemyB[N_MISSILE_ENEMY_B];
	std::vector<FlyingObject*> fos;
	std::vector<Enemy*> enemies;
	std::vector<Missile*> missiles;
	std::vector<Missile*> enemyMissiles;
	Score score;

public:
	ShootingApp();
	~ShootingApp();
	void init(void);
	void cleanup(void);
	void update(void);
	void draw(void);
	void keyDown(WPARAM key);
	void keyUp(WPARAM key);
};

