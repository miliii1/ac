#include <stdio.h>
#include <stdlib.h>

// 1) Hacer una función que reciba un número entero y devuelva ese número al cuadrado.

int numAlCuadrado(int num);

int main()
{
    int num;
        printf("Ingrese un numero: ");
        scanf("%d", &num);

        int resultado = numAlCuadrado(num);
        printf("El cuadrado de %d es: %d\n", num, resultado);

        return 0;
}

int numAlCuadrado(int num) {
    return num * num;
}
