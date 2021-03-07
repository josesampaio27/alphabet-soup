#pragma once
#include <iostream>
#include "Char.h"
#include "Word.h"
#include "Char.h"



class Board
{
private:
	int BoardWidth;
	int BoardHeight;
	Char** Chars;
	Word* Words;
	int NumWords;
	string tema;
	int difficulty;

public:
	Board(void);
	void Init_Rookie(int Sx, int Sy);
	void Init_Master(int Sx, int Sy);
	void View(void);	
	inline int Get_numwords() { return NumWords; };
	string Get_Word(int x);
	bool Get_allreadyPlayed(int x);
	inline void Set_allreadyPlayed(int x, bool y) { Words[x].set_allreadyplayed(y); };
	~Board();
	inline string get_tema() { return tema; };

	inline void Set_BoardWidth(int bw) { BoardWidth = bw; }
	inline void Set_BoardHeight(int bh) { BoardHeight = bh; };

	bool Save();
	bool load();
	


};
