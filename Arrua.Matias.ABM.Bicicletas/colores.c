
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bicicletas.h"
#include "trabajos.h"
#include "tipo.h"
#include "colores.h"



void listarColores(eColor colores[], int tamCol )
{

    printf("*****Listado de Colores*****\n\n");
    printf("Id    Descripcion\n");

    for(int i=0; i<tamCol; i++)
    {
        printf("%d   %10s\n",colores[i].id, colores[i].nombreColor);
    }
    printf("\n\n");
}




int cargarDescripcionColor(char descripcion[], int id, eColor colores[], int tamCol )
{

    int todoOk = 0;
    for(int i=0; i <tamCol; i++)
    {
        if(colores[i].id == id)
        {
            strcpy(descripcion, colores[i].nombreColor);
            todoOk = 1;

        }

    }
    return todoOk;
}

int validarColor(int color)
{

    do
    {

        if(color <5000 || color>5004)
        {

            printf("\nError selecciones un id de color valido: ");
            scanf("%d", &color);
        }
    }
    while(color <5000 || color>5004);

    return color;
}
