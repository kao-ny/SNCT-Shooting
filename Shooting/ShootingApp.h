#pragma once
#include "App.h"
#include "Fighter.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "MissileA.h"
#include <vector>

#define N_ENEMY_A 2
#define N_ENEMY_B 3
#define N_MISSILE_A 100

class ShootingApp : public App {
private:
	Fighter fighter;
	EnemyA enemyA[N_ENEMY_A];
	EnemyB enemyB[N_ENEMY_B];
	MissileA missileA[N_MISSILE_A];
	std::vector<FlyingObject*> fos;
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

