#include "pch.h"
#include "Char.h"
#include <time.h>

using namespace std;

Char::Char()
{
	Ch = 0;
	is_word = 0;
	num_word = -1;
}


Char::~Char()
{
}

Char::Char(char x) {
	Ch = x;
	is_word = 0;
}

void Char::Rand() {

	Ch = rand()%25+97;
	is_word = 0;
}

void Char::View() {
	cout << Ch<<" ";
}

void Char::save(ofstream& os) const{
	os << Ch << ";" << is_word << ";" << num_word << endl;
}

void Char::load(ifstream& is){
	char aux;

	is >> Ch;
	is >> aux;
	is >> is_word;
	is >> aux;
	is >> num_word;
}