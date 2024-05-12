#include <stdio.h>
#include <stdlib.h>

/* 5) Diseñar un programa para imprimir el valor mínimo y máximo de un vector
de temperaturas de 30 muestras. Para ello, realizar dos funciones:
int mayorElemento (float vec[], int n);
int menorElemento (float vec[], int n);
Las funciones reciben el vector de floats y su tamaño y devuelven la posicion
del elemento mayor o menor respectivamente.
*/

int mayorElemento(float vec[], int n) {
    int posicion = 0;
    float maximo = vec[0];
    int i;
    for (i = 1; i < n; i++) {
        if (vec[i] > maximo) {
            maximo = vec[i];
            posicion = i;
        }
    }
    return posicion;
}

int menorElemento(float vec[], int n) {
    int posicion = 0;
    float minimo = vec[0];
    int i;
    for (i = 1; i < n; i++) {
        if (vec[i] < minimo) {
            minimo = vec[i];
            posicion = i;
        }
    }
    return posicion;
}

int main() {
    float temperaturas[30] = {20.5, 22.3, 18.9, 25.6, 19.7, 21.8, 23.4, 20.1, 24.5, 22.0,
                              20.8, 19.6, 25.1, 21.9, 23.2, 19.4, 22.7, 24.9, 18.2, 26.0,
                              23.8, 20.3, 22.6, 21.5, 24.0, 19.8, 21.2, 23.9, 20.6, 22.4};

    int posicion_maximo = mayorElemento(temperaturas, 30);
    int posicion_minimo = menorElemento(temperaturas, 30);

    printf("El valor m%cximo de temperatura es %.1f en la muestra %d.\n", 160, temperaturas[posicion_maximo], posicion_maximo + 1);
    printf("El valor m%cnimo de temperatura es %.1f en la muestra %d.\n", 161, temperaturas[posicion_minimo], posicion_minimo + 1);

    return 0;
}


