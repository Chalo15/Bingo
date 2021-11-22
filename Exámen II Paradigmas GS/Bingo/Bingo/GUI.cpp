#include "GUI.h"

void GUI::game()
{

	cout << endl << endl;
	cout << "		Juego de BINGO tradicional costarricense" << endl << endl;
	cout << "		Reglas para ganar:" << endl;
	cout << "		- Se puede ganar con 4 esquinas" << endl;
	cout << "		- Diagonal de izquierda a derecha" << endl;
	cout << "		- Diagonal de derecha a izquierda" << endl;
	cout << "		- Linea recta horizontal o vertical" << endl;
	cout << endl << endl << endl;
	cout << "Ingrese la cantidad de jugadores:" << endl;
	cin >> cc;
	registraJugadores(0, cc);
	cout << endl;
	

}
