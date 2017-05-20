#ifndef LISTAORDENADA_ARRAY_H
#define LISTAORDENADA_ARRAY_H
#include <cstdlib>
#include <iostream>
using namespace std;

/* Clase que implementa el modelo Lista Ordenada
 * mediante un arreglo de elementos.
 * El tipo de elemento se define mediante un template.
 */

template <typename E>
class ListaOrdenada
{
public:
    typedef E node_t;

    void Imprimir()
    {
        for (int i = 0; i < num_elem; i++)
        {
            cout<< array[i]<<endl;
        }
        cout<<endl;
    }

    /*! Constructor por defecto.
     */
    ListaOrdenada():array(new node_t[30]), max_elem(30), num_elem(0) {};
    ListaOrdenada(size_t m):array(new node_t[m]), max_elem(m), num_elem(0) {};

    /*! Destructor por defecto.
     */
    virtual ~ListaOrdenada()
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


    void Vaciar()
    {
        num_elem = 0;
    };

    void Insertar(E elem)
    {

        if(num_elem == 0)
        {
            array[0] = elem;
            num_elem++;
        }
        else
        {
            bool repetido = false;
            for(int i=0; i < num_elem; i++)
            {
                if(elem == array[i])
                {
                    repetido = true;
                }
            }
            if(repetido == false)
            {
                array[num_elem] = elem;
                num_elem++;
                for(int i=0; i< num_elem; i++)
                {
                    E minimo = array[i];
                    for(int j = i; j < num_elem; j++)
                    {
                        if(minimo > array[j])
                        {
                            minimo = array[j];
                            E tmp = array[i];
                            array[i] = array[j];
                            array[j] = tmp;
                        }
                    }
                }
            }

        }
    }


    void Borrar(E elem)
    {
        bool repetido = false;
        for(int i=0; i < num_elem; i++)
        {
            if(elem == array[i])
            {
                repetido = true;
            }
        }
        if(repetido == false)
        {
            int indiceDelElemento;
            for (int i =0; i < num_elem; i++)
            {
                if(elem == array[i])
                {
                    indiceDelElemento = i;
                }
            }

            for (int j =indiceDelElemento; j < num_elem; j++)
            {
                array[j] = array[j+1];
            }
            num_elem--;
        }

        for (int a = 0; a < num_elem; a++)
        {
            cout<< array[a]<<endl;
        }
        cout<<endl;
    };


    int NumElem()
    {
        return num_elem;
    };


    E Primero()
    {
        return array[0];
    };


    E Ultimo()
    {
        return array[num_elem-1];
    };


    E Siguiente(E elem)
    {
        E respuesta;
        for(int i=0; i<num_elem; i++)
        {
            if(array[i] == elem)
            {
                respuesta = array[i+1];
            }
        }
        return respuesta;
    };


    E Anterior(E elem)
    {
        E anterior;
        for(int i=0; i<num_elem; i++)
        {
            if(array[i] == elem)
            {
                anterior = array[i-1];
            }
        }
        return anterior;
    };


private:
    node_t* array;
    size_t max_elem;
    int num_elem;

};

#endif // LISTAORDENADAARRAY_H
