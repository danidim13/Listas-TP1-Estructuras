#ifndef __PILA_LSE_H__
#define __PILA_LSE_H__

template <typename E>
class NodoSimplePila{
	public:
		E elemento;
		NodoSimplePila *sig;
};

template <typename E>
class Pila{
	public:
		typedef NodoSimplePila<E> node_t;
		typedef NodoSimplePila<E>* pos_t;

		Pila():tope(nullptr),num_elem(0){};
		~Pila();

		void Vaciar(){
			pos_t it = tope;
			pos_t tmp = tope;
			while (it != nullptr) {
				tmp = it;
				it = it->sig;
				delete tmp;
			}
			tope = nullptr;
			num_elem = 0;
		};

		bool Vacia(){
			return num_elem == 0;
		}

		void Meter(E elem){
			pos_t tmp = new node_t;
			tmp->elemento = elem;
			tmp->sig = tope;
			tope = tmp;
			num_elem++;
		}

		void Sacar(){
			pos_t tmp = tope;
			tope = tope->sig;
			delete tmp;
			num_elem--;
		}

		E Tope(){
			return tope->elemento;
		}

		int NumElem(){
			return num_elem;
		}

	private:
		pos_t tope;
		int num_elem;

};

#endif
