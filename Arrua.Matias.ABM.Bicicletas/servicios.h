#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED


typedef struct
{
    int id;
    char descripcion[25];
    int precio;

} eServicio;



#endif // SERVICIOS_H_INCLUDED

/** \brief realiza un listado de todos los servicios cargados en el vector
 *
 * \param servicios[] eServicio vector a listar
 * \param tamSer int tamaño del vector
 * \return void
 *
 */
void listarServicios(eServicio servicios[], int tamSer );

/** \brief Carga la descripcion del servicio correspondiente al id que se le pasa
 *
 * \param descripcion[] char
 * \param id int id a comparar
 * \param servicios[] eServicio
 * \param tamSer int
 * \return int
 *
 */
int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tamSer );

/** \brief Valida que el servicio este entre los parametros correctos
 *
 * \param servicio int id a validar
 * \return int el id una vez validado
 *
 */
int validarServicio(int servicio);
