#include "stdafx.h"
#include "ShootingApp.h"
#include <string>

void ShootingApp::init(void) {
	fighter.init();
	fos.push_back(&fighter); // fos��&fighter��ǉ�
	for (size_t i = 0; i < N_ENEMY_A; i++) {
		enemyA[i].init();
		enemies.push_back(&enemyA[i]);
		fos.push_back(&enemyA[i]);
	}
	for (size_t i = 0; i < N_ENEMY_B; i++) {
		enemyB[i].init();
		enemies.push_back(&enemyB[i]);
		fos.push_back(&enemyB[i]);
	}
	for (size_t i = 0; i < N_MISSILE_A; i++) {
		fighter.loadMissileA(&missileA[i]);
		missiles.push_back(&missileA[i]);
		fos.push_back(&missileA[i]);
	}
	for(size_t i = 0; i < N_MISSILE_B; i++) {
		fighter.loadMissileB(&missileB[i]);
		missiles.push_back(&missileB[i]);
		fos.push_back(&missileB[i]);
	}
	score.init();
}

void ShootingApp::cleanup(void) {
	for (size_t i = 0; i < fos.size(); i++) // fos.size() : fos�̗v�f�̌�
		fos[i]->cleanup(); // �z��̂悤��i�Ԗڂ̗v�f��fos[i]�ƃA�N�Z�X�ł���
	fos.clear();
	enemies.clear();
	missiles.clear();
}

void ShootingApp::update(void) {
	for (size_t i = 0; i < fos.size(); i++)
		if (fos[i]->status & FlyingObject::ACTIVE) // �A�N�e�B�u��FlyingObject����update
			fos[i]->update();

	// �Փ˔���
	for (size_t i = 0; i < enemies.size(); i++) { // ���ׂĂ̓G�@�ɂ��ďՓ˔���
		if (!(enemies[i]->status & FlyingObject::ACTIVE)) // �A�N�e�B�u�łȂ����
			continue; // ���肵�Ȃ�
		for (size_t j = 0; j < missiles.size(); j++) // ���ׂẴ~�T�C���ɂ���
			if (enemies[i]->checkCollision(missiles[j])) // �Փ˂��Ă�����
				score.add(enemies[i]->point);
				enemies[i]->checkCollision(&fighter); // ���@�Ƃ̏Փ˔���
	}
}

void ShootingApp::draw(void) {
	for (size_t i = 0; i < fos.size(); i++)
		if (fos[i]->status & FlyingObject::ACTIVE) // �A�N�e�B�u��FlyingObject����draw
			fos[i]->draw();
	score.draw(800, 600);
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
