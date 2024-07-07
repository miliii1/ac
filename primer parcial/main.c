#include <stdio.h>
#include <string.h>

#define MAX_SOCIOS 200
#define MAX_ACTIVIDADES 20
#define MAX_NOMBRE 30
#define MAX_NOMBRE_ACTIVIDAD 20

typedef struct {
    int legajo;
    char nombre[MAX_NOMBRE];
    int edad;
} Socio;

typedef struct {
    int codigo;
    char nombre[MAX_NOMBRE_ACTIVIDAD];
    int inscritos;
} Actividad;

Socio socios[MAX_SOCIOS];
Actividad actividades[MAX_ACTIVIDADES];
int numSocios = 0;
int numActividades = 0;


void ingresarSocio() {
    if (numSocios >= MAX_SOCIOS) {
        printf("M%cximo de socios alcanzado.\n", 160);
        return;
    }
    Socio nuevo;
    printf("Ingrese legajo: ");
    scanf("%d", &nuevo.legajo);
    printf("Ingrese nombre: ");
    getchar(); //
    fgets(nuevo.nombre, MAX_NOMBRE, stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0';
    printf("Ingrese edad: ");
    scanf("%d", &nuevo.edad);
    socios[numSocios++] = nuevo;
    printf("Socio ingresado con %cxito.\n", 130);
}

void generarActividad() {
    if (numActividades >= MAX_ACTIVIDADES) {
        printf("M%cximo de actividades alcanzado.\n", 160);
        return;
    }
    Actividad nueva;
    printf("Ingrese c%cdigo de actividad: ", 162);
    scanf("%d", &nueva.codigo);
    printf("Ingrese nombre de la actividad: ");
    getchar();
    fgets(nueva.nombre, MAX_NOMBRE_ACTIVIDAD, stdin);
    nueva.nombre[strcspn(nueva.nombre, "\n")] = '\0'; // con esto elimin0 el salto de linea
    nueva.inscritos = 0;
    actividades[numActividades++] = nueva;
    printf("Actividad generada con %cxito.\n", 130);
}

void eliminarActividad() {
    int codigo;
    printf("Ingrese c%cdigo de la actividad a eliminar: ", 162);
    scanf("%d", &codigo);
    for (int i = 0; i < numActividades; ++i) {
        if (actividades[i].codigo == codigo) {
            for (int j = i; j < numActividades - 1; ++j) {
                actividades[j] = actividades[j + 1];
            }
            numActividades--;
            printf("Actividad eliminada con %cxito.\n", 130);
            return;
        }
    }
    printf("Actividad no encontrada.\n");
}

void asignarSocioAActividad() {
    int codigo, legajo;
    printf("lista de actividades:\n");
    for (int i = 0; i < numActividades; ++i) {
        printf("%d: %s\n", actividades[i].codigo, actividades[i].nombre);
    }
    printf("Ingrese c%cdigo de actividad: ", 162);
    scanf("%d", codigo);
    printf("Ingrese legajo del socio: ");
    scanf("%d", &legajo);
    for (int i = 0; i < numActividades; ++i) {
        if (actividades[i].codigo == codigo) {
            for (int j = 0; j < numSocios; ++j) {
                if (socios[j].legajo == legajo) {
                    actividades[i].inscritos++;
                    printf("Socio asignado a la actividad con %cxito.\n", 130);
                    return;
                }
            }
            printf("Socio no encontrado.\n");
            return;
        }
    }
    printf("Actividad no encontrada.\n");
}

void mostrarSociosInactivos() {
    printf("Socios inactivos:\n");
    for (int i = 0; i < numSocios; ++i) {
        int activo = 0;
        for (int j = 0; j < numActividades; ++j) {
            if (actividades[j].inscritos > 0) {
                activo = 1;
                break;
            }
        }
        if (!activo) {
            printf("%d: %s\n", socios[i].legajo, socios[i].nombre);
        }
    }
}

void listarActividades() {
    printf("listado de actividades:\n");
    for (int i = 0; i < numActividades; ++i) {
        for (int j = i + 1; j < numActividades; ++j) {
            if (actividades[i].inscritos < actividades[j].inscritos) {
                Actividad temp = actividades[i];
                actividades[i] = actividades[j];
                actividades[j] = tem;
            }
        }
        printf("C%cdigo: %d, Nombre: %s, Inscritos: %d\n" actividades[i].codigo, actividades[i].nombre, actividades[i].inscritos, 162);
    }
}

void mostrarMenu() {
    printf("Menu:\n");
    printf("1. Ingresar socio\n");
    printf("2. Generar actividad\n");
    printf("3. Eliminar actividad\n");
    printf("4. Asignar socio a actividad\n");
    printf("5. Mostrar socios inactivos\n");
    printf("6. Listar actividades\n");
    printf("7. Salir\n");
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        printf("Seleccione una opci%cn: ", 162);
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                ingresarSocio();
                break;
            case 2:
                generarActividad();
                break;
            case 3:
                eliminarActividad();
                break;
            case 4:
                asignarSocioAActividad();
                break;
            case 5:
                mostrarSociosInactivos();
                break;
            case 6:
                listarActividades();
                break;
            case 7:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opci%cn no válida.\n", 162);
        }
    } while (opcion != 7);
    return 0;
}
