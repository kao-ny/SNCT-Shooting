#include "stdafx.h"
#include "ShootingApp.h"

void ShootingApp::init(void) {
	fighter.init();
	enemyA[0].init();
	enemyA[1].init();

}

void ShootingApp::cleanup(void) {
	fighter.cleanup();
	enemyA[0].cleanup();
	enemyA[1].cleanup();
	for (int i = 0;i < 10;i++) {
		missile[i].cleanup();
	}
}

void ShootingApp::update(void) {
	fighter.update();
	enemyA[0].update();
	enemyA[1].update();
	for (int i = 0;i < 10;i++) {
		missile[i].update();
	}
}

void ShootingApp::draw(void) {
	fighter.draw();
	enemyA[0].draw();
	enemyA[1].draw();
	for (int i = 0;i < 10;i++) {
		missile[i].draw();
	}
}

void ShootingApp::keyDown(WPARAM key) {
	switch(key) {
	case VK_LEFT:
		fighter.move(Fighter::LEFT);
		break;
	case VK_RIGHT:
		fighter.move(Fighter::RIGHT);
		break;

	case VK_UP:
		fighter.move(Fighter::FORE);
		break;
	case VK_DOWN:
		fighter.move(Fighter::BACK);
		break;
	}
}

void ShootingApp::keyUp(WPARAM key) {
	switch(key) {
	case VK_LEFT:
		fighter.stop(Fighter::LEFT);
		break;
	case VK_RIGHT:
		fighter.stop(Fighter::RIGHT);
		break;
	case VK_UP:
		fighter.stop(Fighter::FORE);
		break;
	case VK_DOWN:
		fighter.stop(Fighter::BACK);
		break;
	}
}

ShootingApp::ShootingApp()
{
}


ShootingApp::~ShootingApp()
{
}
