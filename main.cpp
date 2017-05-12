#include <iostream>
#include <string>
#include "ListaPlantilla.h"
#include "ListaDoble.h"

using namespace std;

int main(int argc, char *argv[]) {

	cout << "Hello World!" << endl;

	ListaPos<int> L;

	cout << L.NumElem() << endl;
	L.AgregarUltimo(5);
	L.AgregarUltimo(-1);
	L.AgregarUltimo(10);
	L.AgregarUltimo(69);
	L.AgregarUltimo(7);
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
