#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "ePais.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* newList=NULL;
    newList=(LinkedList*) malloc(sizeof(LinkedList));
    if(newList!=NULL)
    {
        newList->size=0;
        newList->pFirstNode=NULL;
    }
    return newList;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodo=NULL;
	int tam=ll_len(this);

	if(this!=NULL&&nodeIndex>=0&&nodeIndex<tam)/*no puede ser = al tam porque el indice empieza de 0 y si hay 4 elementos llega ahsta el indice 3*/
	{
		pNodo=this->pFirstNode;
		while(nodeIndex>0)/*no igual porque debe tomar el nextnode del nodo anterior*/
		{
			pNodo=pNodo->pNextNode;/*que el nodo tenga la direccion del siguiente y asi*/
			nodeIndex--;
		}
	}

    return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodo=NULL;
    Node* anterior=NULL;
    int tam=ll_len(this);
    if(this!=NULL&&nodeIndex>=0&&nodeIndex<=tam)
    {
        /*pido espacio para ese nuevo nodo*/
        pNodo=(Node*)malloc(sizeof(Node));
        if(pNodo!=NULL)
        {
           pNodo->pElement=pElement;
           pNodo->pNextNode=NULL;

           if(nodeIndex==0)
           {
               pNodo->pNextNode=this->pFirstNode;
               this->pFirstNode=pNodo;
           }
           else
           {
            anterior=getNode(this,nodeIndex-1);
            pNodo->pNextNode=anterior->pNextNode;
            anterior->pNextNode=pNodo;
           }
           this->size++;
           returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)/*agrega un elemento al final*/
{
    int returnAux = -1;
    returnAux=addNode(this,ll_len(this),pElement);
    return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
	puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array.
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodo=NULL;

    pNodo=getNode(this,index);
    if(pNodo!=NULL)
    {
    	returnAux=pNodo->pElement;
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodo=NULL;

    pNodo=getNode(this,index);
    if(pNodo!=NULL)
    {
      pNodo->pElement=pElement;
      returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int tam=ll_len(this);
    Node* pNodo=NULL;
    Node* anterior=NULL;
    if(this!=NULL&&index>=0&&index<tam)
    {
    	pNodo=getNode(this,index);
    	if(pNodo!=NULL)
    	{
			if(index==0)
			{
				this->pFirstNode=pNodo->pNextNode;
				/*y borramos*/
				this->size--;
				free(pNodo);
				returnAux=0;

			}
			else
			{
				anterior=getNode(this,index-1);
				if(anterior!=NULL)
				{
					anterior->pNextNode=pNodo->pNextNode;
					/*y borramos*/
					this->size--;
					free(pNodo);
					returnAux=0;

				}
			}
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int tam;
    Node* pNodo=NULL;
    if(this!=NULL)
    {
    	tam=ll_len(this);
    	for(int i=0;i<tam;i++)
    	{
    		pNodo=getNode(this,i);
    		if(pNodo!=NULL)
    		{
    			ll_remove(this,i);
    			returnAux=0;
    		}
    		else
    		{
    			break;
    		}
    	}
    	this->pFirstNode=NULL;
    	this->size=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if(!ll_clear(this))
    	{
    		free(this);
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNodo=NULL;
    int tam;
    if(this!=NULL)
    {
    	tam=ll_len(this);
    	for(int i=0;i<tam;i++)
    	{
    		pNodo=getNode(this,i);
    		if(pNodo->pElement==pElement&&pNodo!=NULL)
    		{
    			returnAux=i;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int tam;
    if(this!=NULL)
    {
    	tam=ll_len(this);
    	if(!tam)
    	{
    		returnAux=1;
    	}
    	else
    	{
    		returnAux=0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    returnAux=addNode(this,index,pElement);
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int tam=ll_len(this);;

    if(this!=NULL&&index>=0&&index<tam)
    {
    	returnAux=ll_get(this,index);
    	if(ll_remove(this,index)==-1)
    	{
    		returnAux=NULL;
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNodo=NULL;
    int tam;
    if(this!=NULL)
    {
    	tam=ll_len(this);
    	returnAux=0;
    	for(int i=0;i<tam;i++)
    	{
    		pNodo=getNode(this,i);
    		if(pNodo->pElement==pElement&&pNodo!=NULL)
    		{
    			returnAux=1;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int tamThis2;
    void* auxEl=NULL;
    int contadorThis2=0;

    if(this!=NULL&&this2!=NULL)
    {
    	tamThis2=ll_len(this2);
    	for(int i=0;i<tamThis2;i++)
    	{
    		auxEl=ll_get(this2,i);
			if(ll_contains(this,auxEl))
			{
				contadorThis2++;
			}
    	}

        if(contadorThis2==tamThis2)
        {
        	returnAux=1;
        }
        else
        {
        	returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* pNodo=NULL;
    int i=0;
    int tam=ll_len(this);;
    if(this!=NULL&&from>=0&&from<tam&&to>from&&to<=tam)
    {
    	cloneArray=ll_newLinkedList();
    	if(cloneArray!=NULL)
    	{
			while(from<to)
			{
				pNodo=getNode(this,from);
				if(addNode(cloneArray,i,pNodo->pElement)!=-1&&pNodo!=NULL)
				{
					i++;
					from++;
				}
			}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int tam;
    if(this!=NULL)
    {
    	tam=ll_len(this);
    	cloneArray =ll_subList(this,0,tam);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* aux1=NULL;
    void* aux2=NULL;
    int tam;

    if(this!=NULL&&(order==1||order==0)&&pFunc!=NULL)
    {
    	tam=ll_len(this);
    	for(int i=0;i<tam-1;i++)
    	{
    		for(int j=i+1;j<tam;j++)
    		{
    			aux1=ll_get(this,i);
    			aux2=ll_get(this,j);

    			if(order==1&&pFunc(aux1,aux2)==1)
    			{
    				ll_set(this,i,aux2);
    				ll_set(this,j,aux1);
    				returnAux=0;
    			}
    			else
    			{
    				if(order==0&&pFunc(aux1,aux2)==-1)
    				{
    					ll_set(this,i,aux2);
    					ll_set(this,j,aux1);
    					returnAux=0;
    				}
    			}
    		}
    	}
    }
    return returnAux;
}

LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*))
{
    LinkedList* pList=NULL;
    if(this!=NULL&&pFunc!=NULL)
    {
        pList=ll_newLinkedList();
        if(pList!=NULL)
        {
            for(int i=0;i<ll_len(this);i++)
            {
                if(pFunc(ll_get(this,i)))
                {
                    ll_add(pList,ll_get(this,i));
                }
            }
        }

    }

    return pList;

}
int filtrarPorSinVacunar(void* pElement)
{
    ePais* aux;
    int returnAux=0;
    if(pElement!=NULL)
    {
        aux=(ePais*)pElement;
        if(aux->vac2dosis>30)
        {
            returnAux=1;
        }
    }
    return returnAux;
    return 0;
}

int filtrarsinVacunarAlHorno(void* pElement)
{
    ePais* aux;
    int returnAux=0;
    if(pElement!=NULL)
    {
        aux=(ePais*)pElement;
        if(aux->sinVacunar > aux->vac1dosis && aux->sinVacunar > aux->vac1dosis)
        {
            returnAux=1;
        }
    }
    return returnAux;
    return 0;
}

LinkedList* ll_map(LinkedList* this, void* (pFunc)(void*))
{
    int tam;
    void* pElement;
    LinkedList* mapeado = NULL;

    if(this!=NULL && *pFunc!=NULL){
        mapeado = ll_newLinkedList();
        tam=ll_len(this);

        for (int i = 0; i < tam; i++)
        {
            pElement = ll_get(this, i);
            pElement = pFunc(pElement);

            if(pElement!=NULL)
            {
                ll_add(mapeado, pElement);
            }
        }
    }

    return mapeado;
}

int randomVac2dosis(void)
{
    int random;
    random=rand()%(40-1+1)+1;

    return random;
}
int randomSinVacunar(int vac1dosis, int vac2dosis)
{
    int aux;
    aux=100-(vac1dosis+vac2dosis);
    return aux;
}

int randomVac1dosis(void)
{
    int random;
    random=rand()%(60-1+1)+1;
    return random;
}

void asignarRandomVac1dosis (void* pElement)
{
    int random=randomVac1dosis();
    ePais* auxiliar;

    if(pElement!=NULL)
    {
        auxiliar=(ePais*)pElement;
        auxiliar->vac1dosis=random;
        pElement=auxiliar;
    }
}

void asignarRandomSinVacunar (void* pElement)
{
    int auxInt;
    ePais* auxiliar;

    if(pElement!=NULL)
    {
        auxiliar=(ePais*)pElement;
        auxInt = randomSinVacunar(auxiliar->vac1dosis, auxiliar->vac2dosis);
        auxiliar->sinVacunar=auxInt;
        pElement=auxiliar;
    }
}

void asignarRandomVac2dosis (void* pElement)
{
    int random=randomVac2dosis();
    ePais* auxiliar;

    if(pElement!=NULL)
    {
        auxiliar=(ePais*)pElement;
        auxiliar->vac2dosis=random;
        pElement=auxiliar;
    }
}

int comparaPorVac1dosis(void* pPersonA,void* pPersonB)
{
	int retorno;
	ePais* aux1;
	ePais* aux2;
	int a;
	int b;

	if(pPersonA!=NULL&&pPersonB!=NULL)
	{
		aux1=(ePais*)pPersonA;
		aux2=(ePais*)pPersonB;

		if(pais_getVac1dosis(aux1,&a)
		&pais_getVac1dosis(aux2,&b))
		{
			if(a > b)
			{
			 retorno=1;
			}
			else
			{
				if(a < b)
				{
				 retorno=-1;
				}
				else
				{
					retorno=0;
				}
			}
		}
	}
	return retorno;
}
int comparaPorSinVacunar(void* pPersonA,void* pPersonB)
{
	int retorno;
	ePais* aux1;
	ePais* aux2;
	int a;
	int b;

	if(pPersonA!=NULL&&pPersonB!=NULL)
	{
		aux1=(ePais*)pPersonA;
		aux2=(ePais*)pPersonB;

		if(pais_getSinVacunar(aux1,&a)
		&pais_getSinVacunar(aux2,&b))
		{
			if(a > b)
			{
			 retorno=1;
			}
			else
			{
				if(a < b)
				{
				 retorno=-1;
				}
				else
				{
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

void mayorSinVacunas(LinkedList* this)
{
    ePais* aux;
    int sinVacunar;
    int ok;

    ll_sort(this,comparaPorSinVacunar,0);
    printf("    ID             NOMBRE      VAC2DOSIS       VAC1DOSIS      SIN VACUNAR\n");
    list_Pais(this,0);
    printf("\n\n");

    aux=ll_get(this,0);
    ok=pais_getSinVacunar(aux,&sinVacunar);
    if(ok)
    {
        printf("SIN VACUNAR: %d\n",sinVacunar);
    }

}
