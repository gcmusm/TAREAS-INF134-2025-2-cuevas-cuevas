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

void append(lista& L, const carta& c);
bool eraseen(lista& L, int pos);          
int  length(const lista& L);              
bool get(const lista& L, int pos, carta&);  
void clear(lista& L);                       
bool popfront(lista& L, carta& out);  

#endif