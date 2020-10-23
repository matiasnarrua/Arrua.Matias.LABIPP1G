#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{

    int id;
    char nombre[20];
    char sexo;

} eCliente;

#endif // CLIENTE_H_INCLUDED



/** \brief Hace una lista de los clientes ya cargados
 *
 * \param clientes[] eCliente vector que se va a listar
 * \param tamCliente int tamaño del vector
 * \return void
 *
 */
void listarClientes(eCliente clientes[], int tamCliente );

/** \brief Valida el id del cliente
 *
 * \param clientes int id a validar
 * \return int retorna el id ya validado
 *
 */
int validarCliente(int clientes);
