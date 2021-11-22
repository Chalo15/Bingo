#pragma once
#include "Carton.h"
#include <list>
#include <iterator>

class Jugador
{

private:
	string name;
	bool win;
	Carton cBingo;
	list <int> numeros;

public:
	//ctor //dtor
	Jugador() {
		name = "";
		win = false;
	}
	~Jugador() {

	}
	Carton getcBingo() {
		return cBingo;
	}
	bool getGane() {
		if (cBingo.compruebaDiagDer() || cBingo.compruebaDiagIzq() || cBingo.compruebaHorizontal1() || cBingo.compruebaHorizontal2() || cBingo.compruebaHorizontal3() || cBingo.compruebaHorizontal4() || cBingo.compruebaHorizontal5() || cBingo.compruebaVertical1() || cBingo.compruebaVertical2() || cBingo.compruebaVertical3() || cBingo.compruebaVertical4() || cBingo.compruebaVertical5() || cBingo.compruebaEsquinas()) {
			return true;
		}
		else { return false; }
	}
	string getNombre() {
		return name;
	}
	//create players
	void requestName() {
		cout << "Ingrese su nombre: ";
		cin.ignore();
		getline(cin, name);
		win = false; 
		cout << endl;
		cBingo.llenaCarton();
	}
};

