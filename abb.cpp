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
    const char palos[4] = {'C', 'T', 'E', 'D'};
    for(int k =0; k<4; k++){
        carta cartas_palo[13];
        int cantidad =0;
        extraer_por_palo(base, palos[k], cartas_palo, cantidad);
        if(cantidad ==13){
            arboles[k = construir_balanceado(0, 12)];
        }
        else{
            arboles[k] = nullptr;
        }
    }
}
void inorden(nodo_abb* raiz, void (*visitar)(const carta&)){
    if(raiz==nullptr){
        return;
    }
    inorden(raiz->izq, visitar);
    visitar(raiz->info);
    inorden(rais->der, visitar)
}
nodo_abb* buscar_por_categoria(nodo_abb* raiz, int categoria){

}
void destruir_arbol(nodo_abb*& raiz){

}
