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
	//mostrar ambos cartones asignados

	//ply.getcBingo().muestraCarton();
	randomNumber(0);
	bool estado = false;
	int itera = 0;
	player = players.begin();
	while (!estado) {
		cout << "Número obtenido: " << numeros[itera]<<endl;
		
		//mostrar ambos cartones con las posibles variaciones 
		player->getcBingo().modifica(numeros[itera]);
		player++->getcBingo().modifica(numeros[itera]);

		player->getcBingo().muestraCarton();
		player++->getcBingo().muestraCarton();

		//vierifica si hay ganador
		if (player->getGane()) {
			cout << "Felicidades, el jugador " << player->getNombre() << " ha sido el ganador" << endl;
			estado = true;
		}
		else if (player++->getGane()) {
			cout << "Felicidades, el jugador " << player++->getNombre() << " ha sido el ganador" << endl;
			estado = true;
		}


		itera++;

	}
}
