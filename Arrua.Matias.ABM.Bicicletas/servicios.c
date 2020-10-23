#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"servicios.h"


void listarServicios(eServicio servicios[], int tamSer )
{

    printf("*****Listado de Servicios*****\n\n");
    printf("Id    Descripcion     Precio\n");

    for(int i=0; i<tamSer; i++)
    {
        printf("%d   %10s  %4d\n",servicios[i].id, servicios[i].descripcion, servicios[i].precio);
    }
    printf("\n\n");
}



int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tamSer )
{

    int todoOk = 0;
    for(int i=0; i <tamSer; i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(descripcion, servicios[i].descripcion);
            todoOk = 1;

        }

    }
    return todoOk;
}

int validarServicio(int servicio)
{

    do
    {

        if(servicio <5000 || servicio>5004)
        {

            printf("\nError selecciones un id de servicio valido: ");
            scanf("%d", &servicio);
        }
    }
    while(servicio <20000 || servicio>20003);

    return servicio;
}
