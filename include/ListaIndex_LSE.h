#ifndef LISTAINDEX_LSE_H
#define LISTAINDEX_LSE_H
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename E>
class ListaIndex
{
public:
    ListaIndex()
    {
        num_elem = 0;
        cabeza = NULL;
        //ctor
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

    virtual ~ListaIndex()
    {
        Vaciar();
    }

    void Destruir()
    {
        Vaciar();
    }
    bool Vacia()
    {
        return num_elem == 0;
    };

    virtual E Recuperar(int p)   //debe darse un índice válido
    {
        nodoPtr tmp = cabeza;
        for(int i=1; i<p; i++)
        {
            tmp = tmp->siguiente;
        }
        return tmp->elemento;

    };

    void Insertar(int p, E elem)
    {
        nodoPtr n = new Nodo;
        n->siguiente = NULL;
        n->elemento = elem;
        /*
        if(cabeza != NULL) //si hay al menos un elemento
        {
            actual = cabeza;

            while(actual->siguiente != NULL) //mientras no sea el final de la lista
            {
                actual = actual->siguiente;
                actual->anterior = n;
            }
            actual->siguiente = n;

        }
        else //si la cabeza es nula, se establece n como cabeza
        {
            cabeza = n; //si no hay lista se hace n el frente de la lista
            n->anterior = NULL;
        }
        */


        if (num_elem == 0) {
            // Caso especial lista vacia
            cabeza = n;

        } else {

            // Caso especial primer elemento
            if (p == 1) {
                //cout << "caso especial!" << endl;
                n->siguiente = cabeza;
                cabeza = n;

            // Otros casos, se inserta antes del elemento i
            } else {
                //cout << "Buscando posicion" << endl;
                nodoPtr it = cabeza;
                for (int i = 2; i < p; i++) {
                    it = it->siguiente;
                    //cout << "Apuntando a " << it->elemento << endl;
                }
                // Aqui it es el nodo anterior al nodo p
                n->siguiente = it->siguiente;
                it->siguiente = n;
            }
        }

        num_elem++;
    }

    void Borrar(int p)
    {
        /*
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
        */

        nodoPtr tmp; // Nodo que se va a borrar

        if (p == 1) {
            tmp = cabeza;
            cabeza = cabeza->siguiente;
        } else {
            nodoPtr it = cabeza;
            for (int i = 2; i < p; i++) {
                it = it->siguiente;
            }
            // it apunta al nodo anterior al que se
            // va a borrar
            tmp = it->siguiente;
            it->siguiente = tmp->siguiente;
        }

        delete tmp;
        num_elem--;
    }

    void ModificarElem(int p, E elem)
    {
        nodoPtr n = cabeza;
		for(int i=1; i<p; i++)
		{
                n = n->siguiente;
		}
		n->elemento = elem;
    }

    void Intercambiar(int p1, int p2)
    {

		nodoPtr it1, it2;

		it1 = cabeza;
        for (int i=1; i<p1; i++) {
            it1 = it1->siguiente;
        }

		it2 = cabeza;
        for (int i=1; i<p2; i++) {
            it2 = it2->siguiente;
		}

		E tmp = it1->elemento;
		it1->elemento = it2->elemento;
		it2->elemento = tmp;
    }

    int NumElem()
    {
        return num_elem;
    };

    void Imprimir() //efectos de prueba
    {
        nodoPtr n = cabeza;
        if(n==NULL)
        {
            cout<<"La lista esta vacia" << endl;
        }

		else
			cout << "Recorrido desde el primero" << endl;

        while(n!= NULL)
        {
            cout << n->elemento << " ";
            n = n->siguiente;
        }
        cout << endl;
    }

private:
    typedef struct Nodo
    {
        E elemento;
        Nodo* siguiente;
    }* nodoPtr;

    int num_elem;
    nodoPtr cabeza;
};

#endif // LINDEXLSE_H
