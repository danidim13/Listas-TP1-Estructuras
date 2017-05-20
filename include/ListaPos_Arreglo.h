#ifndef __ListaArray_H__
#define __ListaArray_H__
#include <cstdlib>

/*! Clase que implementa el modelo Lista Posicionada
 * mediante un arreglo de elementos.
 * El tipo de elemento se define mediante un template.
 */
template <typename E>
class ListaPos{
	public:
		typedef E node_t;
		typedef int pos_t;
		typedef int der_pos_t;

		/*! Constructor por defecto.
		 */
		ListaPos():array(new node_t[30]), max_elem(30), num_elem(0){};
		ListaPos(size_t m):array(new node_t[m]), max_elem(m), num_elem(0){};

		/*! Destructor por defecto.
		 */
		virtual ~ListaPos(){
			delete[] array;
		};

		//ListaSimple& operator=(const ListaSimple<E> rhs);
		//ListaSimple(const ListaSimple &other);
		
		bool Vacia(){
			return num_elem == 0;
		};

		void Vaciar(){
			num_elem = 0;
		};

		pos_t Primera(){
			if (num_elem)
				return 1;
			else
				return 0;
		};

		pos_t Ultima(){
			return num_elem;
		};

		pos_t Siguiente(pos_t p){
			if (p != num_elem)
				return p + 1;
			else
				return 0;
		};

		pos_t Anterior(pos_t p){
			if (p > 1)
				return p - 1;
			else
				return 0;
		};

		E Recuperar(pos_t p){
			return array[p-1];
		};

		void Insertar(pos_t p, E elem){
			pos_t inicio = p-1;
			E tmp_act = elem;
			E tmp_sig;
			for (int i = inicio; i < num_elem; i++) {
				tmp_sig = array[i];
				array[i] = tmp_act;
				tmp_act = tmp_sig;
			}
			array[num_elem] = tmp_act;
			num_elem++;
		};

		void AgregarAlFinal(E elem){
			array[num_elem] = elem;
			num_elem++;
		};

		void Borrar(pos_t p){
			pos_t inicio = p-1;
			for (int i = inicio; i < num_elem-1; i++) {
				array[i] = array[i+1];
			}
			num_elem--;
		};

		void ModificarElem(pos_t p, E elem){
			array[p-1] = elem;
		};

		void Intercambiar(pos_t p1, pos_t p2){
			E tmp = array[p1-1];
			array[p1-1] = array[p2-1];
			array[p2-1] = tmp;
		};

		int NumElem(){
			return num_elem;
		};

	private:
		node_t* array;
		size_t max_elem;
		int num_elem;

};

#endif
