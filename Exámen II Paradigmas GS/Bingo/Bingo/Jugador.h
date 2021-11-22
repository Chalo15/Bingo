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

