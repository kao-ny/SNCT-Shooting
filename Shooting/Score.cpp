#include "stdafx.h"
#include "Score.h"
#include <string>
#include "ShootingApp.h"


Score::Score()
{
}


Score::~Score()
{
}

void Score::init(void) {
	score = 0;
}

void Score::add(int point) {
	score += point;
}

void Score::draw(int x, int y) {
	std::wstring msg = TEXT("Score : ") + std::to_wstring(score);
	TextOut(App::hDC, x, y, msg.c_str(), lstrlen(msg.c_str()));
}