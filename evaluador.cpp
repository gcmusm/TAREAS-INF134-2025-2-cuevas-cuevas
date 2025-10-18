#include "evaluador.h"

// Puntajes base según pauta
static const int PTS_CARTA_ALTA = 50;
static const int PTS_PAR        = 40;
static const int PTS_DOBLE_PAR  = 80;
static const int PTS_TERCIA     = 120;
static const int PTS_ESCALERA   = 150;
static const int PTS_COLOR      = 200;
static const int PTS_POKER      = 400;

static int indice_palo_local(char p) {
    if (p == 'C') return 0;
    if (p == 'T') return 1;
    if (p == 'E') return 2;
    if (p == 'D') return 3;
    return -1;
}

eval evaluar(const carta jugada[], int cantidad) {
    int cntCat[14];     // 1..13
    int cntPalo[4];     // C,T,E,D

    for (int i = 0; i < 14; ++i) cntCat[i] = 0;
    for (int i = 0; i < 4;  ++i) cntPalo[i] = 0;

    for (int i = 0; i < cantidad; ++i) {
        int c = jugada[i].categoria;
        if (c >= 1 && c <= 13) cntCat[c]++;
        int p = indice_palo_local(jugada[i].palo);
        if (p >= 0) cntPalo[p]++;
    }

    // Color: todas del mismo palo en la jugada (>=5)
    bool hay_color = false;
    for (int p = 0; p < 4; ++p) if (cntPalo[p] >= 5) { hay_color = true; break; }

    // Escalera (A=1 válido para A,2,3,4,5)
    bool hay_escalera = false;
    int racha = 0;
    for (int c = 1; c <= 13; ++c) {
        if (cntCat[c] > 0) { racha++; } else { racha = 0; }
        if (racha >= 5) { hay_escalera = true; break; }
    }

    int pares = 0, tercia = 0, poker = 0;
    for (int c = 1; c <= 13; ++c) {
        if (cntCat[c] == 2) pares++;
        else if (cntCat[c] == 3) tercia++;
        else if (cntCat[c] == 4) poker++;
    }

    eval r; r.tipo = 0; r.puntaje = 0;

    // Póker
    if (poker > 0) {
        r.tipo = 7;
        r.puntaje = PTS_POKER;
        for (int c = 1; c <= 13; ++c) if (cntCat[c] == 4) r.puntaje += 4 * c;
        return r;
    }

    // Color + Escalera (NO se pide Escalera de color en pauta; se prioriza jerarquía simple)
    if (hay_color) {
        r.tipo = 5;
        r.puntaje = PTS_COLOR;
        // En Color “anotan” las 5 cartas (sumamos categorías de toda la jugada)
        for (int i = 0; i < cantidad; ++i) r.puntaje += jugada[i].categoria;
        return r;
    }
    if (hay_escalera) {
        r.tipo = 4;
        r.puntaje = PTS_ESCALERA;
        // Suma categorías de la escalera: aproximamos sumando categorías presentes (máx 5)
        int sum = 0, cont = 0;
        for (int c = 13; c >= 1 && cont < 5; --c) if (cntCat[c] > 0) { sum += c; cont++; }
        r.puntaje += sum;
        return r;
    }

    if (tercia > 0) {
        r.tipo = 3;
        r.puntaje = PTS_TERCIA;
        for (int c = 1; c <= 13; ++c) if (cntCat[c] == 3) r.puntaje += 3 * c;
        return r;
    }

    if (pares >= 2) {
        r.tipo = 2;
        r.puntaje = PTS_DOBLE_PAR;
        int pares_sumados = 0;
        for (int c = 13; c >= 1 && pares_sumados < 2; --c) {
            if (cntCat[c] == 2) { r.puntaje += 2 * c; pares_sumados++; }
        }
        return r;
    }

    if (pares == 1) {
        r.tipo = 1;
        r.puntaje = PTS_PAR;
        for (int c = 1; c <= 13; ++c) if (cntCat[c] == 2) r.puntaje += 2 * c;
        return r;
    }

    // Carta más alta
    r.tipo = 0;
    r.puntaje = PTS_CARTA_ALTA;
    int maxc = 0;
    for (int c = 1; c <= 13; ++c) if (cntCat[c] > 0 && c > maxc) maxc = c;
    r.puntaje += maxc;
    return r;
}