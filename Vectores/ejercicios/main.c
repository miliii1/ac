#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANIMALES 100

typedef struct {
    char id[20];
    float peso;
    int lote;
} Animal;

Animal animales[MAX_ANIMALES];
int cantidadAnimales = 0;

void ingresarNuevoDato() {
    if (cantidadAnimales >= MAX_ANIMALES) {
        printf("No se pueden ingresar más animales.\n");
        return;
    }

    Animal nuevoAnimal;
    printf("Ingrese el ID del animal: ");
    scanf("%s", nuevoAnimal.id);

    // Verificar si el animal ya está registrado
    for (int i = 0; i < cantidadAnimales; i++) {
        if (strcmp(animales[i].id, nuevoAnimal.id) == 0) {
            printf("Error: El animal ya está registrado.\n");
            return;
    }

    printf("Ingrese el peso del animal: ");
    scanf("%f", &nuevoAnimal.peso);

    printf("Ingrese el número de lote (0-3): ");
    scanf("%d", &nuevoAnimal.lote);

    if (nuevoAnimal.lote < 0 || nuevoAnimal.lote > 3) {
        printf("Error: Número de lote inválido.\n");
        return;
    }

    animales[cantidadAnimales] = nuevoAnimal;
    cantidadAnimales++;
}

int compararPeso(const void *a, const void *b) {
    Animal *animalA = (Animal *)a;
    Animal *animalB = (Animal *)b;
    return (animalB->peso - animalA->peso);
}

void imprimirDatosPorLote() {
    for (int lote = 0; lote <= 3; lote++) {
        printf("Lote %d:\n", lote);
        Animal loteAnimales[MAX_ANIMALES];
        int cantidadLoteAnimales = 0;

        for (int i = 0; i < cantidadAnimales; i++) {
            if (animales[i].lote == lote) {
                loteAnimales[cantidadLoteAnimales++] = animales[i];
            }
        }

        qsort(loteAnimales, cantidadLoteAnimales, sizeof(Animal), compararPeso);

        for (int i = 0; i < cantidadLoteAnimales; i++) {
            printf("  ID: %s, Peso: %.2f\n", loteAnimales[i].id, loteAnimales[i].peso);
        }
    }
}

void imprimirLoteConMayorPromedio() {
    float sumaPesos[4] = {0};
    int cantidadPorLote[4] = {0};

    for (int i = 0; i < cantidadAnimales; i++) {
        sumaPesos[animales[i].lote] += animales[i].peso;
        cantidadPorLote[animales[i].lote]++;
    }

    float mayorPromedio = -1;
    int loteMayorPromedio = -1;

    for (int lote = 0; lote <= 3; lote++) {
        if (cantidadPorLote[lote] > 0) {
            float promedio = sumaPesos[lote] / cantidadPorLote[lote];
            if (promedio > mayorPromedio) {
                mayorPromedio = promedio;
                loteMayorPromedio = lote;
            }
        }
    }

    if (loteMayorPromedio != -1) {
        printf("Lote con mayor promedio de peso: %d, Promedio: %.2f\n", loteMayorPromedio, mayorPromedio);
    } else {
        printf("No hay datos suficientes para calcular el promedio.\n");
    }
}

void eliminarAnimalMenorPeso() {
    if (cantidadAnimales == 0) {
        printf("No hay animales para eliminar.\n");
        return;
    }

    int indiceMenorPeso = 0;
    for (int i = 1; i < cantidadAnimales; i++) {
        if (animales[i].peso < animales[indiceMenorPeso].peso) {
            indiceMenorPeso = i;
        }
    }

    for (int i = indiceMenorPeso; i < cantidadAnimales - 1; i++) {
        animales[i] = animales[i + 1];
    }
    cantidadAnimales--;

    printf("Animal de menor peso eliminado.\n");
}

void eliminarAnimalesPorLote() {
    int lote;
    printf("Ingrese el número de lote a eliminar (0-3): ");
    scanf("%d", &lote);

    if (lote < 0 || lote > 3) {
        printf("Error: Número de lote inválido.\n");
        return;
    }

    int nuevaCantidadAnimales = 0;
    for (int i = 0; i < cantidadAnimales; i++) {
        if (animales[i].lote != lote) {
            animales[nuevaCantidadAnimales++] = animales[i];
        }
    }
    cantidadAnimales = nuevaCantidadAnimales;

    printf("Animales del lote %d eliminados.\n", lote);
}

int main() {
    char opcion;
    do {
        printf("\nMenu:\n");
        printf("1. Ingresar nuevo dato\n");
        printf("P. Impresión de todos los datos ingresados, agrupados por lote\n");
        printf("L. Imprimir el lote con mayor promedio de peso\n");
        printf("E. Eliminar el animal de menor peso\n");
        printf("D. Eliminar todos los animales registrados en un lote\n");
        printf("S. Salir\n");
        printf("Ingrese una opcion: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '1':
                ingresarNuevoDato();
                break;
            case 'P':
                imprimirDatosPorLote();
                break;
            case 'L':
                imprimirLoteConMayorPromedio();
                break;
            case 'E':
                eliminarAnimalMenorPeso();
                break;
            case 'D':
                eliminarAnimalesPorLote();
                break;
            case 'S':
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción Inválida\n");
        }
    } while (opcion != 'S');

    return 0;
}
