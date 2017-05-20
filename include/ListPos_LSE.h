#ifndef __ListaSimple_H__
#define __ListaSimple_H__
#include "ListaPlantilla.h"


template <typename E>
class NodoSimple: public Nodo<E>{
	public:
		NodoSimple* sig;
};


/*! Clase que implementa el modelo Lista Posicionada
 * mediante una lista simplemente enlazada.
 * El tipo de elemento se define mediante un template.
 */
template <typename E>
class ListaPos: public ListaPosPlantilla<E> {
	/* XXX Ojo XXX:
	 * La implementación hereda de la clase abstracta
	 */
	public:
		typedef NodoSimple<E> node_t;
		typedef NodoSimple<E>* der_pos_t;
		typedef Nodo<E>* pos_t;

		/*! Constructor por defecto.
		 */
		ListaPos():primera(nullptr), ultima(nullptr), num_elem(0){};

		/*! Destructor por defecto.
		 */
		virtual ~ListaPos(){
			Vaciar();
		};

		//ListaSimple& operator=(const ListaSimple<E> rhs);
		//ListaSimple(const ListaSimple &other);
		
		bool Vacia() override {
			return num_elem == 0;
		};

		void Vaciar() override {
			der_pos_t it = primera;
			der_pos_t tmp;
			while (it != nullptr) {
				tmp = it;
				it = it->sig;
				delete tmp;
			}
			num_elem = 0;
			primera = nullptr;
			ultima = nullptr;
		};

		der_pos_t Primera() override {
			return primera;
		};

		der_pos_t Ultima() override {
			return ultima;
		};

		der_pos_t Siguiente(pos_t p) override {
			return ((der_pos_t) p)->sig;
		};

		der_pos_t Anterior(pos_t p) override {
			der_pos_t it = primera;
			while (it != nullptr) {
				if (it->sig == p)
					break;
				it = it->sig;
			}
			return it;
		};

		E Recuperar(pos_t p) override {
			return p->elemento;
		};

		void Insertar(pos_t p, E elem) override {
			// Caso especial primera
			der_pos_t p_aux = (der_pos_t)p;
			if (p_aux == primera) {
				der_pos_t tmp = new node_t;

				tmp->sig = p_aux;
				tmp->elemento = elem;

				primera = tmp;
			} else {
				der_pos_t tmp = new node_t;
				tmp->sig = p_aux->sig;
				tmp->elemento = p_aux->elemento;

				p_aux->sig = tmp;
				p_aux->elemento = elem;

				if (p_aux == ultima)
					ultima = tmp;
			}
			num_elem++;
		};

		void AgregarAlFinal(E elem) override {

			// Si la lista está vacia
			if (num_elem == 0) {
				primera = new node_t;
				primera->sig = nullptr;
				primera->elemento = elem;
				ultima = primera;
			} else {
				der_pos_t tmp = new node_t;
				tmp->sig = nullptr;
				tmp->elemento = elem;

				ultima->sig = tmp;
				ultima = tmp;
			}
			num_elem++;
		};

		void Borrar(pos_t p) override {
			// Caso especial, lista con unico elemento
			if (num_elem == 1){
				primera = nullptr;
				ultima = nullptr;
				delete p;
			} else {

				if (p == ultima) {
					// Caso especial, ultima
					der_pos_t aux_anterior = Anterior(p);
					aux_anterior->sig = nullptr;
					ultima = aux_anterior;
					delete p;
				} else if (p == primera) {
					//Caso especial, primera
					primera = primera->sig;
					delete p;
				} else {
					der_pos_t aux_siguiente = Siguiente(p);
					p->elemento = aux_siguiente->elemento;
					((der_pos_t) p)->sig = aux_siguiente->sig;
					if (aux_siguiente == ultima)
						ultima = (der_pos_t)p;
					delete aux_siguiente;
				}
			}
			num_elem--;
		};

		void ModificarElem(pos_t p, E elem) override {
			p->elemento = elem;
		};

		void Intercambiar(pos_t p1, pos_t p2) override {
			E tmp = p1->elemento;
			p1->elemento = p2->elemento;
			p2->elemento = tmp;
		};

		int NumElem() override {
			return num_elem;
		};

	private:
		der_pos_t primera;
		der_pos_t ultima;
		int num_elem;

};

#endif
