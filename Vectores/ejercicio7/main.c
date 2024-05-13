#include <stdio.h>
#include <stdlib.h>

/*7) Diseñar una funcion que recibe un vector de N muestras y dos vectores de
tamaño N/2. La funcion guarda en sendos vectores las muestras mas bajas y
mas altas.
void partir (int * vector, int * menores, int * mayores, int n);
Si el tamaño del vector no es un numero par, la función indica un mensaje de
error y no parte el vector.*/


void partir(int *vector, int *menores, int *mayores, int n) {
    // verifico si el tamaño del vector es par
    if (n % 2 != 0) {
        printf("Error: El tamaño del vector no es par.\n");
        return;
    }

    // se ordena el vector de manera ascendente
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }

    // copio los primeros n/2 elementos al vector de menore
    for (int i = 0; i < n / 2; i++) {
        menores[i] = vector[i];
    }

    // copiar los ultimos n/2 elementos al vector de mayor
    for (int i = 0; i < n / 2; i++) {
        mayores[i] = vector[n / 2 + i];
    }
}

int main() {
    int vector[] = {3, 1, 4, 1, 5, 9}; // ejem de vector
    int n = sizeof(vector) / sizeof(vector[0]); // tamaño del vector

    // creo vectores para las muestras más bajas y más altas
    int menores [n / 2];
    int mayores [n / 2];

    partir(vector, menores, mayores, n);

    printf("Muestras m%cs bajas: ", 160);
    for (int i = 0; i < n / 2; i++) {
        printf("%d ", menores[i]);
    }
    printf("\n");

    printf("Muestras m%cs altas: ", 160);
    for (int i = 0; i < n / 2; i++) {
        printf("%d ", mayores[i]);
    }
    printf("\n");

    return 0;
}

