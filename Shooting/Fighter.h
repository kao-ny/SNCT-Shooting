#pragma once
#include "FlyingObject.h"
#include <vector>
#include "Missile.h"

class Fighter : public FlyingObject
{
	unsigned int dir;		// ���݂̈ړ�����
	std::vector<Missile*> missiles;

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
	
	void loadMissile(Missile* m); // �~�T�C��m��o�^����
	void shoot(void); // �~�T�C���𔭎˂���
};

