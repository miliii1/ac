#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
  #include <windows.h>
  #define SLEEP(ms) Sleep(ms)
  #define CLEAR() system("cls")
#else
  #include <unistd.h>
  #define SLEEP(ms) usleep((ms) * 1000)
  #define CLEAR() system("clear")
#endif

#define NOMBRE  "Mila Dainn"
#define GMAIL   "tucorreo@gmail.com"       // <- Reemplazá con tu Gmail
#define GITHUB  "github.com/tu-usuario"    // <- Reemplazá con tu GitHub

void escribir_lento(const char *texto, int delay_ms) {
    for (int i = 0; texto[i] != '\0'; i++) {
        putchar(texto[i]);
        fflush(stdout);
        SLEEP(delay_ms);
    }
}

void separador_animado(int largo, int delay_ms) {
    for (int i = 0; i < largo; i++) {
        putchar('=');
        fflush(stdout);
        SLEEP(delay_ms);
    }
    putchar('\n');
}

void loading() {
    const char *frames[] = { "[=   ]", "[==  ]", "[=== ]", "[====]", "[ ===]", "[  ==]", "[   =]" };
    int total = 7;
    printf("\n  Cargando perfil ");
    for (int i = 0; i < 18; i++) {
        printf("\b\b\b\b\b\b\b%s", frames[i % total]);
        fflush(stdout);
        SLEEP(100);
    }
    printf("\b\b\b\b\b\b\b [LISTO]\n\n");
    SLEEP(400);
}

void presentacion() {
    CLEAR();

    /* ASCII art */
    printf("\n");
    escribir_lento("  ███╗   ███╗██╗██╗      █████╗ \n", 5);
    escribir_lento("  ████╗ ████║██║██║     ██╔══██╗\n", 5);
    escribir_lento("  ██╔████╔██║██║██║     ███████║\n", 5);
    escribir_lento("  ██║╚██╔╝██║██║██║     ██╔══██║\n", 5);
    escribir_lento("  ██║ ╚═╝ ██║██║███████╗██║  ██║\n", 5);
    escribir_lento("  ╚═╝     ╚═╝╚═╝╚══════╝╚═╝  ╚═╝\n", 5);
    printf("\n");

    loading();

    separador_animado(48, 20);
    escribir_lento("       *** TARJETA DE PRESENTACION ***\n", 30);
    separador_animado(48, 20);

    SLEEP(200);
    escribir_lento("\n  >> Nombre  : ", 30);
    escribir_lento(NOMBRE, 60);

    SLEEP(200);
    escribir_lento("\n  >> Gmail   : ", 30);
    escribir_lento(GMAIL, 40);

    SLEEP(200);
    escribir_lento("\n  >> GitHub  : ", 30);
    escribir_lento(GITHUB, 40);

    printf("\n\n");
    separador_animado(48, 20);

    SLEEP(300);
    escribir_lento("\n  Hola! Soy ", 40);
    escribir_lento(NOMBRE, 80);
    escribir_lento(", bienvenido/a a mi perfil!\n\n", 40);

    separador_animado(48, 20);
    printf("\n");
}

int main() {
    presentacion();
    return 0;
}
