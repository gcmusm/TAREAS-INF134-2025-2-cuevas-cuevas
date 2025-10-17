#ifndef CARTA_H
#define CARTA_H

struct carta {
    char palo;
    int categoria;
    int valor;
    bool jugada;
};

void generarbaraja(carta baraja[52]);
void barajar(int orden[52]);

#endif