#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Ingrese el tamaño del vector (n): ");
    scanf("%d", &n);

    int vector[n];

    // 2. Cargar el vector
    printf("\n--- Carga del Vector ---\n");
    for (i = 0; i < n; i++) {
        printf("Ingrese el elemento [%d]: ", i);
        scanf("%d", &vector[i]);
    }

    // 3. Mostrar el vector original
    printf("\n--- Vector Original ---\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    // 4. Ordenar el vector (Método Burbuja - Ascendente)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }

    // 5. Mostrar el vector ordenado
    printf("\n--- Vector Ordenado (Ascendente) ---\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    return 0;
}
