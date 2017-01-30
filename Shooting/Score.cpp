#include "stdafx.h"
#include "Score.h"


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

}