#pragma once
class Score
{
private:
	int score;
public:
	Score();
	~Score();
	void init();
	void add(int point);
	void draw(int x, int y);
};

