#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "validaciones.h"


int menu()
{
    int option;

    system("cls");
    printf("**** Menu **** \n\n");
    printf("1.   Cargar los datos (modo texto).  \n");
    printf("2.   Cargar los datos (modo binario).\n");
    printf("3.   lista de Bicicletas.\n");
    printf("4.   Asignacion de tiempos\n");
    printf("5.   lista filtrada por tipo .\n");
    printf("6.   Mostar pocisones.\n");
    printf("7.   Ordenar empleados.\n");
    printf("8.   Guardar po.\n");
    printf("9.   Salir.\n");
    if(utn_getNumero(&option, "Enter option: ","",1,9,0) == -1)
    {
        option = 0;
    }

    return option;

}
/////////////
void Bicicleta_delete(eBicicleta* this )
{

    if ( this != NULL)
    {
        free(this);
    }

}
/////////////
eBicicleta* Bicicleta_new()
{
    return (eBicicleta*) malloc(sizeof(eBicicleta));
}
/////////////
eBicicleta* Bicicleta_newParametros(char* IdBicicleta, char* nombre, char* tipo,char* tiempo)
{
    eBicicleta* newBicicleta;

    newBicicleta = Bicicleta_new();

    if(newBicicleta != NULL)
    {

        if   ( (Bicicleta_setIdBicicleta(newBicicleta, atoi(IdBicicleta)) == -1) ||
                (Bicicleta_setNombre(newBicicleta, nombre) == -1) ||
                (Bicicleta_setTipo(newBicicleta, tipo) ==-1) ||
                (Bicicleta_setTiempo(newBicicleta, atoi(tiempo) ==-1) ))

        {

            Bicicleta_delete(newBicicleta);
            newBicicleta = NULL;
        }

    }
    return newBicicleta;
}
/////////////
int Bicicleta_setIdBicicleta(eBicicleta* this,int IdBicicleta)
{
    int succes = -1;

    if ( this != NULL && IdBicicleta >0 && IdBicicleta <= 100)
    {
        this->IdBicicleta = IdBicicleta;
        succes = 1;
    }
    return succes;
}

/////////////
int Bicicleta_getIdBicicleta(eBicicleta* this,int* IdBicicleta)
{
    int succes = -1;
    if(this != NULL && IdBicicleta!=NULL)
    {
        *IdBicicleta = this-> IdBicicleta;
        succes = 1;
    }
    return succes;
}
/////////////
int Bicicleta_setNombre(eBicicleta* this,char* nombre)
{
    int succes = -1;

    if (this != NULL  && strlen(nombre) >= 3  && strlen(nombre) < 127)
    {
        strcpy(this ->nombre, nombre);
        succes = 1;
    }
    return succes;
}

/////////////
int Bicicleta_getNombre(eBicicleta* this, char* nombre)
{
    int succes = -1;
    if(this != NULL && nombre!=NULL)
    {
        strcpy(nombre, this ->nombre);
        succes = 1;
    }
    return succes;
}
/////////////
int Bicicleta_setTipo(eBicicleta* this,char* tipo)
{
    int succes = -1;

    if (this != NULL  && strlen(tipo) >= 3  && strlen(tipo) < 127)
    {
        strcpy(this ->tipo, tipo);
        succes = 1;
    }
    return succes;
}

/////////////
int Bicicleta_getTipo(eBicicleta* this, char* tipo)
{
    int succes = -1;
    if(this != NULL && tipo!=NULL)
    {
        strcpy(tipo, this ->tipo);
        succes = 1;
    }
    return succes;
}
/////////////
int Bicicleta_setTiempo(eBicicleta* this,int tiempo)
{
    int succes = -1;

    if ( this != NULL && tiempo >0 && tiempo <= 100)
    {
        this->tiempo = tiempo;
        succes = 1;
    }
    return succes;
}

/////////////
int Bicicleta_getTiempo(eBicicleta* this,int* tiempo)
{
    int succes = -1;
    if(this != NULL && tiempo!=NULL)
    {
        *tiempo = this->tiempo;
        succes = 1;
    }
    return succes;
}

/////////////
int showBicicleta(eBicicleta* this)
{
    int todoOk =-1;
    if(this != NULL)
    {
        todoOk = 1;

        printf("%d  %s  %s  %d \n", this->IdBicicleta, this->nombre, this->tipo, this->tiempo);
    }
    return todoOk;
}
/////////////
int funCritTipo1(void *pElement) {
eBicicleta* aux;

aux=(eBicicleta*)pElement;

	int retorno;
	if (strcmp(aux->tipo, "bmx") == 0) {
		retorno = 1;
	} else {
		retorno = 0;
	}

	return retorno;
}
int funCritTipo2(void *pElement) {
eBicicleta* aux;

aux=(eBicicleta*)pElement;

	int retorno;
	if (strcmp(aux->tipo, "playera") == 0) {
		retorno = 1;
	} else {
		retorno = 0;
	}

	return retorno;
}
int funCritTipo3(void *pElement) {
eBicicleta* aux;

aux=(eBicicleta*)pElement;

	int retorno;
	if (strcmp(aux->tipo, "mtb") == 0) {
		retorno = 1;
	} else {
		retorno = 0;
	}

	return retorno;
}
int funCritTipo4(void *pElement) {
eBicicleta* aux;

aux=(eBicicleta*)pElement;

	int retorno;
	if (strcmp(aux->tipo, "paseo") == 0) {
		retorno = 1;
	} else {
		retorno = 0;
	}

	return retorno;
}
/*int funCritHoras(void *pElement)
{
    eBicicleta *arg1 = (eBicicleta*) pElement;
    eBicicleta *arg11 = (eBicicleta*) pElement;

    int HoraDespegue;
    int HoraLlegada;
    int retorno;

    Bicicleta_getHoraDespegue(arg1, &HoraDespegue);
    Bicicleta_getHoraLlegada(arg11, &HoraLlegada);

    if (HoraLlegada = 3 )
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}*/
/////////////

