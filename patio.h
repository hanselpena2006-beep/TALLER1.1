#ifndef PATIO_H
#define PATIO_H

#include "contenedor.h"

#define MAX_CONTENEDORES 5  // Capacidad máxima del patio

typedef struct {
    Contenedor lista[MAX_CONTENEDORES];
    int cantidad;  // Cuántos hay actualmente
} Patio;

// Prototipos
void patio_inicializar(Patio *p);
int patio_agregar(Patio *p, const Contenedor *c);
int patio_retirar(Patio *p, Contenedor *c);
void patio_mostrar_todos(const Patio *p);
int patio_esta_lleno(const Patio *p);
int patio_esta_vacio(const Patio *p);

#endif
