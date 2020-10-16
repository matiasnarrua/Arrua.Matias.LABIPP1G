#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

typedef struct
{
    int id;
    char marca [20];
    int idTipo;
    int idColor;
    int rodado;
    int isEmpty;

} eBicicleta;

typedef struct
{
    int id;
    char descripcion[20];

} eTipo;



typedef struct
{
    int id;
    char  nombreColor[20];

} eColor;

#endif // BICICLETAS_H_INCLUDED



int menu();

void inicializarBicicletas(eBicicleta vec[], int tam );
int buscarLibres (eBicicleta vec[],int tam );
void listarColores(eColor colores[], int tamCol );
void listarTipos(eTipo tipos [], int tamTip );
int altaBicicleta (int idx,eBicicleta vec[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip );
void mostarBicicleta(eBicicleta bicicletas, eColor colores[], int tamCol,eTipo tipos[], int tamTip);
void listarBicicletas(eBicicleta bicicletas[], int tama, eColor colores[], int tamCol,eTipo tipos[], int tamTip);
int cargarDescripcionColor(char descripcion[], int id, eColor colores[], int tamCol );
int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tamTip );

int buscarBicicleta (int id,eBicicleta bicicletas[],int tama );
void modificarBicicleta(eBicicleta bicicletas[], int tama, eColor colores[], int tamCol,eTipo tipos[], int tamTip);

void bajaBicicleta (eBicicleta bicicletas[], int tama, eColor colores[], int tamCol,eTipo tipos[], int tamTip );
