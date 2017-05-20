#ifndef LISTAINDEXARREGLO_H
#define LISTAINDEXARREGLO_H
#include <cstdlib>
#include <iostream>
using namespace std;
/*! Clase que implementa el modelo Lista Indexada
 * mediante un arreglo de elementos.
 */
template <typename E>
class ListaIndexArreglo
{
public:
    int num_elem;
    typedef E node_t;
    typedef int pos_t;

    /*! Constructor por defecto.
     */
    ListaIndexArreglo():array(new node_t[30]), max_elem(30), num_elem(0) {};
    ListaIndexArreglo(size_t m):array(new node_t[m]), max_elem(m), num_elem(0) {};

    /*! Destructor por defecto.
     */
    virtual ~ListaIndexArreglo()
    {
        delete[] array;
    };

    void Destruir()
    {
        delete[] array;
    }
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
        array[p-1] = elem;
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

};

#endif // LISTAINDEXARREGLO_H
