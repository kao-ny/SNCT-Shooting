#pragma once
#include "FlyingObject.h"
#include <vector>
#include "MissileA.h"
#include "MissileB.h"


class Fighter : public FlyingObject
{
	unsigned int dir;		// ���݂̈ړ�����
	std::vector<MissileA*> missilesA;
	std::vector<MissileB*> missilesB;


public:
	enum DIRECTION {
		STOP = 0,
		FORE = 1,
		BACK = 2,
		LEFT = 4,
		RIGHT = 8
	};

	Fighter(void);
	~Fighter(void);

	void init(void);
	void cleanup(void);
	void update(void);
	void draw(void);

	void move(DIRECTION dir);
	void stop(DIRECTION dir);
	
	void loadMissileA(MissileA* m); // �~�T�C��m��o�^����
	void shootA(void); // �~�T�C���𔭎˂���

	void loadMissileB(MissileB* m); // �~�T�C��m��o�^����
	void shootB(void); // �~�T�C���𔭎˂���
};

