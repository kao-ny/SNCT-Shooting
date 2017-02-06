#include "stdafx.h"
#include "ShootingApp.h"
#include <string>
#include "Sound.h"

void ShootingApp::init(void) {
	fighter.init();
	fos.push_back(&fighter); // fosに&fighterを追加
	for(size_t i = 0; i < N_ENEMY_A; i++) {
		enemyA[i].init();
		enemies.push_back(&enemyA[i]);
		fos.push_back(&enemyA[i]);
	}
	for(size_t i = 0; i < N_ENEMY_B; i++) {
		enemyB[i].init();
		enemies.push_back(&enemyB[i]);
		fos.push_back(&enemyB[i]);
	}
	for(size_t i = 0; i < N_MISSILE_A; i++) {
		fighter.loadMissileA(&missileA[i]);
		missiles.push_back(&missileA[i]);
		fos.push_back(&missileA[i]);
	}
	for(size_t i = 0; i < N_MISSILE_B; i++) {
		fighter.loadMissileB(&missileB[i]);
		missiles.push_back(&missileB[i]);
		fos.push_back(&missileB[i]);
	}
	for(size_t i = 0; i < N_MISSILE_ENEMY; i++) {
		for(size_t j = 0; i < N_ENEMY_B; i++) {
			enemyB[j].loadMissileEnemy(&missileEnemy[i]);
			enemyMissiles.push_back(&missileEnemy[i]);
			fos.push_back(&missileEnemy[i]);
		}
	}
	score.init();
	Sound::getInstance()->registerFile(TEXT("c:/windows/Media/chimes.wav"), TEXT("explosion"));
	Sound::getInstance()->registerFile(TEXT("c:/windows/Media/ir_begin.wav"), TEXT("shoot"));
	Sound::getInstance()->registerFile(TEXT("c:/windows/Media/flourish.mid"), TEXT("bgm"));

	Sound::getInstance()->request(TEXT("bgm"));

}

void ShootingApp::cleanup(void) {
	for(size_t i = 0; i < fos.size(); i++) // fos.size() : fosの要素の個数
		fos[i]->cleanup(); // 配列のようにi番目の要素をfos[i]とアクセスできる
	fos.clear();
	enemies.clear();
	missiles.clear();
	Sound::getInstance()->cleanup();
}

void ShootingApp::update(void) {
	for(size_t i = 0; i < fos.size(); i++)
		if(fos[i]->status & FlyingObject::ACTIVE) // アクティブなFlyingObjectだけupdate
			fos[i]->update();

	// 衝突判定
	// TODO ENEMY_MISSILE
	for(size_t i = 0; i < enemies.size(); i++) { // すべての敵機について衝突判定
		if(!(enemies[i]->status & FlyingObject::ACTIVE)) // アクティブでなければ
			continue; // 判定しない
		for(size_t j = 0; j < missiles.size(); j++) // すべてのミサイルについて
			if(enemies[i]->checkCollision(missiles[j])) // 衝突していたら
				score.add(enemies[i]->point);
	}

	for(size_t j = 0; j < enemyMissiles.size(); j++) // すべてのミサイルについて
		if(fighter.checkCollision(enemyMissiles[j])) { // 衝突していたら
			cleanup();
			init();
		}


	// キャラクターの再アクティブ化
	for(size_t i = 0; i < enemies.size(); i++) {
		if(!enemies[i]->status) {		// 敵機がやられたら（アクティブでなければ）
			enemies[i]->init();			// 初期化してアクティブ化
		}
	}

	// ゲームの再開
	if(!fighter.status) {		// 自機がやられたら
		cleanup();			// ゲームオーバー（終了手続き）
		init();				// ゲームスタート（初期化手続き）
	}
}


void ShootingApp::draw(void) {
	for(size_t i = 0; i < fos.size(); i++)
		if(fos[i]->status & FlyingObject::ACTIVE) // アクティブなFlyingObjectだけdraw
			fos[i]->draw();
	score.draw(800, 600);
	Sound::getInstance()->play();
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
		enemyB[0].shootEnemy();
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
