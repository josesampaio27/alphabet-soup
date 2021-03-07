#pragma once

class Score
{
private:
	int score;

public:
	Score();
	Score(int _s);

	void Set_Score(int _s) { score = _s; }
	int Get_Score(void) const { return score; }

	~Score();
};

