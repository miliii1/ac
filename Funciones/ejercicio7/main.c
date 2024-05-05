#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Ejercicio 7: Desarrolla un programa que genere la serie de Fibonacci hasta el término n ingresado por el usuario.
    int n, t1 = 0, t2 = 1, prev;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    printf("Serie de Fibonacci hasta el termino %d:\n", n);

    for(int i = 0; i <= n; i++) {
        printf("%d ", t1);
        prev = t1 + t2;
        t1 = t2;
        t2 = prev;
    }
    printf("\n");

    return 0;
}
