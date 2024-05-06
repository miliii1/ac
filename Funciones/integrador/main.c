#include <stdio.h>
#include <stdbool.h>

// Prototipos de funciones
int ingresarAnio(const char* mensaje);
int ingresarCantidad(const char* mensaje);
bool esPrimo(int numero);
void imprimirResultados(float porcentajePrimos, float promedioPrimos, float promedioNoPrimos);

// Función para verificar si un número es primo
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
        primerAparicion = ingresarAnio("Ingrese el año de la aparición de población adulta (0 para terminar): ");
        if (primerAparicion == 0) {
            break;
        }

        segundaAparicion = ingresarAnio("Ingrese el año de la segunda aparición: ");

        if (segundaAparicion <= primerAparicion) {
            printf("Error: El año de la segunda aparición debe ser mayor que el año de la primera aparición.\n");
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

// Función para ingresar años y cantidades
int ingresarAnio(const char* mensaje) {
    int anio;
    do {
        printf("%s", mensaje);
        if (scanf("%d", &anio) != 1) {
            printf("Error: Entrada no válida. Por favor, ingrese un número.\n");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            continue;
        }
        if (anio < 0) {
            printf("Error: El año debe ser un número positivo.\n");
        }
    } while (anio < 0);
    return anio;
}

int ingresarCantidad(const char* mensaje) {
    int cantidad;
    do {
        printf("%s", mensaje);
        if (scanf("%d", &cantidad) != 1) {
            printf("Error: Entrada no válida. Por favor, ingrese un número.\n");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            continue;
        }
        if (cantidad <= 0) {
            printf("Error: La cantidad debe ser un número positivo y mayor que cero.\n");
        }
    } while (cantidad <= 0);
    return cantidad;
}

// Función para imprimir los resultados
void imprimirResultados(float porcentajePrimos, float promedioPrimos, float promedioNoPrimos) {
    printf("El porcentaje de poblaciones para las que han transcurrido una cantidad de años primo entre la primera y segunda aparición es: %.2f%%\n", porcentajePrimos);
    printf("El promedio de cantidad de individuos para poblaciones que estuvieron bajo tierra un número primo de años es: %.2f\n", promedioPrimos);
    printf("El promedio de cantidad de individuos para poblaciones que estuvieron bajo tierra un número no primo de años es: %.2f\n", promedioNoPrimos);
}
