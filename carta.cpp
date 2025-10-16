#include "cards.h"
#include <cstdlib>

void generarbaraja(carta baraja[52]){
    const char palos[4] = {'C', 'T', 'E', 'D'};
    int pos=0;
    for(int p=0; p<4; p++){
        for(int c=1; c<=13; c++){
            baraja[pos].palo = palos[p];
            baraja[pos].categoria =c;
            if(c==1){
                baraja[pos].valor=11;
            }
            else if(c>=11){
                baraja[pos].valor =c;
            }
            else{
                baraja[pos].valor =c;
            }
            baraja[pos].jugada = false;
            pos++;
        }
    }
};

void barajarindices();