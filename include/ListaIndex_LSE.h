#ifndef LISTAINDEX_LSE_H
#define LISTAINDEX_LSE_H
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename E>
class ListaIndex
{
public:
    int num_elem = 0;
    ListaIndex()
    {
        cabeza = NULL;
        actual = NULL;
        temporal = NULL;
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
        for(int i=1; i<=p; i++)
        {
            tmp = tmp->siguiente;
        }

       // cout << "El elemento en el indice" << p << "es: " << tmp->elemento;
    };

    void Insertar(int p, E elem)
    {
        nodoPtr n = new Nodo;
        n->siguiente = NULL;
        n->elemento = elem;
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
        num_elem++;
    }

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
    }

    void ModificarElem(int p, E elem)
    {
        nodoPtr n = cabeza;
        if(p==1) cabeza->elemento = elem;
        else
        {
            for(int i=1; i<=p-1; i++)
            {
                n = n->siguiente;
            }
            n->elemento = elem;
        }
       // cout << "El elemento cambiado en el indice es: " << n->elemento << endl;
    }
    void Intercambiar(int p1, int p2)
    {
        nodoPtr n = cabeza;
        nodoPtr n2 = cabeza;
        nodoPtr tmp;
        tmp->elemento = n->elemento;

        if(p1==1) cabeza->elemento = n2->elemento;
        else if(p1!=1)
        {
            for(int i=1; i<=p1-1; i++)
            {
                n = n->siguiente;
                tmp->elemento = n->elemento;
               // cout << "primero: " << n->elemento << endl;
            }

        }

        if(p2==1) cabeza->elemento = n->elemento;
        else if(p2!=1)
        {
            for(int i=1; i<=p2-1; i++)
            {
                n2 = n2->siguiente;
            }
        }
        n->elemento = n2->elemento;
        n2->elemento = tmp->elemento;
       // cout << "primero: " << n->elemento << endl;
      //  cout << "segundo: " << n2->elemento << endl;
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
        while(n!= NULL)
        {
            cout << n->elemento << endl;
            n = n->siguiente;
        }
    }

//private:
    typedef struct Nodo
    {
        E elemento;
        Nodo* siguiente;
        Nodo* anterior;
    }* nodoPtr;

    nodoPtr cabeza;
    nodoPtr actual;
    nodoPtr pos;
    nodoPtr temporal;
};

#endif // LINDEXLSE_H
