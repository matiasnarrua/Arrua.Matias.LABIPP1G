#ifndef HARDCODEAR_H_INCLUDED
#define HARDCODEAR_H_INCLUDED





char marcas [][20] = {"Matias", "Lucia", "Miguel", "Patricia", "Nuria", "Carlos", "Luis", "Daniel", "Antonia", "Nahuel" };
int ids[]= {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009};
int idColor[]= {5000,5001,5002,5003,5002,5001,5002,5000,5003,5004};
int idTipo[]= {1000,1001,1002,1003,1003,1001,1002,1002,1004,1000};
int rodado [] ={ 22, 26 , 24 ,20 ,28 ,22, 28, 20, 22,26};





#endif // HARDCODEAR_H_INCLUDED



void hardcodearBicicletas(eBicicleta vec[],int cant,int proxId,int flag);


void hardcodearBicicletas(eBicicleta vec[],int cant, int proxId,int flag)
{
    for(int i =0; i< cant; i++)
    {

        vec[i].id =ids[i];
        proxId = ids[i];
        strcpy( vec[i].marca, marcas [i]);
        vec[i].idColor = idColor[i];
        vec[i].idTipo = idTipo[i];
        vec[i].rodado = rodado[i];
        vec[i].isEmpty = 0;
        flag = 1;
    }
}

