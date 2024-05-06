#include <stdio.h>
#include <stdlib.h>

//2) Hacer una función que detecte si un número es palíndromo. Dato: debe crear una función para convertir un entero en
// un vector de números cada uno correspondiente a un coeficiente de las potencias de 10 que componen el número.


int convertir_a_vector(int num, int digitos[]) {
    int num_digitos = 0;
    while (num > 0) {
        digitos[num_digitos] = num % 10;
        num /= 10;
        num_digitos++;
    }
    return num_digitos;
}

int es_palindromo(int num) {
    int digitos[20];
    int num_digitos = convertir_a_vector(num, digitos);


    for (int i = 0; i < num_digitos / 2; i++) {
        if (digitos[i] != digitos[num_digitos - i - 1]) {
            return 0;
        }
    }
    return 1; //
}


int main() {
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if (es_palindromo(numero)) {
        printf("El numero %d es palindromo.\n", numero);
    } else {
        printf("El numero %d no es palindromo.\n", numero);
    }

    return 0;
}

