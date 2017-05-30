#include "../include/Algoritmos.h"
#include <iostream>

template <typename E>
ListaPos<E> Invertir(ListaPos<E> L){
	ListaPos<E> inv;
	typename ListaPos<E>::pos_t p1;
	
	p1 = L.Ultima();
	while (p1) {
		inv.AgregarAlFinal(L.Recuperar(p1));
		p1 = L.Anterior(p1);
	}
	return inv;
};

template <typename E>
bool Sublista(ListaPos<E> L1, ListaPos<E> L2){
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

	Pila<typename ListaPos<E>::pos_t> stack;
	stack.Meter(L.Primera());

	while (!stack.Vacia()) {

		typename ListaPos<E>::pos_t pos_ini = stack.Tope();

		if (!pos_ini) {
			stack.Sacar();
		} else {
			typename ListaPos<E>::pos_t pos_min, it;
			pos_min = pos_ini;
			for (it = pos_ini; it; it = L.Siguiente(it)) {
				if (L.Recuperar(it) < L.Recuperar(pos_min)) {
					pos_min = it;
				}
			}
			L.Intercambiar(pos_ini,pos_min);
			stack.Sacar();
			stack.Meter(L.Siguiente(pos_ini));
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
void Imprimir(ListaPos<E> L) {
	std::cout << "Recorrido desde el primero" << std::endl;
	typename ListaPos<E>::pos_t pos = L.Primera();
	while (pos) {
		std::cout << L.Recuperar(pos) << " ";
		pos = L.Siguiente(pos);
	}
	std::cout << std::endl;
}

template ListaPos<int> Invertir<int>(ListaPos<int> L);
template bool Sublista<int>(ListaPos<int> L1, ListaPos<int> L2);
template void BurbujaDoble<int>(ListaPos<int> &L1);
template void Imprimir<int>(ListaPos<int> L);
template void SeleccionPila<int>(ListaPos<int> &L);
template void UnionDesord<int>(ListaPos<int> &L1, ListaPos<int> &L2);
template void Eliminar<int>(ListaPos<int> &L1, ListaPos<int> &L2);
