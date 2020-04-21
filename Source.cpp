#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

#include <string>

using namespace std;


int modulo(int num, int d) {
	int c, r;
	c = num / d;
	r = num - (c * d);
	if (r < 0) {
		c -= 1;
		r = r + d;
	}
	return r;
}

int euclides(int num, int d) {
	int r = 1;

	while (r > 0) {
		r = modulo(num, d);
		num = d;
		d = r;
	}
	return num;
}

vector <int> euclideanExtended(int a, int b) {
	int d, x, y;
	vector <int> dataRes;
	if (b == 0) {
		d = a;
		x = 1;
		y = 0;
		dataRes.push_back(d);
		dataRes.push_back(x);
		dataRes.push_back(y);
		return dataRes;
	}

	int x2 = 1, x1 = 0, y2 = 0, y1 = 1, q, r;

	while (b > 0) {
		q = a / b;
		r = a - (q * b);
		x = x2 - (q * x1);
		y = y2 - (q * y1);
		a = b;
		b = r;
		x2 = x1;
		x1 = x;
		y2 = y1;
		y1 = y;
	}
	d = a;
	x = x2;
	y = y2;
	dataRes.push_back(d);
	dataRes.push_back(x);
	dataRes.push_back(y);

	return dataRes;
}

int inverse(int a, int b) {
	int result = euclideanExtended(a, b)[1];
	if (euclideanExtended(a, b)[1] < 0) {
		result = modulo(euclideanExtended(a, b)[1], b);
	}
	return result;
}

class Afin {
	Afin();
	string cifrado(string mensaje, int multiplicacion, int desplazamiento);
	string descifrado(string mensaje, int multiplicacion, int desplazamiento);

};

Afin::Afin() {
	int xyz = 0;
}

string Afin::cifrado(string mensaje, int multiplicacion, int desplazamiento) {
	string cifrado;
	int size = mensaje.size();   // C = a x m + b    mod n
	for (int i = 0; i < size; i++) {
		int pos = abc.find(mensaje[i]);
		pos = pos * multiplicacion + desplazamiento;
		if (pos > abc_size)
			pos = modulo(pos, abc_size);
		cifrado += abc[pos];
	}

class Afin {
	Afin();
	string cifrado(string mensaje, int multiplicacion, int desplazamiento);
	string descifrado(string mensaje, int multiplicacion, int desplazamiento);

};

Afin::Afin() {
	int xyz = 0;
}

string Afin::cifrado(string mensaje, int multiplicacion, int desplazamiento) {
	string cifrado;
	int size = mensaje.size();   // C = a x m + b    mod n
	for (int i = 0; i < size; i++) {
		int pos = abc.find(mensaje[i]);
		pos = pos * multiplicacion + desplazamiento;
		if (pos > abc_size)
			pos = modulo(pos, abc_size);
		cifrado += abc[pos];
	}
	return cifrado;
}

string Afin::descifrado(string mensaje, int multiplicacion, int desplazamiento) {
	string descifrado;
	int size = mensaje.size();

	if (euclides(multiplicacion, size) != 1) {
		descifrado = "NO SE PUDO DESCIFRAR EL MENSAJE";
		return descifrado;
	}

	int inversa = (multiplicacion, abc_size);

	for (int i = 0; i < size; i++) {
		int pos = abc.find(mensaje[i]);
		pos -= desplazamiento;
		pos *= inversa;
		if (pos < 0)
			pos = modulo(pos, abc_size);
		descifrado += abc[pos];
	}
	return descifrado;
}


//string abc = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
string abc = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
//string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int abc_size = abc.size();

int main() {

	Afin emisor();
	Afin receptor();

	string mensaje = "The MEgraph application used to display this network combines techniques such as topological range searching and motion highlighting to enable interactive exploration of complex network diagrams";
	int mul = 2, aux = 3;


	cout << mensaje << endl << endl;

	mensaje = emisor.cifrado(mensaje, mul, aux);
	cout << mensaje << endl << endl;
	mensaje = receptor.descifrado(mensaje, mul, aux);
	cout << mensaje << endl << endl;

	return 0;
}
