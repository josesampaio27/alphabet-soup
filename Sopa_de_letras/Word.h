#pragma once
#include <iostream>
#include <string>
#include "Point.h"
#include <fstream>


using namespace std;

class Word
{
public:
	Word(void);
	Word(string x);
	Word(string x, Point y);
	void Set_Position(Point x);
	Point Get_Position(int x);
	void Set_Letters(string x);
	string Get_Letters();
	inline void _Posinit(int x) { Position = new Point[x]; };
	inline void Set_Direction(bool x) { Direction = x; }
	inline bool Get_Direction() { return Direction; }
	void Rand_Direction();
	inline void set_allreadyplayed(bool x) { allreadyplayed = x; };
	inline bool Get_allreadyplayed() { return allreadyplayed; };
	inline int size() { return  sizee ; };
	inline void setzize(int x) { sizee = x; };
	void save(ofstream& os) const;
	void load(ifstream& is);

private:
	string Letters;
	Point *Position;
	//0=horizontal 1=vertical
	bool Direction;
	bool allreadyplayed;
	int sizee;
};

