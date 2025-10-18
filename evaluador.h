#ifndef EVALUADOR_H
#define EVALUADOR_H

#include "carta.h"

struct eval{
    int tipo;
    int puntaje;
};

eval evaluar(const carta jugada[], int cantidad);
#endif