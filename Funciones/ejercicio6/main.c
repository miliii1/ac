#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Ejercicio 6: Escribe un programa que pida al usuario un número e imprima si es un número primo o no utilizando un bucle for.

    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);

    for(int i = 2; i <= num / 2; i++) {
        if(num % i == 1) {
            printf("El numero es primo.\n");
        } else {
            printf("El numero no es primo.\n");
        }
    }

    return 0;
}
