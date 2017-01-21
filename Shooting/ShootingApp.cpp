#include "stdafx.h"
#include "ShootingApp.h"

void ShootingApp::init(void) {
	fighter.init();
}

void ShootingApp::cleanup(void) {
	fighter.cleanup();
}

void ShootingApp::update(void) {
	fighter.update();
}

void ShootingApp::draw(void) {
	fighter.draw();
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
