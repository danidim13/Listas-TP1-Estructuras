#include <iostream>
#include <string>
#include "include/ListaPlantilla.h"
#include "include/ListaDoble.h"

using namespace std;

int main(int argc, char *argv[]) {

	cout << "Hello World!" << endl;

	ListaPos<int> L;

	cout << L.NumElem() << endl;
	L.AgregarAlFinal(5);
	L.AgregarAlFinal(-1);
	L.AgregarAlFinal(10);
	L.AgregarAlFinal(69);
	L.AgregarAlFinal(7);
	cout << L.NumElem() << endl;

	cout << "Recorrido desde el primero" << endl;
	Nodo<int>* pos = L.Primera();
	while (pos != nullptr) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Siguiente(pos);
	}
	cout << endl;
	
	cout << "Recorrido desde el ultimo" << endl;
	pos = L.Ultima();
	while (pos != nullptr) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Anterior(pos);
	}
	cout << endl;
	cout << endl;

	cout << "Ahora borramos una posicion..." << endl;

	//pos = L.Primera();
	//pos = L.Siguiente(L.Siguiente(pos));
	pos = L.Ultima();
	cout << "Borrando " << L.Recuperar(pos) << endl;
	cout << endl;
	L.Borrar(pos);
	cout << L.NumElem() << endl;


	cout << "Recorrido desde el primero" << endl;
	pos = L.Primera();
	while (pos != nullptr) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Siguiente(pos);
	}
	cout << endl;
	
	cout << "Recorrido desde el ultimo" << endl;
	pos = L.Ultima();
	while (pos != nullptr) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Anterior(pos);
	}
	cout << endl;
	return 0;
}
