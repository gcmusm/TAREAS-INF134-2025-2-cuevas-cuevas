#include "mazo.h"

void cargarMazo(lista& mazo, const carta base[52], const int orden[52]){
    const int NUM = 52;
    clear(mazo);
    for(int pos=0; pos<NUM; pos++){
        int ibase= orden[pos];
        if(ibase>= 0 && ibase<NUM){
            append(mazo, base[ibase]);
        }
    }
}  

void repartir(lista& mazo, lista& mano, int n){
    int entregadas=0;
    bool haycartas = true;
    carta cartasacada;
    while(haycartas==true && entregadas<n){
        haycartas= popfront(mazo, cartasacada);
        if(haycartas==true){
            append(mano, cartasacada);
            entregadas++;
        }
    }

}

void reponerHasta(lista& mazo, lista& mano, int objetivo){
    if (objetivo<=0) 
        return;
    int actuales=length(mano); 
    while (actuales<objetivo) {
        carta c;
        if (!popfront(mazo,c)) 
            break;  
        append(mano,c);               
        actuales++;
    }
}

void moverTodo(lista& origen, lista& destino){
    carta c;
    while (popfront(origen,c)) {
        append(destino,c); 
    }
}