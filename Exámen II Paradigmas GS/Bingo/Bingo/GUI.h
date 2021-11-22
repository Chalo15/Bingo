#pragma once
#include "Jugador.h"
#include <list>
#include <iterator>
#include <bits/stdc++.h>
#include <ctime>
#include <random>
#include <limits>
#include <stdlib.h>
#include <time.h>

class GUI
{
private:
	int opcion = 0, cantJugadores = 0;
	Jugador ply;
	Jugador ply2;
	list <Jugador> players;
	list <Jugador>::iterator player;
	int cc = 0;
	int num = 0;
	int numeros[75];
	string numbers[75];
	int num1 = 0;


public:
	//ctor //dtor
	GUI() {
		llenaVec(0);
		LLenaNumeros(0);
		shuffle_vec(numeros, 75);
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

	void registraJugadores() {
		cout << "Jugador " << 1 <<endl;
		ply.requestName();
		cout << endl;
		cout << "Jugador " << 2 << endl;
		ply2.requestName();
		cout << endl;

		
	}
	/*void randomNumber(int i) {
		if (i < 75) {
			bool compr = false;
		genera:
			num = 0;
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
			randomNumber(i);
		}
		else {
			return;
		}
	}
	bool compruebaSerie(int i, int num) {
		bool prueba1 = false; 
		if (i < 75) {
			if (num == numeros[i]) {
				return true;
			}
			else {
				i++;
				prueba1= compruebaSerie(i, num);
			}
		}
		return prueba1;
	}*/
	void LLenaNumeros(int i) {
		if (i < 75) {
			numeros[i] = i+1;
			i++;
			LLenaNumeros(i);
		}
		else {
			return;
		}
	}
	void shuffle_vec(int arr[], int n) {
		unsigned seed = 0;
		shuffle(arr, arr + n,
			default_random_engine (seed));
	}
	void verVector(int i) {
		if (i < 75) {
			cout << numeros[i] << " ";
			i++;
			verVector(i);
		}
		else {
			return;
		}
	};
	void delay(int secs) {
		for (int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
	}
};

