#include "fecha.h"
#include "servicios.h"
#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED


typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty ;

} eTrabajo;

#endif // TRABAJOS_H_INCLUDED


/** \brief Inicializa el campo isEmpty del vector en 0 para que puedan ser cargados
 *
 * \param vec[] eTrabajo vector a inicializar
 * \param tam int tamaño del vector
 * \return void
 *
 */
void inicializarTrabajos(eTrabajo vec[], int tam );




/** \brief Realiza un alta de trabajo en el indice del vector que tenga el campo isEmpty en 0
 *
 ** \param eBicicleta bicicletas[] vector  de bicicletas
 * \param int tama tamaño del vector bicicletas
* \param eColor Colores[] vector que contiene los id y descripciones de los colores
 * \param int tamCol Tamaño del vector colores
 * \param eTipo tipos[] vector que contiene los id y descripciones de los tipos de bicicleta
 * \param int tamTip Tamaño del vector tipos
 * \param trabajos[] eTrabajo vector de trabajos que se realiza la lista
 * \param tamTra int tamaño del vector de trabajos
 * \param servicios[] eServicio vector de servicios que contiene los id descripciones y precios
 * \param tamSer int tamaño del vector de servicios
 * \param eCliente clientes[] vector que contiene los id, nombres y sexos de los clientes
 * \param int tamCliente Tamaño del vector clientes
 * \return int
 *
 */
int altaTrabajo ( int idx,eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamtra, eServicio servicios[], int tamSer, eCliente clientes[], int tamCliente);



/** \brief Hace un listado de todos los Trabajos que estan activos
 *
 * \param eBicicleta bicicletas[] vector  de bicicletas
 * \param int tama tamaño del vector bicicletas
* \param eColor Colores[] vector que contiene los id y descripciones de los colores
 * \param int tamCol Tamaño del vector colores
 * \param eTipo tipos[] vector que contiene los id y descripciones de los tipos de bicicleta
 * \param int tamTip Tamaño del vector tipos
 * \param trabajos[] eTrabajo vector de trabajos que se realiza la lista
 * \param tamTra int tamaño del vector de trabajos
 * \param servicios[] eServicio vector de servicios que contiene los id descripciones y precios
 * \param tamSer int tamaño del vector de servicios
 * \return int
 *
 */
int listarTrabajos(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
