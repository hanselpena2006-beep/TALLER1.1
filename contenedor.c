#include "contenedor.h"
#include <stdio.h>
#include <string.h>

void contenedor_leer(Contenedor *c) {
    printf("Ingrese codigo (4 caracteres): ");
    scanf("%4s", c->codigo);
    
    printf("Ingrese peso en toneladas: ");
    scanf("%f", &c->peso);
    getchar(); // limpiar el salto de línea
    
    printf("Ingrese tipo de mercancia: ");
    fgets(c->tipo, 50, stdin);
    c->tipo[strcspn(c->tipo, "\n")] = 0; // quitar el salto de línea
}

void contenedor_mostrar(const Contenedor *c) {
    printf("Codigo: %s | Peso: %.2f ton | Tipo: %s\n", 
           c->codigo, c->peso, c->tipo);
}
