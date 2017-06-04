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


/*! Funcion auxiliar para Quicksort
 */
template <typename E>
typename ListaPos<E>::pos_t __Partition(ListaPos<E> &L, typename ListaPos<E>::pos_t p, typename ListaPos<E>::pos_t u, E pivot){

	typename ListaPos<E>::pos_t lo, hi;
	lo = p;
	hi = u;

	bool menores = true;
	while (lo != hi) {
		if (menores) {
			if (L.Recuperar(lo) > pivot) {
				L.Intercambiar(lo, hi);
				menores = false;
			} else {
				lo = L.Siguiente(lo);
			}
		} else {
			if (L.Recuperar(hi) < pivot) {
				L.Intercambiar(hi, lo);
				menores = true;
			} else {
				hi = L.Anterior(hi);
			}
		}
	}
	return menores ? lo : hi;
}

/*! Funcion recursiva para quicksort
 * Ordena recursivamente la Sublista desde la posicion
 * p (primera) hasta u (ultima).
 */
template <typename E>
void __Quicksort(ListaPos<E> &L, typename ListaPos<E>::pos_t p, typename ListaPos<E>::pos_t u){

	// Se elige el ultimo elemento de la sublista como
	// el pivot.
	E pivot = L.Recuperar(u);
	typename ListaPos<E>::pos_t q, next_p, next_u;

	// q es la posicion final del pivot
	q = __Partition(L, p, u, pivot);

	// Luego se deben ordenar sublistas L[p : q-1] y L[q+1 : u]

	// next_u es q-1
	next_u = L.Anterior(q);

	// next_p es q+1
	next_p = L.Siguiente(q);

	if (!(p == q || p == next_u)) {
		__Quicksort(L, p, next_u);
	}
	if (!(u == q || u == next_p)) {
		__Quicksort(L, next_p, u);
	}
}

template <typename E>
void Quicksort(ListaPos<E> &L){
	if (!L.Vacia())
		__Quicksort(L, L.Primera(), L.Ultima());
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

/*! Funcion auxiliar para Quicksort
 */
template <typename E>
int __Partition(ListaIndex<E> &L, int p, int u, E pivot){

	int lo = p;
	int hi = u;


	// Indica si se itera sobre los elementos menores al
	// pivot o los mayores 
	bool menores = true;
	while (lo < hi) {
		if (menores) {
			// hi apunta al pivot, mientras que lo itera sobre
			// los elementos que deberian ser menores al pivot

			if (L.Recuperar(lo) > pivot) {
				// Si se encuentra un elemento mayor al pivot
				// se intercambian de posicion.
				L.Intercambiar(lo, hi);
				menores = false;
			} else {
				lo++;
			}
		} else {
			// lo apunta al pivot mientras que hi itera
			// sobre los elementos que deberian ser mayores
			if (L.Recuperar(hi) < pivot) {
				L.Intercambiar(hi, lo);
				menores = true;
			} else {
				hi--;
			}
		}
		// El loop acaba cuando los indices se encuentran
	}
	return menores ? hi : lo;
}

/*! Funcion recursiva para Quicksort.
 * Ordena la sublista L[p:u] mediante el algoritmo quicksort
 * p es el primer indice y u el ultimo.
 */
template <typename E>
void __Quicksort(ListaIndex<E> &L, int p, int u){

	// Condicion de parada
	if (p >= u)
		return;

	// Siempre elegimos el elemento más a la derecha
	// de pivot.
	E pivot = L.Recuperar(u);

	// El algoritmo Partition acomoda la sublista tal que
	// todos los elementos queden en su posicion correcta
	// respecto al pivot (menores a la izquierda, mayores
	// a la derecha).
	
	//cout << "Particionando L con pivot " << pivot;
	//cout << " desde " << p << " hasta " << u << endl;

	//cout << "Antes: " << endl;
	//L.Imprimir();
	int q = __Partition(L, p, u, pivot);
	// q es la posicion final del pivot,  en este punto
	// este elemento ya se encuentra en su posicion correcta
	//cout << "Despues: " << endl;
	//L.Imprimir();
	//cout << endl; 

	// Se llama recursivamente a quicksort sobre los elementos
	// a ambos lados del pivot.
	__Quicksort(L, p, q-1);
	__Quicksort(L, q+1, u);
}
template <typename E>
void Quicksort(ListaIndex<E> &L){
	__Quicksort(L, 1, L.NumElem());
}

/***************************************/
/*** Algoritmos de la lista ordenada ***/
/***************************************/

template <typename E>
void Copiar(ListaOrdenada<E> &L1, ListaOrdenada<E> &L2){
	L2.Vaciar();
	if (L1.NumElem() == 0) {
		return;
	}

	E elem_actual = L1.Primero();
	while (true) {
		L2.Insertar(elem_actual);
		if (elem_actual == L1.Ultimo()) {
			break;
		} else {
			elem_actual = L1.Siguiente(elem_actual);
		}
	}
}

template <typename E>
void Eliminar(ListaOrdenada<E> &L1, ListaOrdenada<E> &L2){

	if (L1.Vacia() || L2.Vacia())
		return;

	E elem2 = L2.Primero();
	E max_elem1 = L1.Ultimo();
	while (true) {
		//cout << "elem = " << elem2 << endl;
		L1.Borrar(elem2);
		if (elem2 == L2.Ultimo() || L1.Vacia() || elem2 >= max_elem1) {
			break;
		} else {
			elem2 = L2.Siguiente(elem2);
		}
	}
}

template <typename E>
void Interseccion1(ListaOrdenada<E> &L1, ListaOrdenada<E> &L2, ListaOrdenada<E> &L3){

	L3.Vaciar();
	if (L1.Vacia() || L2.Vacia())
		return;

	E elem1, elem2, ult1, ult2;

	elem1 = L1.Primero();
	ult1 = L1.Ultimo();

	elem2 = L2.Primero();
	ult2 = L2.Ultimo();

	while (true) {
		if (elem1 == elem2) {
			L3.Insertar(elem1);
			if (elem1 == ult1 || elem2 == ult2) {
				break;
			} else {
				elem1 = L1.Siguiente(elem1);
				elem2 = L2.Siguiente(elem2);
			}
		} else if (elem1 < elem2) {
			if (elem1 == ult1) {
				break;
			} else {
				elem1 = L1.Siguiente(elem1);
			}
		} else if (elem1 > elem2) {
			if (elem2 == ult2) {
				break;
			} else {
				elem2 = L2.Siguiente(elem2);
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
template void Quicksort<int>(ListaPos<int> &L);
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
template void Quicksort<int>(ListaIndex<int> &L);

/********************************/
/*** Instancias ListaOrdenada ***/
/********************************/
template void Copiar<int>(ListaOrdenada<int> &L1, ListaOrdenada<int> &L2);
template void Eliminar<int>(ListaOrdenada<int> &L1, ListaOrdenada<int> &L2);
template void Interseccion1<int>(ListaOrdenada<int> &L1, ListaOrdenada<int> &L2, ListaOrdenada<int> &L3);
