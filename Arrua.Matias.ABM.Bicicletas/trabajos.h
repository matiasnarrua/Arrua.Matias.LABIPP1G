#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED


typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct{
int id;
char descripcion[25];
int precio;

}eServicio;


typedef struct{
int id;
int idBicicleta;
int idServicio;
eFecha fecha;
int isEmpty ;

}eTrabajo;

#endif // TRABAJOS_H_INCLUDED


void inicializarTrabajos(eTrabajo vec[], int tam );

void listarServicios(eServicio servicios[], int tamSer );

int altaTrabajo ( int idx,eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamtra, eServicio servicios[], int tamSer );
