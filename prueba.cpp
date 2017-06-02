#include <iostream>
#include <limits>
#include <string>
#include <sstream>

//#include "include/ListaPlantilla.h"

//#include "include/Listas_LDE.h"
//#warning "Usando implementacion con LDE!"
#include "include/Listas_LSE.h"
#warning "Usando implementacion con LSE!"
//#include "include/Listas_Arreglo.h"
//#warning "Usando implementacion con arreglo!"


#include "Algoritmos.h"

using namespace std;

/*
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
*/

/*
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
*/

int main(int argc, char *argv[]) {

	/*********************************/
	/*** Pruebas Lista Posicionada ***/
	/*********************************/

	/*** Pruebas constructor por copia ***/

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

	/******************************/
	/*** Pruebas lista indexada ***/
	/******************************/

	/*
	ListaIndex<char> Li;
	cout << "Lista indexada" << endl;
	Li.Insertar(Li.NumElem()+1,'b');
	Li.Insertar(Li.NumElem()+1,'c');
	Li.Insertar(Li.NumElem()+1,'d');
	Li.Insertar(Li.NumElem()+1,'e');
	Li.Insertar(1,'a');
	Li.Insertar(Li.NumElem()+1,'f');
	Li.Insertar(Li.NumElem()+1,'g');
	Li.Insertar(Li.NumElem()+1,'h');
	Li.Imprimir();
	cout << Li.NumElem() << endl;
	cout << endl;

	for (int i = 1; i <= Li.NumElem(); i++) {
		cout << "Elemento " << i << " " << Li.Recuperar(i) << endl;
	}

	int i = 2;
	cout << "Moficando elemento " << i << " " << Li.Recuperar(i) << endl;
	Li.ModificarElem(i,'O');
	Li.Imprimir();
	cout << Li.NumElem() << endl;
	

	int j = Li.NumElem();
	i = 1;
	cout << "Intercambiando " << Li.Recuperar(i) << " y " << Li.Recuperar(j) << endl;
	Li.Intercambiar(i, j);
	Li.Imprimir();

	Li.Insertar(2, 'x');
	Li.Borrar(5);
	Li.Imprimir();
	cout << Li.NumElem() << endl << endl;

	Li.Borrar(1);
	Li.Imprimir();
	cout << Li.NumElem() << endl << endl;

	for (int i = 0; i < 3; i++) {
		Li.Borrar(Li.NumElem());
		Li.Imprimir();
		cout << Li.NumElem() << endl << endl;
	}

	for (int i = 0 ; i < 2; i++) {
		Li.Insertar(Li.NumElem()+1,'z' - i);
		Li.Imprimir();
		cout << Li.NumElem() << endl << endl;
	}
	*/

	/********************************/
	/**** Pruebas Lista Ordenada ****/
	/********************************/

	/*
	ListaOrdenada<int> L, L2, L3;

	//cout << "Intento borrar elemento en lista vacia" << endl;
	//L.Borrar(999);

	cout << "Insertando elementos" << endl;
	L.Insertar(-5);
	L.Insertar(5);
	L.Insertar(22);
	L.Insertar(3);
	L.Insertar(9);
	L.Insertar(11);
	L.Imprimir();
	cout << L.NumElem() << " elementos" << endl;
	cout << endl;

	cout << "Tratando de insertar elementos repetidos" << endl;
	L.Insertar(11);
	L.Insertar(5);
	L.Imprimir();
	cout << L.NumElem() << " elementos" << endl;
	cout << endl;


	cout << "Borrando elementos 5, -5, 22 (en ese orden)" << endl;
	L.Borrar(5);
	L.Imprimir();
	cout << L.NumElem() << endl;
	cout << endl;
	L.Borrar(-5);
	L.Imprimir();
	cout << L.NumElem() << endl;
	cout << endl;
	L.Borrar(22);
	L.Imprimir();
	cout << L.NumElem() << endl;
	cout << endl;

	cout << "Agregando elementos -1, 30, 2, 29 (en ese orden)" << endl;
	L.Insertar(-1);
	L.Imprimir();
	L.Insertar(30);
	L.Imprimir();
	L.Insertar(2);
	L.Imprimir();
	L.Insertar(29);
	L.Imprimir();
	cout << L.NumElem() << " elementos" << endl;
	cout << endl;
	*/

	/**********************/
	/**** Pruebas Pila ****/
	/**********************/

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



	/********************************************/
	/*** Pruebas Algoritmos Lista Posicionada ***/
	/********************************************/

	/*
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

	L.Insertar(L.Ultima(), -1);
	L.Insertar(L.Ultima(), 10);
	L.Insertar(L.Primera(), 69);
	L.Insertar(L.Primera(), 7);
	cout << L.NumElem() << endl;

	ListaPos<int> L2;
	L2.Vaciar();
	L2.AgregarAlFinal(50);
	L2.AgregarAlFinal(30);
	L2.AgregarAlFinal(15);
	L2.AgregarAlFinal(-3);
	L2.AgregarAlFinal(22);
	L2.AgregarAlFinal(-1);
	L2.AgregarAlFinal(9);

	ListaPos<int> L3;
	L3.AgregarAlFinal(6);
	L3.AgregarAlFinal(5);
	L3.AgregarAlFinal(6);
	L3.AgregarAlFinal(7);


	cout << "Probando algoritmo Invertir" << endl;
	cout << "L:" << endl;
	Imprimir(L);
	Invertir(L);
	Imprimir(L);
	cout << endl;

	cout << "Probando algoritmo Burbuja Doble" << endl;
	cout << "L:" << endl;
	Imprimir(L2);
	BurbujaDoble(L2);
	Imprimir(L2);
	cout << endl;


	cout << "Probando algoritmo Selección con Pila manual" << endl;
	cout << "L:" << endl;
	Imprimir(L2);
	SeleccionPila(L2);
	Imprimir(L2);
	cout << endl;


	cout << "Probando Union para listas desordenadas"  << endl;
	cout << "L1:" << endl;
	Imprimir(L2);
	cout << "L2:" << endl;
	Imprimir(L3);
	UnionDesord(L2, L3);
	cout << "L1 U L2:" << endl;
	Imprimir(L2);
	cout << endl;
	
	cout << "Probando Eliminar para listas ordenadas"  << endl;
	SeleccionPila(L2);
	SeleccionPila(L3);
	cout << "L1:" << endl;
	Imprimir(L2);
	cout << "L2:" << endl;
	Imprimir(L3);
	Eliminar(L2, L3);
	cout << "L1 - L2:" << endl;
	Imprimir(L2);
	cout << endl;
	*/

	/*****************************************/
	/*** Pruebas Algoritmos Lista Indexada ***/
	/*****************************************/

	/*
	ListaIndex<int> L;
	cout << "Lista indexada" << endl;
	L.Insertar(L.NumElem()+1,4);
	L.Insertar(L.NumElem()+1,6);
	L.Insertar(L.NumElem()+1,5);
	L.Insertar(L.NumElem()+1,6);
	L.Insertar(1,1);
	L.Insertar(L.NumElem()+1,7);
	L.Insertar(L.NumElem()+1,3);
	L.Insertar(L.NumElem()+1,2);
	Imprimir(L);
	cout << L.NumElem() << endl;
	cout << endl;



	ListaIndex<int> L2;

	L2.Insertar(L2.NumElem()+1,6);
	L2.Insertar(L2.NumElem()+1,5);
	L2.Insertar(L2.NumElem()+1,6);

	cout << "Probando algoritmo Invertir" << endl;
	cout << "L es:" << endl;
	Imprimir(L);
	Invertir(L);
	cout << "Invertida" << endl;
	Imprimir(L);
	cout << endl;

	cout << "Probando algoritmo Sublista" << endl;
	cout << "L1 es:" << endl;
	Imprimir(L);
	cout << "L2 es:" << endl;
	Imprimir(L2);
	cout << "Es sublista? " << (bool)Sublista(L, L2) << endl;
	cout << endl;

	cout << "Probando algoritmo Burbuja Doble" << endl;
	cout << "L es:" << endl;
	Imprimir(L);
	BurbujaDoble(L);
	cout << "Ordenada:" << endl;
	Imprimir(L);
	cout << endl;

	cout << "Probando algoritmo Seleccion con Pila" << endl;
	cout << "L es:" << endl;
	Imprimir(L);
	SeleccionPila(L);
	cout << "Ordenada:" << endl;
	Imprimir(L);
	cout << endl;
	*/

	/*****************************************/
	/*** Pruebas Algoritmos Lista Ordenada ***/
	/*****************************************/

	ListaOrdenada<int> L, L2, L3;

	L.Insertar(-5);
	L.Insertar(5);
	L.Insertar(22);
	L.Insertar(3);
	L.Insertar(9);
	L.Insertar(11);
	L.Imprimir();
	cout << L.NumElem() << endl;
	cout << endl;

	L2.Insertar(-7);
	L2.Insertar(2);
	L2.Insertar(69);
	L2.Insertar(3);
	L2.Insertar(11);
	L2.Insertar(1);
	L2.Imprimir();
	cout << L.NumElem() << endl;
	cout << endl;


	/*
	cout << "Probando algoritmo Copiar" << endl;
	cout << "L1:" << endl;
	L.Imprimir();
	cout << "L2:" << endl;
	L2.Imprimir();
	Copiar(L, L2);
	cout << "Copia de L1 en L2" << endl;
	L2.Imprimir();
	*/


	cout << "Probando algoritmo Eliminar" << endl;
	cout << "L1:" << endl;
	L.Imprimir();
	cout << "L2:" << endl;
	L2.Imprimir();
	Eliminar(L, L2);
	cout << "L1 - L2: " << endl;
	L.Imprimir();
	return 0;
}



