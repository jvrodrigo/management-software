#include <stdio.h>
#include <stdlib.h>
#include"..\include\pintar_textos_Globales.h"

///** FUNCIONES PARA PINTAR POR PANTALLA TODOS LOS MENSAJES DE LA APLICACION **///

// SE PUEDEN AGREGAR MAS IDIOMAS A TRAVES DE ESTAS FUNCIONES //

void pintarElegirSistema(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nPor favor, elija el sistema operativo: ");
        printf("\n\n\t1.- WINDOWS");
        printf("\n\n\t2.- LINUX");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nPlease choose the operating system: ");
        printf("\n\n\t1.- WINDOWS");
        printf("\n\n\t2.- LINUX");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}

void pintarElegirIdioma(int valido,int idioma)       // Muestra por pantalla la eleccion de idioma
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nPor favor, elija el idioma\n");
        printf("\n\t\t\t1.- Espa%col",164);
        printf("\n\t\t\t2.- English\n");
        printf("\nElija 1 o 2 y pulse <ENTER>: ");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nPlease, select your language\n");
        printf("\n\t\t\t1.- Espa%col",164);
        printf("\n\t\t\t2.- English\n");
        printf("\nSelect 1 o 2 and press <INTRO>: ");
    }
    else
    {
        system("cls");
        printf("\n\n\t\t*******************************************************\n");
        printf("\t\t*                                                     *\n");
        printf("\t\t*                       WELCOME                       *\n");
        printf("\t\t*                        TO THE                       *\n");
        printf("\t\t*                     APPLICATION:                    *\n");
        printf("\t\t*                                                     *\n");
        printf("\t\t*                     MENU SYSTEM                     *\n");
        printf("\t\t*                                                     *\n");
        printf("\t\t*******************************************************\n\n\n");
        printf("\nATTENTION: NO LANGUAGE SELECTED\n");
        printf("\nPlease, select your language\n");
        printf("\n\t\t\t1.- Espa%col",164);
        printf("\n\t\t\t2.- English\n");
        printf("\nSelect 1 o 2 and press <INTRO>: ");

    }
}
void pintarIdioma(int idioma)             // Muestra en los menus el idioma seleccionado: 1.- Español, 2.- English
{
    if(idioma==1)           // 1.- Español
    {
        printf("Idioma: Espa%col",164);
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("Language: English");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarError(int idioma)              // Muestra por pantalla "DATOS ERRONEOS"
{
    if(idioma==1)           // 1.-Español
    {
        printf(" \nDATOS ERRONEOS\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf(" \nDATA ERROR\n");
    }
    else
    {
        printf("\nDATA ERROR\n");
    }
}
void pintarContinuar(int idioma)          // Muestra por pantalla "Pulse <ENTER> para continuar"
{
    if(idioma==1)       // 1.- Español
    {
        printf("\nPulse <ENTER> para continuar");
    }
    else if(idioma==2)  // 2.- Ingles
    {
        printf("\nPress <INTRO> to continue");
    }
    else
    {
        printf("\nPress <INTRO> to continue");
    }
}
void paintSaveFile(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nDesea guardar los cambios? s/n: ");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nDo you want to save changes? y/n: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}

void pintarContinuarSIoNO(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nDesea CONTINUAR s/n: ");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nDo you want to CONTINUE y/n: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarArchivoNoAbierto(int idioma)
    {
    if(idioma==1)       // 1.-Español
    {
        printf("\nArchivo no Abierto\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nFile not opened\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarArchivoNoCerrado(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nError al cerrar el archivo\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nClose file error\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarArchivoNoExiste(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nEl archivo no existe\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nFile is missing\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}

void pintarRegistroCompleto(int idioma)
{
     if(idioma==1)       // 1.-Español
    {
        printf("\n---- Error, Registro Completo ----\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\n---- Error, Full Record ----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarFacturasNoHayStock(int idioma)
{
         if(idioma==1)       // 1.-Español
    {
        printf("\n---- No hay Stock ----\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\n---- No Stock ----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarMensajeBienvenida(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        system("cls");
        printf("\n\n\n\n\n\n");
        printf("\n\n\t\t\t\t       BIENVENIDO");
        printf("\n\n\t\t\t\t      AL GESTOR DE");
        printf("\n\n\t\t\t\t        ALMACEN");
        printf("\n\n\t\t\t\t        CLIENTES");
        printf("\n\n\t\t\t\t           Y");
        printf("\n\n\t\t\t\t      FACTURACION");
        printf("\n\n\n\n\t\t\t\t     de la empresa:");
        printf("\n\n\t\t\t\t   AGROALIMENTOS S.A.");
        printf("\n\n\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        system("cls");
        printf("\n\n\n\n\n\n");
        printf("\n\n\t\t\t\t         WELCOME");
        printf("\n\n\t\t\t\t       TO THE STORE");
        printf("\n\n\t\t\t\t         MANAGER");
        printf("\n\n\t\t\t\t           AND");
        printf("\n\n\t\t\t\t         BILLING");
        printf("\n\n\t\t\t\t        CUSTOMERS");
        printf("\n\n\n\n\t\t\t\t     company:");
        printf("\n\n\t\t\t\t     AGROALIMENTOS S.A.");
        printf("\n\n\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED\n");

    }
}
void pintarMensajeDespedida(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\n\t\t|***************************************************************|");
        printf("\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\n\t\t|             GRACIAS POR USAR NUESTRO SOFTWARE                 |");
        printf("\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\n\t\t|***************************************************************|");
        printf("\n\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\n\t\t|***************************************************************|");
        printf("\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\n\t\t|              THANKS YOU FOU USE THIS SOFTWARE                 |");
        printf("\n\t\t|\t\t\t\t\t\t\t\t|");
        printf("\n\t\t|***************************************************************|");
        printf("\n\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }

}

void pintarMenuPrincipal(int idioma)                      // Menu Principal
{
    if(idioma==1)       // 1.-Español
    {
        system("cls");
        printf(" _____________________________________________________________________________________________\n");
        printf(" _____________________________________________________________________________________________\n");
        printf("\n                           Gestor de Almacen, Clientes y Facturacion");
        printf("\n\n                                    AGROALIMENTOS S.A.\t\t\t");
        pintarIdioma(idioma);
        printf("\n _____________________________________________________________________________________________\n");
        printf(" _____________________________________________________________________________________________\n");
        printf("\n\n\tMENU PRINCIPAL");
        printf("\n\n_______________________________________");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|    0 - Salir                 |");
        printf("\n\t|                              |");
        printf("\n\t|    1 - Productos             |");
        printf("\n\t|                              |");
        printf("\n\t|    2 - Clientes              |");
        printf("\n\t|                              |");
        printf("\n\t|    3 - Facturas              |");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|    8 - Seleccionar Idioma    |");
        printf("\n\t|                              |");
        printf("\n\t|______________________________|");
        printf(" \n_____________________________________________________________________________________________");
        printf("\n\nSeleccione una de las opciones y pulse <ENTER>: ");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        system("cls");
        printf(" _____________________________________________________________________________________________\n");
        printf(" _____________________________________________________________________________________________\n");
        printf("\n                           Warehouse manager, and billing customers");
        printf("\n\n                                    AGROALIMENTOS S.A.\t\t\t");
        pintarIdioma(idioma);
        printf("\n _____________________________________________________________________________________________\n");
        printf(" _____________________________________________________________________________________________\n");
        printf("\n\n\tMAIN MENU\n");
        printf("\n_______________________________________");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|    0 - Exit                  |");
        printf("\n\t|                              |");
        printf("\n\t|    1 - Products              |");
        printf("\n\t|                              |");
        printf("\n\t|    2 - Customers             |");
        printf("\n\t|                              |");
        printf("\n\t|    3 - Delivery Notes        |");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|    8 - Select Language       |");
        printf("\n\t|                              |");
        printf("\n\t|______________________________|");
        printf(" \n_____________________________________________________________________________________________");
        printf("\n\nSelect an option and press <ENTER>: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
