#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


int menuInformes();

/** \brief Hace un listado de las bicicletas por el color que quiera el usuario
 *
 * \param bicicletas[] eBicicleta Vector de bicicletas
 * \param tamB int tamaño del vector de bicicletas
 * \param colores[] eColor vector que contiene los colores
 * \param tamCol int tamaño del vector de colores
 * \param tipos[] eTipo vector que contiene los tipo de bicicleta
 * \param tamTip int tamañano del vector de tipos
 * \param clientes[] eCliente vector que contiene los clientes
 * \param tamCliente int tamaño del vector de clientes
 * \return void
 *
 */
void mostrarBicicletaXColor(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente);

/** \brief Hace un listado de las bicicletas por el tipo que seleccione el usuario
 *
 * \param bicicletas[] eBicicleta Vector de bicicletas
 * \param tamB int tamaño del vector de bicicletas
 * \param colores[] eColor vector que contiene los colores
 * \param tamCol int tamaño del vector de colores
 * \param tipos[] eTipo vector que contiene los tipo de bicicleta
 * \param tamTip int tamañano del vector de tipos
 * \param clientes[] eCliente vector que contiene los clientes
 * \param tamCliente int tamaño del vector de clientes
 * \return void
 *
 */
void mostrarBicicletaXTipo(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente);

/** \brief Muestra las bicicletas que tienen el menor rodados
 *
 * \param bicicletas[] eBicicleta Vector de bicicletas
 * \param tamB int tamaño del vector de bicicletas
 * \param colores[] eColor vector que contiene los colores
 * \param tamCol int tamaño del vector de colores
 * \param tipos[] eTipo vector que contiene los tipo de bicicleta
 * \param tamTip int tamañano del vector de tipos
 * \param clientes[] eCliente vector que contiene los clientes
 * \param tamCliente int tamaño del vector de clientes
 * \return void
 *
 */
void mostrarBicicletasMenorRodado(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente);

/** \brief
 *
 ** \param bicicletas[] eBicicleta Vector de bicicletas
 * \param tamB int tamaño del vector de bicicletas
 * \param colores[] eColor vector que contiene los colores
 * \param tamCol int tamaño del vector de colores
 * \param tipos[] eTipo vector que contiene los tipo de bicicleta
 * \param tamTip int tamañano del vector de tipos
 * \param clientes[] eCliente vector que contiene los clientes
 * \param tamCliente int tamaño del vector de clientes
 * \return void
 *
 */

void listarBicicletasXTipo(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente);

/** \brief Lista todas las bicicletas separadas por el tipo
 *
* \param bicicletas[] eBicicleta Vector de bicicletas
 * \param tamB int tamaño del vector de bicicletas
 * \param colores[] eColor vector que contiene los colores
 * \param tamCol int tamaño del vector de colores
 * \param tipos[] eTipo vector que contiene los tipo de bicicleta
 * \param tamTip int tamañano del vector de tipos
 * \param clientes[] eCliente vector que contiene los clientes
 * \param tamCliente int tamaño del vector de clientes
 * \return void
 *
 */
void contarBicicletasXColorYTipo(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol,eTipo tipos[], int tamTip, eCliente clientes[], int tamCliente);

/** \brief Muestra el color mas elegido de todas las bicicletas
 *
 * \param bicicletas[] eBicicleta Vector de bicicletas
 * \param tamB int tamaño del vector de bicicletas
 * \param colores[] eColor vector que contiene los colores
 * \param tamCol int tamaño del vector de colores
 * \return void
 *
 */
void MostrarColorMasElegido(eBicicleta bicicletas[], int tamB, eColor colores[], int tamCol);
