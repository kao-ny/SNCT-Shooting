#include "stdafx.h"
#include "ShootingApp.h"

void ShootingApp::init(void) {
	fighter.init();
	fos.push_back(&fighter); // fos��&fighter��ǉ�
	for (size_t i = 0; i < N_ENEMY_A; i++) {
		enemyA[i].init();
		fos.push_back(&enemyA[i]);
	}
	for (size_t i = 0; i < N_ENEMY_B; i++) {
		enemyB[i].init();
		fos.push_back(&enemyB[i]);
	}
	for (size_t i = 0; i < N_MISSILE_A; i++) {
		fighter.loadMissileA(&missileA[i]);
		fos.push_back(&missileA[i]);
	}
	for(size_t i = 0; i < N_MISSILE_B; i++) {
		fighter.loadMissileB(&missileB[i]);
		fos.push_back(&missileB[i]);
	}

}

void ShootingApp::cleanup(void) {
	for (size_t i = 0; i < fos.size(); i++) // fos.size() : fos�̗v�f�̌�
		fos[i]->cleanup(); // �z��̂悤��i�Ԗڂ̗v�f��fos[i]�ƃA�N�Z�X�ł���
	fos.clear();

}

void ShootingApp::update(void) {
	for (size_t i = 0; i < fos.size(); i++)
		if (fos[i]->status & FlyingObject::ACTIVE) // �A�N�e�B�u��FlyingObject����update
			fos[i]->update();
}

void ShootingApp::draw(void) {
	for (size_t i = 0; i < fos.size(); i++)
		if (fos[i]->status & FlyingObject::ACTIVE) // �A�N�e�B�u��FlyingObject����draw
			fos[i]->draw();
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
	case VK_SPACE:
		fighter.shootA();
		break;
	case 0x53:				// S key
		fighter.shootB();
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
