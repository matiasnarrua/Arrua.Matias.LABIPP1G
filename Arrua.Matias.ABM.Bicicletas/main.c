#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bicicletas.h"
#include "trabajos.h"

#define TAM_B 5
#define TAM_TIPO 4
#define TAM_C 5
#define TAM_S 4
#define TAM_T 10


int main()
{

    char seguir = 's';
    char confirma;
    int proximoId = 1000;
    int proximoId2=1;
    eBicicleta bicicletas[TAM_B];
    eTipo tipos[TAM_TIPO] = { { 1000, "Rutera" },{ 1001, "Carrera" },{ 1002, "Mountain" },{ 1003, "BMX" } };
    eColor colores[TAM_C]= { { 5000, "Gris" },{ 5001, "Negro" },{ 5002, "Blanco" },{ 5003, "Azul"},{ 5004, "Rojo" } };
    eServicio servicios[TAM_S]= { { 20000, "Limpieza", 250 },{ 20001, "Parche", 300 },{ 20002, "Centrado", 400 },{ 20003, "Cadena", 350 } };
    eTrabajo trabajos[TAM_T];


    inicializarBicicletas(bicicletas, TAM_B);
    inicializarTrabajos(trabajos, TAM_T);


    do
    {
        switch(menu())
        {

        case 1:
            if ( altaBicicleta(proximoId, bicicletas, TAM_B, colores,TAM_C,tipos, TAM_TIPO) == 1)
            {
                proximoId ++ ;
            }
            break;

        case 2:
            modificarBicicleta(bicicletas, TAM_B, colores,TAM_C,tipos, TAM_TIPO);
            break;

        case 3:
            bajaBicicleta(bicicletas, TAM_B, colores,TAM_C,tipos, TAM_TIPO);
            break;

        case 4:
            listarBicicletas(bicicletas,TAM_B,colores,TAM_C,tipos,TAM_TIPO);
            break;

        case 5:
            listarTipos(tipos,TAM_TIPO);

            break;

        case 6:
            listarColores(colores,TAM_C);
            break;
        case 7:
            listarServicios(servicios,TAM_S);
            break;
        case 8:
             altaTrabajo(proximoId2,bicicletas,TAM_B,colores,TAM_C,tipos,TAM_TIPO,trabajos,TAM_T,servicios,TAM_S);
            break;
        case 9:
            //  ListarTrabajos
            break;

        case 10:
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
