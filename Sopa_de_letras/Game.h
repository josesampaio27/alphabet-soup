#pragma once
#include <iostream>
#include "Board.h"
#include <fstream>
#include "Player.h"


using namespace std;

class Game
{
private:
		Board PlayBoard;
		string GamePlayer; 
		int GameSore;

public:
		Game(int x, int y, string z,int w);
		Game();
		~Game();
		int Play();
		void Run(Player x,bool difficulty);
		inline int Get_Gamescore() { return GameSore; };
		int contador = 0;
		bool Save();
		bool load();
};

