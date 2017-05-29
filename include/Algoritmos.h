#ifndef __ALGORITMOS_H__
#define __ALGORITMOS_H__
#include "Listas_LDE.h"

template <typename E>
ListaPos<E> Invertir(ListaPos<E> L);

template <typename E>
bool Sublista(ListaPos<E> L1, ListaPos<E> L2);

template <typename E>
void BurbujaDoble(ListaPos<E> &L1);

template <typename E>
void Imprimir(ListaPos<E> L);

#endif
