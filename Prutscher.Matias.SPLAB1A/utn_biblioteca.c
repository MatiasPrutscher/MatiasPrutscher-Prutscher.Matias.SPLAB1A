#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"

char utn_getLetra(char mensaje[])
{
    char letra;
    printf("%s",mensaje);
    scanf("%c",&letra);

    return letra;
}
int utn_validarTelefono (char vector[])
{
    int retorno=0;
    int retornoAuxiliar=0;
    int contadorGuion=0;

    for(int i=0;vector[i]!='\0';i++)
    {
        if(vector[i]!=' '&&vector[i]!='-'&&(vector[i]<'0'||vector[i]>'9'))
        {
            retornoAuxiliar=1;
        }
        else
        {
            if(vector[i]=='-')
            {
                contadorGuion++;
            }
        }
    }

    if(contadorGuion==1&&retornoAuxiliar==0)
    {
        retorno=1;
    }

    return retorno;
}

void utn_inicializadorString (int vector[],int tam,int inicio)
{
    for(int i=0;i<tam;i++)
    {
        vector[i]=inicio;
    }
}

int utn_buscadorEspacio(int vector[],int tam,int buscado)
{
    int retorno=-1;
    for(int i=0;i<tam;i++)
    {
        if(vector[i]==buscado)
        {
            retorno=i;//Para despues saber la posicion en la que esta lo buscado
            break;
        }
    }

    return retorno;
}

int utn_numeroMayor(int x, int y,int* mayor)
{
    int retorno;

    if(x==y)
    {
        retorno=0;
    }
    else
    {
        retorno=1;
        if(x>y)
        {
            *mayor=x;
        }
        else
        {
            if(y>x)
            {
                *mayor=y;
            }
        }
    }

    return retorno;

}
int utn_inicializadorFloat (float vector[],int tam,float inicio)
{
    int retorno=-1;
    if(vector!=NULL&&tam>0)
    {
        retorno=0;
        for(int i=0;i<tam;i++)
        {
            vector[i]=inicio;
        }
    }

    return retorno;
}

int getAlfanumerico(char string[],int tam,char* mensaje,char* mensajeError,int reintentos)/*construye alfa*/
{
    char auxiliarResultado[tam];
    int validacion=0;

    if(string!=NULL && mensaje!= NULL && mensajeError!= NULL &&reintentos>=0&&tam>0)
    {
        for(int i=0;i<=reintentos;reintentos--)
        {
            printf("\n%s",mensaje);
            if(alfanumericoValidated(auxiliarResultado,tam))
            {
                strcpy(string,auxiliarResultado);
                validacion=1;
                break;
            }
            else
            {
                printf("\n%s\n",mensajeError);
            }
        }
    }

    return validacion;
}


int getString(char string[],int tam,char* mensaje,char* mensajeError,int reintentos)/*construye letras*/
{
    char auxiliarResultado[tam];
    int validacion=0;

    if(string!=NULL && mensaje!= NULL && mensajeError!= NULL &&reintentos>=0&&tam>0)
    {
        for(int i=0;i<=reintentos;reintentos--)
        {
            printf("\n%s",mensaje);
            if(stringValidated(auxiliarResultado,tam))
            {
                strcpy(string,auxiliarResultado);
                validacion=1;
                break;
            }
            else
            {
                printf("\n%s\n",mensajeError);
            }
        }
    }

    return validacion;
}
int alfanumericoValidated(char cadena[],int tam)/*confirma datos de alfa*/
{
    int retorno=0;
    char bufferString[tam];
    if(cadena!=NULL&&tam>0)
    {
        if(scanString(bufferString,tam)&&strlen(bufferString)>0)
        {
            retorno=1;
            strncpy(cadena,bufferString,tam);
        }
    }
    return retorno;
}
int scanString (char ingreso[],int tam)/*toma datos*/
{
    int retorno=0;
    char auxiliar[4500];

    if(ingreso!=NULL&&tam>0)
    {
        fflush(stdin);

        if((fgets(auxiliar,sizeof(auxiliar),stdin)!=NULL))
        {
            if(auxiliar[strlen(auxiliar)-1]=='\n')
            {
                 auxiliar[strlen(auxiliar)-1]='\0';
            }
            if(strlen(auxiliar)<=tam)
            {
                strncpy(ingreso,auxiliar,tam);
                retorno=1;
            }
        }

    }
   return retorno;
}

int stringValidated(char cadena[],int tam)/*confirma datos de leras*/
{
    int retorno=0;
    char bufferString[tam];
    if(cadena!=NULL&&tam>0)
    {
        if(scanString(bufferString,tam)&&validarStringLetras(bufferString,tam)&&strlen(bufferString)>0)
        {
            retorno=1;
            strncpy(cadena,bufferString,tam);
        }
    }
    return retorno;
}

