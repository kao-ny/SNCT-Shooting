#pragma once
#include "App.h"
#include "Fighter.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "Missile.h"
#include <vector>

#define N_ENEMY_A 2
#define N_ENEMY_B 3
#define N_MISSILE 100

class ShootingApp : public App {
private:
	Fighter fighter;
	EnemyA enemyA[N_ENEMY_A];
	EnemyB enemyB[N_ENEMY_B];
	Missile missile[N_MISSILE];
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

