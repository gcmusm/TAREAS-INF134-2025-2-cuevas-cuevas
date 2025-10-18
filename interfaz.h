#ifndef INTERFAZ_H
#define INTERFAZ_H  

#include <iostream>
#include "carta.h"
#include "list.h"
#include "abb.h"

void imprimir_carta(const carta& c);
void imprimir_lista(const lista& L);
void imprimir_primeras(const lista& L, int n);
void imprimir_inorden(nodo_abb* raiz);
void imprimir_estado(int fichas, int pozo, int quedan_mazo);
#endif