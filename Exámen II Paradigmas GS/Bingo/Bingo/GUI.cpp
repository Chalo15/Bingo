#include "GUI.h"

void GUI::game()
{
	bool aux = false;
	while (!aux) {
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
			cout << "Número obtenido: " << numeros[itera] << endl;

			//mostrar ambos cartones con las posibles variaciones 
			cout << "Analizando el carton de " << ply.getNombre() << "..." << endl << endl;
			delay(1);
			ply.getcBingo()->modifica(numeros[itera]);
			ply.getcBingo()->muestraCarton();

			cout << endl;

			cout << "Analizando el carton de " << ply2.getNombre() << "..." << endl << endl;
			delay(1);
			ply2.getcBingo()->modifica(numeros[itera]);
			ply2.getcBingo()->muestraCarton();
			delay(2);
			//vierifica si hay ganador
			if (ply.getGane()) {
				cout << "Felicidades, el jugador " << ply.getNombre() << " ha sido el ganador" << endl;
				estado = true; 
				system("pause");

			}
			else if (ply2.getGane()) {
				cout << "Felicidades, el jugador " << ply2.getNombre() << " ha sido el ganador" << endl;
				estado = true;
				system("pause");
			}
			itera++;
			system("cls");
		}
		cout << "Si desea salir, presione 0 \nSi desea jugar otra vez, presione 1" << endl;
		cin >> aux;
	}
}
