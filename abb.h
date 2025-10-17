#ifndef ABB_H
#define ABB_H
#include "carta.h"

struct nodo_abb {
    carta info;
    nodo_abb* izq;
    nodo_abb* der;
};

void construir_arboles_por_palo(const carta base[52], nodo_abb* arboles[4]);
void inorden(nodo_abb* raiz, void (*visitar)(const carta&));
nodo_abb* buscar_por_categoria(nodo_abb* raiz, int categoria);
void destruir_arbol(nodo_abb*& raiz);
void extraer_por_palo(const carta base[52], char palo, carta salida[13], int& n);
nodo_abb* construir_balanceado(const carta v[], int inicio, int fin);

#endif