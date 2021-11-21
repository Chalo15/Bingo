#pragma once
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Carton
{
private:
	string tittle[5];
	string coloum1[5], coloum2[5], coloum3[5], coloum4[5], coloum5[5];
	int col[5]; //para crear los numeros aleatorios de cada columna


public:
	//ctor
	Carton() {
		tittle[0] = "B", tittle[1] = "I", tittle[2] = "N", tittle[3] = "G", tittle[4] = "O";
		col[0] = 0, col[1] = 0, col[2] = 0, col[3] = 0, col[4] = 0;		

	}
	//dtor
	~Carton() {

	}
	void limpiar() {
		col[0] = 0, col[1] = 0, col[2] = 0, col[3] = 0, col[4] = 0;
	}

	//Creación del cartón
	void randomC1(int i) {
		srand(time(NULL));
		int num = 0;
		bool comp = false;
		if (i < 5) {
			genera:
			num = 1 + rand() % 15; 
			if (!comprueba(0, num)) {
				goto genera;
			}
			coloum1[i]= "" + col[i];
			i++;
			randomC1(i);
		}
		else {
			limpiar();
			return;
		}
	}
	void randomC2(int i) {
		srand(time(NULL));
		int num = 0;
		bool comp = false;
		if (i < 5) {
		genera:
			num = 16 + rand() % 30;
			if (!comprueba(0, num)) {
				goto genera;
			}
			coloum2[i] = "" + col[i];
			i++;
			randomC2(i);
		}
		else {
			limpiar();
			return;
		}
	}
	void randomC3(int i) {
		srand(time(NULL));
		int num = 0;
		bool comp = false;
		if (i < 5) {
		genera:
			num = 31 + rand() % 45;
			if (!comprueba(0, num)) {
				goto genera;
			}
			coloum3[i] = "" + col[i];
			i++;
			randomC3(i);
		}
		else {
			limpiar();
			return;
		}
	}
	void randomC4(int i) {
		srand(time(NULL));
		int num = 0;
		bool comp = false;
		if (i < 5) {
		genera:
			num = 46 + rand() % 60;
			if (!comprueba(0, num)) {
				goto genera;
			}
			coloum4[i] = "" + col[i];
			i++;
			randomC4(i);
		}
		else {
			limpiar();
			return;
		}
	}
	void randomC5(int i) {
		srand(time(NULL));
		int num = 0;
		bool comp = false;
		if (i < 5) {
		genera:
			num = 61 + rand() % 75;
			if (!comprueba(0, num)) {
				goto genera;
			}
			coloum5[i] = "" + col[i];
			i++;
			randomC5(i);
		}
		else {
			limpiar();
			return;
		}
	}

	bool comprueba(int i, int num) {
		if (num == col[i]) {
			return true;
		}
		else {
			i++;
			comprueba(i, num);
		}
		return false;
	}

	//methods
	void llenaCarton() {
		randomC1(0); //0 es el parámetro inicial de la recursividad
		randomC2(0);
		randomC3(0);
		randomC4(0);
		randomC5(0);
	}

};

