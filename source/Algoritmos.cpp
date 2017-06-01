#include "../include/Algoritmos.h"
#include <iostream>

/************************************/
/*** Algoritmos Lista Posicionada ***/
/************************************/

template <typename E>
void Invertir(ListaPos<E> &L){
	//ListaPos<E> inv;
	typename ListaPos<E>::pos_t p1, p2;
	
	p1 = L.Primera();
	p2 = L.Ultima();
	for (int i = 0; i < L.NumElem()/2 ; i++) {
		L.Intercambiar(p1,p2);
		p1 = L.Siguiente(p1);
		p2 = L.Anterior(p2);
	}
};

template <typename E>
bool Sublista(ListaPos<E> &L1, ListaPos<E> &L2){
	typename ListaPos<E>::pos_t p1, p2, p1_aux;
	
	p1 = L1.Primera();
	while (p1) {

		p2 = L2.Primera();

		if (L1.Recuperar(p1) == L2.Recuperar(p2)){
			bool matching = true;
			p1_aux = p1;
			while (matching) {
				if (!p2){
					break;
				} else if (!p1_aux){
					matching = false;
				} else if (L1.Recuperar(p1_aux) != L2.Recuperar(p2)) {
					matching = false;
				}
				p1_aux = L1.Siguiente(p1_aux);
				p2 = L2.Siguiente(p2);
			}
			if (matching) {
				return true;
			}
		}
				
		p1 = L1.Siguiente(p1);
	}
	return false;
}

template <typename E>
void BurbujaDoble(ListaPos<E> &L1){

	typename ListaPos<E>::pos_t it, sig;
	it = L1.Primera();
	sig = L1.Siguiente(it);
	
	int pasada = 1;
	//FIXME
	//El algoritmo se está saliendo de los limites
	//de la lista
	//std::cout << std::endl;
	//std::cout << "Iniciando Burbuja doble" << std::endl;
	//Imprimir(L1);
	while (L1.NumElem() - (2*pasada) >= 0 ){

		//std::cout << "Pasada " << pasada << std::endl;

		// Pasada ascendente
		bool swap = false;
		for (int i = 0; i < L1.NumElem() - (2*pasada); i++) {
			if (L1.Recuperar(it) > L1.Recuperar(sig)) {
				L1.Intercambiar(it, sig);
				swap = true;
			}
			it = L1.Siguiente(it);
			sig = L1.Siguiente(it);
		}
		if (L1.Recuperar(it) > L1.Recuperar(sig)) {
			L1.Intercambiar(it, sig);
			swap = true;
		}
		//Imprimir(L1);
		if (!swap)
			break;

		// Pasada descendente
		swap = false;
		for (int i = 0; i < L1.NumElem() - (2*pasada); i++) {
			it = L1.Anterior(it);
			sig = L1.Siguiente(it);
			if (L1.Recuperar(it) > L1.Recuperar(sig)) {
				L1.Intercambiar(it, sig);
				swap = true;
			}
		}
		//Imprimir(L1);
		if (!swap)
			break;
		pasada++;
		it = L1.Siguiente(it);
		sig = L1.Siguiente(it);
	}
}

template <typename E>
void SeleccionPila(ListaPos<E> &L){

	struct StackFrame {
		typename ListaPos<E>::pos_t pos_ini;
		bool sorted;
	};

	Pila<StackFrame> stack;

	StackFrame f;
	f.pos_ini = L.Primera();
	f.sorted = false;

	stack.Meter(f);

	while (!stack.Vacia()) {
		// f contiene la informacion de variables
		// locales a cada llamado recursivo.
		f = stack.Tope();
		stack.Sacar();

		if (!f.pos_ini) {
			// Condicion de parada: no hay mas elementos
			// return -> no se vuelve a guardar el frame local
			continue;
		} else {
			if (!f.sorted) {
				typename ListaPos<E>::pos_t pos_min, it;
				pos_min = f.pos_ini;
				for (it = f.pos_ini; it; it = L.Siguiente(it)) {
					if (L.Recuperar(it) < L.Recuperar(pos_min)) {
						pos_min = it;
					}
				}
				L.Intercambiar(f.pos_ini,pos_min);

				f.sorted = true;
				stack.Meter(f);
				// Se guardan las variable locales

				StackFrame nextCall;
				nextCall.pos_ini = L.Siguiente(f.pos_ini);
				nextCall.sorted = false;
				stack.Meter(nextCall);
				// Nuevo llamado a la funcion;
			}
			else {
				// return
				continue;
			}
		}
	}
}


