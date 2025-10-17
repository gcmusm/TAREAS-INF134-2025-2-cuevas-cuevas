#include "carta.h"
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

void barajar(int orden[52]){
    for(int i=0, i<52, i++){ //llenamos la lista con  los indices de las cartas
        orden[i]=i;
    }
    srand(time(nullptr)); //definimos el valor de la semilla segun el reloj del pc 

    for(int i=51; i>0; i--){ //usamos algoritmo de fisher-yates para alterar aleatoriamente el orden de las cartas B-)
        int j= rand() %(i+1);
        int temp = orden[i];
        orden[i] = orden[j];
        orden[j] = temp;
    }
};