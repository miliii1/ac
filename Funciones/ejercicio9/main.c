#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Ejercicio 10: Escribe un programa que muestre los números primos del 1 al 100 utilizando un bucle while.

    int count = 0;
    for(int num = 2; num <= 100; num++) {
        for(int x = 2; x <= num; x++) {
            if(num % x == 0) {
                count++;
                if(count == 1) {
                    printf("%d-", num);
                    count = 0;
                }
            }
        }
    }

    return 0;
}
