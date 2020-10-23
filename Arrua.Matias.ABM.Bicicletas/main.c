#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bicicletas.h"
#include "trabajos.h"
#include "servicios.h"
#include "tipo.h"
#include "colores.h"
#include "informes.h"
#include "cliente.h"

#include "hardcodear.h"

#define TAM_B 10
#define TAM_TIPO 4
#define TAM_C 5
#define TAM_S 4
#define TAM_T 10
#define TAM_CLIENTE 10




int main()
{

    char seguir = 's';
    char seguir2 = 's';
    char confirma;
    char confirma2;
    int proximoId = 1000;
    int proximoId2=1;
    int flag = 0;
    eBicicleta bicicletas[TAM_B];
    eTipo tipos[TAM_TIPO] = { { 1000, "Rutera" },{ 1001, "Carrera" },{ 1002, "Mountain" },{ 1003, "BMX" } };
    eColor colores[TAM_C]= { { 5000, "Gris" },{ 5001, "Negro" },{ 5002, "Blanco" },{ 5003, "Azul"},{ 5004, "Rojo" } };
    eServicio servicios[TAM_S]= { { 20000, "Limpieza", 250 },{ 20001, "Parche", 300 },{ 20002, "Centrado", 400 },{ 20003, "Cadena", 350 } };
    eTrabajo trabajos[TAM_T];
    eCliente clientes [TAM_CLIENTE]= { { 300, "Martin", 'm' },{ 301, "Carla", 'f' },{ 302, "Camila", 'f' },{ 303, "Juan", 'm'},{ 304, "Jose", 'm' },{ 305, "Maria", 'f' },{ 306, "Nahuel", 'm' },{ 307, "Jimena", 'f' },{ 308, "Ailin", 'f' },{ 309, "Cristian", 'm' } };


    inicializarBicicletas(bicicletas, TAM_B);
    inicializarTrabajos(trabajos, TAM_T);

    hardcodearBicicletas(bicicletas,TAM_B-2);
    flag = 1; // Dejo el flag en 1 asi el programa no pide un alta para listar bicicletas ya que esta hardcodeado
    proximoId+= TAM_B;

    do
    {
        switch(menu())
        {

        case 1:
            if ( altaBicicleta(proximoId, bicicletas, TAM_B, colores,TAM_C,tipos, TAM_TIPO,clientes,TAM_CLIENTE) == 1)
            {
                flag = 1;
                proximoId ++ ;
            }
            break;

        case 2:
            if(flag == 1)
            {
                modificarBicicleta(bicicletas, TAM_B, colores,TAM_C,tipos, TAM_TIPO,clientes,TAM_CLIENTE);
            }
            else
            {
                printf("Error.... Primero debe realizar el alta de una bicicleta");
            }
            break;

        case 3:
            if(flag == 1)
            {
                bajaBicicleta(bicicletas, TAM_B, colores,TAM_C,tipos, TAM_TIPO,clientes,TAM_CLIENTE);
            }
            else
            {
                printf("Error.... Primero debe realizar el alta de una bicicleta");
            }

            break;

        case 4:
            if(flag == 1)
            {
                ordenarBicicletas(bicicletas,TAM_B);
                listarBicicletas(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_TIPO,clientes,TAM_CLIENTE);
            }
            else
            {
                printf("Error.... Primero debe realizar el alta de una bicicleta");
            }
            break;

        case 5:
            system("cls");
            listarTipos(tipos,TAM_TIPO);

            break;

        case 6:
            system("cls");
            listarColores(colores,TAM_C);
            break;
        case 7:
            listarServicios(servicios,TAM_S);
            break;
        case 8:
            if ( altaTrabajo(proximoId2,bicicletas,TAM_B,colores,TAM_C,tipos,TAM_TIPO,trabajos,TAM_T,servicios,TAM_S,clientes,TAM_CLIENTE) == 1)
            {
                flag = 1;
                proximoId2 ++ ;
            }
            break;
        case 9:
            listarTrabajos(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_TIPO,trabajos,TAM_T,servicios,TAM_S);
            break;
        case 10:
            system("cls");
            do
            {
                switch (menuInformes())
                {
                case 1:
                    mostrarBicicletaXColor(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_TIPO,clientes,TAM_CLIENTE);
                    break;

                case 2:
                    mostrarBicicletaXTipo(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_TIPO,clientes,TAM_CLIENTE);
                    break;

                case 3:
                    mostrarBicicletasMenorRodado(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_TIPO,clientes,TAM_CLIENTE);
                    break;

                case 4:
                    listarBicicletasXTipo(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_TIPO,clientes,TAM_CLIENTE);
                    break;

                case 5:
                    contarBicicletasXColorYTipo(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_TIPO,clientes,TAM_CLIENTE);
                    break;

                case 6:
                    MostrarColorMasElegido(bicicletas,TAM_B,colores,TAM_C);
                    break;

                case 7:
                    break;

                case 8:
                    break;

                case 9:
                    break;

                case 10:
                    break;

                case 11:
                    printf("Confirma salir ?");
                    fflush(stdin);
                    scanf("%c", &confirma2);
                    if (confirma2 == 's')
                    {
                        seguir2 = 'n';
                    }
                    break;
                }
            }
            while(seguir2 == 's');
            break;


        case 11:
            printf("Confirma salir ?");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }
        system ("pause");
    }
    while(seguir == 's');


    return 0;
}
