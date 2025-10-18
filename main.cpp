#include <iostream>
#include "carta.h"
#include "list.h"
#include "mazo.h"
#include "abb.h"
#include "interfaz.h"
#include "comandos.h"
#include "evaluador.h"

using namespace std;

int main() {
    carta baraja_base[52];
    int orden_barajado[52];
    lista mazo;
    lista mano;
    nodo_abb* arboles_por_palo[4] = { nullptr, nullptr, nullptr, nullptr };

    int fichas = 100;
    int pozo = 0;
    const int CARTAS_OBJETIVO_MANO = 8;

    generarbaraja(baraja_base);
    barajar(orden_barajado);
    cargarMazo(mazo, baraja_base, orden_barajado);
    repartir(mazo, mano, CARTAS_OBJETIVO_MANO);
    construir_arboles_por_palo(baraja_base, arboles_por_palo);

    cout << "Mano inicial: ";
    imprimir_lista(mano);
    cout << "\nMazo (primeras 5): ";
    imprimir_primeras(mazo, 5);
    cout << "\n";
    imprimir_estado(fichas, pozo, length(mazo));
    bool seguir = true;

    while (seguir == true) {
        cout << "\n> Comando (M / D n pos... / J n pos... / Q): ";

        char comando;
        cin >> comando;

        if (!cin) {
            seguir = false;
        }
        else {
            if (comando == 'M' || comando == 'm') {
                cout << "Mano: ";
                imprimir_lista(mano);
                cout << "\nMazo (primeras 5): ";
                imprimir_primeras(mazo, 5);
                cout << "\nABB Corazones (C): ";
                imprimir_inorden(arboles_por_palo[0]);
                cout << "\n";
                imprimir_estado(fichas, pozo, length(mazo));
            }
            else {
                if (comando == 'D' || comando == 'd') {
                    int cantidad_descartar;
                    cin >> cantidad_descartar;

                    if (!cin || cantidad_descartar <= 0) {
                        cout << "Entrada invalida.\n";
                    }
                    else {
                        int posiciones_descartar[32];
                        int i = 0;

                        while (i < cantidad_descartar) {
                            cin >> posiciones_descartar[i];
                            i = i + 1;
                        }

                        descartar_y_reponer(mano, mazo, posiciones_descartar, cantidad_descartar, CARTAS_OBJETIVO_MANO);

                        cout << "Mano tras descartar y reponer: ";
                        imprimir_lista(mano);
                        cout << "\n";
                        imprimir_estado(fichas, pozo, length(mazo));
                    }
                }
                else {
                    if (comando == 'J' || comando == 'j') {
                        int cantidad_seleccionada;
                        cin >> cantidad_seleccionada;

                        if (!cin || cantidad_seleccionada <= 0) {
                            cout << "Entrada invalida.\n";
                        }
                        else {
                            int posiciones_jugada[32];
                            int i = 0;

                            while (i < cantidad_seleccionada) {
                                cin >> posiciones_jugada[i];
                                i = i + 1;
                            }

                            carta cartas_jugada[32];
                            int cantidad_real_jugada = 0;
                            bool exito = preparar_jugada(mano, posiciones_jugada, cantidad_seleccionada, cartas_jugada, cantidad_real_jugada);

                            if (exito == false) {
                                cout << "Posiciones invalidas.\n";
                            }
                            else {
                                cout << "Jugada: ";
                                i = 0;
                                while (i < cantidad_real_jugada) {
                                    imprimir_carta(cartas_jugada[i]);
                                    if (i + 1 < cantidad_real_jugada) {
                                        cout << "  ";
                                    }
                                    i = i + 1;
                                }
                                cout << "\n";

                                eval resultado = evaluar(cartas_jugada, cantidad_real_jugada);
                                cout << "Tipo=" << resultado.tipo << "  Puntaje=" << resultado.puntaje << "\n";
                                ordenar_posiciones_desc(posiciones_jugada, cantidad_seleccionada);

                                i = 0;
                                while (i < cantidad_seleccionada) {
                                    eraseen(mano, posiciones_jugada[i]);
                                    i = i + 1;
                                }

                                fichas = fichas + resultado.puntaje;

                                reponerHasta(mazo, mano, CARTAS_OBJETIVO_MANO);

                                cout << "Mano tras jugar y reponer: ";
                                imprimir_lista(mano);
                                cout << "\n";
                                imprimir_estado(fichas, pozo, length(mazo));
                            }
                        }
                    }
                    else {
                        if (comando == 'Q' || comando == 'q') {
                            seguir = false;
                        }
                        else {
                            cout << "Comando no reconocido.\n";
                        }
                    }
                }
            }
        }
    }
    clear(mano);
    clear(mazo);

    int k = 0;
    while (k < 4) {
        destruir_arbol(arboles_por_palo[k]);
        k = k + 1;
    }

    return 0;
}//pipip 