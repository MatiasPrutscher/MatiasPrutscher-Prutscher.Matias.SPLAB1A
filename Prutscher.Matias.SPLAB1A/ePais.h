#ifndef EPAIS_H_INCLUDED
#define EPAIS_H_INCLUDED
#include "linkedlist.h"

typedef struct{

int id;
char nombre[25];
int vac1dosis;
int vac2dosis;
int sinVacunar;

}ePais;

int list_Paises(LinkedList* pArrayList);
int list_Pais(LinkedList* pArrayList,int index);
int pais_getVac2dosis(ePais* this,int* vac2dosis);
int pais_getSinVacunar(ePais* this,int* sinVacunar);
int pais_getVac1dosis(ePais* this,int* vac1dosis);
int pais_getId(ePais* this,int* id);
int pais_getNombre(ePais* this,char* nombre);
int pais_setNombre(ePais* this,char* nombre);
int pais_setVac1dosis(ePais* this,int vac1dosis);
int pais_setSinVacunar(ePais* this,int sinVacunar);
int pais_setVac2dosis(ePais* this,int vac2dosis);
int pais_setId(ePais* this,int id);
int pais_delete(ePais* pais);
ePais* pais_newParametros(char* idStr,char* nombreStr,char* recuperadosStr,char* infectadosStr,char* muertosStr);
ePais* pais_new();

#endif // EPAIS_H_INCLUDED
