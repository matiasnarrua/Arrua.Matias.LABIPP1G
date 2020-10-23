#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bicicletas.h"
#include "trabajos.h"
#include "tipo.h"
#include "colores.h"
#include "cliente.h"

int menu()
{
    int opcion;

    system("cls");
    printf("***** Gestion de la Bicicleteria *****\n\n");
    printf("1. Alta Bicicleta\n2. Modificar Bicicleta\n3. Baja Bicicleta\n4. Listar Bicicletas\n5. Listar Tipos\n"
           "6. Listar Colores\n7. Listar Servicios\n8. Alta Trabajo\n9. Listar Trabajos\n10. Informes\n11. Salir\n\n");
    fflush(stdin);
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}


void inicializarBicicletas(eBicicleta vec[], int tam )
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;

    }
}

int buscarLibres (eBicicleta vec[],int tam )
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int altaBicicleta (int idx,eBicicleta vec[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente )
{
    int todoOk = 0;
    int indice = buscarLibres(vec, tam);

    eBicicleta auxBicicleta;

    system("cls");
    printf("***** Alta bicicletas *****\n\n");
    if (  indice == -1 )
    {

        printf("Sistema Completo\n\n");
    }
    else
    {

        auxBicicleta.id = idx;

        printf("ingrese marca: ");
        fflush(stdin);
        gets(auxBicicleta.marca);

        system("cls");
        listarColores(colores, tamCol);
        printf("\nSeleccione el id del Color:   ");
        scanf("%d", &auxBicicleta.idColor);


        auxBicicleta.idColor = validarColor(auxBicicleta.idColor);


        system("cls");
        listarTipos(tipos, tamTip);
        printf("\n Seleccione el id del Tipo de bicicleta:  ");
        scanf("%d", &auxBicicleta.idTipo);

        auxBicicleta.idTipo = validarTipo(auxBicicleta.idTipo);

        printf("Ingrese rodado(20, 26, 27.5 o 29): ");
        scanf("%f",&auxBicicleta.rodado);

        auxBicicleta.rodado = validarRodado(auxBicicleta.rodado);
        system("cls");
        listarClientes(clientes,tamCliente);
        printf("Seleccione el id del cliente: ");
        scanf("%d",&auxBicicleta.idCliente);

        auxBicicleta.idCliente = validarCliente(auxBicicleta.idCliente);

        auxBicicleta.isEmpty = 0;

        vec[indice] = auxBicicleta;

        todoOk = 1;
    }
    return todoOk;
}


void mostrarBicicleta (eBicicleta bicicletas, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente)
{
    char descColor[20];
    char descTipo[20];

    cargarDescripcionColor(descColor,bicicletas.idColor,colores,tamCol);
    cargarDescripcionTipo(descTipo,bicicletas.idTipo,tipos,tamTip);
    printf("%10d   %10s     %15s  %15s  %2.2f\n", bicicletas.id, bicicletas.marca, descTipo,descColor,bicicletas.rodado);

}

void listarBicicletas(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente)
{

    int flag = 0;

    system("cls");
    printf("*****Listado de bicicletas*****\n\n");

    printf("       Id     Marca                 Tipo             Color     rodado    Nombre Cliente \n");

    for(int i=0; i<tamB; i++)
    {
        if(bicicletas[i].isEmpty == 0 )
        {
            mostrarBicicleta (bicicletas [i], colores, tamCol,tipos, tamTip,clientes,tamCliente);
            flag = 1;
        }
    }
    if(flag ==0)
    {
        printf("****No hay bicicletas que mostrar****\n\n");
    }

}

int buscarBicicleta (int id,eBicicleta bicicletas[],int tamB )
{
    int indice = -1;
    for(int i=0; i<tamB; i++)
    {
        if(bicicletas[i].id == id && bicicletas[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



void modificarBicicleta (eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente)
{
    int id ;
    int indice;
    char confirma;
    int opcion;
    int nuevo;
    float nuevoRodado;



    system("cls");
    printf("***** Modificar Bicicleta *****\n\n");

    listarBicicletas(bicicletas,tamB,colores,tamCol,tipos,tamTip,clientes,tamCliente);

    printf("Ingrese id: ");
    scanf("%d", &id);
    indice = buscarBicicleta(id, bicicletas, tamB);

    if(indice == -1)
    {
        printf("No hay registro de la bicicleta con el Id: %d\n",id);
    }
    else
    {
        mostrarBicicleta(bicicletas[indice],colores, tamCol,tipos,tamTip,clientes,tamCliente);

        printf("Modificar esta Bicicleta[S/N] ?");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            printf("Seleccione que desea modificar:\n1_Tipo\n2_Rodado\n\n");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                system("cls");

                printf("****Modificar Tipo de bicicleta****\n\n");
                listarTipos(tipos,tamTip);

                printf("Seleccione el id del nuevo Tipo de bicicleta: ");
                scanf("%d",&nuevo);
                nuevo = validarTipo(nuevo);
                bicicletas[indice].idTipo = nuevo;
                printf("Se ha actualizado el Tipo de bicicleta con exito \n\n");

                break;
            case 2:
                system("cls");
                printf("****Modificar Rodado****\n\n");
                printf("Ingrese nuevo rodado(20, 26, 27.5 o 29): : ");
                scanf("%f",&nuevoRodado);
                nuevoRodado = validarRodado(nuevoRodado);

                bicicletas[indice].rodado = nuevoRodado;
                printf("Se ha actualizado el rodado con exito \n\n");
                break;
            }

        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }
}




void bajaBicicleta (eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente )
{
    int id ;
    int indice;
    char confirma;
    system("cls");
    printf("*****Baja Bicicleta *****\n\n");

    listarBicicletas(bicicletas,tamB,colores,tamCol,tipos,tamTip,clientes,tamCliente);
    printf("\nIngrese id: ");
    scanf("%d", &id);
    indice = buscarBicicleta(id, bicicletas, tamB);

    if(indice == -1)
    {

        printf("No hay registro de la bicicleta con el Id: %d\n",id);
    }
    else
    {
        mostrarBicicleta (bicicletas[indice],colores, tamCol,tipos,tamTip,clientes,tamCliente);
        printf("Confirma baja[S/N] ?");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            bicicletas[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito \n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }
}


void ordenarBicicletas(eBicicleta bicicletas[], int tamB)
{
    eBicicleta auxBicicleta;
    for(int i=0; i<tamB-1; i++)
    {
        for(int j= i+1; j<tamB; j++)
        {

            if( bicicletas[i].idTipo > bicicletas[j].idTipo)
            {

                auxBicicleta = bicicletas[i];
                bicicletas[i]=bicicletas[j];
                bicicletas[j] = auxBicicleta;
            }
            else if (bicicletas[i].idTipo == bicicletas[j].idTipo && bicicletas[i].rodado < bicicletas[j].rodado)
            {
                auxBicicleta=bicicletas[i];
                bicicletas[i]=bicicletas[j];
                bicicletas[j] = auxBicicleta;
            }

        }
    }
}


float validarRodado(float rodado)
{

    do
    {

        if(!(rodado == 20 || rodado == 26 || rodado == 27.5 || rodado == 29))
        {

            printf("\nError selecciones un rodado valido (20, 26, 27.5 o 29): ");
            scanf("%f", &rodado);
        }
    }
    while(!(rodado == 20 || rodado == 26 || rodado == 27.5 || rodado == 29));

    return rodado;
}


