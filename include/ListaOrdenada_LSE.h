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

    void Imprimir() //efectos de prueba
    {
        nodoPtr n = cabeza;
        if(n==NULL)
        {
            cout<<"La lista esta vacia" << endl;
        }
        while(n!= NULL)
        {
            cout << n->elemento << " ";
            n = n->siguiente;
        }
		cout << endl;
    };
    /* Constructor por defecto.
     */
    ListaOrdenada(): cabeza(NULL), num_elem(0)
    {
        //cabeza = NULL;
        //actual = NULL;
        //temporal = NULL;
		//num_elem = 0;
        //ctor
		//cout << "construido";
    };

    /* Destructor por defecto.
     */
    virtual ~ListaOrdenada()
    {
        Vaciar();
    };

    void Destruir()
    {
        Vaciar();
    };

    void Vaciar()
    {
		cout << "vaciar" << endl;
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

    void Insertar(E elem)
    {
		//cout << "Insertando " << elem << endl;
		// Caso especial lista vacia
		if (num_elem == 0) {
			cabeza = new Nodo;
			cabeza->elemento = elem;
			cabeza->siguiente = NULL;
			num_elem++;
			return;
		}

		// Se debe buscar la posicion correcta para elem
		
		nodoPtr iter = cabeza;

		// Caso especial, insertar al principio
		if (elem < iter->elemento) {
			nodoPtr nuevo = new Nodo;
			nuevo->elemento = elem;
			nuevo->siguiente = cabeza;
			cabeza = nuevo;
			num_elem++;
			return;
		}

		// Ojo: el condicional se evalua de izquierda a
		// derecha (primero se ve que iter no es nulo).
		// El orden es importante porque sino se daría
		// un segfault cuando se trata de accesar el 
		// elemento de iter.
		while ((iter->siguiente) && (iter->siguiente)->elemento < elem) {
			iter = iter->siguiente;
		}

		// En este punto iter apunta al nodo anterior
		// a donde iria el nuevo elemento 
		
		// Insertar al final (iter->sig no existe) o elem no es repetido
		// De nuevo, el orden del if importa
		if (!(iter->siguiente) || (iter->siguiente)->elemento != elem) {
			nodoPtr nuevo = new Nodo;
			nuevo->elemento = elem;
			nuevo->siguiente = iter->siguiente;
			iter->siguiente = nuevo;
			num_elem++;
			return;
		} else {
			// En caso contrario el elemento ya esta en la lista
			return;
		}

		/*
		nodoPtr nuevo = new Nodo;
		nuevo->elemento = elem;
		nuevo->siguiente = iter->siguiente;
		iter->siguiente = nuevo;
		num_elem++;
		return
		*/


		// 
		/*
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
		*/
    };
    //fuente de info: http://stackoverflow.com/questions/4825030/c-add-to-linked-list-in-sorted-order

    void Borrar(E elem)
    {
		//cout << "Borrando " << elem << endl;
		// Lista vacia
		if (num_elem == 0)
			return;

		//
		if (elem < cabeza->elemento)
			return;

		// Caso especial primer elemento
		nodoPtr it = cabeza;
		if (elem == cabeza->elemento) {
			cabeza = cabeza->siguiente;
			delete it;
			num_elem--;
			return;
		}

		while ((it->siguiente) && (it->siguiente)->elemento < elem) {
			it = it->siguiente;
		}

		// En este punto it esta en la posicion anterior
		// a donde deberia estar elem.

		// No se encontró elem
		if (!(it->siguiente) || (it->siguiente)->elemento != elem) {
			return;
		} else {
			nodoPtr tmp = it->siguiente;
			it->siguiente = tmp->siguiente;
			delete tmp;
			num_elem--;
			return;
		}

		/*
		cout << "borrando" << endl;
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
		*/
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
        nodoPtr actual = cabeza;
        while(actual->siguiente != NULL)
        {
            //elUltimo = actual->elemento;
            actual = actual->siguiente;
        }
        elUltimo = actual->elemento;
        return elUltimo;
    }

    E Siguiente(E elem)
    {
        nodoPtr n = cabeza;
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
        nodoPtr n = cabeza;
		nodoPtr temporal;
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

private:

	typedef struct Nodo
	{
		E elemento;
		Nodo* siguiente;
		//Nodo* tmp;
	}* nodoPtr;

    nodoPtr cabeza;
    int num_elem;
};

#endif
