#include "pch.h"
#include "Board.h"
#include "Char.h"
#include "Word.h"
#include <time.h>
#include <string>
#include <fstream>
#include <Windows.h>

//Defenir ascii code dos contornos da sopa de letra
#define  linhav 186
#define  linhah 205
#define  canto1 201
#define  canto2 187
#define  canto3 200
#define  canto4 188

using namespace std;

Board::Board()
{
	BoardWidth = 0;
	BoardHeight = 0;
	Chars = NULL;
	NumWords = 0;
}

void Board::Init_Rookie(int Sx, int Sy) {
	BoardHeight = Sx;
	BoardWidth = Sy;
	difficulty = 0;
	int i = 0, j = 0, k = 0, w = 0;

	//alocaçao da matriz
	Chars = new Char*[Sx];
	for (i = 0; i < Sx; i++) {
		Chars[i] = new Char[Sy];
	}

	//prenchimento dos chars aleatoriamente
	for (i = 0; i < Sx; i++) {
		for (j = 0; j < Sy; j++) {
			Chars[i][j].Rand();
		}
	}

	//criaçao e abertura do ficheiro
	ifstream is;
	is.open("words.txt");
	if (!is) {
		cout << "Erro ao abrir o ficheiro";
		exit(1);
	}

	string temp;

	int lengt;
	Point aux;
	bool valid = 1;

	Word words_temp[50];

	//leitura de todas as palavras
	for (i = 0; i < 50; i++) {
		getline(is, temp);
		lengt = temp.size();
		words_temp[i].Set_Letters(temp);
		words_temp[i].setzize(lengt);
		words_temp[i]._Posinit(lengt);
	}

	int choice = 0;

	//escolha do tema e quantas palavras quer
	do {
		cout << "Qual dos temas quer jogar?" << endl << "1 - Cidades  de portugal" << endl << "2 - Paises" << endl << "3 - Profissoes" << endl << "4 - Planetas/astros" << endl << "5 - Capitais" << endl;
		cin >> choice;
	} while (choice < 1 || choice > 5);
	do {
		cout << "De 1 a 5 com quantas palavras quer jogar?"<<endl;
		cin >> NumWords;
	} while (NumWords < 0 || NumWords > 5);

	system("CLS");

	//alocaçao do array words
	Words = new Word[NumWords];

	if (choice == 1) {
		for (i = 0; i < NumWords; i++) {
			Words[i] = words_temp[i];
		}
		tema = "Cidades De Portugal";
	}
	else if (choice == 2) {
		for (i = 0; i < NumWords; i++) {
			Words[i] = words_temp[i + 10];
		}
		tema = "Paises";
	}
	else if (choice == 3) {
		for (i = 0; i < NumWords; i++) {
			Words[i] = words_temp[i + 20];
		}
		tema = "Proficoes";
	}
	else if (choice == 4) {
		for (i = 0; i < NumWords; i++) {
			Words[i] = words_temp[i + 30];
		}
		tema = "Planetas/Astros";
	}
	else if (choice == 5) {
		for (i = 0; i < NumWords; i++) {
			Words[i] = words_temp[i + 40];
		}
		tema = "Capitais";
	}

	//criaçao de coordenadas aleatorias e validas
	for (i = 0; i < NumWords; i++) {
		
		//verificar se a matriz é grande o sufeciente para caberem as palavras
		if (Sx < Words[i].size() + 1 || Sy < Words[i].size() + 1) {
			cout << "A matriz e pequena demais, por favor insira uma maior!";
			exit(-1);
		}
		
		do {
			//escolha das cordenadas e verificação se validas
			valid = 1;
			Words[i].Rand_Direction();

			if (Words[i].Get_Direction() == 0) {
				if (aux.SetX(rand() % Sx)) {
				}
				else {
					valid = 0;
				}
				if (aux.SetY((rand() % Sy) - lengt)) {
				}
				else {
					valid = 0;
				}
				Words[i].Set_Position(aux);
			}

			else{

				if (aux.SetX((rand() % Sx) - lengt)) {
				}
				else {
					valid = 0;
				}
				if (aux.SetY(rand() % Sy)) {
				}
				else {
					valid = 0;
				}

				Words[i].Set_Position(aux);
			}

			for (j = i - 1; j >= 0; j--) {
				for (w = 0; w < Words[i].size(); w++) {
					for (k = 0; k < Words[j].size(); k++) {

						//verifica se as palavras nao estao umas em cima das outras
						if (Words[i].Get_Position(w) == Words[j].Get_Position(k)) {
							valid = 0;
						}
				
					}
				}
			}

			aux = Words[i].Get_Position(0);
			if (aux.IsValid()!=1) {
				valid = 0;
			}

		} while (valid == 0);

		Words[i].set_allreadyplayed(0);
	
	}	

	//colocaçao das palavras na matriz
	for (i = 0; i < NumWords; i++) {
		temp = Words[i].Get_Letters();
		lengt = temp.size();
		aux = Words[i].Get_Position(0);
		
		if (Words[i].Get_Direction() == 0) {
			
				for (j = 0; j < lengt; j++) {
					Chars[aux.GetX()][aux.GetY() + j] = temp[j];
					//Set para mostrar que este chat faz parte de uma word e qual
					Chars[aux.GetX()][aux.GetY() + j].set_is_word(1);
					Chars[aux.GetX()][aux.GetY() + j].set_num_word(i);
				}
		}

		else if (Words[i].Get_Direction() == 1) {

			for (j = 0; j < lengt; j++) {
				Chars[aux.GetX() + j][aux.GetY()] = temp[j];
				//Set para mostrar que este chat faz parte de uma word e qual
				Chars[aux.GetX() + j][aux.GetY()].set_is_word(1);
				Chars[aux.GetX() + j][aux.GetY()].set_num_word(i);
			}
		}
	}

	is.close();
}

