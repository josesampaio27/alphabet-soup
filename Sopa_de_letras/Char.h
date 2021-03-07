#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Char
{
public:
	Char();
	Char(char x);
	~Char();
	void Rand();
	void View();

	void Set_Ch(char c) { Ch = c; }
	char Get_Ch() { return Ch; }
	inline void set_is_word(bool x) { is_word = x; };
	inline bool get_is_word() { return is_word; };
	inline void set_num_word(int x) { num_word = x; };
	inline int get_num_word() { return num_word; };
	void save(ofstream& os) const;
	void load(ifstream& is);

private:
	char Ch;
	bool is_word;
	int num_word;

};

