#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];

} eTipo;


#endif // TIPO_H_INCLUDED


/** \brief Realiza un listado de los tipos
 *
 * \param [] eTipo tipos vector que se imprime en pantalla
 * \param tamTip int cantidad del vector
 * \return void
 *
 */
void listarTipos(eTipo tipos [], int tamTip );

/** \brief Carga la descripcion del tipo correspondiente al id que se le pasa
 *
 * \param descripcion[] char
 * \param id int
 * \param tipos[] eTipo
 * \param tamTip int
 * \return int
 *
 */
int cargarDescripcionTipo(char descripcion[], int id, eTipo tipos[], int tamTip );

/** \brief Valida el id del tipo de servicio, que este entre los parametros correctos
 *
 * \param tipo int id a validar
 * \return int retorna el valor una vez validado
 *
 */
int validarTipo(int tipo);
