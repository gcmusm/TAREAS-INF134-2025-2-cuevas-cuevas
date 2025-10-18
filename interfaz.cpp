#include "interfaz.h"
using namespace std;

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
    cout << "[";
    inorden(raiz, mostrar_carta_inorden);
    cout << "]";
}

void imprimir_estado(int fichas, int pozo, int quedan_mazo){
        cout << "Fichas: " << fichas
         << " | Pozo: " << pozo
         << " | Mazo restante: " << quedan_mazo
         << endl;
}
bool contiene(const lista& L, char palo, int categoria){
    const nodo* cur = L.head;
    while(cur){
        if(cur->info.palo == palo && cur->info.categoria == categoria) return true;
        cur = cur->sig;
    }
    return false;
}
static void inorden_marcado_rec(nodo_abb* r, const lista& mano, const lista& jugadas){
    if(!r) return;
    inorden_marcado_rec(r->izq, mano, jugadas);

    const carta& c = r->info;
    bool enMano = contiene(mano, c.palo, c.categoria);
    bool enJugadasLista = contiene(jugadas, c.palo, c.categoria);
    bool jugadaFlag = c.jugada;
    bool marcar = enMano || enJugadasLista || jugadaFlag;

    cout << c.palo << " " << c.categoria << " (" << c.valor << ")";
    if(marcar) cout << " x";
    cout << "  ";

    inorden_marcado_rec(r->der, mano, jugadas);
}
void imprimir_inorden_marcado(nodo_abb* raiz, const lista& mano, const lista& jugadas){
    cout << "[";
    inorden_marcado_rec(raiz, mano, jugadas);
    cout << "]";
}
