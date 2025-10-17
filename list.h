#ifndef LIST_H
#define LIST_H
#include "carta.h"

struct nodo{
    carta info;
    nodo* sig;
}

struct lista{
    nodo* head;
    lista() : head(nullptr) {}
}

void append(Lista& L, const carta& c);


#endif