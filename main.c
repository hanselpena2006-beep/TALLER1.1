#include <stdio.h>
#include "patio.h"

void mostrar_menu() {
    printf("========== SISTEMA DE GESTION DE PATIO DE CONTENEDORES ==========\n");
    printf("1. Agregar contenedor\n");
    printf("2. Retirar contenedor (FIFO)\n");
    printf("3. Mostrar todos los contenedores\n");
    printf("4. Salir\n");
    printf("=================================================================\n");
    printf("Seleccione una opcion: ");
}

int main() {
    Patio patio;
    patio_inicializar(&patio);
    int opcion;
    Contenedor c;

    do {
        mostrar_menu();
        if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n'); // Limpiar entrada inválida
            opcion = 0;
        }
        getchar();

        switch (opcion) {
            case 1:
                printf("\n--- Agregar Nuevo Contenedor ---\n");
                contenedor_leer(&c);
                patio_agregar(&patio, &c);
                printf("\n");
                break;

            case 2:
                printf("\n--- Retirar Contenedor ---\n");
                if (patio_retirar(&patio, &c)) {
                    printf("Retirado: ");
                    contenedor_mostrar(&c);
                }
                printf("\n");
                break;

            case 3:
                patio_mostrar_todos(&patio);
                break;

            case 4:
                printf("👋 Saliendo del sistema... Hasta luego.\n");
                break;

            default:
                printf("❌ Opcion invalida. Intente nuevamente.\n\n");
        }
    } while (opcion != 4);

    return 0;
}
