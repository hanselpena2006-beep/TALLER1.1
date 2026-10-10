#include "patio.h"
#include <stdio.h>

void patio_inicializar(Patio *p) {
    p->cantidad = 0;
}

int patio_esta_lleno(const Patio *p) {
    return p->cantidad >= MAX_CONTENEDORES;
}

int patio_esta_vacio(const Patio *p) {
    return p->cantidad == 0;
}

// Agrega al final (FIFO)
int patio_agregar(Patio *p, const Contenedor *c) {
    if (patio_esta_lleno(p)) {
        printf("⚠️  El patio esta LLENO. No se puede agregar mas contenedores.\n");
        return 0; // Fallo
    }
    p->lista[p->cantidad] = *c;
    p->cantidad++;
    printf("✅ Contenedor agregado correctamente.\n");
    return 1; // Éxito
}

// Retira el primero que entró (FIFO)
int patio_retirar(Patio *p, Contenedor *c) {
    if (patio_esta_vacio(p)) {
        printf("⚠️  El patio esta VACIO.\n");
        return 0;
    }
    // Guardar el que sale
    *c = p->lista[0];
    // Desplazar todos hacia adelante
    for (int i = 0; i < p->cantidad - 1; i++) {
        p->lista[i] = p->lista[i + 1];
    }
    p->cantidad--;
    printf("✅ Contenedor retirado.\n");
    return 1;
}

void patio_mostrar_todos(const Patio *p) {
    if (patio_esta_vacio(p)) {
        printf("📋 El patio no tiene contenedores registrados.\n");
        return;
    }
    printf("\n=== Contenedores en el Patio (%d/%d) ===\n", 
           p->cantidad, MAX_CONTENEDORES);
    for (int i = 0; i < p->cantidad; i++) {
        printf("[%d] ", i + 1);
        contenedor_mostrar(&p->lista[i]);
    }
    printf("=========================================\n\n");
}
