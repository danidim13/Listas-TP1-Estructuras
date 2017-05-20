#ifndef __ListaOrdenada_LSE_H__
#define __ListaOrdenada_LSE_H__
#include <cstdlib>
#include <iostream>
using namespace std;

/*! Clase que implementa el modelo Lista Ordenada
 *  mediante una lista simplemente enlazada.
 */
template <typename E>
class ListaOrdenada
{

public:
    int num_elem=0;

    void Imprimir() //efectos de prueba
    {
        nodoPtr n = cabeza;
        if(n==NULL)
        {
            cout<<"La lista esta vacia" << endl;
        }
        while(n!= NULL)
        {
            cout << n->elemento << endl;
            n = n->siguiente;
        }
    }
    /* Constructor por defecto.
     */
    ListaOrdenada()
    {
        cabeza= NULL;
        actual = NULL;
        temporal = NULL;
        //ctor
    }

    /* Destructor por defecto.
     */
    virtual ~ListaOrdenada()
    {
        Vaciar();
    };

    void Destruir()
    {
        Vaciar();
    }

    void Vaciar()
    {
        nodoPtr it = cabeza;
        nodoPtr tmp;
        while (it != NULL)
        {
            tmp = it;
            it = it->siguiente;
            delete tmp;
        }
        num_elem = 0;
        cabeza = NULL;
    };

    bool Vacia()
    {
        return num_elem == 0;
    };

    //Requerimiento: NO PUEDEN INSERTAR ELEMENTOS REPETIDOS.
    void Insertar(E elem)
    {
        Nodo *n = new Nodo;
        n->elemento = elem;
        Nodo *tmp = cabeza;
        Nodo **tmp2 = &cabeza;

        while(tmp != NULL && tmp->elemento < n->elemento)
        {
            tmp2 = &tmp->siguiente;
            tmp = tmp->siguiente;
        }
        *tmp2 = n;
        n->siguiente = tmp;
		num_elem++;
    };
    //fuente de info: http://stackoverflow.com/questions/4825030/c-add-to-linked-list-in-sorted-order

    void Borrar(int p)
    {
        nodoPtr temp = cabeza;
        nodoPtr temp2;
        if(p==1)
        {
            cabeza = temp->siguiente;
            delete(temp);
        }
        for(int i= 1; i<=p-1; i++)
        {
            temp = temp->siguiente;
        }
        temp2 = temp->siguiente;
        temp->siguiente = temp2->siguiente;
        delete(temp2);
		num_elem--;
    };

    int NumElem()
    {
        return num_elem;
    };


    E Primero()
    {
        return cabeza->elemento;
    }

    E Ultimo()
    {
        E elUltimo;
        actual = cabeza;
        while(actual->siguiente != NULL)
        {
            elUltimo = actual->elemento;
            actual = actual->siguiente;
        }
        elUltimo = actual->elemento;
        return elUltimo;
    }

    E Siguiente(E elem)
    {
        nodoPtr n = new Nodo;
        n = cabeza;
        while(n != NULL)
        {
            if(n-> elemento == elem)
            {
                break;
            }
            else
            {
                n = n ->siguiente;
            }
        }
        n = n->siguiente;
        return n->elemento;
    }

    E Anterior(E elem)
    {
        nodoPtr n = new Nodo;
        n = cabeza;
        while(n != NULL)
        {
            if(n-> elemento == elem)
            {
                break;
            }
            else
            {
                temporal = n;
                n = n ->siguiente;
            }
        }
        return temporal->elemento;

    }

//private:
    typedef struct Nodo
    {
        E elemento;
        Nodo* siguiente;
        Nodo* tmp;
    }* nodoPtr;

    nodoPtr cabeza;
    nodoPtr actual;
    nodoPtr pos;
    nodoPtr temporal;
};

#endif
