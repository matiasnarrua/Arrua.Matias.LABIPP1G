#ifndef HARDCODEAR_H_INCLUDED
#define HARDCODEAR_H_INCLUDED

int idsHard[]= {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009};
char marcasHard[][20] = {"Top", "BiciMax", "MountainBike", "Unlimited", "Top", "Unlimited", "Unlimited", "BiciMax", "Top", "BiciMax" };
int idsTipoHard[] = {1003,1000,1001,1002,1003,1002,1001,1002,1003,1000};
int idsColorHard [] = { 5000, 5001, 5003,5000,5004,5001, 5002, 5000, 5002,5003};
float rodadosHard []= {20,29,20,27.5,26,20,29,27.5,20,26,};


#endif // HARDCODEAR_H_INCLUDED


/** \brief Hardcodea el vector bicicletas
 *
 * \param vec[] eBicicleta vector a hardcodear
 * \param cant int cantidad de espacio que se quiera llenar del vector
 * \return void
 *
 */
void hardcodearBicicletas(eBicicleta vec[],int cant);


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
