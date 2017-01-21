#pragma once
#include "App.h"
#include "Fighter.h"

class ShootingApp : public App {
private:
	Fighter fighter;
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

