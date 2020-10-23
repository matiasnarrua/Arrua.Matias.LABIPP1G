#include "bicicletas.h"


void hardcodearBicicletas(eBicicleta vec[],int cant)
{
    for(int i =0; i< cant; i++)
    {

        vec[i].id =idsHard[i];
        strcpy( vec[i].marca, marcasHard [i]);
        vec[i].idTipo = idsTipoHard[i];
        vec[i].idColor = idsColorHard[i];
        vec[i].rodado = rodadosHard[i];
        vec[i].isEmpty = 0;
    }
}
