#include <stdio.h>
#include <stdlib.h>

/*9) Especial: Una funcion recibe dos vectores de flotantes del mismo tamaño 'n'
denominados x e y. Estos son valores de su dominio y de su imagen
respectivamente. La funcion imprime si los valores corresponden a una funcion
lineal y si es asi el valor de la ordenada al origen y la pendiente. En caso
contrario solo lo informa.
void comprobarLineal (float * x, float * y, int n);*/


void comprobarLineal(float *x, float *y, int n) {
    float sum_xy = 0, sum_x = 0, sum_y = 0, sum_x_squared = 0;
    for (int i = 0; i < n; i++) {
        sum_xy += x[i] * y[i];
        sum_x += x[i];
        sum_y += y[i];
        sum_x_squared += x[i] * x[i];
    }

    float m = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);

    float b = (sum_y - m * sum_x) / n;

    int lineal = 1;
    for (int i = 0; i < n; i++) {
        if (y[i] != m * x[i] + b) {
            lineal = 0;
            break;
        }
    }

    if (lineal) {
        printf("Los valores corresponden a una funci%cn lineal.\n", 162);
        printf("Pendiente (m): %.2f\n", m);
        printf("Ordenada al origen (b): %.2f\n", b);
    } else {
        printf("Los valores no corresponden a una funci%cn lineal.\n", 162);
    }
}

int main() {
    float x[] = {1, 2, 3, 4, 5};
    float y[] = {2, 4, 6, 8, 10};
    int n = sizeof(x) / sizeof(x[0]);

    comprobarLineal(x, y, n);

    return 0;
}

