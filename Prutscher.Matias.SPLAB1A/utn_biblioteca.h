#include "LinkedList.h"


#ifndef CONTROLADORES_H_INCLUDED
#define CONTROLADORES_H_INCLUDED
/*TEXTO*/
int controller_loadFromText(char* path , LinkedList* pArrayList);
int parser_FromText(FILE* pFile , LinkedList* pArrayList);
int controller_saveAsText(char* path , LinkedList* pArrayList);

#endif // CONTROLADORES_H_INCLUDED
