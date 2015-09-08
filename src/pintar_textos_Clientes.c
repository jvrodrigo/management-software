#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"..\include\pintar_textos_Clientes.h"
#include"..\include\pintar_textos_Globales.h"

void pintarMenuClientes(int idioma)                    // SubMenu Clientes
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
        printf("\n\n\tMENU CLIENTES\n");
        printf("\n_______________________________________");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|    0 - Volver MENU PRINCIPAL |");
        printf("\n\t|                              |");
        printf("\n\t|    1 - Crear Cliente         |");
        printf("\n\t|                              |");
        printf("\n\t|    2 - Editar Cliente        |");
        printf("\n\t|                              |");
        printf("\n\t|    3 - Borrar Cliente        |");
        printf("\n\t|                              |");
        printf("\n\t|    4 - Buscar Cliente        |");
        printf("\n\t|                              |");
        printf("\n\t|    5 - Listado Clientes      |");
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
        printf("\n\n\tCOSTUMERS MENU\n");
        printf("\n_______________________________________");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|    0 - Back to MAIN MENU     |");
        printf("\n\t|                              |");
        printf("\n\t|    1 - Create Customer       |");
        printf("\n\t|                              |");
        printf("\n\t|    2 - Edit Customer         |");
        printf("\n\t|                              |");
        printf("\n\t|    3 - Delete Customer       |");
        printf("\n\t|                              |");
        printf("\n\t|    4 - Search Customer       |");
        printf("\n\t|                              |");
        printf("\n\t|    5 - Client List           |");
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

void pintarClientesCrear(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\t1.- Crear Cliente\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n\t1.- Create customer\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarClientesEditar(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\t2.- Editar Clientes\n\n\tIntroduzca el DNI o CIF del cliente a editar y presione <ENTER>\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf ("\n\t2.- Edit Client\n\n\tEnter the customer ID or CIF to edit and press <ENTER>\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarClientesBorrar(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\t3.- Borrar Cliente\n\n\tIntroduzca el DNI o CIF del cliente y pulse <ENTER>\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n\t3.- Delete Customer\n\n\tEnter customer ID card or CIF and press <ENTER>\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarClientesBuscar(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\n\t4.- Buscar Clientes\n\n\tComo desea buscar al cliente:\n\n\t\ta.- Por DNI o CIF\n\n\t\tb.- Por Nombre\n\n\tElija una opcion y pulse <ENTER>: ");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n\n\t4.- Search Customer\n\n\tAs a customer you want to find:\n\n\t\ta.- For ID or CIF\n\n\t\tb.- By Name\n\n\tSelect an option and press <ENTER>: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarClientesListado(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\t5.- Listado Clientes\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n\t5.- Client List\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarClientesEditar_OK_1(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\n\t2.- Editar Cliente:\n\n\t\ta.- DNI o CIF\n\n\t\tb.- Nombre\n\n\t\tc.- Direccion\n\n\tElija una opcion y pulse <ENTER>: ");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf ("\n\n\t2.- Edit Client:\n\n\t\ta.- DNI or CIF\n\n\t\tb.- Name\n\n\t\tc.- Address\n\n\tSelect an option and press <ENTER>: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}

void pintarValidarClientesEditar(int idioma)
{
    if(idioma==1)
    {
        printf("\nIntroduzca una de las opciones (a, b, c) o (A, B, C) y pulse <ENTER>");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nEnter one of the options (a, b, c) o (A, B, C) and press <ENTER>");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}

void pintarClientesEditar_OK_2(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n---- Cliente Editado ----\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n---- Edited client ----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarClientesEditar_NOT(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n---- Cliente No Editado ----\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n---- Not Edited Customer ----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}

void pintarClientesBorrar_OK(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n---- Cliente Borrado ----\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n---- Customer deleted ----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarClienteNoBorrado(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n---- Cliente no borrado ----\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n---- Client does not erase ----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}

void pintarValidarClientesBuscar(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nPulsa 'a' para buscar por el cliente por DNI o CIF o pulsa 'b' para buscar por el cliente por su nombre o razon social y presione <ENTER>\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nPress 'a' to search for the customer ID or CIF or press 'b' to search for the customer by name or business name and press <ENTER>\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}

//////////////////////////////////////////////////
// 1.-CREAR CLIENTE
void pintarClientes_dni_cif(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\nDNI o CIF: ");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\nID card or CIF: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarValidarClientes_dni_cif(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\nDNI o CIF incorrecto, intentelo de nuevo.\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\nID card or CIF incorrect\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarValidarClientes_registro_dni_cif(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\nLo siento el DNI o CIF  ya existe, intentelo de nuevo\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf ("\nSorry the DNI or CIF already exists, try again\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarValidarClientes_direccion(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\nLa direccion no puede contener mas de 30 caracteres ni menos de 1, intentelo de nuevo\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\nThe address can not contain more than 30 characters or less than 1, try again\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarClientes_nombre_rs(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\nNombre o razon social: ");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\nName or business name: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarClientes_direccion(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\nDireccion: ");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\nAddress: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarValidarClientes_nombre_rs(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\nEl nombre no puede contener mas de 30 caracteres ni menos de 1, intentelo de nuevo\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\nThe name can not contain more than 30 characters or less than 1, try again\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarClientesNoExiste_1(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n---- El cliente no existe ----\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n---- The client does not exist ----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarClientesNoExiste_2(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n---- No existen clientes ----\n");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf("\n---- There are no clients ----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