void Board::Init_Master(int Sx, int Sy) {
	BoardHeight = Sx;
	BoardWidth = Sy;
	difficulty = 1;
	int i = 0, j = 0, k = 0, w = 0;

	//alocaçao da matriz
	Chars = new Char*[Sx];
	for (i = 0; i < Sx; i++) {
		Chars[i] = new Char[Sy];
	}

	//prenchimento dos chars aleatoriamente
	for (i = 0; i < Sx; i++) {
		for (j = 0; j < Sy; j++) {
			Chars[i][j].Rand();
		}
	}

	//criaçao e abertura do ficheiro
	ifstream is;
	is.open("words.txt");
	if (!is) {
		cout << "Erro ao abrir o ficheiro";
		exit(1);
	}

	string temp;

	int lengt;
	Point aux;
	bool valid = 1;

	Word words_temp[50];

	//leitura de todas as palavras
	for (i = 0; i < 50; i++) {
		getline(is, temp);
		lengt = temp.size();
		words_temp[i].Set_Letters(temp);
		words_temp[i].setzize(lengt);
		words_temp[i]._Posinit(lengt);
	}

	int choice = 0;

	//escolha do tema e quantas palavras quer
	do {
		cout << "Qual dos temas quer jogar?" << endl << "1 - Cidades  de portugal" << endl << "2 - Paises" << endl << "3 - Profissoes" << endl << "4 - Planetas/astros" << endl << "5 - Capitais" << endl;
		cin >> choice;
	} while (choice < 1 || choice > 5);
	do {
		cout << "De 5 a 10 com quantas palavras quer jogar?" << endl;
		cin >> NumWords;
	} while (NumWords < 5 || NumWords > 10);

	system("CLS");

	//alocaçao do array words
	Words = new Word[NumWords];

	if (choice == 1) {
		for (i = 0; i < NumWords; i++) {
			Words[i] = words_temp[i];
		}
		tema = "Cidades De Portugal";
	}
	else if (choice == 2) {
		for (i = 0; i < NumWords; i++) {
			Words[i] = words_temp[i + 10];
		}
		tema = "Paises";
	}
	else if (choice == 3) {
		for (i = 0; i < NumWords; i++) {
			Words[i] = words_temp[i + 20];
		}
		tema = "Proficoes";
	}
	else if (choice == 4) {
		for (i = 0; i < NumWords; i++) {
			Words[i] = words_temp[i + 30];
		}
		tema = "Planetas/Astros";
	}
	else if (choice == 5) {
		for (i = 0; i < NumWords; i++) {
			Words[i] = words_temp[i + 40];
		}
		tema = "Capitais";
	}

	//criaçao de coordenadas aleatorias e validas
	for (i = 0; i < NumWords; i++) {

		//verificar se a matriz é grande o sufeciente para caberem as palavras
		if (Sx < Words[i].size() + 1 || Sy < Words[i].size() + 1) {
			cout << "A matriz e pequena demais, por favor insira uma maior!";
			exit(-1);
		}

		do {
			//escolha das cordenadas e verificação se validas
			valid = 1;
			Words[i].Rand_Direction();

			if (Words[i].Get_Direction() == 0) {
				if (aux.SetX(rand() % Sx)) {
				}
				else {
					valid = 0;
				}
				if (aux.SetY((rand() % Sy) - lengt)) {
				}
				else {
					valid = 0;
				}
				Words[i].Set_Position(aux);
			}

			else {

				if (aux.SetX((rand() % Sx) - lengt)) {
				}
				else {
					valid = 0;
				}
				if (aux.SetY(rand() % Sy)) {
				}
				else {
					valid = 0;
				}

				Words[i].Set_Position(aux);
			}

			for (j = i - 1; j >= 0; j--) {
				for (w = 0; w < Words[i].size(); w++) {
					for (k = 0; k < Words[j].size(); k++) {

						//verifica se as palavras nao estao umas em cima das outras
						if (Words[i].Get_Position(w) == Words[j].Get_Position(k)) {
							valid = 0;
						}

					}
				}
			}

			aux = Words[i].Get_Position(0);
			if (aux.IsValid() != 1) {
				valid = 0;
			}

		} while (valid == 0);

		Words[i].set_allreadyplayed(0);

	}

	//colocaçao das palavras na matriz
	for (i = 0; i < NumWords; i++) {
		temp = Words[i].Get_Letters();
		lengt = temp.size();
		aux = Words[i].Get_Position(0);

		if (Words[i].Get_Direction() == 0) {

			for (j = 0; j < lengt; j++) {
				Chars[aux.GetX()][aux.GetY() + j] = temp[j];
				//Set para mostrar que este char faz parte de uma word e qual
				Chars[aux.GetX()][aux.GetY() + j].set_is_word(1);
				Chars[aux.GetX()][aux.GetY() + j].set_num_word(i);
			}
		}

		else if (Words[i].Get_Direction() == 1) {

			for (j = 0; j < lengt; j++) {
				Chars[aux.GetX() + j][aux.GetY()] = temp[j];
				//Set para mostrar que este chat faz parte de uma word e qual
				Chars[aux.GetX() + j][aux.GetY()].set_is_word(1);
				Chars[aux.GetX() + j][aux.GetY()].set_num_word(i);
			}
		}
	}

	is.close();
}

