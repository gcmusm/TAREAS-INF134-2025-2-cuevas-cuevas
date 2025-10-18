#ifndef COMANDOS_H
#define COMANDOS_H

#include "carta.h"
#include "list.h"
#include "mazo.h"

bool indices_validos(const lista& mano, const int posiciones[], int cantidad);
bool copiar_cartas_por_posiciones(const lista& mano, const int posiciones[], int cantidad, carta cartas_salida[], int& cantidad_salida);
void ordenar_posiciones_desc(int posiciones[], int cantidad);
void descartar_y_reponer(lista& mano, lista& mazo, int posiciones[], int cantidad, int cantidad_objetivo);
bool preparar_jugada(const lista& mano, const int posiciones[], int cantidad, carta jugada[], int& cantidad_jugada);

#endif