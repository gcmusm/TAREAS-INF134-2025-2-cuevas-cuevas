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
        
    }

}