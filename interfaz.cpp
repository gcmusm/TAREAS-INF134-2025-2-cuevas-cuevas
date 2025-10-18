#include "interfaz.h"
using namespace std;

static void imprimir_par(const carta& c) {
    // Formato pauta: "categoria+palo" (ej: 1C, 12E, 10C)
    cout << c.categoria << c.palo;
}

void imprimir_carta(const carta& c) {
    imprimir_par(c);
}

void imprimir_lista(const lista& L){
    nodo* actual = L.head;
    bool first = true;
    while(actual != nullptr){
        if (!first) cout << " ";
        imprimir_par(actual->info);
        first = false;
        actual = actual->sig;
    }
}

void imprimir_primeras(const lista& L, int n){
    nodo* actual = L.head;
    int i = 0;
    bool first = true;
    while(actual != nullptr && i < n){
        if (!first) cout << " ";
        imprimir_par(actual->info);
        first = false;
        actual = actual->sig;
        i++;
    }
}

void mostrar_carta_inorden(const carta& c){
    imprimir_par(c);
    cout << " ";
}

void imprimir_inorden(nodo_abb* raiz){
    if(raiz == nullptr){
        cout << "(arbol vacio)";
        return;
    }
    inorden(raiz, mostrar_carta_inorden);
}

void imprimir_estado(int fichas, int pozo, int quedan_mazo){
    // Este se reemplaza desde main con el formato pauta, pero lo dejamos por compatibilidad
    cout << "Fichas: " << fichas
         << " | Pozo: " << pozo
         << " | Mazo restante: " << quedan_mazo
         << endl;
}