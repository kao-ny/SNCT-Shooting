#pragma once
#include "FlyingObject.h"

class Fighter : public FlyingObject
{
	unsigned int dir;		// Œ»İ‚ÌˆÚ“®•ûŒü

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
};

