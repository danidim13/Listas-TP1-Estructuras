#ifndef __LISTAPOS_LDE_H__
#define __LISTAPOS_LDE_H__
#include "ListaPlantilla.h"


template <typename E>
class NodoDoble: public Nodo<E>{
	public:
		NodoDoble* ant;
		NodoDoble* sig;
};


/*! Clase que implementa el modelo Lista Posicionada
 * mediante una lista doblemente enlazada.
 * El tipo de elemento se define mediante un template.
 */
template <typename E>
class ListaPos: public ListaPosPlantilla<E> {
	/* XXX Ojo XXX:
	 * La implementación hereda de la clase abstracta
	 */
	public:
		typedef NodoDoble<E> node_t;
		typedef NodoDoble<E>* der_pos_t;
		typedef Nodo<E>* pos_t;

		/*! Constructor por defecto.
		 */
		ListaPos():primera(nullptr), ultima(nullptr), num_elem(0){};

		/*! Destructor por defecto.
		 */
		virtual ~ListaPos(){
			Vaciar();
		};

		//ListaDoble& operator=(const ListaDoble<E> rhs);
		//ListaDoble(const ListaDoble &other);
		
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
	;		return ((der_pos_t) p)->ant;
		};
		E Recuperar(pos_t p) override {
			return p->elemento;
		};

		void Insertar(pos_t p, E elem) override {
			// Caso especial primera
			der_pos_t p_aux = (der_pos_t)p;
			if (p_aux == primera) {
				der_pos_t tmp = new node_t;

				tmp->ant = nullptr;
				tmp->sig = p_aux;
				tmp->elemento = elem;

				p_aux->ant = tmp;
				primera = tmp;
			} else {
				der_pos_t tmp = new node_t;

				tmp->ant = p_aux->ant;
				tmp->sig = p_aux;
				tmp->elemento = elem;

				(p_aux->ant)->sig = tmp;
				p_aux->ant = tmp;
			}
			num_elem++;
		};

		void AgregarAlFinal(E elem) override {

			// Si la lista está vacia
			if (num_elem == 0) {
				primera = new node_t;
				primera->ant = nullptr;
				primera->sig = nullptr;
				primera->elemento = elem;
				ultima = primera;
			} else {
				der_pos_t tmp = new node_t;

				tmp->ant = ultima;
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
			} else {

				der_pos_t aux_siguiente = Siguiente(p);
				der_pos_t aux_anterior = Anterior(p);

				if (p == primera) {
					//Caso especial, primera
					aux_siguiente->ant = nullptr;
					primera = aux_siguiente;
				} else if (p == ultima) {
					// Caso especial, ultima
					aux_anterior->sig = nullptr;
					ultima = aux_anterior;
				} else {
					aux_anterior->sig = aux_siguiente;
					aux_siguiente->ant = aux_anterior;
				}
			}
			delete p;
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
