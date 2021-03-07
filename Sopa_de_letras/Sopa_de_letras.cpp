#include "pch.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include "Point.h"
#include "Char.h"
#include "Word.h"
#include "Board.h"
#include "Game.h"
#include "Rooky.h"
#include "Master.h"
#include "Player.h"

using namespace std;

int main()
{
	int dificulty,choice;

	cout << "1 - Novo Jogo" << endl << "2 - Carregar Jogo" << endl;
	do {
		cin >> choice;
	} while (choice < 1 || choice>2);

	system("CLS");

	if (choice == 1) {
		cout << "Escolha a dificuldade:" << endl << "1 - Principiante" << endl << "2 - Experiente" << endl;
		do {
			cin >> dificulty;
		} while (dificulty < 1 || dificulty>2);

		system("CLS");

		if (dificulty == 1) {
			Rooky player;
			player.Play();
		}

		else {
			Master player;
			player.Play();
		}

	}

	else {
		cout << "Escolha o jogo que deseja carregar:" << endl << "1 - Principiante" << endl << "2 - Experiente" << endl;
		do {
			cin >> dificulty;
		} while (dificulty < 1 || dificulty>2);

		system("CLS");

		if (dificulty == 1) {
			Rooky player;
			if (!player.load()) {
				cout << "Erro ao carregar jogo" << endl;
				system("Pause");
			}
		}

		else {
			Master player;
			if (!player.load()) {
				cout << "Erro ao carregar jogo" << endl;
				system("Pause");
			}
		}
	}
	
}
