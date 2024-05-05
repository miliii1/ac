#include <stdio.h>
#include <stdlib.h>

// 2) Usar la función del punto anterior para hacer una función que reciba un número entero y obtenga,
// si el número la tiene, la raíz cuadrada entera de ese número, en caso contrario devolverá -1
double numAlCuadrado(int num);

int main()
{
    int num;
        printf("Ingrese un numero: ");
        scanf("%d", &num);

        double resultado = numAlCuadrado(num);
        if(resultado == -1) {
             printf("El numero no es valido.");
        } else {
             printf("El cuadrado de %d es: %d\n", num, resultado);
             printf("La raiz cuadrada de %d es: %.21f\n", num, sqrt(resultado));
        }

        return 0;
}

double numAlCuadrado(int num) {
    if(num < 0) {
        return -1;
    } else {
        return (double)num * num;
    }
}

