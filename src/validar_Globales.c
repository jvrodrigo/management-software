#include <stdio.h>
#include"..\include\funciones_Globales.h"
#include"..\include\validar_Globales.h"
#include"..\include\pintar_textos_Globales.h"

///** FUNCIONES PARA VALIDAR LAS ENTRADAS POR TECLADO REALIZADAS POR EL USUARIO **///

int validarElegirIdioma(char *entrada,int valido,int idioma)      // opcion 8
{
    if((entrada[0]>='1' && entrada[0]<='2') && cuentaCaracteres(entrada)==1)
    {
        return 1;
    }
    else
    {
        pintarError(idioma);
        continuar(valido,idioma);
        return 0;
    }
}
int validarContinuar(char *entrada,int idioma)         // Valida solo si se Pulsa <ENTER> Y SOLO <ENTER>
{
    if(entrada[0]=='\0' && cuentaCaracteres(entrada)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarContinuarSIoNO(char *entrada,int valido, int idioma)    // Pregunta "Desea continuar s/n: "
{
    if((entrada[0]=='s' || entrada[0]=='S' || entrada[0]=='n' || entrada[0]=='N') && cuentaCaracteres(entrada)==1 && idioma==1)
    {
        return 1;
    }
    else if((entrada[0]=='y' || entrada[0]=='Y' || entrada[0]=='n' || entrada[0]=='N')&& cuentaCaracteres(entrada)==1 && idioma==2)
    {
        return 1;
    }
    else
    {
        pintarError(idioma);
        continuar(valido,idioma);
        return 0;
    }
}
///** VALIDACION DE LAS ENTRADAS DEL USUARIO POR TECLADO MENU PRINCIPAL **///

int validarMenuPrincipal(char *entrada,int valido, int idioma)
{
    if (((entrada[0]>='0' && entrada[0]<='3') || entrada[0]=='8') && cuentaCaracteres(entrada)==1)
    {
        return 1;
    }
    else
    {
        pintarError(idioma);
        continuar(valido,idioma);
        return 0;
    }
}
