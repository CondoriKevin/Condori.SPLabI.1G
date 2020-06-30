#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int IdBicicleta;
    char nombre[30];
    char tipo[30];
    int tiempo;

}eBicicleta;

/** \brief
 *
 * \return int
 *
 */
int menu();
/** \brief
 *
 * \param this eBicicleta*
 * \return void
 *
 */
void Bicicleta_delete(eBicicleta* this );
/** \brief
 *
 * \return eBicicleta*
 *
 */
eBicicleta* Bicicleta_new();
/** \brief
 *
 * \param IdBicicleta char*
 * \param nombre char*
 * \param tipo char*
 * \param tiempo char*
 * \return eBicicleta*
 *
 */
eBicicleta* Bicicleta_newParametros(char* IdBicicleta, char* nombre, char* tipo,char* tiempo);
/** \brief
 *
 * \param this eBicicleta*
 * \param IdBicicleta int
 * \return int
 *
 */
int Bicicleta_setIdBicicleta(eBicicleta* this,int IdBicicleta);
/** \brief
 *
 * \param this eBicicleta*
 * \param IdBicicleta int*
 * \return int
 *
 */
int Bicicleta_getIdBicicleta(eBicicleta* this,int* IdBicicleta);
/** \brief
 *
 * \param this eBicicleta*
 * \param nombre char*
 * \return int
 *
 */
int Bicicleta_setNombre(eBicicleta* this,char* nombre);
/** \brief
 *
 * \param this eBicicleta*
 * \param nombre char*
 * \return int
 *
 */
int Bicicleta_getNombre(eBicicleta* this, char* nombre);
/** \brief
 *
 * \param this eBicicleta*
 * \param tipo char*
 * \return int
 *
 */
int Bicicleta_setTipo(eBicicleta* this,char* tipo);
/** \brief
 *
 * \param this eBicicleta*
 * \param tipo char*
 * \return int
 *
 */
int Bicicleta_getTipo(eBicicleta* this, char* tipo);
/** \brief
 *
 * \param this eBicicleta*
 * \param tiempo int
 * \return int
 *
 */
int Bicicleta_setTiempo(eBicicleta* this,int tiempo);
/** \brief
 *
 * \param this eBicicleta*
 * \param tiempo int*
 * \return int
 *
 */
int Bicicleta_getTiempo(eBicicleta* this,int* tiempo);
/** \brief
 *
 * \param this eBicicleta*
 * \return int
 *
 */
int showBicicleta(eBicicleta* this);
/** \brief
 *
 * \param pElement void*
 * \return int
 *
 */
int funCritTipo1(void *pElement);
/** \brief
 *
 * \param pElement void*
 * \return int
 *
 */
int funCritTipo2(void *pElement);
/** \brief
 *
 * \param pElement void*
 * \return int
 *
 */
int funCritTipo3(void *pElement);
/** \brief
 *
 * \param pElement void*
 * \return int
 *
 */
int funCritTipo4(void *pElement);







#endif // Bicicleta_H_INCLUDED

