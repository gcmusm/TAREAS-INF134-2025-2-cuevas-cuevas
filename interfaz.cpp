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

}
void mostrar_carta_inorden(const carta& c){
    imprimir_carta(c);
    cout << "  ";
}
void imprimir_inorden(nodo_abb* raiz){

}
void imprimir_estado(int fichas, int pozo, int quedan_mazo){
    
}