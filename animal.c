#include <stdio.h>
#include <string.h>

#define MAX_LONG 50 // Longitud máxima para cada nombre

// Declaración de funciones
void cargarNombres(int tam, char nombres[][MAX_LONG]);
void mostrarNombres(int tam, char nombres[][MAX_LONG]);
void ordenarNombres(int tam, char nombres[][MAX_LONG]);

int main() {
    int n;

    printf("Ingrese la cantidad de nombres (n): ");
    scanf("%d", &n);
    getchar(); // Limpia el buffer del salto de línea de scanf

    char nombres[n][MAX_LONG];

    printf("\n--- Carga de Nombres ---\n");
    cargarNombres(n, nombres);

    printf("\n--- Lista Original ---\n");
    mostrarNombres(n, nombres);

    ordenarNombres(n, nombres);

    printf("\n--- Lista Ordenada Alfabeticamente ---\n");
    mostrarNombres(n, nombres);

    return 0;
}

// Función para pedir los nombres
void cargarNombres(int tam, char nombres[][MAX_LONG]) {
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el nombre [%d]: ", i + 1);
        fgets(nombres[i], MAX_LONG, stdin);
        
        // Remover el salto de linea ('\n') que deja fgets al presionar Enter
        nombres[i][strcspn(nombres[i], "\n")] = '\0';
    }
}

// Función para mostrar los nombres
void mostrarNombres(int tam, char nombres[][MAX_LONG]) {
    for (int i = 0; i < tam; i++) {
        printf("%d. %s\n", i + 1, nombres[i]);
    }
}

// Función para ordenar alfabéticamente (Método Burbuja con cadenas)
void ordenarNombres(int tam, char nombres[][MAX_LONG]) {
    char temp[MAX_LONG];
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            // strcmp retorna un valor > 0 si la primera cadena es alfabéticamente mayor
            if (strcmp(nombres[j], nombres[j + 1]) > 0) {
                // Intercambio de cadenas usando strcpy
                strcpy(temp, nombres[j]);
                strcpy(nombres[j], nombres[j + 1]);
                strcpy(nombres[j + 1], temp);
            }
        }
    }
}
