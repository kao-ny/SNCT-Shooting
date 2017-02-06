#include "stdafx.h"
#include "ShootingApp.h"
#include "Fighter.h"
#include "Sound.h"

Fighter::Fighter(void) : FlyingObject(), dir(STOP)
{
}

Fighter::~Fighter(void)
{
}

void Fighter::init(void)
{
	FlyingObject::init();

	x = 425;
	y = 600;
	vx = 200;
	// Add: ‰‰K1
	vy = 200;
	radius = 20;
}

void Fighter::cleanup(void)
{
	FlyingObject::cleanup();
	missilesA.clear();
	missilesB.clear();
}

void Fighter::loadMissileA(MissileA* m)
{
	missilesA.push_back(m);
}

void Fighter::loadMissileB(MissileB* m)
{
	missilesB.push_back(m);
}

void Fighter::update(void)
{
	if (status & COLLISION) { // Õ“Ë‚µ‚Ä‚¢‚½‚çÀ•W‚ðXV‚µ‚È‚¢
		if (etimer.get() > 0.5) // Õ“ËŠúŠÔ‚ªI‚í‚Á‚½‚çA
			cleanup(); // I—¹Žè‘±‚«
		return;
	}


	FlyingObject::update();

	double dx = 0;
	// Add: ‰‰K1
	double dy = 0;
	double dt = lap.get();

	if(dir & LEFT)
		dx -= vx * dt;
	if(dir & RIGHT)
		dx += vx * dt;
	// Add: ‰‰K1
	if(dir & FORE)
		dy -= vy * dt;
	if(dir & BACK)
		dy += vy * dt;

	x += dx;
	// Add: ‰‰K1
	y += dy;
	lap.reset();
}

void Fighter::draw(void)
{
	LPCWSTR c;

	if (status & COLLISION) { // Õ“Ë‚µ‚Ä‚¢‚½‚ç”š”­ƒAƒjƒ[ƒVƒ‡ƒ“
		drawExplosion();
		return;
	}

	RECT objArea;
	objArea.left = x - 60;
	objArea.top = y-30;
	objArea.right = x + 60;
	objArea.bottom = y+30;

	HFONT defFont = CreateFont(20, 0, 0, 0, FW_DONTCARE,
		FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
		TEXT("Œ¹ƒmŠpƒSƒVƒbƒN Code JP"));

	SelectObject(App::hDC, defFont);

	//DrawText(App::hDC, L"|\n--+--\n-+-", -1, &objArea, DT_CENTER);
	DrawText(App::hDC, L"¿¿		\nR(L[M)ƒm\n		iQQ_j		", -1, &objArea, DT_CENTER);


	DeleteObject(defFont);

	// drawDebug();	
}


void Fighter::move(DIRECTION dir)
{
	this->dir |= dir;
}

void Fighter::stop(DIRECTION dir)
{
	this->dir &= ~dir;
}

void Fighter::shootA(void)
{
	for (size_t i = 0; i < missilesA.size(); i++)
		if (!(missilesA[i]->status & ACTIVE)) {
			missilesA[i]->init();
			missilesA[i]->fire(x, y - radius, 0, -300);
			Sound::getInstance()->request(TEXT("shoot"));
			return;
		}
}

void Fighter::shootB(void)
{
	for(size_t i = 0; i < missilesB.size()-5; i++)
		if(!(missilesB[i]->status & ACTIVE)) {
			missilesB[i]->init();
			missilesB[i+1]->init();
			missilesB[i+2]->init();
			missilesB[i + 3]->init();
			missilesB[i + 4]->init();
			missilesB[i]->fire(x, y - radius, 150 * App::rand(), -1200 * App:: rand());
			missilesB[i+1]->fire(x-20, y - radius, -20, -450);
			missilesB[i+2]->fire(x+20, y - radius, +20, -450);
			missilesB[i + 3]->fire(x - 40, y - radius, -40, -450);
			missilesB[i + 4]->fire(x + 40, y - radius, +40, -450);
			Sound::getInstance()->request(TEXT("shoot"));
			return;
		}
}