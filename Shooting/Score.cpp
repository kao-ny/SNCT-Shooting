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
	HFONT defFont = CreateFont(18, 0, 0, 0, FW_DONTCARE,
		FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
		TEXT("ÇlÇr ÉSÉVÉbÉN"));

	SelectObject(App::hDC, defFont);
	SetTextColor(App::hDC, RGB(0, 0, 0));

	std::wstring msg = TEXT("Score : ") + std::to_wstring(score);
	TextOut(App::hDC, x, y, msg.c_str(), lstrlen(msg.c_str()));

	DeleteObject(defFont);
}