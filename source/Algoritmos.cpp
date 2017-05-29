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
	
