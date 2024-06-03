#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLEADOS 30
#define MAX_NOMBRE 40

typedef struct {
    char dni[10];
    char nombre[MAX_NOMBRE];
    float salario;
} Empleado;

void cargarEmpleados(Empleado empleados[], int *n) {
    strcpy(empleados[0].dni, "12345678");
    strcpy(empleados[0].nombre, "Perez Juan");
    empleados[0].salario = 2500.00;

    strcpy(empleados[1].dni, "87654321");
    strcpy(empleados[1].nombre, "Gomez Ana");
    empleados[1].salario = 3000.00;

    // C
    *n = 2; 
}

void buscarEmpleado(Empleado empleados[], int n) {
    char nombreBusqueda[MAX_NOMBRE];
    printf("Ingrese Apellido y Nombre para buscar (o FIN para terminar): ");
    gets(nombreBusqueda);

    while (strcmp(nombreBusqueda, "FIN") != 0) {
        int encontrado = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(empleados[i].nombre, nombreBusqueda) == 0) {
                printf("DNI: %s, Salario: %.2f\n", empleados[i].dni, empleados[i].salario);
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("Empleado no encontrado.\n");
        }
        printf("Ingrese Apellido y Nombre para buscar (o FIN para terminar): ");
        gets(nombreBusqueda);
    }
}

int compararEmpleados(const void *a, const void *b) {
    Empleado *empleadoA = (Empleado *)a;
    Empleado *empleadoB = (Empleado *)b;
    return strcmp(empleadoA->nombre, empleadoB->nombre);
}

void mostrarEmpleadosOrdenados(Empleado empleados[], int n) {
    qsort(empleados, n, sizeof(Empleado), compararEmpleados);
    printf("DNI\t\tApellido y Nombre\tSalario\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t%.2f\n", empleados[i].dni, empleados[i].nombre, empleados[i].salario);
    }
}

int main() {
    Empleado empleados[MAX_EMPLEADOS];
    int n;

    cargarEmpleados(empleados, &n);
    buscarEmpleado(empleados, n);
    mostrarEmpleadosOrdenados(empleados, n);

    return 0;
}

