#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bicicletas.h"
#include "trabajos.h"
#include "cliente.h"



void inicializarTrabajos(eTrabajo vec[], int tam )
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;

    }
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

int altaTrabajo ( int idx,eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer, eCliente clientes[], int tamCliente )
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

        listarBicicletas(bicicletas,tamB,colores,tamCol,tipos,tamTip,clientes,tamCliente);
        printf("***********************************************\n");
        printf("Seleccione el id de la bicicleta: \n\n");
        scanf("%d", &auxTrabajo.idBicicleta);

        system("cls");
        listarServicios(servicios,tamSer);
        printf("***********************************************\n");
        printf("Seleccione el id del servicio: \n\n");
        scanf("%d", &auxTrabajo.idServicio);
        auxTrabajo.idServicio= validarServicio(auxTrabajo.idServicio);


        printf("ingrese una fecha(dd/mm/aaaa): ");
        scanf("%d/%d/%d",&auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);

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

    printf(" IdBicicleta      IdTrabajo         Marca        Tipo          Color      Rodado   Servicio     Fecha \n");

    for(int i = 0; i < tamB; i++)
    {
        for(int j =0; j<tamTra; j++ )
        {
            if (bicicletas[i].id == trabajos[j].idBicicleta && bicicletas[i].isEmpty == 0 && trabajos[j].isEmpty == 0)
            {
                cargarDescripcionColor(descColor,bicicletas[i].idColor,colores,tamCol);

                cargarDescripcionTipo(descTipo,bicicletas[i].idTipo,tipos,tamTip);

                cargarDescripcionServicio(descServicio,trabajos[j].idServicio,servicios,tamSer);

                printf("%10d  %10d      %10s %15s %15s    %.2f   %10s    %d/%d/%d\n", bicicletas[i].id,trabajos[j].id, bicicletas[i].marca, descTipo,descColor,bicicletas[i].rodado, descServicio, trabajos[j].fecha.dia,trabajos[j].fecha.mes, trabajos[j].fecha.anio);
            }
        }

    }



    return error;
}
