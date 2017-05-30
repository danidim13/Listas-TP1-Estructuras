#include <iostream>
#include <limits>
#include <string>
#include <sstream>

//#include "include/ListaPlantilla.h"

#include "include/Listas_LDE.h"
#warning "Usando implementacion con LDE!"
//#include "include/Listas_LSE.h"
//#warning "Usando implementacion con LSE!"
//#include "include/Listas_Arreglo.h"
//#warning "Usando implementacion con arreglo!"


#include "Algoritmos.h"

using namespace std;

template <typename E>
void Imprimir(ListaPos<E> L) {
	cout << "Recorrido desde el primero" << endl;
	typename ListaPos<E>::pos_t pos = L.Primera();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Siguiente(pos);
	}
	cout << endl;
}

template <typename E>
void ImprimirReversa(ListaPos<E> L) {
	cout << "Recorrido desde el ultimo" << endl;
	typename ListaPos<E>::pos_t pos = L.Ultima();
	while (pos) {
		cout << L.Recuperar(pos) << " ";
		pos = L.Anterior(pos);
	}
	cout << endl;
}

int main(int argc, char *argv[]) {


	/*
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


	*/


	/*
	cout << "Agregando un elemento en el medio de la lista" << endl;
	pos = L.Siguiente(L.Siguiente(L.Primera()));
	L.Insertar(pos, 666);
	cout << L.NumElem() << endl;

	Imprimir(L);
	ImprimirReversa(L);
	
	cout << endl;

	cout << "Ahora borramos una posicion..." << endl;

	pos = L.Primera();
	pos = L.Siguiente(L.Siguiente(pos));
	//pos = L.Ultima();
	cout << "Borrando " << L.Recuperar(pos) << endl;
	cout << endl;
	L.Borrar(pos);
	cout << L.NumElem() << endl;

	Imprimir(L);
	ImprimirReversa(L);
	cout << endl;

	*/

	ListaPos<int> L;
	ListaPos<int>::pos_t pos;

	L.AgregarAlFinal(1);
	L.AgregarAlFinal(4);
	L.AgregarAlFinal(6);
	L.AgregarAlFinal(5);
	L.AgregarAlFinal(6);
	L.AgregarAlFinal(5);
	L.AgregarAlFinal(6);
	L.AgregarAlFinal(7);
	L.AgregarAlFinal(3);
	L.AgregarAlFinal(2);
	L.AgregarAlFinal(5);

	/*
	L.Insertar(L.Ultima(), -1);
	L.Insertar(L.Ultima(), 10);
	L.Insertar(L.Primera(), 69);
	L.Insertar(L.Primera(), 7);
	cout << L.NumElem() << endl;
	*/

	cout << "L es:" << endl;
	Imprimir(L);
	ImprimirReversa(L);
	cout << endl;
	ListaPos<int> L2;
	ListaPos<int> L3;

	//L3.AgregarAlFinal(6);
	L3.AgregarAlFinal(5);
	L3.AgregarAlFinal(6);
	L3.AgregarAlFinal(7);

	cout << "Probando algoritmo Invertir" << endl;
	L2 = Invertir(L);
	Imprimir(L);
	Imprimir(L2);

	cout << "Probando algoritmo Sublista" << endl;
	Imprimir(L);
	Imprimir(L3);
	cout << Sublista(L, L3) << endl;

	L2.Vaciar();
	L2.AgregarAlFinal(50);
	L2.AgregarAlFinal(30);
	L2.AgregarAlFinal(15);
	L2.AgregarAlFinal(-3);
	L2.AgregarAlFinal(22);
	L2.AgregarAlFinal(-1);
	L2.AgregarAlFinal(9);
	/*
	cout << "Probando algoritmo Burbuja Doble" << endl;
	Imprimir(L2);
	BurbujaDoble(L2);
	Imprimir(L2);
	*/

	cout << "Probando algoritmo Selección con Pila manual" << endl;
	Imprimir(L2);
	SeleccionPila(L2);
	Imprimir(L2);

	cout << endl;

	cout << "Probando Union"  << endl;
	cout << "L1:" << endl;
	Imprimir(L2);

	cout << "L2:" << endl;
	Imprimir(L3);

	UnionDesord(L2, L3);
	cout << "L1:" << endl;
	Imprimir(L2);
	
	cout << endl;
	cout << "Probando Eliminar"  << endl;
	SeleccionPila(L2);
	SeleccionPila(L3);
	cout << "L1:" << endl;
	Imprimir(L2);

	cout << "L2:" << endl;
	Imprimir(L3);

	Eliminar(L2, L3);
	cout << "L1:" << endl;
	Imprimir(L2);
	/*
	cout << "Construyendo copias" << endl;
	cout << "L1:" << endl;
	Imprimir(L);
	cout << endl;

	cout << "L2:" << endl;
	Imprimir(L2);
	cout << endl;

	cout << "L3:" << endl;
	Imprimir(L3);
	cout << endl;

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Some stuff happened :S xdxd" << endl;
	pos = L2.Primera();
	L2.Borrar(pos);

	pos = L3.Primera();
	pos = L3.Siguiente(pos);
	L3.Intercambiar(pos, L3.Ultima());

	cout << "L1:" << endl;
	Imprimir(L);
	cout << endl;

	cout << "L2:" << endl;
	Imprimir(L2);
	cout << endl;

	cout << "L3:" << endl;
	Imprimir(L3);
	cout << endl;

	cout << "L1:" << endl;
	ImprimirReversa(L);
	cout << endl;

	cout << "L2:" << endl;
	ImprimirReversa(L2);
	cout << endl;

	cout << "L3:" << endl;
	ImprimirReversa(L3);
	cout << endl;
	*/

	return 0;
}



