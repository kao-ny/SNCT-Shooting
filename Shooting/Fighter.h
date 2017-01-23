#pragma once
#include "FlyingObject.h"
#include <vector>
#include "Missile.h"

class Fighter : public FlyingObject
{
	unsigned int dir;		// 現在の移動方向
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
	
	void loadMissile(Missile* m); // ミサイルmを登録する
	void shoot(void); // ミサイルを発射する
};

