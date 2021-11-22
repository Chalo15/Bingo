#pragma once
#include "Jugador.h"
#include <list>
#include <iterator>

class GUI
{
private:
	int opcion = 0, cantJugadores = 0;
	Jugador ply;
	list <Jugador> players;
	list <Jugador>::iterator player;
	int cc = 0;
	int num = 0;
	int numeros[75];
	string numbers[75];


public:
	//ctor //dtor
	GUI() {
		llenaVec(0);
	}
	~GUI() {

	}

	//game method
	void game();

	void llenaVec(int i){
		if (i < 75) {
			numeros[i] = 0;
			i++;
			llenaVec(i);
		}
		else {
			return;
		}
	}

	void registraJugadores(int i, int cp) {
		if (i < cp) {
			cout << "Jugador " << i;
			ply.requestName();
			players.push_back(ply);
			i++;
			registraJugadores(i, cp);
		}
		else {
			return;
		}
	}
	void randomNumber(int i) {
		if (i < 5) {
			bool compr = false;
		genera:
			num = rand() % (75 - 1 + 1) + 1;
			compr = compruebaSerie(0, num);
			if (compr == true) {
				goto genera;
			}
			numeros[i] = num;
			string n = "";
			stringstream x;
			x << numeros[i];
			n = x.str();
			numbers[i] = n;
			system("pause");
			randomNumber(i);
		}
		else {
			return;
		}
	}
	bool compruebaSerie(int i, int num) {
		bool prueba = false; // omite el buffer
		if (i < 75) {
			if (numeros[i] == num) {
				return true;
			}
			else {
				i++;
				prueba = compruebaSerie(i, num);
			}
		}
		return prueba;
	}


};

