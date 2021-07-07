#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "ePais.h"
#include <string.h>
#include "controladores.h"

/*TEXTO*/
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    FILE* archivo;
	int retorno=0;


	if(path!=NULL&&pArrayList!=NULL)
	{
		archivo=fopen(path,"r");
		if(path!=NULL)
		{
			if(parser_FromText(archivo,pArrayList))
			{
				retorno=1;
			}
		}
	}

	if(retorno)
	{
		printf("\nDatos cargados con exito\n");
	}

	fclose(archivo);
    return retorno;
}


int parser_FromText(FILE* pFile , LinkedList* pArrayList)
{
	char a[128];
	char b[128];
	char c[128];
	char d[128];
    char e[128];
	int cantidadLeida;
	int flag=0;
	int titulo=1;
	ePais* auxiliar;

	if(pFile!=NULL&&pArrayList!=NULL)
	{
		do
		{
				cantidadLeida=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",a,b,c,d,e);

				if(cantidadLeida==5&&strlen(a)<128&&strlen(b)<128&&strlen(c)<128&&strlen(d)<128&&strlen(e)<128&&titulo!=1)
				{
					auxiliar=pais_newParametros(a,b,c,d,e);
					if(auxiliar!=NULL)
					{
						ll_add(pArrayList,auxiliar);
						flag=1;
					}
					else
					{
						pais_delete(auxiliar);
					}
				}
				else
				{
					titulo=0;
				}
		}while(!feof(pFile));
	}
    return flag;
}

int controller_saveAsText(char* path , LinkedList* pArrayList)
{
	int retorno=0;
	int tam=ll_len(pArrayList);
	FILE* archivo;
	ePais* auxiliar;

	char nombre[128];
	int id;
	int vac1dosis;
	int vac2dosis;
	int sinVacunar;

	if(path!=NULL&&pArrayList!=NULL)
	{
		archivo=fopen(path,"w");
		if(archivo!=NULL)
		{
			fprintf(archivo,"id,pais,vac1dosis,vac2dosis,sinVacunar\n");
			for(int i=0;i<tam;i++)
			{
					auxiliar=(ePais*)ll_get(pArrayList,i);
					if(auxiliar!=NULL)
					{
						if(pais_getId(auxiliar,&id)
                            &&pais_getNombre(auxiliar,nombre)
                            &&pais_getVac1dosis(auxiliar,&vac1dosis)
                            &&pais_getSinVacunar(auxiliar,&sinVacunar)
                            &&pais_getVac2dosis(auxiliar,&vac2dosis))
							{
								fprintf(archivo,"%d,%s,%d,%d,%d\n",id,nombre,vac2dosis,sinVacunar,vac1dosis);
							}
						retorno=1;
					}
			}
		}
	}

	fclose(archivo);
    return retorno;
}
