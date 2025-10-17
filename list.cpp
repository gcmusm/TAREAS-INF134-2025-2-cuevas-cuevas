#include "list.h"

void append(lista& L, const carta& c){
    nodo* nuevo = new nodo{c, nullptr};
    if(!L.head){
        L.head=nuevo;
    }
    else{
        nodo* aux =L.head;
        while(aux->sig){
            aux= aux->sig;
        }
        aux->sig =nuevo;
    }
}

bool eraseen(lista& L, int pos){
    if(pos<0 || L.head == nullptr){
        return false;
    }
    if(pos==0){
        nodo* borrar = L.head;
        L.head = L.head->sig;
        delete borrar;
        return true;
    }
    nodo* prev = L.head;
    for(int i =0; prev != nullptr && i<pos-1; i++){
        prev = prev->sig
    }
    if(prev ==nullptr ||prev->sig == nullptr){
        return false;
    }
    nodo* borrar = prev->sig;
    prev->sig = borrar->sig;
    delete borrar;
    return true;
}

int length(lista& L) {
    int cont=0;
    nodo* aux=L.head;
    while(aux!=nullptr) {
        contador++;
        aux=aux->sig;
    }
    return cont;
}

void clear(lista& L){
    nodo* aux= L.head;
    while(aux!=nullptr){
        nodo* borrar= aux;
        aux= aux->sig;
        delete borrar;
    }
    L.head=nullptr;
}

bool popfront(lista& L, carta& out){
    if(L.head==nullptr){
        return false;
    }
    nodo* borrar= L.head;
    out=borrar->info;
    L.head= borrar->sig
    delete borrar;
    return true;
}