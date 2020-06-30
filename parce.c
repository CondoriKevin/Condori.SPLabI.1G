#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicleta.h"

int parser_BicicletaFromText(FILE* pFile, LinkedList* pArrayListBicicleta)
{
    int cantParametros;
    eBicicleta* auxBicicleta;
    int todoOk = -1;
    char buffer[4][50];

    if (pFile != NULL  && pArrayListBicicleta != NULL)
    {
        fscanf(pFile, "%*[^\n]\n");
        while(!feof(pFile))
        {
            auxBicicleta = Bicicleta_new();
            cantParametros = fscanf(pFile,"%[^,] , %[^,], %[^,], %[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cantParametros == 4)
            {
                auxBicicleta = Bicicleta_newParametros(buffer[0], buffer[1], buffer[2],  buffer[3]);
                ll_add(pArrayListBicicleta, auxBicicleta);
                todoOk = 1;
            }
            else
            {
                break;
            }
        }
    }

    return todoOk;
}

//************************************************************************************************************************************/
int parser_BicicletaFromBinary(FILE* pFile, LinkedList* pArrayListBicicleta)
{
    int todoOk=-1;
    eBicicleta* auxBicicleta;

    if(pFile!=NULL && pArrayListBicicleta!= NULL)
    {
        while(!feof(pFile))
        {
            auxBicicleta=Bicicleta_new();
            if ( fread ( auxBicicleta, sizeof(eBicicleta),1,pFile) != 0)
            {
                ll_add(pArrayListBicicleta, auxBicicleta);
                todoOk = 1;
            }
        }

    }
    return todoOk;
}
