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


public:
	//ctor //dtor
	GUI() {

	}
	~GUI() {

	}
	//game method
	void game();


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


};

