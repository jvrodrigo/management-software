#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#include"..\include\funciones_Globales.h"
#include"..\include\funciones_Productos.h"
#include"..\include\funciones_Clientes.h"
#include"..\include\funciones_Facturas.h"

#include"..\include\validar_Globales.h"
#include"..\include\validar_Productos.h"
#include"..\include\validar_Clientes.h"
#include"..\include\validar_Facturas.h"

#include"..\include\pintar_textos_Globales.h"
#include"..\include\pintar_textos_Productos.h"
#include"..\include\pintar_textos_Clientes.h"
#include"..\include\pintar_textos_Facturas.h"

///** FUNCIONES GLOBALES DE LA APLICACION **///

char INTRO[100];


int cuentaCaracteres(char *entrada)       // cuenta los caracteres de una cadena
{
    int i=0;
    while(entrada[i]!='\0')
    {
        i++;
    }
    return i;
}
void continuar(int valido, int idioma)                        // Funcion "Pulse <ENTER> para continuar"
{
    do
    {
        pintarContinuar(idioma);
        gets(INTRO);
        valido = validarContinuar(INTRO,idioma);
    }
    while(!valido);
}
int SaveFile(int valido,int idioma)
{
    char contenedor[30];
    do
    {
        paintSaveFile(idioma);
        gets(contenedor);
        valido = validarContinuarSIoNO(contenedor,valido,idioma);
    }
    while(!valido);

    if(contenedor[0]=='s' || contenedor[0]=='S' || contenedor[0]=='y' || contenedor[0]=='Y')
    {
        return 1;       // Return YES
    }
    else
    {
        return 0;       // Return NO
    }
}
int ContinuarSIoNO(int valido,int idioma) // SI DEVUELVE 1, NO DEVUELVE 0
{
    char contenedor[30];
    do
    {
        pintarContinuarSIoNO(idioma);
        gets(contenedor);
        valido = validarContinuarSIoNO(contenedor,valido,idioma);
    }
    while(!valido);

    if(contenedor[0]=='s' || contenedor[0]=='S' || contenedor[0]=='y' || contenedor[0]=='Y')
    {
        return 1;       // Devuelve SI
    }
    else
    {
        return 0;       // Devuelve NO
    }
}
int ElegirIdioma(int valido, int idioma)                     // opcion 8
{
    char contenedor[31];
    do
    {
        pintarElegirIdioma(valido,idioma);
        gets(contenedor);
        valido = validarElegirIdioma(contenedor,valido,idioma);
    }
    while(!valido);

    idioma = (contenedor[0]-48);
    return (idioma);   // Devuelvo el valor del IDIOMA
}

