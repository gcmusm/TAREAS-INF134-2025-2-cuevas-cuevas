#include "interfaz.h"

void imprimir_carta(const carta& c) {
    cout << c.palo << " " << c.categoria << " (" << c.valor << ")";
}
void imprimir_lista(const lista& L){
    nodo* actual= L.head;
    cout<< "[";
    while(actual != nullptr){
        imprimir_carta(actual->info);
        if(actual->sig != nullptr){
            cout << "  ";
        }
        actual =actual->sig;
    }
    cout<< "]";
}
void imprimir_primeras(const lista& L, int n){
    nodo* actual = L.head;
    int i=0;
    cout << "[";
    while(actual !=nullptr && i<n){
        imprimir_carta(actual->info);
        actual = actual->sig;
        i++;
        if(actual !=nullptr && i<n){
            cout <<"  ";
        }   
    }
    cout << "]";
}
void mostrar_carta_inorden(const carta& c){
    imprimir_carta(c);
    cout << "  ";
}
void imprimir_inorden(nodo_abb* raiz){
    if(raiz == nullptr){
        cout << "(arbol vacio)";
        return;
    }
    cout << "[";
    inorden(raiz, mostrar_carta_inorden);
    cout << "]";
}
void imprimir_estado(int fichas, int pozo, int quedan_mazo){
    
}