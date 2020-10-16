#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bicicletas.h"
#include "trabajos.h"



void inicializarTrabajos(eTrabajo vec[], int tam )
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;

    }
}

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


int buscarTrabajosLibres (eTrabajo vec[],int tamTra )
{
    int indice = -1;
    for(int i=0; i<tamTra; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaTrabajo ( int idx,eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer )
{
    int todoOk = 0;
    int indice = buscarTrabajosLibres(trabajos, tamTra);

    eTrabajo auxTrabajo;

    system("cls");
    printf("***** Alta Trabajos *****\n\n");
    if (  indice == -1 )
    {

        printf("Sistema Completo\n\n");
    }
    else
    {

        auxTrabajo.id = idx;

        listarBicicletas(bicicletas,tamB,colores,tamCol,tipos,tamTip);
        printf("***********************************************\n");
        printf("Seleccione el id de la bicicleta: \n\n");
        scanf("%d", &auxTrabajo.idBicicleta);

        system("cls");
        listarServicios(servicios,tamSer);
        printf("***********************************************\n");
        printf("Seleccione el id del servicio: \n\n");
        scanf("%d", &auxTrabajo.idServicio);

        auxTrabajo.isEmpty = 0;

        trabajos[indice] = auxTrabajo;

        todoOk = 1;
    }
    return todoOk;
}



int listarTrabajos(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer)
{

    int error =1;

     char descColor[20];
                char descTipo[20];
                char descServicio[20];


    system("cls");
    printf("***** Trabajos *****\n\n ");

     printf("       Id     Marca       Tipo        Color       Rodado        Servicio   \n");

    for(int i = 0; i < tamB; i++)
    {
        for(int j =0; j<tamTra; j++ )
        {
            if (bicicletas[i].id == trabajos[j].idBicicleta && bicicletas[i].isEmpty == 0 && trabajos[j].isEmpty == 0)
            {
                cargarDescripcionColor(descColor,bicicletas[i].idColor,colores,tamCol);
                cargarDescripcionTipo(descTipo,bicicletas[i].idTipo,tipos,tamTip);
                cargarDescripcionServicio(descServicio,servicios[i].id,servicios,tamSer);
                printf("%10d   %10s     %15s  %15s    %4d   %10s\n", bicicletas[i].id, bicicletas[i].marca, descTipo,descColor,bicicletas[i].rodado, descServicio);
            }
        }

    }



    return error;
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
