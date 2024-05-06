#include <stdio.h>
#include <stdbool.h>

// Prototipos de funciones
int ingresarAnio(const char* mensaje);
int ingresarCantidad(const char* mensaje);
bool esPrimo(int numero);
void imprimirResultados(float porcentajePrimos, float promedioPrimos, float promedioNoPrimos);

// Funci�n para verificar si un n�mero es primo
bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int primerAparicion, segundaAparicion, cantidadIndividuos;
    int sumaPrimos = 0, sumaNoPrimos = 0;
    int cantidadPrimos = 0, cantidadNoPrimos = 0;
    float promedioPrimos = 0.0, promedioNoPrimos = 0.0;

    while (1) {
        primerAparicion = ingresarAnio("Ingrese el a�o de la aparici�n de poblaci�n adulta (0 para terminar): ");
        if (primerAparicion == 0) {
            break;
        }

        segundaAparicion = ingresarAnio("Ingrese el a�o de la segunda aparici�n: ");

        if (segundaAparicion <= primerAparicion) {
            printf("Error: El a�o de la segunda aparici�n debe ser mayor que el a�o de la primera aparici�n.\n");
            continue;
        }

        cantidadIndividuos = ingresarCantidad("Ingrese la cantidad estimada de individuos: ");

        if (esPrimo(segundaAparicion - primerAparicion)) {
            sumaPrimos += cantidadIndividuos;
            cantidadPrimos++;
        } else {
            sumaNoPrimos += cantidadIndividuos;
            cantidadNoPrimos++;
        }
    }

    if (cantidadPrimos > 0) {
        promedioPrimos = (float) sumaPrimos / cantidadPrimos;
    }

    if (cantidadNoPrimos > 0) {
        promedioNoPrimos = (float) sumaNoPrimos / cantidadNoPrimos;
    }

    imprimirResultados((float) cantidadPrimos / (cantidadPrimos + cantidadNoPrimos) * 100, promedioPrimos, promedioNoPrimos);

    printf("Programa finalizado.\n");

    return 0;
}

// Funci�n para ingresar a�os y cantidades
int ingresarAnio(const char* mensaje) {
    int anio;
    do {
        printf("%s", mensaje);
        if (scanf("%d", &anio) != 1) {
            printf("Error: Entrada no v�lida. Por favor, ingrese un n�mero.\n");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            continue;
        }
        if (anio < 0) {
            printf("Error: El a�o debe ser un n�mero positivo.\n");
        }
    } while (anio < 0);
    return anio;
}

int ingresarCantidad(const char* mensaje) {
    int cantidad;
    do {
        printf("%s", mensaje);
        if (scanf("%d", &cantidad) != 1) {
            printf("Error: Entrada no v�lida. Por favor, ingrese un n�mero.\n");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            continue;
        }
        if (cantidad <= 0) {
            printf("Error: La cantidad debe ser un n�mero positivo y mayor que cero.\n");
        }
    } while (cantidad <= 0);
    return cantidad;
}

// Funci�n para imprimir los resultados
void imprimirResultados(float porcentajePrimos, float promedioPrimos, float promedioNoPrimos) {
    printf("El porcentaje de poblaciones para las que han transcurrido una cantidad de a�os primo entre la primera y segunda aparici�n es: %.2f%%\n", porcentajePrimos);
    printf("El promedio de cantidad de individuos para poblaciones que estuvieron bajo tierra un n�mero primo de a�os es: %.2f\n", promedioPrimos);
    printf("El promedio de cantidad de individuos para poblaciones que estuvieron bajo tierra un n�mero no primo de a�os es: %.2f\n", promedioNoPrimos);
}
