#include "evaluador.h"

int indice_palo(char palo) {
    if (palo == 'C') {
        return 0;
    }
    else if (palo == 'T') {
        return 1;
    }
    else if (palo == 'E') {
        return 2;
    }
    else if (palo == 'D') {
        return 3;
    }
    else {
        return -1;
    }
}

eval evaluar(const carta jugada[], int cantidad) {
    int conteo_categoria[14];
    int conteo_palo[4];

    // contadores
    for (int i = 0; i < 14; i++) {
        conteo_categoria[i] = 0;
    }
    for (int i = 0; i < 4; i++) {
        conteo_palo[i] = 0;
    }

    for (int i = 0; i < cantidad; i++) {
        int categoria = jugada[i].categoria;
        int p = indice_palo(jugada[i].palo);

        if (categoria >= 1 && categoria <= 13) {
            conteo_categoria[categoria]++;
        }
        if (p >= 0) {
            conteo_palo[p]++;
        }
    }
    bool hay_color = false;
    for (int i = 0; i < 4; i++) {
        if (conteo_palo[i] >= 5) {
            hay_color = true;
        }
    }
    bool hay_escalera = false;
    int racha = 0;
    for (int c = 1; c <= 13; c++) {
        if (conteo_categoria[c] > 0) {
            racha++;
        } else {
            racha = 0;
        }
        if (racha >= 5) {
            hay_escalera = true;
        }
    }

    int pares = 0;
    int tercia = 0;
    int poker = 0;

    for (int c = 1; c <= 13; c++) {
        if (conteo_categoria[c] == 2) {
            pares++;
        }
        else if (conteo_categoria[c] == 3) {
            tercia++;
        }
        else if (conteo_categoria[c] == 4) {
            poker++;
        }
    }
    eval resultado;
    resultado.tipo = 0;
    resultado.puntaje = 0;

    if (poker > 0) {
        resultado.tipo = 7;
        resultado.puntaje = 100;
        return resultado;
    }
    if (tercia > 0 && pares > 0) {
        resultado.tipo = 6; 
        resultado.puntaje = 70;
        return resultado;
    }
    if (hay_color && hay_escalera) {
        resultado.tipo = 8; 
        resultado.puntaje = 120;
        return resultado;
    }
    if (hay_color) {
        resultado.tipo = 5;
        resultado.puntaje = 60;
        return resultado;
    }
    if (hay_escalera) {
        resultado.tipo = 4;
        resultado.puntaje = 50;
        return resultado;
    }
    if (tercia > 0) {
        resultado.tipo = 3;
        resultado.puntaje = 30;
        return resultado;
    }
    if (pares >= 2) {
        resultado.tipo = 2;
        resultado.puntaje = 20;
        return resultado;
    }
    if (pares == 1) {
        resultado.tipo = 1;
        resultado.puntaje = 10;
        return resultado;
    }
    return resultado;
}