template <typename E>
void UnionDesord(ListaPos<E> &L1, ListaPos<E> &L2){
	typename ListaPos<E>::pos_t it1, it2;

	it2 = L2.Primera();
	bool repetido;
	while (it2) {
		repetido = false;
		it1 = L1.Primera();
		while (it1) {
			if (L1.Recuperar(it1) == L2.Recuperar(it2)){
				repetido = true;
				break;
			}
			it1 = L1.Siguiente(it1);
		}
		if (!repetido) {
			L1.AgregarAlFinal(L2.Recuperar(it2));
		}
		it2 = L2.Siguiente(it2);
	}

}

template <typename E>
void Eliminar(ListaPos<E> &L1, ListaPos<E> &L2){
	typename ListaPos<E>::pos_t it1, it2, tmp;

	// Se itera empezando por el ultimo elemento
	// porque el operador Borrar invalida cualquier
	// variable pos_t que apuntaba a un elemento
	// posterior al que se borró.
	it1 = L1.Ultima();
	it2 = L2.Ultima();

	while (it1 && it2) {
		if (L1.Recuperar(it1) > L2.Recuperar(it2)){
			it1 = L1.Anterior(it1);
		} else if (L1.Recuperar(it1) < L2.Recuperar(it2)) {
			it2 = L2.Anterior(it2);
		} else {
			tmp = it1;
			it1 = L1.Anterior(it1);
			L1.Borrar(tmp);
			it2 = L2.Anterior(it2);
		}

	}
}

template <typename E>
void Imprimir(ListaPos<E> &L) {
	//std::cout << "Recorrido desde el primero" << std::endl;
	typename ListaPos<E>::pos_t pos = L.Primera();
	while (pos) {
		std::cout << L.Recuperar(pos) << " ";
		pos = L.Siguiente(pos);
	}
	std::cout << std::endl;
}

/***************************************/
/*** Algoritmos de la lista indexada ***/
/***************************************/

template <typename E>
void Invertir(ListaIndex<E> &L) {

	int p1 = 1;
	int p2 = L.NumElem();
	for (int i = 0; i < L.NumElem()/2; i++) {
		L.Intercambiar(p1, p2);
		p1++;
		p2--;
	}
}
template <typename E>
bool Sublista(ListaIndex<E> &L1, ListaIndex<E> &L2) {
	int p1, p2, p1_aux;
	
	if (L2.NumElem() == 0)
		return true;

	for (p1 = 1; p1 <= L1.NumElem(); p1++) {

		p2 = 1;
		if (L1.Recuperar(p1) == L2.Recuperar(p2)) {
			bool matching = true;
			p1_aux = p1;
			while (matching) {
				if (p2 > L2.NumElem()) {
					break;
				} else if (p1_aux > L1.NumElem()) {
					matching = false;
				} else if (L1.Recuperar(p1_aux) != L2.Recuperar(p2)) {
					matching = false;
				}
				p1_aux++;
				p2++;
			}
			if (matching) {
				return true;
			}
		}
	}
	return false;
}

