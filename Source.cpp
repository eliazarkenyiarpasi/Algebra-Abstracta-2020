#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Cesar {
private:
	int clave;
public:
	Cesar() {
		clave = 3;
	}
	
	string alfabeto = {"abcdefghijklmnopqrstuvwxyz"};
	string cif;
	string descif;
	int tam_alf = alfabeto.length();

	string cifrado(string mensaje) {

		int tam = mensaje.length();
		for (int i = 0; i < tam; i++) {
			int pos = alfabeto.find(mensaje[i]);
			if (pos > 23) {
				cif += alfabeto[pos + clave - tam_alf];
			}
			else {
				cif += alfabeto[pos + clave];
			}
		}
		return cif;
	}
	string descifrado(string mensaje_cifrado) {

		int tam = mensaje_cifrado.length();
		for (int i = 0; i < tam; i++) {
			int pos = alfabeto.find(mensaje_cifrado[i]);
			if (pos > 23) {
				descif += alfabeto[pos + tam_alf - clave];
			}
			else {
				descif += alfabeto[pos - clave];
			}
		}
		return descif;

	}
	

};



int main() {
	
	Cesar emisor;
	Cesar receptor;

	string mensaje;
	cin >> mensaje;

	string mensaje_cifrado = emisor.cifrado(mensaje);
	cout << "mensaje_cifrado: " << mensaje_cifrado << endl;
	
	string mensaje_descifrado = receptor.descifrado(mensaje_cifrado);
	cout << "mensaje descifrado: " << mensaje_descifrado << endl;
	
	return 0;

}