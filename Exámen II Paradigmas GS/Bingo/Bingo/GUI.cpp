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
	cout << "Ingrese los nombres de los jugadores:" << endl;
	registraJugadores();
	cout << endl;

	//ply.getcBingo().muestraCarton();

	bool estado = false;
	int itera = 0;
	player = players.begin();
	while (!estado) {
		cout << "Girando la tombola..." << endl;
		delay(1);
		cout << "Número obtenido: " << numeros[itera]<<endl;
		
		//mostrar ambos cartones con las posibles variaciones 
		cout << "Analizando el carton de " << ply.getNombre() <<"..." << endl;
		//delay(1.5);
		ply.getcBingo()->modifica(numeros[itera]);
		ply.getcBingo()->muestraCarton();
		cout << endl;
		cout << "Analizando el carton de " << ply2.getNombre() << "..." << endl;
		//delay(1.5);
		ply2.getcBingo()->modifica(numeros[itera]);
		ply2.getcBingo()->muestraCarton();

		//vierifica si hay ganador
		if (ply.getGane()) {
			cout << "Felicidades, el jugador " << ply.getNombre() << " ha sido el ganador" << endl;
			estado = true;
		}
		else if (ply2.getGane()) {
			cout << "Felicidades, el jugador " << ply2.getNombre() << " ha sido el ganador" << endl;
			estado = true;
		}
		itera++;
	}
}
