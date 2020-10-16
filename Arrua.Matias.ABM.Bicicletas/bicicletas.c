#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bicicletas.h"
#include "trabajos.h"

int menu()
{
    int opcion;

    system("cls");
    printf("***** Gestion de la Bicicleteria *****\n\n");
    printf("1. Alta Bicicleta\n2. Modificar Bicicleta\n3. Baja Bicicleta\n4. Listar Bicicletas\n5. Listar Tipos\n6. Listar Colores\n7. Listar Servicios\n8. Alta Trabajo\n9. Listar Trabajos\n10. Salir\n\n");
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



int altaBicicleta (int idx,eBicicleta vec[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip )
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


        if(auxBicicleta.idColor <5000 || auxBicicleta.idColor>5004)
        {

            printf("\nError selecciones un id de color valido: ");
            scanf("%d", &auxBicicleta.idColor);
        }

        system("cls");
        listarTipos(tipos, tamTip);
        printf("\n Seleccione el id del Tipo de bicicleta:  ");
        scanf("%d", &auxBicicleta.idTipo);

        if(auxBicicleta.idTipo <1000 || auxBicicleta.idTipo>1004)
        {

            printf("\nError selecciones un id de Tipo de bicicleta valido:  ");
            scanf("%d", &auxBicicleta.idTipo);
        }
        printf("ingrese rodado: ");
        scanf("%d",&auxBicicleta.rodado);


        auxBicicleta.isEmpty = 0;

        vec[indice] = auxBicicleta;

        todoOk = 1;
    }
    return todoOk;
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
void mostrarBicicleta (eBicicleta bicicletas, eColor colores[], int tamCol,eTipo tipos[], int tamTip)
{
    char descColor[20];
    char descMarca[20];

    cargarDescripcionColor(descColor,bicicletas.idColor,colores,tamCol);
    cargarDescripcionTipo(descMarca,bicicletas.idTipo,tipos,tamTip);
    printf("%10d   %10s     %15s  %15s  %4d\n", bicicletas.id, bicicletas.marca, descMarca,descColor,bicicletas.rodado);

}

void listarBicicletas(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip)
{

    int flag = 0;

    system("cls");
    printf("*****Listado de bicicletas*****\n\n");

    printf("       Id     Marca         Marca              Color     rodado  \n");

    for(int i=0; i<tamB; i++)
    {
        if(bicicletas[i].isEmpty == 0 )
        {
            mostrarBicicleta (bicicletas [i], colores, tamCol,tipos, tamTip);
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



void modificarBicicleta (eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip)
{
    int id ;
    int indice;
    char confirma;
    int opcion;
    int nuevo;



    system("cls");
    printf("***** Modificar Bicicleta *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);
    indice = buscarBicicleta(id, bicicletas, tamB);

    if(indice == -1)
    {
        printf("No hay registro de la bicicleta con el Id: %d\n",id);
    }
    else
    {
        mostrarBicicleta(bicicletas[indice],colores, tamCol,tipos,tamTip);

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
                bicicletas[indice].idTipo = nuevo;
                printf("Se ha actualizado el Tipo de bicicleta con exito \n\n");

                break;
            case 2:
                system("cls");
                printf("****Modificar Rodado****\n\n");
                printf("Ingrese el nuevo rodado: ");
                scanf("%d",&nuevo);
                bicicletas[indice].rodado = nuevo;
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




void bajaBicicleta (eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip )
{
    int id ;
    int indice;
    char confirma;
    system("cls");
    printf("*****Baja Bicicleta *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);
    indice = buscarBicicleta(id, bicicletas, tamB);

    if(indice == -1)
    {

        printf("No hay registro de la bicicleta con el Id: %d\n",id);
    }
    else
    {
        mostrarBicicleta (bicicletas[indice],colores, tamCol,tipos,tamTip);
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

