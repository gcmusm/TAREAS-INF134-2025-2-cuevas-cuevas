#include "abb.h"


void extraer_por_palo(const carta base[52], char palo, carta salida[13], int& n){
    n=0;
    for(int i =0; i<52; i++){
        if(base[i].palo == palo){
            if(n<13){
                salida[n] = base[i];
                n++;
            }
        }
    }
}
nodo_abb* construir_balanceado(const carta v[], int inicio, int fin){
    if(inicio>fin){
        return nullptr;
    }
    int medio = (inicio+fin)/2;
    nodo_abb* raiz = new nodo_abb;
    raiz->info = v[medio];  
    raiz->izq = nullptr;
    raiz->der = nullptr;
    raiz->izq = construir_balanceado(v, inicio, medio-1);
    raiz->der = construir_balanceado(v, medio+1, fin);
    return raiz;    
}


void construir_arboles_por_palo(const carta base[52], nodo_abb* arboles[4]){
    const char palos[4] = 
    

}
void inorden(nodo_abb* raiz, void (*visitar)(const carta&)){

}
nodo_abb* buscar_por_categoria(nodo_abb* raiz, int categoria){

}
void destruir_arbol(nodo_abb*& raiz){

}
