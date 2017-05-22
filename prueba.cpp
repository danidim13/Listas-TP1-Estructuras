#include <iostream>
#include <limits>
#include <string>
#include <sstream>
//#include "include/ListaPlantilla.h"
//#include "include/ListaPos_Arreglo.h"
#include "include/Pila_LSE.h"

using namespace std;


int main(int argc, char *argv[]) {


	Pila<string> P;
	P.Meter("uno");
	P.Meter("dos");
	P.Meter("tres");
	P.Meter("cuatro");
	P.Imprimir();

	cout << "Sacando un elemento" << endl;
	P.Sacar();
	P.Imprimir();
	
	cout << "El tope es " << P.Tope() << endl;



	/*
	ListaPos<int> L;

	cout << L.NumElem() << endl;
	L.AgregarAlFinal(5);
	L.Insertar(L.Ultima(), -1);
	L.Insertar(L.Ultima(), 10);
	L.Insertar(L.Primera(), 69);
	L.Insertar(L.Primera(), 7);
	cout << L.NumElem() << endl;

	cout << "Recorrido desde el primero" << endl;
	ListaPos<int>::pos_t pos = L.Primera();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Siguiente(pos);
	}
	cout << endl;
	
	cout << "Recorrido desde el ultimo" << endl;
	pos = L.Ultima();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Anterior(pos);
	}
	cout << endl;
	cout << endl;

	cout << "Agregando un elemento en el medio de la lista" << endl;
	pos = L.Siguiente(L.Siguiente(L.Primera()));
	L.Insertar(pos, 666);
	cout << L.NumElem() << endl;

	cout << "Recorrido desde el primero" << endl;
	pos = L.Primera();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Siguiente(pos);
	}
	cout << endl;
	
	cout << "Recorrido desde el ultimo" << endl;
	pos = L.Ultima();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Anterior(pos);
	}
	cout << endl;
	cout << endl;

	cout << "Ahora borramos una posicion..." << endl;

	pos = L.Primera();
	pos = L.Siguiente(L.Siguiente(pos));
	//pos = L.Ultima();
	cout << "Borrando " << L.Recuperar(pos) << endl;
	cout << endl;
	L.Borrar(pos);
	cout << L.NumElem() << endl;


	cout << "Recorrido desde el primero" << endl;
	pos = L.Primera();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Siguiente(pos);
	}
	cout << endl;
	
	cout << "Recorrido desde el ultimo" << endl;
	pos = L.Ultima();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Anterior(pos);
	}
	cout << endl;
	*/

	return 0;
}



