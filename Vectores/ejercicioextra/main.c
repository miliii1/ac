#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUMNOS 25
#define MAX_LEGAJO_LENGTH 10

//se define de la estructura para un alumno
typedef struct {
    char legajo[MAX_LEGAJO_LENGTH];
    float nota_parcial1;
    float nota_parcial2;
    float promedio;
} Alumno;

int compararPromedios(const void *a, const void *b) {
    Alumno *alumno_a = (Alumno *)a;
    Alumno *alumno_b = (Alumno *)b;
    if (alumno_a->promedio < alumno_b->promedio) return 1;
    if (alumno_a->promedio > alumno_b->promedio) return -1;
    return 0;
}

int compararLegajos(const void *a, const void *b) {
    Alumno *alumno_a = (Alumno *)a;
    Alumno *alumno_b = (Alumno *)b;
    return strcmp(alumno_a->legajo, alumno_b->legajo);
}

void cargarAlumno(Alumno *alumno) {
    printf("Ingrese el número de legajo del alumno: ");
    scanf("%s", alumno->legajo);
    printf("Ingrese la nota del primer parcial: ");
    scanf("%f", &alumno->nota_parcial1);
    printf("Ingrese la nota del segundo parcial: ");
    scanf("%f", &alumno->nota_parcial2);
    alumno->promedio = (alumno->nota_parcial1 + alumno->nota_parcial2) / 2;
}

// Función para imprimir un alumno
void imprimirAlumno(Alumno alumno) {
    printf("Legajo: %s, Nota Parcial 1: %.2f, Nota Parcial 2: %.2f, Promedio: %.2f\n",
           alumno.legajo, alumno.nota_parcial1, alumno.nota_parcial2, alumno.promedio);
}

void buscarAlumnoPorLegajo(Alumno alumnos[], int n, char legajo[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(alumnos[i].legajo, legajo) == 0) {
            imprimirAlumno(alumnos[i]);
            return;
        }
    }
    printf("No se encontró ningún alumno con el legajo %s.\n", legajo);
}

int main() {
    Alumno alumnos[MAX_ALUMNOS];
    int num_alumnos = 0;

    for (int i = 0; i < MAX_ALUMNOS; i++) {
        printf("Ingrese los datos del alumno %d:\n", i + 1);
        cargarAlumno(&alumnos[i]);
        num_alumnos++;
    }

    qsort(alumnos, num_alumnos, sizeof(Alumno), compararPromedios);

    printf("\nListado de alumnos por promedio de notas de mayor a menor:\n");
    for (int i = 0; i < num_alumnos; i++) {
        imprimirAlumno(alumnos[i]);
    }

    qsort(alumnos, num_alumnos, sizeof(Alumno), compararLegajos);

    printf("\nListado de alumnos por legajo de menor a mayor:\n");
    for (int i = 0; i < num_alumnos; i++) {
        imprimirAlumno(alumnos[i]);
    }

    char legajo_buscar[MAX_LEGAJO_LENGTH];
    printf("\nIngrese el legajo del alumno que desea buscar: ");
    scanf("%s", legajo_buscar);
    buscarAlumnoPorLegajo(alumnos, num_alumnos, legajo_buscar);

    return 0;
}
