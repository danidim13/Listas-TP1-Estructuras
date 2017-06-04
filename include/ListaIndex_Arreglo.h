#ifndef LISTAINDEX_ARREGLO_H
#define LISTAINDEX_ARREGLO_H
#include <cstdlib>
#include <iostream>
using namespace std;
/*! Clase que implementa el modelo Lista Indexada
 * mediante un arreglo de elementos.
 */
template <typename E>
class ListaIndex
{
public:
    typedef E node_t;
    typedef int pos_t;

    /*! Constructor por defecto.
     */
    ListaIndex():array(new node_t[256]), max_elem(256), num_elem(0) {};
    ListaIndex(size_t m):array(new node_t[m]), max_elem(m), num_elem(0) {};

    /*! Destructor por defecto.
     */
    virtual ~ListaIndex()
    {
        delete[] array;
    };

	/*
    void Destruir()
    {
        delete[] array;
    }
	*/
    bool Vacia()
    {
        return num_elem == 0;
    };

    void Imprimir()
    {
        cout << "Recorrido desde el primero" << endl;
        pos_t pos = 1;
        while (pos<=num_elem)
        {
            cout << Recuperar(pos) << " ";
            pos++;
        }
        cout << endl;
    }
    void Vaciar()
    {
        num_elem = 0;
    };

    void Insertar(int p, E elem)
    {
		int inicio = p-1;
		E tmp_act = elem;
		E tmp_sig;
		for (int i = p-1; i < num_elem; i++) {
			tmp_sig = array[i];
			array[i] = tmp_act;
			tmp_act = tmp_sig;

		}
		array[num_elem] = tmp_act;
        num_elem++;
    };

    void Borrar(int p)
    {
        pos_t inicio = p-1;
        for (int i = inicio; i < num_elem-1; i++)
        {
            array[i] = array[i+1];
        }
        num_elem--;
    };

    E Recuperar(int p)
    {
        return array[p-1];
    };

    void ModificarElem(int p, E elem)
    {
        array[p-1] = elem;
    };

    void Intercambiar(int p1, int p2)
    {
        E tmp = array[p1-1];
        array[p1-1] = array[p2-1];
        array[p2-1] = tmp;
    };

    int NumElem()
    {
        return num_elem;
    };

protected:

private:
    node_t* array;
    size_t max_elem;
	int num_elem;
};

#endif // LISTAINDEXARREGLO_H
