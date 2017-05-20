#ifndef __ListaPlantilla_H__
#define __ListaPlantilla_H__

template <typename E>
class Nodo{
	public:
		Nodo(){};
		virtual ~Nodo(){};
		E elemento;
};

template <typename E>
class ListaPosPlantilla{
	public:
		
		// XXX
		// Tipo base para el nodo, en la implementacion
		// se puede usar un nuevo tipo que herede de
		// la clase Nodo<E> pero *solo para el return type*!
		// Para los parametros de los metodos tiene que 
		// ser este tipo, sino no compila!
		typedef Nodo<E>* pos_t;
		// XXX

		/*! \brief Indica si la Lista se encuentra vacía.
		 * @return Valor booleano.
		 */
		virtual bool Vacia() = 0;

		/*! \brief Elimina todos los elementos de la lista.
		 */
		virtual void Vaciar() = 0;

		/*! \brief Retorna la posición del primer elemento.
		 * @return Variable tipo \c pos_t.
		 */
		virtual pos_t Primera() = 0;

		/*! \brief Retorna la posición del último elemento.
		 * @return Variable tipo \c pos_t.
		 */
		virtual pos_t Ultima() = 0;

		/*! \brief Retorna la posición siguiente.
		 * @param p Una posición dentro de la lista.
		 * @return Una variable tipo \c pos_t.
		 */
		virtual pos_t Siguiente(pos_t p) = 0;

		/*! \brief Retorna la posición anterior.
		 * @param p Una posición dentro de la lista.
		 * @return Una variable tipo \c pos_t.
		 */
		virtual pos_t Anterior(pos_t p) = 0;

		/*! \brief Retorna el elemento de una posición.
		 * @param p Una posición dentro de la lista.
		 * @return Una variable tipo \c E.
		 */
		virtual E Recuperar(pos_t p) = 0;

		/*! \brief Inserta un elemento en la lista.
		 * El elemento \p elem se inserta antes de la
		 * posición \p p.
		 * @param p Una posición dentro de la lista.
		 * @param elem El elemento a insertar.
		 */
		virtual void Insertar(pos_t p, E elem) = 0;

		/*! \brief Agrega un elemento al final de la lista.
		 * @param elem El elemento a insertar.
		 */
		virtual void AgregarAlFinal(E elem) = 0;

		/*! \brief Elimina un elemento de la lista.
		 * Se elimina el elemento que se encuentra
		 * en la posición \p p.
		 * @param p Una posición dentro de la lista.
		 */
		virtual void Borrar(pos_t p) = 0;

		/*! \brief Modifica el elemento en una posición.
		 * @param p La posición del elemento que se quiere modificar.
		 * @param elem El nuevo elemento que se va a guardar en \p p.
		 */
		virtual void ModificarElem(pos_t p, E elem) = 0;


		/*! \brief Intercambia dos posiciones de la lista.
		 * @param p1,p2 Las posiciones a intercambiar en la lista.
		 */
		virtual void Intercambiar(Nodo<E>* p1, Nodo<E>* p2) = 0;

		/*! \brief Retorna el número de elementos de la lista.
		 * @return Una variable de tipo entero.
		 */
		virtual int NumElem() = 0;
};

template <typename E>
class ListaIndexPlantilla{
	public:
		
		/*! \brief Indica si la Lista se encuentra vacía.
		 * @return Valor booleano.
		 */
		virtual bool Vacia() = 0;

		/*! \brief Elimina todos los elementos de la lista.
		 */
		virtual void Vaciar() = 0;

		/*! \brief Retorna el elemento en un índice.
		 * @param i Un índice dentro de la lista.
		 * @return Una variable tipo \c E.
		 */
		virtual E Recuperar(int i) = 0;

		/*! \brief Inserta un elemento en la lista.
		 * El elemento \p elem se inserta en el
		 * índice \p i.
		 * @param i Un índice dentro de la lista.
		 * @param elem El elemento a insertar.
		 */
		virtual void Insertar(int i, E elem) = 0;

		/*! \brief Elimina un elemento de la lista.
		 * Se elimina el elemento que se encuentra
		 * en el índice \p i.
		 * @param i Un índice dentro de la lista.
		 */
		virtual void Borrar(int i) = 0;

		/*! \brief Modifica el elemento en un índice.
		 * @param i El índice del elemento que se quiere modificar.
		 * @param elem El nuevo elemento que se va a guardar en \p i.
		 */
		virtual void ModificarElem(int i, E elem) = 0;


		/*! \brief Intercambia dos elementos de la lista.
		 * @param p1,p2 Los índices de los elementos a
		 * intercambiar en la lista.
		 */
		virtual void Intercambiar(int i1, int i2) = 0;

		/*! \brief Retorna el número de elementos de la lista.
		 * @return Una variable de tipo entero.
		 */
		virtual int NumElem() = 0;
};

template <typename E>
class ListaOrdPlantilla{
	public:
		
		/*! \brief Indica si la Lista se encuentra vacía.
		 * @return Valor booleano.
		 */
		virtual bool Vacia() = 0;

		/*! \brief Elimina todos los elementos de la lista.
		 */
		virtual void Vaciar() = 0;

		/*! \brief Retorna el primer elemento.
		 * @return Variable tipo \c E.
		 */
		virtual E Primero() = 0;

		/*! \brief Retorna el último elemento.
		 * @return Variable tipo \c E.
		 */
		virtual E Ultimo() = 0;

		/*! \brief Retorna el elemento siguiente.
		 * @param elem Un elemento dentro de la lista.
		 * @return Una variable tipo \c E.
		 */
		virtual E Siguiente(E elem) = 0;

		/*! \brief Retorna el elemento anterior.
		 * @param elem Un elemento dentro de la lista.
		 * @return Una variable tipo \c E.
		 */
		virtual E Anterior(E elem) = 0;

		/*! \brief Inserta un elemento en la lista.
		 * El elemento \p elem se inserta en orden
		 * ascendente. Si ya existe en la lista
		 * no hace nada.
		 * @param elem El elemento a insertar.
		 */
		virtual void Insertar(E elem) = 0;

		/*! \brief Elimina un elemento de la lista.
		 * Si el elemento no existe en la lista
		 * no hace nada.
		 * @param e El elemento a eliminar
		 */
		virtual void Borrar(E elem) = 0;

		/*! \brief Retorna el número de elementos de la lista.
		 * @return Una variable de tipo entero.
		 */
		virtual int NumElem() = 0;
};

#endif
