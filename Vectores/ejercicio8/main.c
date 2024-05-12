#include <stdio.h>
#include <stdlib.h>

/*8) Diseñe una funcion que recibe un vector de enteros y su tamaño y devuelve
1 si hay al menos dos elementos duplicados y 0 en caso contrario.*/


int hayDuplicados(int vector[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (vector[i] == vector[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int vector1[] = {1, 2, 3, 4, 5};
    int vector2[] = {1, 2, 3, 4, 1};

    int n1 = sizeof(vector1) / sizeof(vector1[0]);
    int n2 = sizeof(vector2) / sizeof(vector2[0]);

    if (hayDuplicados(vector1, n1)) {
        printf("El primer vector tiene al menos dos elementos duplicados.\n");
    } else {
        printf("El primer vector no tiene elementos duplicados.\n");
    }

    if (hayDuplicados(vector2, n2)) {
        printf("El segundo vector tiene al menos dos elementos duplicados.\n");
    } else {
        printf("El segundo vector no tiene elementos duplicados.\n");
    }

    return 0;
}

