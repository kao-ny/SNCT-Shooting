#include "stdafx.h"
#include "ShootingApp.h"
#include "FlyingObject.h"

// Add: ���K1
FlyingObject::FlyingObject(void) : x(0), vx(0), y(0), vy(0), radius(0), status(0)
{
}


FlyingObject::~FlyingObject(void)
{
}

void FlyingObject::init(void)
{
	x = 0;
	vx = 0;
	// Add: ���K1
	y = 0;
	vy = 0;
	lap.reset();

	radius = 0;
	status = ACTIVE;
	mtimer.reset();

}

void FlyingObject::cleanup(void)
{
	status = 0;
}

void FlyingObject::update(void)
{
}

void FlyingObject::draw(void)
{
}

void FlyingObject::drawDebug(void) {
	HPEN rp = CreatePen(PS_DASH, 0.5, RGB(255, 0, 0));
	SelectObject(App::hDC, rp);
	SelectObject(App::hDC, GetStockObject(NULL_BRUSH));
	Ellipse(App::hDC, x - radius, y - radius, x + radius, y + radius);
	DeleteObject(rp);
}

#define sqr(x) ((x)*(x))
bool FlyingObject::checkCollision(FlyingObject* fo)
{
	if (!(fo->status & ACTIVE)) // ���葊�肪�A�N�e�B�u�łȂ����
		return false; // false��Ԃ�

	if (!(fo->status & COLLISION))
		return false; // false��Ԃ�

	if (!(status & COLLISION)) { // �����̏Փ˃t���O���Z�b�g����Ă��Ȃ���΁A
		status = COLLISION; // �����̏Փ˃t���O���Z�b�g
		mtimer.reset(); // �����̏Փ˃A�j���[�V�����p�^�C�}�[���Z�b�g
	}

	// TODO
	if (!(fo->status & COLLISION)) { // ����̏Փ˃t���O���Z�b�g����Ă��Ȃ���΁A
		fo->status = COLLISION; // ����̏Փ˃t���O���Z�b�g
		fo->mtimer.reset(); // ����̏Փ˃A�j���[�V�����p�^�C�}�[���Z�b�g
	}

	return true;
}

void FlyingObject::drawExplosion(void)
{ // TODO: �e���I���W�i���̔����A�j���[�V��������邱�ƁB
	LPCWSTR c;
	double t = mtimer.get(); // �Փ˂��Ă���̌o�ߎ���
	if (t > 0.4) {
		c = TEXT("*");
		TextOut(App::hDC, (int)x - 5, (int)y - 5, c, lstrlen(c));
	}
	else if (t > 0.3) {
		c = TEXT("***");
		TextOut(App::hDC, (int)x - 15, (int)y - 5, c, lstrlen(c));
	}
	else if (t > 0.1) {
		c = TEXT("(***)");
		TextOut(App::hDC, (int)x - 25, (int)y - 5, c, lstrlen(c));
	}
	else {
		c = TEXT("(*)");
		TextOut(App::hDC, (int)x - 15, (int)y - 5, c, lstrlen(c));
	}
}