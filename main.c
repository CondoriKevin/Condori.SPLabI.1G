#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "bicicleta.h"
int main()
{
     srand (time(NULL));  // esta linea va al inicio de main
    int aleatorio;
    LinkedList* lista = ll_newLinkedList();
    LinkedList* filtradaTipos;
    if(lista == NULL)
    {
        printf("No se pudo conseguir espacio en la memoria\n");
        exit(EXIT_FAILURE);
    }

    char confirm = 0;
    char seguir = 's';
    int flag=0;




    do
    {
        switch(menu())
        {
        case 1:
            controller_loadFromText("bicicleta.csv",lista);
            system("pause");
            flag=1;

            break;
        case 2:
            controller_loadFromBinary("bicicleta.bin",lista);
            system("pause");
            flag=1;

            break;
        case 3:
          if( !ll_isEmpty(lista))
            {
                controller_ListBicicleta(lista);
            }
            else
            {
                printf("La lista esta vacia. Debe cargar algo.\n");
            }
            system("pause");
            break;
        case 4:

            break;
        case 5:

if (flag == 1) {
				filtradaTipos = ll_newLinkedList();
				filtradaTipos = ll_filter(lista,
						funCritTipo1);
				controller_saveAsText("FiltradaTipos.csv",filtradaTipos);
			} else {
				printf("Primero debe cargar el archivo");
			}

            break;
        case 6:


            break;
        case 7:


            break;
        case 8:

            break;
        case 9:
                        printf("Esta seguro que desea salir? [s/n] : ");
            fflush(stdin);
            scanf("%c", &confirm);
            if (confirm == 's')
            {
                seguir = 'n';
            }
            break;


        }
    }
    while(seguir == 's');
//    ll_deleteLinkedList(listaEmpleados);
    return 0;
}



