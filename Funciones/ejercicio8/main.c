#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Ejercicio 8: Desarrolla un programa que cuente cuántos dígitos tiene un número ingresado por el usuario.


    // con switch
    /*
    int n;

    printf("Introduzca un numero entero: ");
    scanf("%d", &n);

    switch(n) {
    case 0 ... 9:
        printf("Tiene 1 digito");
        break;
    case 10 ... 99:
        printf("Tiene 2 digitos");
        break;
    case 100 ... 999:
        printf("Tiene 3 digitos");
        break;
    default:
        printf("Tiene m%cs de 3 digitos");
    }
    return 0;
    */

    // con while

    float a;
    int s = 0;
    printf("Ingrese un numero: ");
    scanf("%f", &a);

    if(a == 0) {
        printf("El numero tiene 1 cifra");
        return 0;
    }
    while(a != 0) {
        if(a > 10 || a < -10) {
            a = a / 10;
            s = s + 1;
        } else {
            break;
     }
 }
    printf("El numero tiene %d cifra(s)\n", s);
    return 0;

}


