#include <stdio.h>
#include "funciones.h"


int main() {
    char opcion;
    do {
        printf("\nMenu:\n");
        printf("0. ingresar nuevo dato\n");
        printf("p. impresion de todos los datos ingresados, agrupados por lote\n");
        printf("l. imprimir el lote con mayor promedio de peso\n");
        printf("e. eliminar el animal de menor peso\n");
        printf("d. eliminar todos los animales registrados en un lote\n");
        printf("s. salir\n");
        printf("ingrese una opcion: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '0':
                ingresarNuevoDato();
                break;
            case 'p':
                imprimirDatosPorLote();
                break;
            case 'l':
                imprimirLoteConMayorPromedio();
                break;
            case 'e':
                eliminarAnimalMenorPeso();
                break;
            case 'd':
                eliminarAnimalesPorLote();
                break;
            case 's':
                printf("saliendo...\n");
                break;
            default:
                printf("opcion invalida\n");
        }
    } while (opcion != 's');

    return 0;
}
