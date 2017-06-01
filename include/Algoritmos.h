#ifndef __ALGORITMOS_H__
#define __ALGORITMOS_H__
#include "Listas_LSE.h"

// Algoritmos de la lista posicionada
template <typename E>
void Invertir(ListaPos<E> &L);

template <typename E>
bool Sublista(ListaPos<E> L1, ListaPos<E> L2);

template <typename E>
void BurbujaDoble(ListaPos<E> &L1);

template <typename E>
void Imprimir(ListaPos<E> L);

template <typename E>
void SeleccionPila(ListaPos<E> &L);

template <typename E>
void UnionDesord(ListaPos<E> &L1, ListaPos<E> &L2);

template <typename E>
void Eliminar(ListaPos<E> &L1, ListaPos<E> &L2);


// Algoritmos de la lista indexada
template <typename E>
void Invertir(ListaIndex<E> &L);

template <typename E>
bool Sublista(ListaIndex<E> &L1, ListaIndex<E> &L2);

template <typename E>
void BurbujaDoble(ListaIndex<E> &L1);

template <typename E>
void Imprimir(ListaIndex<E> &L);

template <typename E>
void SeleccionPila(ListaIndex<E> &L);

template <typename E>
void UnionDesord(ListaIndex<E> &L1, ListaIndex<E> &L2);

template <typename E>
void Eliminar(ListaIndex<E> &L1, ListaIndex<E> &L2);

#endif
