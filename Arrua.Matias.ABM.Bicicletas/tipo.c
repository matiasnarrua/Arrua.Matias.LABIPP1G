#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bicicletas.h"
#include "trabajos.h"
#include "tipo.h"
#include "colores.h"



void listarTipos(eTipo tipos [], int tamTip )
{

    printf("*****Listado de tipos*****\n\n");
    printf("Id    Descripcion\n");

    for(int i=0; i<tamTip; i++)
    {
        printf("%d   %10s\n",tipos[i].id, tipos[i].descripcion);
    }
    printf("\n\n");
}


int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tamTip )
{

    int todoOk = 0;
    for(int i=0; i <tamTip; i++)
    {
        if(tipos[i].id == id)
        {
            strcpy(descripcion, tipos[i].descripcion);
            todoOk = 1;

        }

    }
    return todoOk;
}


int validarTipo(int tipo)
{

    do
    {

        if(tipo <1000 || tipo>1003)
        {

            printf("\nError selecciones un id de Tipo valido: ");
            scanf("%d", &tipo);
        }
    }
    while(tipo <1000 || tipo>1003);

    return tipo;
}
