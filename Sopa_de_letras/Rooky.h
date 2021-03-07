#pragma once
#include "Player.h"
#include <time.h>
#include "Game.h"

class Rooky: public Player
{
private:

public:
	Rooky();
	~Rooky();
	void Play();
	bool load();
};

