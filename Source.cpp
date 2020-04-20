#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Vigenere {
public:
	string cif;
	string descif;
	string alf = {"abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	int tam_alf = alf.length();
	string clave;
	int tam_clave;
	int num_al;
	int pos_m;
	int pos_c;
	int pos_f;

	Vigenere() {/*
		int tam_clave = 5;
		num_al=
		for (int i = 0; i < tam_clave; i++) {
			clave += alf[num_al];
		}

		//clave = "abcde";*/
	}
	string cifrado(string msj) {
		int tam = msj.length();
		
		for (int i = 0; i < tam; i++) {

		}

		for (int i = 0; i < tam; i++) {
			pos_m = alf.find(msj[i]);
			pos_c = alf.find(clave[i]);
			pos_f = (pos_m + pos_c) % tam_alf;
			cif += alf[pos_f];
		}

		return cif;
	}
	string descif(string msj_cif) {

		return descif;
	}
};



int main() {
	
	string mensaje;
	cin >> mensaje;
	Vigenere emisor;
	emisor.cifrado(mensaje);

	return 0;
}