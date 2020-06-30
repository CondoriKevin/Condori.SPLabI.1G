#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicleta.h"
#include "controller.h"
#include "validaciones.h"
#include "parce.h"
#include <ctype.h>
#include<string.h>

int controller_loadFromText(char* path, LinkedList* pArrayListBicicleta)
{
    int todoOk = -1;
    FILE* pFile;
    if(path != NULL && pArrayListBicicleta != NULL)
    {

        pFile = fopen(path, "r");
        if(pFile != NULL)
        {
            if( parser_BicicletaFromText(pFile, pArrayListBicicleta) == 1)
            {
                todoOk = 1;
                printf("Bicicletas cargadas. \n");
            }
            else
            {
                printf("No se pudieron cargar mega F.\n");
            }
            fclose(pFile);
        }
        else
        {
            printf("\nEl archivo no pudo abrirse.\n");
        }
    }

    return todoOk;
}

//************************************************************************************************************************************/
int controller_loadFromBinary(char* path, LinkedList* pArrayListBicicleta)
{
    int todoOk=-1;
    FILE* pFile;
    if(path!=NULL && pArrayListBicicleta!=NULL)
    {

        pFile=fopen(path,"rb");
        if( pFile != NULL)
        {
            if(parser_BicicletaFromBinary(pFile,pArrayListBicicleta)==1)
            {
                todoOk=1;
                printf("Bicicletas cargados correctamente. \n");
            }
            else
            {
                printf("No se pudieron cargar Ultra F.\n");
            }

        }
        else
        {
            printf("\nEl archivo no pudo abrirse.\n");
        }
        fclose(pFile);
    }
    return todoOk;
}


//************************************************************************************************************************************/
int controller_ListBicicleta(LinkedList* pArrayListBicicleta)
{
    int todoOk = -1;
    int size = ll_len(pArrayListBicicleta);
    int flag = 0;
    eBicicleta* auxBicicleta;

    if( pArrayListBicicleta != NULL)
    {
        todoOk = 1;
        printf("\n idBicicleta  Nombre  tipo  tiempo  \n");
        printf("------------------------------------------------------------------------\n");
        for(int i = 0; i< size; i++)
        {
            auxBicicleta = (eBicicleta*) ll_get(pArrayListBicicleta, i);
            if (  auxBicicleta  != NULL )
            {
                showBicicleta(auxBicicleta);
                flag = 1;
            }
        }
        printf("\n\n");
        if(flag == 0)
        {
            printf("\nNo hay nada que mostrar\n");
        }
    }
    return todoOk;

}
//************************************************************************************************************************************/
int controller_saveAsText(char* path, LinkedList* pArrayListBicicleta)
{
    FILE* f = fopen(path,"w") ;
    int size =  ll_len(pArrayListBicicleta);
    eBicicleta* auxBicicleta;
    int todoOk = -1;

    if(f != NULL)
    {
        fprintf(f,"\n  idBicicleta  Nombre  tipo  tiempo  \n");
        for (int i =0; i<size; i++)
        {
            auxBicicleta = (eBicicleta*) ll_get(pArrayListBicicleta, i);
            if (auxBicicleta !=NULL)
            {
                fprintf(f, "%d  %s  %s  %d \n", auxBicicleta->IdBicicleta, auxBicicleta->nombre, auxBicicleta->tipo, auxBicicleta->tiempo);
                todoOk = 1;
            }
        }
        fclose(f);

    }
    return todoOk;
}
