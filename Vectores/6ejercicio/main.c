#include <stdio.h>
#include <stdlib.h>

#define MAX_MUESTRAS 100


float calcularMedia(float muestras[], int n) {
    float suma = 0;
    int i;
    for (i = 0; i < n; i++) {
        suma += muestras[i];
    }
    return suma / n;
}

float medicionMasCercana(float muestras[], int n, float media) {
    float min_diferencia = muestras[0] - media > 0 ? muestras[0] - media : media - muestras[0];
    float valor_cercano = muestras[0];
    int i;
    for (i = 1; i < n; i++) {
        float diferencia = muestras[i] - media > 0 ? muestras[i] - media : media - muestras[i];
        if (diferencia < min_diferencia) {
            min_diferencia = diferencia;
            valor_cercano = muestras[i];
        }
    }
    return valor_cercano;
}

int main() {
    float muestras[MAX_MUESTRAS];
    int n = 0;

    // igreso de las muestras
    printf("Ingrese las muestras de presión (ingrese un número negativo para finalizar):\n");
    float presion;
    while (1) {
        printf("Muestra %d: ", n + 1);
        scanf("%f", &presion);
        if (presion < 0 || n >= MAX_MUESTRAS) {
            break;
        }
        muestras[n] = presion;
        n++;
    }

    if (n == 0) {
        printf("No se ingresaron muestras.\n");
        return 1;
    }

    float media = calcularMedia(muestras, n);
    printf("La media del conjunto es: %.2f\n", media);

    float mas_cercano = medicionMasCercana(muestras, n, media);
    printf("La medición más cercana a la media es: %.2f\n", mas_cercano);

    return 0;
}

