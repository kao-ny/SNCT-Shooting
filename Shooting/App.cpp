#include "stdafx.h"
#include "App.h"
#include <cstdlib>	// srand(), rand()
#include <ctime>	// time()

App::App(void)
{
}

App::~App(void)
{
}

void App::init(void)
{
	// �����̏�����
	srand(static_cast<unsigned int>(time(NULL)));
}

void App::cleanup(void)
{
}

void App::update(void)
{
}

void App::draw(void)
{
}

void App::keyDown(WPARAM key)
{
}

void App::keyUp(WPARAM key)
{
}

// 0~1�̗�����ԋp
double App::rand(void) {
	return static_cast<double>(::rand()) / RAND_MAX;
}

HWND App::hWnd = 0;
HDC App::hDC = 0;

