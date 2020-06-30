#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListBicicleta);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

 //************************************************************************************************************************************/
int controller_loadFromBinary(char* path , LinkedList* pArrayListBicicleta);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

//************************************************************************************************************************************/
int controller_ListBicicleta(LinkedList* pArrayListBicicleta);
/** \brief Listar empleados
*
* \param pArrayListEmployee LinkedList*
* \return int
*
*/

//************************************************************************************************************************************/
int controller_saveAsText(char* path, LinkedList* pArrayListBicicleta);
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

#endif // VALIDATIONS_H_INCLUDED
