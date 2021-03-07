#pragma once
#include "Player.h"
#include <time.h>
#include "Game.h"

class Master: public Player
{
private:

public:
	Master();
	~Master();
	void Play();
	bool load();
};

