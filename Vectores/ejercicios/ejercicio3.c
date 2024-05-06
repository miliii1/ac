#include <stdio.h>
#include <stdlib.h>

void enteroAVector(int numero, int vector[], int *largo) {
    *largo = 0;
    while (numero > 0) {
        vector[*largo] = numero % 10;
        numero /= 10;
        (*largo)++;
    }
}

int esPalindromo(int numero) {
    int vector[20]; // Se asume que el n�mero tiene menos de 20 d�gitos
    int largo = 0;
    enteroAVector(numero, vector, &largo);

    int inicio = 0;
    int fin = largo - 1;

    while (inicio < fin) {
        if (vector[inicio] != vector[fin]) {
            return 0; // No es pal�ndromo
        }
        inicio++;
        fin--;
    }

    return 1; // Es pal�ndromo
}

int main() {
    int numero = 12321;

    if (esPalindromo(numero)) {
        printf("%d es un pal�ndromo.\n", numero);
    } else {
        printf("%d no es un pal�ndromo.\n", numero);
    }

    return 0;
}