template <typename E>
void BurbujaDoble(ListaIndex<E> &L1){

	int it = 1;
	
	int pasada = 1;
	//std::cout << std::endl;
	//std::cout << "Iniciando Burbuja doble" << std::endl;
	//Imprimir(L1);
	while (L1.NumElem() - (2*pasada) >= 0 ){

		//std::cout << "Pasada " << pasada << std::endl;

		// Pasada ascendente
		bool swap = false;
		for (int i = 0; i < L1.NumElem() - (2*pasada); i++) {
			if (L1.Recuperar(it) > L1.Recuperar(it+1)) {
				L1.Intercambiar(it, it+1);
				swap = true;
			}
			it++;
		}
		if (L1.Recuperar(it) > L1.Recuperar(it+1)) {
			L1.Intercambiar(it, it+1);
			swap = true;
		}
		//Imprimir(L1);
		if (!swap)
			break;

		// Pasada descendente
		swap = false;
		for (int i = 0; i < L1.NumElem() - (2*pasada); i++) {
			it--;
			if (L1.Recuperar(it) > L1.Recuperar(it+1)) {
				L1.Intercambiar(it, it+1);
				swap = true;
			}
		}
		//Imprimir(L1);
		if (!swap)
			break;
		pasada++;
		it++;
	}
}

template <typename E>
void Imprimir(ListaIndex<E> &L){
	for (int i = 1; i <= L.NumElem(); i++) {
		cout << L.Recuperar(i) << " ";
	}
	cout << endl;
}

template <typename E>
void SeleccionPila(ListaIndex<E> &L){

	struct StackFrame {
		int pos_ini;
		bool sorted;
	};

	Pila<StackFrame> stack;

	StackFrame f;
	f.pos_ini = 1;
	f.sorted = false;

	stack.Meter(f);

	while (!stack.Vacia()) {
		// f contiene la informacion de variables
		// locales a cada llamado recursivo.
		f = stack.Tope();
		stack.Sacar();

		if (f.pos_ini > L.NumElem()) {
			// Condicion de parada: no hay mas elementos
			// return -> no se vuelve a guardar el frame local
			//cout << "TOP" << endl;
			continue;
		} else {
			if (!f.sorted) {
				//cout << "hola! " << f.pos_ini << endl;

				int pos_min, it;
				pos_min = f.pos_ini;
				for (it = f.pos_ini; it <= L.NumElem(); it++) {
					if (L.Recuperar(it) < L.Recuperar(pos_min)) {
						pos_min = it;
					}
				}
				L.Intercambiar(f.pos_ini,pos_min);

				f.sorted = true;
				stack.Meter(f);
				// Se guardan las variable locales

				StackFrame nextCall;
				nextCall.pos_ini = f.pos_ini+1;
				nextCall.sorted = false;
				stack.Meter(nextCall);
				// Nuevo llamado a la funcion;
			}
			else {
				//cout << "adios! " << f.pos_ini << endl;
				// return -> No se vuelve a guardar el frame
				// local, fin del llamado.
				continue;
			}
		}
	}
}

/***************************/
/*** Instancias ListaPos ***/
/***************************/
template void Invertir<int>(ListaPos<int> &L);
template void Invertir<char>(ListaPos<char> &L);
template bool Sublista<int>(ListaPos<int> &L1, ListaPos<int> &L2);
template void BurbujaDoble<int>(ListaPos<int> &L1);
template void Imprimir<int>(ListaPos<int> &L);
template void SeleccionPila<int>(ListaPos<int> &L);
template void UnionDesord<int>(ListaPos<int> &L1, ListaPos<int> &L2);
template void Eliminar<int>(ListaPos<int> &L1, ListaPos<int> &L2);


/*****************************/
/*** Instancias ListaIndex ***/
/*****************************/
template void Invertir<int>(ListaIndex<int> &L);
template void Invertir<char>(ListaIndex<char> &L);
template bool Sublista<int>(ListaIndex<int> &L1, ListaIndex<int> &L2);
template void BurbujaDoble<int>(ListaIndex<int> &L1);
template void Imprimir<int>(ListaIndex<int> &L);
template void SeleccionPila<int>(ListaIndex<int> &L);