int validarStringLetras (char vector[],int tam)/*valida letras*/
{
    int retorno=1;

    if(vector!=NULL&&tam>0)
    {
         for(int i=0;vector[i]!='\0'&&i<tam;i++)
        {
            if(vector[i]!=' '&&(vector[i]<'a'||vector[i]>'z')&&(vector[i]<'A'||vector[i]>'Z'))
            {
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}
int getFloat(float* numero,char* mensaje,char* mensajeError,int max,int min,int reintentos)/*construye*/
{
    float auxiliarResultado;
    int validacion=0;

    if(numero!=NULL && mensaje!= NULL && mensajeError!= NULL &&reintentos>=0&&min<=max)
    {
        for(int i=0;i<=reintentos;reintentos--)
        {
            printf("\n%s",mensaje);
            if(floatValidated(&auxiliarResultado)&&(auxiliarResultado<=max)&&(auxiliarResultado>=min))
            {
                *numero=auxiliarResultado;
                validacion=1;
                break;
            }
            else
            {
                printf("\n%s\n",mensajeError);
            }
        }
    }

    return validacion;
}

int validarNumeroFloat (char vector[],int tam)/*valida flotante*/
{
    int retorno=0;
    int contadorPunto=0;
    int retornoAuxiliar=1;

    if(vector!=NULL&&tam>0)
    {
        for(int i=0;vector[i]!='\0'&&i<tam;i++)
        {
            if((vector[i]<'0'||vector[i]>'9')&&vector[i]!='.')
            {
                retornoAuxiliar=0;
                break;
            }
            else
            {
                if(vector[i]=='.')
                {
                    contadorPunto++;
                }
            }
        }

        if((contadorPunto==1||contadorPunto==0)&&retornoAuxiliar==1)
        {
            retorno=1;
        }
    }
    return retorno;
}

int floatValidated(float* numero)/*confirma atos de flotantes*/
{
    int retorno=0;
    char bufferString[30];
    if(numero!=NULL)
    {
        if(scanString(bufferString,sizeof(bufferString))&&validarNumeroFloat(bufferString,sizeof(bufferString))&&strlen(bufferString)>0)
        {
            retorno=1;
            *numero=atof(bufferString);
        }
    }
    return retorno;
}

int getInt(int* numero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)/*construe int*/
{
    int auxiliarResultado;
    int validacion;
    validacion=0;

    if(numero!=NULL && mensaje!= NULL && mensajeError!= NULL && minimo<=maximo&&reintentos>=0)
    {
        for(int i=0;i<=reintentos;reintentos--)
        {
            printf("\n%s",mensaje);
            if(validatedInt(&auxiliarResultado)&&(auxiliarResultado<=maximo)&&(auxiliarResultado>=minimo))
            {
                *numero=auxiliarResultado;
                validacion=1;
                break;
            }
            else
            {
                printf("\n%s\n",mensajeError);
            }
        }

    }
    return validacion;
}
int validatedInt(int* numero)/*confirma datos de int*/
{
    int retorno=0;
    char bufferString[20];
    if(numero!=NULL)
    {
        if(scanString(bufferString,sizeof(bufferString))&&validarNumeroInt(bufferString,sizeof(bufferString))&&strlen(bufferString)>0)
        {
            retorno=1;
            *numero=atoi(bufferString);
        }
    }

    return retorno;
}

int validarNumeroInt (char vector[],int tam)/*valida int*/
{
    int retorno=1;
    if(vector!=NULL)
    {
        for(int i=0;vector[i]!='\0'&&i<tam;i++)
        {
            if(vector[i]<'0'||vector[i]>'9')
            {
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}

int getSexo(char sexo[],char* mensaje,char* mensajeError,int reintentos)/*construe*/
{
    char auxiliarResultado;
    int validacion=0;

    if(sexo!=NULL && mensaje!= NULL && mensajeError!= NULL &&reintentos>=0)
    {
        for(int i=0;i<=reintentos;reintentos--)
        {
            printf("\n%s",mensaje);
            if(  validatedSexo(&auxiliarResultado)  )
            {
                *sexo=auxiliarResultado;
                validacion=1;
                break;
            }
            else
            {
                printf("\n%s\n",mensajeError);
            }
        }
    }

    return validacion;
}

int validarSexo (char vector)/*valida sexo*/
{
    int retorno=1;

        if(vector!='f'&&vector!='m')
        {
            retorno=0;
        }

    return retorno;
}

int validatedSexo (char* sexo)/*confirma datos de sexo*/
{
    int retorno=0;
    char bufferString[20];
    char letra;
    if(sexo!=NULL)
    {
        if(scanString(bufferString,sizeof(bufferString)))
        {
            if(strlen(bufferString)==1)
            {
                letra=bufferString[0];
                if(validarSexo(letra))
                {
                     retorno=1;
                    *sexo=letra;
                }

            }
        }
    }

    return retorno;
}
