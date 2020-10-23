#include "tipo.h"
#include "colores.h"
#include "cliente.h"

#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

typedef struct
{
    int id;
    char marca [20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;
    int idCliente;

} eBicicleta;

#endif // BICICLETAS_H_INCLUDED


int menu();



/** \brief Inicializa el vector
 *
 * \param vec[] eBicicleta vector a inicializar
 * \param tam int  tamaño del vector
 * \return void
 *
 */
void inicializarBicicletas(eBicicleta vec[], int tam );




/** \brief Busca vectores que tengan el campo isEmpty en 0
 *
 * \param vec[] eBicicleta vector en el que se realiza la busqueda
 * \param tam int  tamaño del vector
 * \return retorna el indice en el que este libre
 *
 */
int buscarLibres (eBicicleta vec[],int tam );





/** \brief Dar de alta una nueva bicicleta
 *
 * \param idx el id que tendra asignado
 * \param eBicicleta vec[] vector en el que se cargaran los datos
 * \param int tam tamaño del vector "vec"
 * \param eColor Colores[] vector que contiene los id y descripciones de los colores
 * \param int tamCol Tamaño del vector colores
 * \param eTipo tipos[] vector que contiene los id y descripciones de los tipos de bicicleta
 * \param int tamTip Tamaño del vector tipos
 * \param eCliente clientes[] vector que contiene los id, nombres y sexos de los clientes
 * \param int tamCliente Tamaño del vector clientes
 * \return 1 si se pudo dar el alta 0 si hubo un error
 *
 */
int altaBicicleta (int idx,eBicicleta vec[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente );


/** \brief Muestra 1 bicicleta en cierto indice
 *
 * \param eBicicleta bicicletas[] vector  de bicicletas
* \param eColor Colores[] vector que contiene los id y descripciones de los colores
 * \param int tamCol Tamaño del vector colores
 * \param eTipo tipos[] vector que contiene los id y descripciones de los tipos de bicicleta
 * \param int tamTip Tamaño del vector tipos
 * \param eCliente clientes[] vector que contiene los id, nombres y sexos de los clientes
 * \param int tamCliente Tamaño del vector clientes
 * \return Void
 *
 */
void mostrarBicicleta(eBicicleta bicicletas, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente);


/** \brief Hace un listado de las bicicletas utilizando la funcion mostrarBicicleta reiteradas veces
 *
 * \param eBicicleta bicicletas[] vector  de bicicletas
 * \param int tama tamaño del vector bicicletas
* \param eColor Colores[] vector que contiene los id y descripciones de los colores
 * \param int tamCol Tamaño del vector colores
 * \param eTipo tipos[] vector que contiene los id y descripciones de los tipos de bicicleta
 * \param int tamTip Tamaño del vector tipos
 * \param eCliente clientes[] vector que contiene los id, nombres y sexos de los clientes
 * \param int tamCliente Tamaño del vector clientes
 * \return Void
 *
 */
void listarBicicletas(eBicicleta bicicletas[], int tama, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente);



/** \brief Hace un listado de las bicicletas utilizando la funcion mostrarBicicleta reiteradas veces
 *
* \param int id es el id que se busca para ver si hay uno igual dentro del vector
 * \param eBicicleta bicicletas[] vector de bicicletas
 * \param int tama tamaño del vector bicicletas
 * \return int
 *
 */
int buscarBicicleta (int id,eBicicleta bicicletas[],int tama );



/** \brief Pregunta cual de los dos campos se quiere modificar y realiza esa modificacion
 *
 * \param eBicicleta bicicletas[] vector  de bicicletas que se modificara
 * \param int tama tamaño del vector bicicletas
* \param eColor Colores[] vector que contiene los id y descripciones de los colores
 * \param int tamCol Tamaño del vector colores
 * \param eTipo tipos[] vector que contiene los id y descripciones de los tipos de bicicleta
 * \param int tamTip Tamaño del vector tipos
 * \param eCliente clientes[] vector que contiene los id, nombres y sexos de los clientes
 * \param int tamCliente Tamaño del vector clientes
 * \return Void
 *
 */
void modificarBicicleta(eBicicleta bicicletas[], int tama, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente);


/** \brief Realiza una baja logica cambiando isEmpty del vector bicicleta
 *
 * \param eBicicleta bicicletas[] vector  de bicicletas a dar la baja
 * \param int tama tamaño del vector bicicletas
* \param eColor Colores[] vector que contiene los id y descripciones de los colores
 * \param int tamCol Tamaño del vector colores
 * \param eTipo tipos[] vector que contiene los id y descripciones de los tipos de bicicleta
 * \param int tamTip Tamaño del vector tipos
 * \param eCliente clientes[] vector que contiene los id, nombres y sexos de los clientes
 * \param int tamCliente Tamaño del vector clientes
 * \return Void
 *
 */
void bajaBicicleta (eBicicleta bicicletas[], int tama, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente );



/** \brief Ordena las bicicletas por Tipo y Marca
 *
 * \param eBicicleta bicicletas[] vector  de bicicletas a ordenar
 * \param int tama tamaño del vector bicicletas
* \param eColor Colores[] vector que contiene los id y descripciones de los colores
 * \param int tamCol Tamaño del vector colores
 * \param eTipo tipos[] vector que contiene los id y descripciones de los tipos de bicicleta
 * \param int tamTip Tamaño del vector tipos
 * \param eCliente clientes[] vector que contiene los id, nombres y sexos de los clientes
 * \param int tamCliente Tamaño del vector clientes
 * \return Void
 *
 */
void ordenarBicicletas(eBicicleta bicicletas[], int tamB);



/** \brief Valida que el rodado sea igual a los validos y si no pide reingresar el valor
 *
 * \param rodado float valor a vereficar
 * \return float devuelve el valor una vez verificado
 *
 */
float validarRodado(float rodado);
