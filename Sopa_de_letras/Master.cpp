#include "pch.h"
#include "Master.h"


Master::Master()
{
}

void Master::Play() {
	srand(time(NULL));

	int nc, nl;
	int again;

	this->ask2set();

	Player temp(this->Get_Name(), this->Get_age());

	do {
		do {
			cout << "Introduza o numero de colunas do jogo com um minimo de 15 e um maximo de 30: ";
			cin >> nc;
		} while (nc < 15 || nc > 30);
		do {
			cout << "Introduza o numero de linhas do jogo com um minimo de 15 e um maximo de 30: ";
			cin >> nl;
		} while (nl < 15 || nl > 30);

		system("CLS");

		Game Sopa(nc, nl, this->Get_Name(), 1);

		Sopa.Run(temp,0);
		this->add_points(Sopa.Get_Gamescore());

		system("CLS");

		cout << "Parabens venceu o jogo com " << this->Get_points() << " pontos!!" << endl;
		do {
			cout << "Quer voltar a jogar?" << endl << "1 - sim" << endl << "2 - nao" << endl;
			cin >> again;
		} while (again != 1 && again != 2);


	} while (again == 1);
}

bool Master::load() {
	char aux[50];
	int again, nc, nl;
	ifstream is;

	is.open("Player_Save.txt");

	if (!is) {
		return 0;
	}

	else {
		is.getline(aux, 100, ';');
		this->Set_Name(aux);
		is.getline(aux, 100, '\n');
		this->Set_age(atoi(aux));
		is.close();
	}

	Game sopa;

	if (!sopa.load()) {
		cout << "Erro ao carregar jogo" << endl;
		system("Pause");
		return 0;
	}

	Player temp(this->Get_Name(), this->Get_age());

	sopa.Run(temp, 1);
	this->add_points(sopa.Get_Gamescore());

	system("CLS");

	cout << "Parabens venceu o jogo com " << this->Get_points() << " pontos!!" << endl;

	do {
		cout << "Quer voltar a jogar?" << endl << "1 - sim" << endl << "2 - nao" << endl;
		cin >> again;
	} while (again != 1 && again != 2);

	if (again == 1) {
		do {
			do {
				cout << "Introduza o numero de colunas do jogo com um minimo de 15 e um maximo de 30: ";
				cin >> nc;
			} while (nc < 15 || nc > 30);
			do {
				cout << "Introduza o numero de linhas do jogo com um minimo de 15 e um maximo de 30: ";
				cin >> nl;
			} while (nl < 10 || nl > 20);

			system("CLS");

			Game Sopa(nc, nl, this->Get_Name(), 1);

			Sopa.Run(temp, 0);
			this->add_points(Sopa.Get_Gamescore());

			system("CLS");

			cout << "Parabens venceu o jogo com " << this->Get_points() << " pontos!!" << endl;
			do {
				cout << "Quer voltar a jogar?" << endl << "1 - sim" << endl << "2 - nao" << endl;
				cin >> again;
			} while (again != 1 && again != 2);


		} while (again == 1);
	}
}


Master::~Master()
{
}
