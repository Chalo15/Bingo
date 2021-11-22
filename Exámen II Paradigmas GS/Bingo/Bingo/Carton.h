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
	int num = 0;
	bool comp = false;


public:
	//ctor
	Carton() {
		tittle[0] = "B", tittle[1] = "I", tittle[2] = "N", tittle[3] = "G", tittle[4] = "O";
		col[0] = 0, col[1] = 0, col[2] = 0, col[3] = 0, col[4] = 0;
		srand(time(NULL));

	}
	//dtor
	~Carton() {

	}
	void limpiar() {
		col[0] = 0, col[1] = 0, col[2] = 0, col[3] = 0, col[4] = 0;
	}

	//Creación del cartón
	void randomC1(int i) {
		if (i < 5) {
		genera:
			num = 0;
			num = rand() % (15 - 1 + 1) + 1;
			comp = comprueba(0, num);
			if (comp == true) {
				goto genera;
			}
			string n = "";
			stringstream x;			
			col[i] = num;
			x << col[i];
			n = x.str();
			coloum1[i]= n;
			i++;
			randomC1(i);
		}
		else {
			limpiar();
			return;
		}
	}
	void randomC2(int i) {
		if (i < 5) {
		genera:
			num = 0;
			num = rand() % (30 - 16 + 1) + 16;
			comp = comprueba(0, num);
			if (comp == true) {
				goto genera;
			}
			string n = "";
			stringstream x;
			col[i] = num;
			x << col[i];
			n = x.str();
			coloum2[i] = n;
			i++;
			randomC2(i);
		}
		else {
			limpiar();
			return;
		}
	}
	void randomC3(int i) {
		if (i < 5) {
		genera:
			num = 0;
			num = rand() % (45 - 31 + 1) + 31;
			comp = comprueba(0, num);
			if (comp == true) {
				goto genera;
			}
			string n = "";
			stringstream x;
			col[i] = num;
			x << col[i];
			n = x.str();
			coloum3[i] = n;
			i++;
			randomC3(i);
		}
		else {
			limpiar();
			return;
		}
	}
	void randomC4(int i) {
		if (i < 5) {
		genera:
			num = 0;
			num = rand() % (60 - 46 + 1) + 46;
			comp = comprueba(0, num);
			if (comp == true) {
				goto genera;
			}
			string n = "";
			stringstream x;
			col[i] = num;
			x << col[i];
			n = x.str();
			coloum4[i] = n;
			i++;
			randomC4(i);
		}
		else {
			limpiar();
			return;
		}
	}
	void randomC5(int i) {
		if (i < 5) {
		genera:
			num = 0;
			num = rand() % (75 - 61 + 1) + 61;
			comp = comprueba(0, num);
			if (comp == true) {
				goto genera;
			}
			string n = "";
			stringstream x;
			col[i] = num;
			x << col[i];
			n = x.str();
			coloum5[i] = n;
			i++;
			randomC5(i);
		}
		else {
			limpiar();
			return;
		}
	}

	bool comprueba(int i, int num) {
		bool prueba = false;
		if (i < 5) {
			if (col[i] == num) {
				return true;
			}
			else {
				i++;
				prueba = comprueba(i, num);
			}
		}
		return prueba;
	}

	void printfTittle(int i) {
		if (i < 5) {
			cout << "	" << tittle[i] << " ";
			i++;
			printfTittle(i);
		}
		else {
			return;
		}
	}
	void printfColoums(int i) {
		if (i < 5) {
			cout << "\t" << coloum1[i] << "\t" << coloum2[i] << "\t" << coloum3[i] << "\t" << coloum4[i] << "\t" << coloum5[i] << "\t" << endl<<endl;
			i++;
			printfColoums(i);
		}
		else {
			return;
		}
	}

	//methods
	void llenaCarton() {
		randomC1(0); //0 es el parámetro inicial de la recursividad
		randomC2(0);
		randomC3(0);
		coloum3[2] = "X";
		randomC4(0);
		randomC5(0);
	}
	void muestraCarton() {
		cout << endl;
		printfTittle(0);
		cout << endl<<endl;
		printfColoums(0);
	}

	//Validaciones de victorias
	bool compruebaDiagIzq() {
		if (coloum1[0] == "X") {
			if (coloum2[1] == "X") {
				if (coloum3[2] == "X") {
					if (coloum4[3] == "X") {
						if (coloum5[4] == "X") {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool compruebaDiagDer() {
		if (coloum5[0] == "X") {
			if (coloum4[1] == "X") {
				if (coloum3[2] == "X") {
					if (coloum2[3] == "X") {
						if (coloum1[4] == "X") {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool compruebaHorizontal1() {
		if (coloum1[0] == "X") {
			if (coloum2[0] == "X") {
				if (coloum3[0] == "X") {
					if (coloum4[0] == "X") {
						if (coloum5[0] == "X") {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool compruebaHorizontal2() {
		if (coloum1[1] == "X") {
			if (coloum2[1] == "X") {
				if (coloum3[1] == "X") {
					if (coloum4[1] == "X") {
						if (coloum5[1] == "X") {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool compruebaHorizontal3() {
		if (coloum1[2] == "X") {
			if (coloum2[2] == "X") {
				if (coloum3[2] == "X") {
					if (coloum4[2] == "X") {
						if (coloum5[2] == "X") {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool compruebaHorizontal4() {
		if (coloum1[3] == "X") {
			if (coloum2[3] == "X") {
				if (coloum3[3] == "X") {
					if (coloum4[3] == "X") {
						if (coloum5[3] == "X") {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool compruebaHorizontal5() {
		if (coloum1[4] == "X") {
			if (coloum2[4] == "X") {
				if (coloum3[4] == "X") {
					if (coloum4[4] == "X") {
						if (coloum5[4] == "X") {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool compruebaVertical1() {
		if (coloum1[0] == "X") {
			if (coloum1[1] == "X") {
				if (coloum1[2] == "X") {
					if (coloum1[3] == "X") {
						if (coloum1[4] == "X") {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool compruebaVertical2() {
		if (coloum2[0] == "X") {
			if (coloum2[1] == "X") {
				if (coloum2[2] == "X") {
					if (coloum2[3] == "X") {
						if (coloum2[4] == "X") {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool compruebaVertical3() {
		if (coloum3[0] == "X") {
			if (coloum3[1] == "X") {
				if (coloum3[2] == "X") {
					if (coloum3[3] == "X") {
						if (coloum3[4] == "X") {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool compruebaVertical4() {
		if (coloum4[0] == "X") {
			if (coloum4[1] == "X") {
				if (coloum4[2] == "X") {
					if (coloum4[3] == "X") {
						if (coloum4[4] == "X") {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool compruebaVertical5() {
		if (coloum5[0] == "X") {
			if (coloum5[1] == "X") {
				if (coloum5[2] == "X") {
					if (coloum5[3] == "X") {
						if (coloum5[4] == "X") {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	bool compruebaEsquinas() {
		if (coloum1[0] == "X" && coloum1[4] == "X") {
			if (coloum5[0] == "X" && coloum5[4] == "X") {
				return true;
			}
		}
		return false;
	}
};

