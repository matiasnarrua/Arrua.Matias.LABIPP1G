#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED


typedef struct
{
    int id;
    char  nombreColor[20];

} eColor;

#endif // COLORES_H_INCLUDED


/** \brief Realiza un listado de los colores ya cargados
 *
 * \param colores[] eColor Vector a listar
 * \param tamCol int tamaño del vector
 * \return void
 *
 */
void listarColores(eColor colores[], int tamCol );

/** \brief compara el id que llega por referencia con el valor que tiene el vector en el campo id color si son iguales copia el campo descripcion color y lo retorna
 *
 * \param descripcion[] char
 * \param id int
 * \param colores[] eColor
 * \param tamCol int
 * \return int
 *
 */
int cargarDescripcionColor(char descripcion[], int id, eColor colores[], int tamCol );

/** \brief Valida que el id del color ingresado este entre los parametros validos
 *
 * \param color int id a validar
 * \return int retorna el valor ya validado
 *
 */
int validarColor(int color);


