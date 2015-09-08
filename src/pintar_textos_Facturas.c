#include <stdio.h>
#include <stdlib.h>

#include"..\include\pintar_textos_Facturas.h"
#include"..\include\pintar_textos_Globales.h"

void pintarMenuFacturas(int idioma)                    // SubMenu Facturas
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
        printf("\n\n\tMENU FACTURAS\n");
        printf("\n_______________________________________");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|    0 - Volver MENU PRINCIPAL |");
        printf("\n\t|                              |");
        printf("\n\t|    1 - Crear Factura         |");
        printf("\n\t|                              |");
        printf("\n\t|    2 - Borrar Factura        |");
        printf("\n\t|                              |");
        printf("\n\t|    3 - Buscar Factura        |");
        printf("\n\t|                              |");
        printf("\n\t|    4 - Imprimir Factura      |");
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
        printf("\n\n\tINVOICES MENU\n");
        printf("\n_______________________________________");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|    0 - Back to MAIN MENU     |");
        printf("\n\t|                              |");
        printf("\n\t|    1 - Create Invoice        |");
        printf("\n\t|                              |");
        printf("\n\t|    2 - Delete Invoice        |");
        printf("\n\t|                              |");
        printf("\n\t|    3 - Search Bill           |");
        printf("\n\t|                              |");
        printf("\n\t|    4 - Print Invoice         |");
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


void pintarFacturasCrear(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\t1.- Crear Factura\n\n\tIntroduzca el DNI o CIF del Cliente\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n\t1.- Create Invoice\n\n\tEnter Customer ID card or CIF\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarFacturasBorrar(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\t2.- Borrar Factura\n\n\tIntroduzca el Id de la factura y pulse <ENTER>: ");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n\t2.- Delete Invoice\n\n\tIntroduzca el Id de la factura y pulse <ENTER>: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarFacturasBuscar(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\t3.- Buscar Factura\n\n\tComo desea buscar la factura\n\n\t\ta.- ID Factura\n\n\t\tb.- Por CIF o DNI de cliente\n\n\tElija una opcion y pulse <ENTER>: ");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n\t3.- Search Bill\n\n\tAs you search for the invoice\n\n\t\ta.- Invoice ID\n\n\t\tb.- For CIF or Customer ID\n\n\tSelect an option and press <ENTER>: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}

void pintarValidarFacturasBuscar(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\tIntroduzca 'A' or 'B' y pulse <ENTER>\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n\tEnter 'A' or 'B' and press <ENTER>\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarFacturasBuscar_id_factura(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\tIntroduzca el Id de la factura y pulse <ENTER>: ");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n\tEnter ID Invoice and press <ENTER>: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarValidarFacturasBuscar_id_factura(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\tFormato incorrecto, formato correcto [AAAANNNN] y pulse <ENTER>\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n\tIncorrect format, correct format [AAAANNNN] and press <ENTER>\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarFacturasImprimir(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\t4.- Imprimir Factura\n\n\tIntroduzca el Id de la factura y pulse <ENTER>: ");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n\t4.- Print Invoice\n\n\tEnter ID Invoice and press <ENTER>: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}

