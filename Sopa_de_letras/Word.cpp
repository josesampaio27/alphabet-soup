#include "pch.h"
#include "Word.h"
#include <string>
#include <time.h>
#include "Point.h"


Word::Word()
{
	Letters = "NULL";
}

Word::Word(string x) {
	Letters = x;
}

Word::Word(string x, Point y) {
	Letters = x;
	Position[0] = y;
}

void Word::Set_Position(Point x) {
	Position[0] = x;
	int i;

	for (i = 1; i < this->size(); i++) {
		if (this->Get_Direction() == 0) {
			Position[i].SetX(Position[0].GetX());
			Position[i].SetY(Position[0].GetY() + i);
		}

		else {
			Position[i].SetX(Position[0].GetX() + i);
			Position[i].SetY(Position[0].GetY());
		}
	}
}

void Word::Set_Letters(string x) {
	Letters = x;
}

Point Word::Get_Position(int x){
	return Position[x];
}

string Word::Get_Letters() {
	return Letters;
}

void Word::Rand_Direction() {
	Direction = rand() % 2; 
}

void Word::save(ofstream& os) const{
	os << Letters << ";" << Direction << ";" << allreadyplayed << ";" << sizee << ";" << this->Position->GetX() << ";" << this->Position->GetY() << endl;
}

void Word::load(ifstream& is) {
	char aux[50];

	is.getline(aux, 100, ';');
	Letters = aux;
	is.getline(aux, 100, ';');
	Direction = atoi(aux);
	is.getline(aux, 100, ';');
	allreadyplayed = atoi(aux);
	is.getline(aux, 100, ';');
	sizee = atoi(aux);
	is.getline(aux, 100, ';');
	this->Position->SetX(atoi(aux));
	is.getline(aux, 100, '\n');
	this->Position->SetY(atoi(aux));
	
}
