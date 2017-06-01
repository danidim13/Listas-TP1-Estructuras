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
            cout<< array[i] << " ";
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

        //cout << "Insertando " << elem << endl;
        if(num_elem == 0)
        {
            array[0] = elem;
            num_elem++;
            return;
        }
        else {
            // Primero se encuentra la posición
            // donde iría el nuevo elemento
            int i_elem = 0;
            while (i_elem < num_elem && array[i_elem] < elem) {
                i_elem++;
            }

            // Si se llego al final de la lista entonces
            // simplemente se agrega el elemento
            if (i_elem == num_elem) {
                array[i_elem] = elem;
                num_elem++;
                return;
            }

            // Se verifica si el elemento es repetido
            // en ese caso no se hace nada
            if (array[i_elem] == elem) {
                return;
            }

            // En caso contrario hay que correr los
            // elementos posteriores para que la lista
            // quede ordenada
            E tmp_act = elem;
            E tmp_sig;
            for (int i = i_elem; i < num_elem; i++) {
                tmp_sig = array[i];
                array[i] = tmp_act;
                tmp_act = tmp_sig;
            }
            array[num_elem] = tmp_act;
            num_elem++;
            return;
        }

        /*
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
        */
    }


    void Borrar(E elem)
    {
        // Si la lista esta vacía no hay nada que hacer
        if (num_elem == 0)
            return;

        // Primero se encuentra la posición
        // donde iría el elemento
        int i_elem = 0;
        while (i_elem < num_elem && array[i_elem] < elem) {
            i_elem++;
        }

        // Si se llega al final es que no se encontró elem
        if (i_elem == num_elem)
            return;

        // Tampoco se encotró si se llega a un elemento mayor
        if (array[i_elem] != elem)
            return;

        // Cuando el elemento existe, se corren todos
        // los elementos posteriores
        for (int i = i_elem; i < num_elem-1; i++) {
            array[i] = array[i+1];
        }
        num_elem--;

        /*
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
        */

        /*
        for (int a = 0; a < num_elem; a++)
        {
            cout<< array[a]<<endl;
        }
        cout<<endl;
        */
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
