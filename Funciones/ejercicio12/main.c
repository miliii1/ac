#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ingresarAnios();
int ingresarCantidadIndividuos();
bool esPrimo(int numero);
void imprimirResultados(float porcentajePrimos, float promedioPrimos, float promedioNoPrimos);

int main() {
    int primerAparicion, segundaAparicion, cantidadIndividuos;
    int sumaPrimos = 0, sumaNoPrimos = 0;
    int cantidadPrimos = 0, cantidadNoPrimos = 0;
    float promedioPrimos = 0.0, promedioNoPrimos = 0.0;

    do {
        primerAparicion = ingresarAnios();
        if (primerAparicion == 0) {
            break;
        }

        segundaAparicion = ingresarAnios();

        if (segundaAparicion <= primerAparicion) {
            printf("Error: El a�o de la segunda aparici�n debe ser mayor que el a�o de la primera aparici�n.\n");
            continue;
        }

        cantidadIndividuos = ingresarCantidadIndividuos();

        if (esPrimo(segundaAparicion - primerAparicion)) {
            sumaPrimos += cantidadIndividuos;
            cantidadPrimos++;
        } else {
            sumaNoPrimos += cantidadIndividuos;
            cantidadNoPrimos++;
        }
    } while (primerAparicion != 0);

    float porcentajePrimos = 0.0;
    if (cantidadPrimos > 0 && cantidadNoPrimos > 0) {
        porcentajePrimos = ((float)cantidadPrimos / (cantidadPrimos + cantidadNoPrimos)) * 100;
    }

    if (cantidadPrimos > 0) {
        promedioPrimos = (float)sumaPrimos / cantidadPrimos;
        printf("El promedio de cantidad de individuos para poblaciones que estuvieron bajo tierra un n�mero primo de a�os es: %.2f\n", promedioPrimos);
    }

    if (cantidadNoPrimos > 0) {
        promedioNoPrimos = (float)sumaNoPrimos / cantidadNoPrimos;
        printf("El promedio de cantidad de individuos para poblaciones que estuvieron bajo tierra un n�mero no primo de a�os es: %.2f\n", promedioNoPrimos);
    }

    imprimirResultados(porcentajePrimos, promedioPrimos, promedioNoPrimos);
    printf("Programa finalizado\n"); // Mensaje de depuraci�n


    return 0;
}

int ingresarAnios() {
    int anios;
    do {
        printf("Ingrese el a�o de la aparici�n de poblaci�n adulta (0 para terminar): ");
        scanf("%d", &anios);
        if (anios < 0) {
            printf("Error: El a�o debe ser un n�mero positivo.\n");
        }
    } while (anios < 0);
    return anios;
}

int ingresarCantidadIndividuos() {
    int cantidad;
    do {
        printf("Ingrese la cantidad estimada de individuos: ");
        scanf("%d", &cantidad);
        if (cantidad <= 0) {
            printf("Error: La cantidad debe ser un n�mero positivo.\n");
        }
    } while (cantidad <= 0);
    return cantidad;
}

bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }
    if (numero == 2) {
        return true;
    }
    if (numero % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= numero; i += 2) {
        if (numero % i == 0) {
            printf("%d no es primo\n", numero);
            return false;
        }
    }
    printf("%d es primo\n", numero);
    return true;
}


void imprimirResultados(float porcentajePrimos, float promedioPrimos, float promedioNoPrimos) {
    printf("El porcentaje de poblaciones para las que han transcurrido una cantidad de a�os primo entre la primera y segunda aparici�n es: %.2f%%\n", porcentajePrimos);
}

