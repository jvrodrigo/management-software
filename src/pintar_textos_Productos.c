#include <stdio.h>
#include <stdlib.h>

#include"..\include\pintar_textos_Productos.h"
#include"..\include\pintar_textos_Globales.h"

void pintarMenuProductos(int idioma)                   // SubMenu Productos
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
        printf("\n\n\tMENU PRODUCTOS\n");
        printf("\n_______________________________________");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|    0 - Volver MENU PRINCIPAL |");
        printf("\n\t|                              |");
        printf("\n\t|    1 - Crear Producto        |");
        printf("\n\t|                              |");
        printf("\n\t|    2 - Editar Producto       |");
        printf("\n\t|                              |");
        printf("\n\t|    3 - Borrar Producto       |");
        printf("\n\t|                              |");
        printf("\n\t|    4 - Buscar Producto       |");
        printf("\n\t|                              |");
        printf("\n\t|    5 - Listado de Productos  |");
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
        printf("\n\n\tPRODUCTS MENU \n");
        printf("\n_______________________________________");
        printf("\n\t|                              |");
        printf("\n\t|                              |");
        printf("\n\t|    0 - Back to MAIN MENU     |");
        printf("\n\t|                              |");
        printf("\n\t|    1 - Create Product        |");
        printf("\n\t|                              |");
        printf("\n\t|    2 - Edit Product          |");
        printf("\n\t|                              |");
        printf("\n\t|    3 - Delete Product        |");
        printf("\n\t|                              |");
        printf("\n\t|    4 - Search Product        |");
        printf("\n\t|                              |");
        printf("\n\t|    5 - Product Report        |");
        printf("\n\t|                              |");
        printf("\n\t|    8 - Select Language       |");
        printf("\n\t|                              |");
        printf("\n\t|______________________________|");
        printf(" \n_____________________________________________________________________________________________");
        printf("\n\nSelect an option and press <ENTER>: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED.Submenu Productos");
    }
}
void pintarProductosCrear(int idioma)                     // opcion 1
{
    if(idioma==1)       // 1.-Español
    {
        printf("\n\t1.- Crear Producto\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\n\t1.- Create Product\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductosEditar(int idioma)                    // opcion 1.2
{
    if(idioma==1)       // 1.-Español
    {
        printf("\n\t2.- Editar Producto\n\n\tIntroduzca el Id del producto a editar y presione <ENTER>\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\n\t2.- Edit Product\n\n\tEnter the Id product to edit and press <ENTER>\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductosEditar_OK_1(int idioma)
{
    if(idioma==1)           // 1.- Español
    {
        printf("\n\n\t2.- Editar Producto:\n\n\t\ta.- Id producto\t\td.- Precio de Venta\n\n\t\tb.- Nombre\t\te.- Stock\n\n\t\tc.- Precio de Compra\n\n\tElija una opcion y pulse <ENTER>: ");
    }
    else if(idioma==2)      // 2.- Ingles
    {
        printf ("\n\n\t2.- Edit Product:\n\n\t\ta.- Product Idtb.- Name\n\n\t\tc.- Purchase Pricetd.- Sale Price\n\n\t\te.- Stock\n\n\tSelect an option and press <ENTER>: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductosEditar_OK_2(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\n---- Producto Editado ----\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\n---- Product Produced -----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductosEditar_NOT(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\n---- Producto No Editado ----\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\n---- Not Edited Product -----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductosBorrar(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\n\t3.- Borrar Producto\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\n\t3.- Delete Product\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductosBuscar(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\n\n\t4.- Elija como buscar el producto\n\n\t\ta.- Buscar ID Producto\n\n\t\tb.- Buscar Nombre Producto\n\nElija una opcion: ");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\n\n\t4.- Choose how to find the product\n\n\t\ta.- Search for Product ID\n\n\t\tb.- Product Name Search\n\nSelect an option: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductosListado(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\n\n\t5.- Listado de Productos\n\n\t\ta.- Mas vendido\n\n\t\tb.- Mas rentabilidad\n\n\t\tc.- Mayor stock\n\n\tElija una opcion: ");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\n\n\t5.- Product List\n\n\n\t\ta.- Best Selling\n\n\t\tb.- More profitability\n\n\t\tc.- Major Stock\n\n\tChoose an option: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductosBorrar_OK(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\n---- Producto Borrado ----\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\n---- Deleted Product -----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductosNoBorrado(int idioma)

{
    if(idioma==1)       // 1.-Español
    {
        printf("\n---- Producto No Borrado ----\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\n---- Product is not deleted -----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}


void pintarProductos_id_producto(int idioma)              // opcion 1.1
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nID del producto: ");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nProduct ID: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarValidarProductos_id_producto(int idioma)       // opcion 1.1
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nEl formato del ID es incorrecto, formatos correctos: [A00 - Z99]\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nThe format of the ID is incorrect, correct formats: [A00 -Z99]\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarValidarProductos_registro_id_productos(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nEl ID ya existe, intentelo de nuevo\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nThe ID already exists, try again\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductos_nombre_producto(int idioma)          // opcion 1.1
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nNombre del producto: ");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nProduct name: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarValidarProductos_nombre_producto(int idioma)   // opcion 1.1
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nEl nombre del producto no puede tener mas de 30 caracteres, ni menos de 3, intentelo de nuevo\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nThe product name can not have more than 30 characters, try again\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductos_precio_compra(int idioma)            // opcion 1.1
{
if(idioma==1)       // 1.-Español
    {
        printf("\nPrecio de compra: ");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nPurchase price: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarValidarProductos_precio_compra(int idioma)     // opcion 1.1
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nEl precio de compra no tiene el formato correcto");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nThe purchase price not in a correct format");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductos_stock(int idioma)          // opcion 1.1
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nStock: ");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nStock: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}

void pintarValidarProductos_stock(int idioma)   // opcion 1.1
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nIntroduzca desde 1 hasta 999 unidades");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nEnter from 1 to 999 units");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductos_precio_venta(int idioma)             // opcion 1.1
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nPrecio de venta al p%cblico: ",163);
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nSelling price to the public");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarValidarProductos_precio_venta(int idioma)      // opcion 1.1
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nEl precio de venta no tiene el formato correcto");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nThe sale price is not formatt correctly");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}

void pintarProductos_unidades_vendidas(int idioma)        // opcion 1.1
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nLa unidades vendidas de XXXX son: ");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nUnit sales of XXXX is: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductos_num_unidades(int idioma)          // opcion 1.1
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nUnidades del producto: ");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nUnits of product: ");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarValidarProductos_num_unidades(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nFormato incorrecto, introduzca mas de 0 unidades y menos de 500, y presione <ENTER>\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nIncorrect format, enter more than 0 units or less than 500 units, and press <ENTER>");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}

void pintarValidarProductosListado(int idioma)
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

void pintarValidarProductosBuscar(int idioma)
{
    if(idioma==1)       // 1.-Español
    {
        printf("\nPulsa 'a' para buscar por el ID del producto o pulsa 'b' para buscar por el nombre del producto y presione <ENTER>\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\nPress 'a' to search by product ID or press 'b' to search by product name and press ENTER\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductosNoExiste_1(int idioma)
{
    if(idioma==1)
    {
        printf("\n---- El producto no existe ----\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\n---- The product does not exist ----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
void pintarProductosNoExiste_2(int idioma)
{
    if(idioma==1)
    {
        printf("\n---- No existen productos ----\n");
    }
    else if(idioma==2)  // 2.-Ingles
    {
        printf("\n---- No products ----\n");
    }
    else
    {
        printf("\nATTENTION: NO LANGUAGE SELECTED");
    }
}
