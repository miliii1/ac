#include <stdio.h>
#include <stdlib.h>

//4) Crear una función que sume todos los números de un vector hasta encontrar un 0.

int sumarVector(int vector[], int longitud) {
    int suma = 0;
    int i;
    for (i = 0; i < longitud && vector[i] != 0; i++) {
        suma += vector[i];
    }
    return suma;
}

int main() {
    int vector[] = {1, 2, 3, 4, 5, 0, 6, 7, 8}; // Ejemplo de vector
    int longitud = sizeof(vector) / sizeof(vector[0]); // Calculamos la longitud del vector
    int resultado = sumarVector(vector, longitud); // Llamamos a la función para sumar
    printf("La suma de los n%cmeros del vector hasta encontrar un 0 es: %d\n", 163, resultado);
    return 0;
}

