#include "pch.h"
#include "Player.h"


Player::Player()
{
	Name = "";
	age = 0;
	Points = 0;
}

Player::Player(string x, int y) {
	Name = x;
	age = y;
	Points = 0;
}

void Player::ask2set() {
	cout << "Introduza o seu nome:";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, Name);
	cout << "Introduza a sua Idade:";
	cin >> age;
}

bool Player::Save() {
	ofstream os;

	os.open("Player_Save.txt");

	if (!os) {
		return 0;
	}

	else {
		os << Name << ";" << age << endl;
		os.close();
		return 1;
	}
}

Player::~Player()
{
}
