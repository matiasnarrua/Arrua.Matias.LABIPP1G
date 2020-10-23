#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bicicletas.h"
#include "trabajos.h"
#include "servicios.h"
#include "tipo.h"
#include "colores.h"
#include "informes.h"


int menuInformes()
{
    int opcion;

    system("cls");
    printf("***---*** Informes ***---***\n\n");
    printf("1. Mostrar Bicicletas por Color\n2. Mostrar bicicletas de un tipo\n3. Informar bicicletas menor rodado\n4. Listar Bicicletas por tipo\n5. Contar bicicletas por color y tipo\n"
           "6. Listar Colores mas elejidos\n7. Mostrar trabajos de una bicicleta\n8. Importes a pagar de una bicicleta\n9. Bicicletas por servicio\n10. Servicios de la fecha\n11. Volver al menu principal\n\n");
    fflush(stdin);
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}

void mostrarBicicletaXColor(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente)
{


    int flag = 0;
    int auxColor;

    system("cls");
    printf("*****Listado de bicicletas Por color*****\n\n");

    listarColores(colores,tamCol);

    printf("Ingrese el id del color que quiera mostrar: ");
    scanf("%d", &auxColor);
    if(auxColor <5000 || auxColor>5004)
    {
        printf("\nError selecciones un id de color valido: ");
        scanf("%d", &auxColor);
    }
    printf("       Id     Marca                 Tipo             Color     rodado  \n");

    for(int i=0; i<tamB; i++)
    {
        if(bicicletas[i].isEmpty == 0 && auxColor == bicicletas[i].idColor )
        {
            mostrarBicicleta (bicicletas [i], colores, tamCol,tipos, tamTip,clientes,tamCliente);

            flag = 1;
        }
    }
    system("pause");
    if(flag ==0)
    {
        printf("****No hay bicicletas que mostrar****\n\n");
    }
}


void mostrarBicicletaXTipo(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente)
{


    int flag = 0;
    int auxTipo;

    system("cls");
    printf("*****Listado de bicicletas por Tipo*****\n\n");

    listarTipos(tipos,tamTip);

    printf("Ingrese el id del tipo que quiera mostrar: ");
    scanf("%d", &auxTipo);
    if(auxTipo <1000 || auxTipo>1003)
    {
        printf("\nError selecciones un id de tipo valido: ");
        scanf("%d", &auxTipo);
    }
    printf("       Id     Marca                 Tipo             Color     rodado  \n");

    for(int i=0; i<tamB; i++)
    {
        if(bicicletas[i].isEmpty == 0 && auxTipo == bicicletas[i].idTipo )
        {
            mostrarBicicleta (bicicletas [i], colores, tamCol,tipos, tamTip,clientes,tamCliente);

            flag = 1;
        }
    }
    system("pause");
    if(flag ==0)
    {
        printf("****No hay bicicletas que mostrar****\n\n");
    }


}

void mostrarBicicletasMenorRodado(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente)
{

    int auxRodado = 100;
    int flag = 0;
    system("cls");
    printf("*****Bicicletas de menor Rodado*****\n\n");

    printf("       Id     Marca                 Tipo             Color     rodado  \n");

    for(int i=0; i<tamB; i++)
    {

        if( bicicletas[i].isEmpty == 0 && auxRodado> bicicletas[i].rodado)
        {
            auxRodado= bicicletas[i].rodado;

        }
    }
    for(int i=0; i<tamB; i++)
    {
        if(bicicletas[i].isEmpty == 0 && auxRodado == bicicletas[i].rodado )
        {
            mostrarBicicleta (bicicletas [i], colores, tamCol,tipos, tamTip,clientes,tamCliente);

            flag = 1;
        }
    }
    system("pause");
    if(flag ==0)
    {
        printf("****No hay bicicletas que mostrar****\n\n");
    }
}


void listarBicicletasXTipo(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente)
{
    char tipoAux[20];
    int flag = 0;

    system("cls");
    printf("***** Listado de bicicletas por cada tipo *****\n\n");
    printf("       Id     Marca                 Tipo             Color     rodado  \n");

    for(int i = 0; i < tamTip; i++)
    {
        flag = 0 ;
        cargarDescripcionTipo(tipoAux,bicicletas[i].idTipo,tipos,tamTip);
        printf("Tipo: %s: \n\n", tipoAux);


        for(int j =0; j<tamB; j++ )
        {

            if (bicicletas[j].idTipo == tipos[i].id && bicicletas[j].isEmpty == 0)
            {
                mostrarBicicleta (bicicletas [j], colores, tamCol,tipos, tamTip,clientes,tamCliente);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("No hay Bicicletas de tipo: %s\n\n ", tipoAux);

        }
    }
    system("pause");
}


void contarBicicletasXColorYTipo(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente)
{
    int auxCol;
    int auxTip;
    char auxCharTipo [20];
    char auxCharColor [20];
    int flag =0;
    system("cls");
    listarColores(colores,tamCol);
    printf("Seleccione el id de un color: ");
    scanf("%d", &auxCol);
    auxCol = validarColor(auxCol);

    system("cls");
    listarTipos(tipos,tamTip);
    printf("Seleccione el id de un tipo: ");
    scanf("%d", &auxTip);
    auxTip = validarTipo(auxTip);

    cargarDescripcionTipo(auxCharTipo,auxTip,tipos,tamTip);
    cargarDescripcionColor(auxCharColor,auxCol,colores,tamCol);
    system("cls");
    printf("********** Bicicletas Tipo %s y color %s ***********\n\n ", auxCharTipo, auxCharColor);
    for(int j =0; j<tamB; j++ )
    {

        if (bicicletas[j].idTipo == auxTip && bicicletas[j].isEmpty == 0 && bicicletas[j].idColor == auxCol)
        {
            mostrarBicicleta (bicicletas [j], colores, tamCol,tipos, tamTip,clientes,tamCliente);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("No hay Bicicletas Tipo %s y color %s\n\n ", auxCharTipo, auxCharColor);

    }

    system("pause");
}

void MostrarColorMasElegido(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol)
{
    int mayor;
    int contadores[tamCol];
    int flag = 0;

    for(int i = 0; i < tamCol; i++)
    {
        contadores[i] =0;
    }


    system("cls");
    printf("***** Deporte Favorito *****\n\n ");

    for(int i = 0; i < tamCol; i++)
    {
        for(int j =0; j<tamB; j++ )
        {
            if (bicicletas[j].idColor == colores[i].id && bicicletas[j].isEmpty == 0)
            {
                contadores[i]++;
            }
        }
    }

    for(int i = 0; i < tamCol; i++)
    {
        if(contadores[i]> mayor || flag == 0)
        {
            mayor = contadores[i];
            flag = 1 ;
        }
    }
    printf("El o los Colores favoritos son favoritos son : \n");

    for(int i = 0; i < tamCol; i++)
    {
        if (contadores [ i ]== mayor)
        {
            printf("%s\n",colores[i].nombreColor);
        }
    }
    system("pause");
}
