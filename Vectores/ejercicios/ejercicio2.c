#include <stdio.h>
#include <stdbool.h>

// Función para convertir un número en un vector de dígitos
int convertir_a_vector(int num, int digitos[]) {
    int num_digitos = 0;
    while (num > 0) {
        digitos[num_digitos] = num % 10;
        num /= 10;
        num_digitos++;
    }
    return num_digitos;
}

// Función para determinar si un número es palíndromo
int es_palindromo(int num) {
    int digitos[20]; // Se asume que el número tiene menos de 20 dígitos
    int num_digitos = convertir_a_vector(num, digitos);

    // Comprobación de palíndromo
    for (int i = 0; i < num_digitos / 2; i++) {
        if (digitos[i] != digitos[num_digitos - i - 1]) {
            return 0; // Falso
        }
    }
    return 1; // Verdadero
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

