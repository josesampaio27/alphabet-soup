#include "pch.h"
#include "Game.h"


Game::Game(int x, int y, string z,int w){
	if (w == 0) {
		PlayBoard.Init_Rookie(x, y);
	}
	else{
		PlayBoard.Init_Master(x, y);
	}
	GamePlayer = z;
}

Game::Game() {

}

void Game::Run(Player x,bool difficulty) {
	do {
		bool saved;
		system("CLS");
		cout << "Jogador: " << GamePlayer<< endl;
		cout << "Tema: " <<PlayBoard.get_tema()<< endl;
		cout << "Numero de palavras: " << PlayBoard.Get_numwords() << endl;
		PlayBoard.View();
		cout <<"Palavras encontradas: " << GameSore<<endl<<endl;
		int choice;
			cout << "1 - Jogar palavra" << endl << "2 - Guardar jogo" << endl;
		do {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			do {
				cin >> choice;
			} while (choice < 1 || choice>2);

			saved = 1;
			
			if (choice == 2) {
				system("CLS");
				if (!this->Save()) {
					cout << "Problema ao salvar"<<endl;
					system("Pause");;
					system("CLS");
					cout << "Jogador: " << GamePlayer <<endl;
					cout << "Tema: " << PlayBoard.get_tema() << endl;
					cout << "Numero de palavras: " << PlayBoard.Get_numwords() << endl;
					PlayBoard.View();
					cout << "Palavras encontradas: " << GameSore << endl << endl;
					cout << "1 - Jogar palavra" << endl << "2 - Guardar jogo" << endl;
					saved = 0;
					}
				else if (!x.Save()) {
					cout << "Problema ao salvar"<<endl;
					system("Pause");
					system("CLS");
					cout << "Jogador: " << GamePlayer << endl;
					cout << "Tema: " << PlayBoard.get_tema() << endl;
					cout << "Numero de palavras: " << PlayBoard.Get_numwords() << endl;
					PlayBoard.View();
					cout << "Palavras encontradas: " << GameSore << endl << endl;
					cout << "1 - Jogar palavra" << endl << "2 - Guardar jogo" << endl;
					saved = 0;
					}
				else if (!PlayBoard.Save()) {
					cout << "Problema ao salvar"<<endl;
					system("Pause");
					system("CLS");
					cout << "Jogador: " << GamePlayer << endl;
					cout << "Tema: " << PlayBoard.get_tema() << endl;
					cout << "Numero de palavras: " << PlayBoard.Get_numwords() << endl;
					PlayBoard.View();
					cout << "Palavras encontradas: " << GameSore << endl << endl;
					cout << "1 - Jogar palavra" << endl << "2 - Guardar jogo" << endl;
					saved = 0;
					}
				if (saved == 1) {
					cout << "Jogo Salvo" << endl;
					system("Pause");
					system("CLS");
					cout << "Jogador: " << GamePlayer << endl;
					cout << "Tema: " << PlayBoard.get_tema() << endl;
					cout << "Numero de palavras: " << PlayBoard.Get_numwords() << endl;
					PlayBoard.View();
					cout << "Palavras encontradas: " << GameSore << endl << endl;
					cout << "1 - Jogar palavra" << endl << "2 - Guardar jogo" << endl;
				}
			}

		} while (choice != 1);
	} while (this->Play() != 0);
}

int Game::Play() {
	string temp;
	int i;
	int numwords = PlayBoard.Get_numwords();
	int availablewords = numwords;
	bool exist=0;

	cout << "Escreva uma plavra encontrada:";
	cin >> temp;

	for (i = 0; i < numwords; i++) {
		
		if (temp == PlayBoard.Get_Word(i)) {
			if (PlayBoard.Get_allreadyPlayed(i) == 0) {
				PlayBoard.Set_allreadyPlayed(i, 1);
				availablewords--;
				cout << "Parabens a palavra escrita existe!!" << endl;
				contador++;
				exist = 1;
				system("PAUSE");
			}

			else {
				cout << "A palavra ja foi jogada" << endl;
				exist = 1;
				system("PAUSE");
			}
		}

		else if (PlayBoard.Get_allreadyPlayed(i)==1){
			availablewords--;
		}

	}

	if (exist == 0) {
		cout << "A palavra escrita nao existe" << endl;
		system("PAUSE");
	}

	GameSore = contador;
	return availablewords;
}

bool Game::Save() {
	ofstream os;

	os.open("Game_Save.txt");
	
	if (!os) {
		return 0;
	}

	else {
		os << GamePlayer << ";" << GameSore << endl;
		os.close();
		return 1;
	}
}

bool Game::load() {
	char aux[50];
	ifstream is;
	is.open("Game_Save.txt");

	if (!is) {
		return 0;
	}

	else {
		is.getline(aux, 100, ';');
		GamePlayer = aux;
		is.getline(aux, 100, '\n');
		GameSore = atoi(aux);
		contador = GameSore;
		is.close();
		PlayBoard.load();
		return 1;
	}
}

Game::~Game() {

}