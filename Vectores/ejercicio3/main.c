#include <stdio.h>
#include <stdlib.h>

/*
3) Dise�ar una funci�n que dados dos vectores y su largo devuelva el producto
escalar modificando un tercer par�metro de la misma. El valor de retorno se
utilizar� para informar con 1 si la operaci�n se pudo realizar o 0 si el largo de
los vectores no permiti� realizar la operaci�n.
int productoEscalar(int x[], unsigned int largoX, int y[], unsigned int
largoY, int *error);

//////////////////////////////////////////////////////////////////////////////////////////////
esta funcio�n toma dos vectores x e y, junto con sus longitudes, y un puntero a un entero error para indicar si
la operaci�n fue exitosa o no. Retorna el producto escalar de los dos vectores si tienen la misma longitud,
de lo contrario, actualiza el par�metro de error y devuelve 0.

*/

int productoEscalar(int x[], unsigned int largoX, int y[], unsigned int largoY, int *error) {
    // verificar si los vectores tienen la misma longitud
    if (largoX != largoY) {
        *error = 0; // indica que la operaci�n no se pudo realizar
        return 0;   // devuelve 0 para indicar que la operaci�n no se pudo realizar
    }

    // calcula el producto escalar
    int producto = 0;
    for (unsigned int i = 0; i < largoX; i++) {
        producto += x[i] * y[i];
    }

    // se actualiza el parametro de error
    *error = 1; // idicar que la operaci�n se realiz� con �xito

    return producto; // devuelve el producto escalar
}

int main() {
    int vector1[] = {1, 2, 3};
    int vector2[] = {4, 5, 6};
    unsigned int longitud1 = sizeof(vector1) / sizeof(vector1[0]);
    unsigned int longitud2 = sizeof(vector2) / sizeof(vector2[0]);

    int error;
    int resultado = productoEscalar(vector1, longitud1, vector2, longitud2, &error);

    if (error) {
        printf("El producto escalar es: %d\n", resultado);
    } else {
        printf("No se pudo realizar el producto escalar debido a longitudes diferentes.\n");
    }

    return 0;
}
