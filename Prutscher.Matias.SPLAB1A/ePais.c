#include <stdio.h>
#include <stdlib.h>
#include "ePais.h"
#include <string.h>
#include "linkedlist.h"
#include "utn_biblioteca.h"



ePais* pais_new()
{
 	ePais* nuevoPais=NULL;

	nuevoPais=(ePais*)malloc(sizeof(ePais));

	if(nuevoPais!=NULL)
	{
		nuevoPais->id=0;
		nuevoPais->sinVacunar=0;
		nuevoPais->vac1dosis=0;
		nuevoPais->vac2dosis=0;
		strcpy(nuevoPais->nombre,"");
	}
    return nuevoPais;
}
ePais* pais_newParametros(char* idStr,char* nombreStr,char* vac2dosisStr,char* vac1dosisStr,char* sinVacunarStr)
{

	ePais* nuevoPaisParams=NULL;
	nuevoPaisParams=pais_new();
	if(nuevoPaisParams!=NULL)
	{
		if(!(pais_setId(nuevoPaisParams,atoi(idStr))
			&&pais_setSinVacunar(nuevoPaisParams,atoi(sinVacunarStr))
			&&pais_setVac2dosis(nuevoPaisParams,atoi(vac2dosisStr))
            &&pais_setVac1dosis(nuevoPaisParams,atoi(vac1dosisStr))
            &&pais_setNombre(nuevoPaisParams,nombreStr)))
		{
			pais_delete(nuevoPaisParams);
		}
	}
	return nuevoPaisParams;
}
int pais_delete(ePais* pais)
{

	int retorno=0;
	if(pais!=NULL)
	{
		free(pais);
		retorno=1;
	}

	return retorno;

}

/*--------------GETTERS Y SETTERS--------------------*/

int pais_setId(ePais* this,int id)
{
 	int retorno=0;
	if(this!=NULL&&id>0)
	{
		this->id=id;
		retorno=1;
	}
	return retorno;
}

int pais_setVac2dosis(ePais* this,int vac2dosis)
{
 	int retorno=0;
	if(this!=NULL&&vac2dosis>=0)
	{
		this->vac2dosis=vac2dosis;
		retorno=1;
	}
	return retorno;
}
int pais_setSinVacunar(ePais* this,int sinVacunar)
{
 	int retorno=0;
	if(this!=NULL&&sinVacunar>=0)
	{
		this->sinVacunar=sinVacunar;
		retorno=1;
	}
	return retorno;
}
int pais_setVac1dosis(ePais* this,int vac1dosis)
{
 	int retorno=0;
	if(this!=NULL&&vac1dosis>=0)
	{
		this->vac1dosis=vac1dosis;
		retorno=1;
	}
	return retorno;
}
int pais_setNombre(ePais* this,char* nombre)
{
 	int retorno=0;
	if(this!=NULL&&nombre!=NULL&&validarStringLetras(nombre,sizeof(nombre)))
	{
		strcpy(this->nombre,nombre);
		retorno=1;
	}
	return retorno;
}
int pais_getNombre(ePais* this,char* nombre)
{
 	int retorno=0;
	if(this!=NULL&&nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		retorno=1;
	}

	return retorno;
}
int pais_getId(ePais* this,int* id)
{
 	int retorno=0;
	if(this!=NULL&&id!=NULL)
	{
		*id=this->id;
		retorno=1;
	}
	return retorno;
}
int pais_getVac2dosis(ePais* this,int* vac2dosis)
{
 	int retorno=0;
	if(this!=NULL&&vac2dosis!=NULL)
	{
		*vac2dosis=this->vac2dosis;
		retorno=1;
	}
	return retorno;
}
int pais_getSinVacunar(ePais* this,int* sinVacunar)
{
 	int retorno=0;
	if(this!=NULL&&sinVacunar!=NULL)
	{
		*sinVacunar=this->sinVacunar;
		retorno=1;
	}
	return retorno;
}
int pais_getVac1dosis(ePais* this,int* vac1dosis)
{
 	int retorno=0;
	if(this!=NULL&&vac1dosis!=NULL)
	{
		*vac1dosis=this->vac1dosis;
		retorno=1;
	}
	return retorno;
}

int list_Pais(LinkedList* pArrayList,int index)
{
	int retorno=0;
	char nombre[128];
	int id;
	int sinVacunar;
    int vac2dosis;
    int vac1dosis;
	ePais* auxiliar=NULL;

	if(pArrayList!=NULL&&index>=0)
	{
		auxiliar=(ePais*)ll_get(pArrayList,index);
		if(auxiliar!=NULL)
		{
			if(pais_getId(auxiliar,&id)
				&&pais_getNombre(auxiliar,nombre)
                &&pais_getSinVacunar(auxiliar,&sinVacunar)
				&&pais_getVac2dosis(auxiliar,&vac2dosis)
				&&pais_getVac1dosis(auxiliar,&vac1dosis))
			{
				printf("%6d  %20s      %8d      %8d      %8d\n",id,nombre,vac2dosis,vac1dosis,sinVacunar);
				retorno=1;
			}
		}


	}

	return retorno;/*flag si se mostro o no*/
}

int list_Paises(LinkedList* pArrayList)
{

	int retorno=0;
	int tam;
	int flag;


	if(pArrayList!=NULL)
	{
		tam=ll_len(pArrayList);
		printf("%d\n",tam);
		retorno=1;
		printf("    ID             NOMBRE      VAC2DOSIS       VAC1DOSIS      SIN VACUNAR\n");
		for(int i=0;i<tam;i++)
		{
			flag=list_Pais(pArrayList,i);
		}
	}


	if(!flag)
	{
		printf("No hay empleados que mostrar\n");
	}

    return retorno;
}

