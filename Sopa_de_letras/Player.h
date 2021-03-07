#pragma once
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Player
{
private:
	string Name;
	int age;
	int Points;

public:
	Player();
	Player(string x, int y);
	inline void Set_Name(string x) { Name = x; };
	inline void Set_age(int x) { age = x; };
	inline void Set_points(int x) { Points = x; };
	inline string Get_Name() { return Name; };
	inline int Get_age() { return age; };
	inline int Get_points() { return Points; };
	void ask2set();
	inline void add_points(int x) { Points = Points + x; };
	bool Save();
	~Player();
};

