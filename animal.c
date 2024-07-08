#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"

Animal animales[MAX_ANIMALES];
   int cantidadAnimales = 0;


int compararPeso(const void *a, const void *b) {
    Animal *animalA = (Animal *)a;
    Animal *animalB = (Animal *)b;
    return (animalB->peso - animalA->peso);
}

void ordenarAnimalesPorLote(Animal * loteAnimales, int cantidad){
    qsort(loteAnimales, cantidad, sizeof(Animal), compararPeso);
}
