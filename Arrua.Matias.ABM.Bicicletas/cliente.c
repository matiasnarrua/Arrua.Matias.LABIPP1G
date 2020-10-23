#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"


void listarClientes(eCliente clientes[], int tamCliente )
{

    printf("*****Listado de Clientes*****\n\n");
    printf("Id    Descripcion      Sexo\n");

    for(int i=0; i<tamCliente; i++)
    {
        printf("%d   %10s      %c\n",clientes[i].id, clientes[i].nombre, clientes[i].sexo);
    }
    printf("\n\n");
}



int validarCliente(int clientes)
{

    do
    {

        if(clientes <300 || clientes>309)
        {

            printf("\nError selecciones un id de clientes valido: ");
            scanf("%d", &clientes);
        }
    }
    while(clientes <300 || clientes>309);

    return clientes;
}