void Board::View() {
	int i, j, aux = 0,num;

	//Desenho da sopa com contornos
	cout << char(canto1);
	for (i = 0; i < BoardWidth*2; i++) {
		cout << char(linhah);
	}
	cout << char(canto2);

	cout << endl;
	cout << char(linhav);

	for (i = 0; i < BoardHeight; i++) {
		for (j = 0; j < BoardWidth; j++) {
			
			//verifica se o char faz parte de uma word e se essa word ja foi jogada, se ja muda a cor dele para amarelo
			if (Chars[i][j].get_is_word() == 1) {
				num = Chars[i][j].get_num_word();

				if (Words[num].Get_allreadyplayed() == 1) {
					aux = 1;

					if (difficulty == 0) {
						HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(H, 14);
						Chars[i][j].View();
						SetConsoleTextAttribute(H, 7);
					}
					else {
						Chars[i][j].View();
					}
				}
			}

			if (aux == 0) {
				Chars[i][j].View();
			}
			aux = 0;

		}
		cout << char(linhav);
		cout << endl;
		if (i < BoardHeight - 1) {
			cout << char(linhav);
		}
	}
		
	cout << char(canto3);

	for (i = 0; i < BoardWidth*2; i++) {
		cout << char(linhah);
	}

	cout << char(canto4);
	cout << endl;
}

string Board::Get_Word(int x) {
	string temp;
	temp = Words[x].Get_Letters();
	return temp;
}

bool Board::Get_allreadyPlayed(int x) {
	bool temp;
	temp = Words[x].Get_allreadyplayed();
	return temp;
}

bool Board::Save() {
	ofstream os;
	int i,j;

	os.open("Board_Save.txt");

	if (!os) {
		return 0;
	}

	else {
		os << BoardWidth << ";" << BoardHeight << ";" << NumWords << ";" << difficulty << ";" << tema << endl;
		os.close();

		ofstream oc;

		oc.open("Word_Save.txt");
		if (!oc) {
			return 0;
		}
		
		for (i = 0; i < NumWords; i++) {
			this->Words[i].save(oc);
		}

		oc.close();


		ofstream od;

		od.open("Char_Save.txt");

		if (!od) {
			return 0;
		}

		else {
			for (i = 0; i < BoardHeight; i++) {
				for (j = 0; j < BoardWidth; j++) {
					this->Chars[i][j].save(od);
				}
			}
		}

		od.close();

		return 1;
	}
	
}

bool Board::load() {
	char aux[50];
	ifstream is;
	int i, j;

	is.open("Board_Save.txt");

	if (!is) {
		return 0;
	}

	else {
		is.getline(aux, 100, ';');
		BoardWidth = atoi(aux);
		is.getline(aux, 100, ';');
		BoardHeight = atoi(aux);
		is.getline(aux, 100, ';');
		NumWords = atoi(aux);
		is.getline(aux, 100, ';');
		difficulty = atoi(aux);
		is.getline(aux, 100, '\n');
		tema = aux;
		is.close();

		Words = new Word[NumWords];

		Chars = new Char*[BoardHeight];
		for (i = 0; i < BoardHeight; i++) {
			Chars[i] = new Char[BoardWidth];
		}

		ifstream ic;

		ic.open("Word_Save.txt");
		if (!ic) {
			return 0;
		}

		for (i = 0; i < NumWords; i++) {
			this->Words[i]._Posinit(i);
			this->Words[i].load(ic);
		}

		ic.close();


		ifstream id;

		id.open("Char_Save.txt");

		if (!id) {
			return 0;
		}

		else {
			for (i = 0; i < BoardHeight; i++) {
				for (j = 0; j < BoardWidth; j++) {
					this->Chars[i][j].load(id);
				}
			}
		}

		id.close();

		return 1;
	}
}


Board::~Board()
{
	int i = 0;

	delete[] this->Words;

	for (i = 0; i < BoardHeight; i++) {
		delete[] this->Chars[i];
	}
	delete[] this->Chars;
}
