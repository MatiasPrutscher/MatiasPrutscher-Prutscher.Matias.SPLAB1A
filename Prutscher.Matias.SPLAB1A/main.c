#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"
#include "controladores.h"
#include "ePais.h"
#include "utn_biblioteca.h"
#define TAMARCHIVO 50

int menu(void);
int subMenu(void);
int main()
{
    LinkedList* lista=ll_newLinkedList();
    LinkedList* listaFiltradaSinVacunar=ll_newLinkedList();
    LinkedList* listaFiltradaInfectadosHorno=ll_newLinkedList();
    srand(time(NULL));

    int menuOption;
    int flagCarga=0;
    char archivo[TAMARCHIVO];


    if(lista==NULL)
    {
        printf("No se pudo conseguir memoria\n");
        exit(EXIT_FAILURE);
    }

    do
    {
        menuOption=menu();
        switch(menuOption)
        {
        case 1:
            if(!flagCarga)
            {
                printf("ingrese nombre del archivo tipo csv ej: data.csv: ");
                fflush(stdin);
                scanString(archivo,TAMARCHIVO);
                if(controller_loadFromText(archivo,lista))
                {
                    flagCarga=1;
                }

            }
            else
            {
                printf("Ya fue cargado un archivo\n");
            }
            break;
        case 2:
            list_Paises(lista);
            break;
        case 3:
            lista=ll_map(lista,asignarRandomVac1dosis);
            lista=ll_map(lista,asignarRandomVac2dosis);
            lista=ll_map(lista,asignarRandomSinVacunar);
            printf("Asignaciones realizadas con exito\n");
            break;
        case 4:
            listaFiltradaSinVacunar=ll_filter(lista,filtrarPorSinVacunar);
            if(listaFiltradaSinVacunar!=NULL)
            {
                list_Paises(listaFiltradaSinVacunar);
                controller_saveAsText("pandemiaSalvados.csv" , listaFiltradaSinVacunar);
            }
            break;
        case 5:
            listaFiltradaInfectadosHorno=ll_filter(lista,filtrarsinVacunarAlHorno);
            if(listaFiltradaInfectadosHorno!=NULL)
            {
                list_Paises(listaFiltradaInfectadosHorno);
                controller_saveAsText("pandemiaAlhorno.csv" , listaFiltradaInfectadosHorno);
            }
            break;
        case 6:
            switch(subMenu())
            {
                case 1:
                    ll_sort(lista,comparaPorVac1dosis,1);
                    break;
                case 2:
                    ll_sort(lista,comparaPorVac1dosis,0);
                    break;
            }
            break;
        case 7:
            mayorSinVacunas(lista);
            break;
        case 8:
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
        system("pause");
    }while(menuOption!=8);


    ll_deleteLinkedList(lista);
    return 0;
}

int menu(void)
{

    int opcion;
    system("cls");
    printf("********Menu de opciones**********\n");

    printf("1-Cargar Archivo\n");
    printf("2-Imprimir lista\n");
    printf("3-Asignar estadisticas\n");
    printf("4-Filtrar por paises exitosos\n");
    printf("5-Filtrar por paises en el horno\n");
    printf("6-Ordenar por nivel de vacunacion:\n");
    printf("7-Mostrar mas castigado\n");
    printf("8-Salir\n");

    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
int subMenu(void)
{
    int opcion;
    system("cls");
    printf("********Menu de opciones**********\n");

    printf("1-Ascendente\n");
    printf("2-Descendente\n");

    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

