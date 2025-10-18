#include "comandos.h"

bool indices_validos(const lista& mano, const int posiciones[], int cantidad){
    int tamano_mano = length(mano);
    for(int i= 0; i<cantidad; i++){
        if(posiciones[i]<0 ||posiciones[i]>=tamano_mano){
            return false;
        }
    }
    return true;
}
bool copiar_cartas_por_posiciones(const lista& mano, const int posiciones[], int cantidad, carta cartas_salida[], int& cantidad_salida){
    if(indices_validos(mano, posiciones, cantidad)== false){
        cantidad_salida=0;
        return false;
    }
    cantidad_salida=0;
    for(int i=0;i<cantidad; i++){
        carta carta_temporal;
        bool exito= get(mano,posiciones[i], carta_temporal);
        if(exito==false){
            cantidad_salida=0;
            return false;
        }
        cartas_salida[cantidad_salida]=carta_temporal;
        cantidad_salida++;
    }
    return true;
}
void ordenar_posiciones_desc(int posiciones[], int cantidad){
    for(int i =1;i<cantidad;i++){
        int posicion_actual = posiciones[i];
        int j= i-1;
        while(j>=0 && posiciones[j]< posicion_actual){
            posiciones[j+1] = posiciones[j];
            j--;    
        }
        posiciones[j+1]= posicion_actual;
    }
}
void descartar_y_reponer(lista& mano, lista& mazo, int posiciones[], int cantidad, int cantidad_objetivo){
    if(indices_validos(mano, posiciones, cantidad)== false){
        return;
    }
    ordenar_posiciones_desc(posiciones, cantidad);
    for(int i=0; i<cantidad; i++){
        eraseen(mano, posiciones[i]);
    }
    reponerHasta(mazo, mano, cantidad_objetivo);
}
bool preparar_jugada(const lista& mano, const int posiciones[], int cantidad, carta jugada[], int& cantidad_jugada){
    return copiar_cartas_por_posiciones(mano, posiciones, cantidad, jugada, cantidad_jugada);

}
