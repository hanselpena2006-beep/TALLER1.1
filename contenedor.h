#ifndef CONTENEDOR_H
#define CONTENEDOR_H

typedef struct {
    char nombre[50];
    int edad;
    float salario;
} Empleado;

void ingresarEmpleado(Empleado *e);
void mostrarEmpleado(Empleado e);

#endif