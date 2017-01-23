#pragma once
#include "App.h"
#include "Fighter.h"
#include "EnemyA.h"
#include "Missile.h"

#define N_ENEMY_A 2
#define N_MISSILE 10

class ShootingApp : public App {
private:
	Fighter fighter;
	EnemyA enemyA[N_ENEMY_A];
	Missile missile[N_MISSILE];
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

