#include <stdio.h>
#include <stdlib.h>

// 2) Usar la funci�n del punto anterior para hacer una funci�n que reciba un n�mero entero y obtenga,
// si el n�mero la tiene, la ra�z cuadrada entera de ese n�mero, en caso contrario devolver� -1
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

