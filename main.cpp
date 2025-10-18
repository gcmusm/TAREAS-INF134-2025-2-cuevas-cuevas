#include <iostream>
#include <ctime>
#include <cstdlib>
#include "carta.h"
#include "list.h"
#include "mazo.h"
#include "abb.h"
#include "interfaz.h"
#include "comandos.h"
#include "evaluador.h"

using namespace std;

static const int CARTAS_OBJETIVO_MANO = 8;

static const char* nombre_mano(int tipo) {
    switch (tipo) {
        case 7: return "Poker";
        case 5: return "Color";
        case 4: return "Escalera";
        case 3: return "Tercia";
        case 2: return "Doble par";
        case 1: return "Par";
        default: return "Carta mas alta";
    }
}

static void imprimir_estado_pauta(int fichas, int pozo_obj, int mazo_rest, int j_rest, int d_rest) {
    cout << fichas << " / " << pozo_obj << " fichas\n";
    cout << mazo_rest << " / 52 cartas\n";
    cout << j_rest << " J / " << d_rest << "D\n";
}

void jugar_ciega(const char* nombre_ciega, int pozo_obj, int& fichas_global) {
    carta baraja_base[52];
    int orden_barajado[52];
    lista mazo;
    lista mano;
    nodo_abb* arboles_por_palo[4] = { nullptr, nullptr, nullptr, nullptr };

    generarbaraja(baraja_base);
    barajar(orden_barajado);
    cargarMazo(mazo, baraja_base, orden_barajado);
    repartir(mazo, mano, CARTAS_OBJETIVO_MANO);
    construir_arboles_por_palo(baraja_base, arboles_por_palo);

    int fichas = 0;
    int j_rest = 4;
    int d_rest = 3;

    cout << "Comienza la ciega " << nombre_ciega << ", pozo a vencer: " << pozo_obj << " fichas\n\n";
    imprimir_estado_pauta(fichas, pozo_obj, length(mazo), j_rest, d_rest);
    imprimir_lista(mano);
    cout << "\n";

    bool seguir = true;
    while (seguir) {
        cout << "Juega : ";
        char comando;
        cin >> comando;
        if (!cin) break;

        if (comando == 'M' || comando == 'm') {
            cout << "M\n";
            cout << "Disponibles -\n";
            cout << "C: "; imprimir_inorden(arboles_por_palo[0]); cout << "\n";
            cout << "E: "; imprimir_inorden(arboles_por_palo[2]); cout << "\n";
            cout << "T: "; imprimir_inorden(arboles_por_palo[1]); cout << "\n";
            cout << "D: "; imprimir_inorden(arboles_por_palo[3]); cout << "\n\n";
            cout << "No disponibles -\n";
            imprimir_lista(mano); cout << "\n\n";
            imprimir_estado_pauta(fichas, pozo_obj, length(mazo), j_rest, d_rest);
            imprimir_lista(mano); cout << "\n";
        }
        else if (comando == 'D' || comando == 'd') {
            int n; cin >> n;
            if (!cin || n <= 0 || d_rest <= 0) { cout << "Entrada invalida.\n"; continue; }
            int pos[32];
            for (int i = 0; i < n; ++i) cin >> pos[i];
            descartar_y_reponer(mano, mazo, pos, n, CARTAS_OBJETIVO_MANO);
            d_rest--;
            cout << "\n";
            imprimir_estado_pauta(fichas, pozo_obj, length(mazo), j_rest, d_rest);
            imprimir_lista(mano); cout << "\n";
        }
        else if (comando == 'J' || comando == 'j') {
            int n; cin >> n;
            if (!cin || n <= 0 || j_rest <= 0) { cout << "Entrada invalida.\n"; continue; }
            int pos[32];
            for (int i = 0; i < n; ++i) cin >> pos[i];
            carta jugada[32];
            int cant_real = 0;
            if (!preparar_jugada(mano, pos, n, jugada, cant_real)) { cout << "Posiciones invalidas.\n"; continue; }

            eval r = evaluar(jugada, cant_real);
            cout << "Mano jugada : " << nombre_mano(r.tipo) << "\n";
            cout << "Fichas anotadas : " << r.puntaje << "\n\n";

            ordenar_posiciones_desc(pos, n);
            for (int i = 0; i < n; ++i) eraseen(mano, pos[i]);
            fichas += r.puntaje;
            fichas_global += r.puntaje;
            reponerHasta(mazo, mano, CARTAS_OBJETIVO_MANO);
            j_rest--;

            imprimir_estado_pauta(fichas, pozo_obj, length(mazo), j_rest, d_rest);
            imprimir_lista(mano); cout << "\n";

            if (fichas >= pozo_obj) {
                cout << "Ciega " << nombre_ciega << " vencida : " << fichas << " / " << pozo_obj << " fichas\n\n";
                break;
            }
        }
        else if (comando == 'Q' || comando == 'q') {
            seguir = false;
        }
        else {
            cout << "Comando no reconocido.\n";
        }
    }

    clear(mano);
    clear(mazo);
    for (int k = 0; k < 4; ++k) destruir_arbol(arboles_por_palo[k]);
}

int main() {
    srand((unsigned)time(nullptr));
    cout << "Bienvenido al maravilloso juego de Data Balatro!\n\n";
    int fichas_totales = 0;

    // Ciega pequeña
    jugar_ciega("pequena", 250, fichas_totales);

    // Ciega grande (solo si venciste la anterior)
    if (fichas_totales >= 250) {
        jugar_ciega("grande", 350, fichas_totales);
    }

    // Ciega del jefe (solo si venciste la grande)
    if (fichas_totales >= 600) {
        jugar_ciega("del jefe", 500, fichas_totales);
    }

    cout << "Juego terminado. Fichas totales: " << fichas_totales << "\n";
    return 0;
}
