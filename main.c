/*Programa: Aplicacion para gestionar un almacen, los clientes y la emision de facturas*/

#include <stdio.h>
#include <stdlib.h>
#include "include/funciones_Globales.h"
#include "include/funciones_Productos.h"
#include "include/funciones_Clientes.h"
#include "include/funciones_Facturas.h"

#include "include/validar_Globales.h"
#include "include/validar_Productos.h"
#include "include/validar_Clientes.h"
#include "include/validar_Facturas.h"

#include "include/pintar_textos_Globales.h"
#include "include/pintar_textos_Productos.h"
#include "include/pintar_textos_Clientes.h"
#include "include/pintar_textos_Facturas.h"

void MenuPrincipal(int valido,int idioma);
void MenuProductos(int valido,int idioma);
void MenuClientes(int valido,int idioma);
void MenuFacturas(int valido,int idioma);

int main(int argc,char **argv)
{
    int VALIDO = 1;
    int IDIOMA = 2;
    int i;

	if (!( (argc >= 1) && (argc <= 4) ))
	{
		printf("Usage: %s [%s] [%s] [%s]\n",argv[0],"productos.dat","clientes.dat","facturas.dat");
		continuar(VALIDO,IDIOMA);
	}
	else
	{
		switch(argc)
		{
			case 1:     printf("\n---- No arguments ----\n");
                        continuar(VALIDO,IDIOMA);
                        break;
			case 2:     printf("\n---- One file: %s %s ----\n",argv[0],argv[1]);
                        continuar(VALIDO,IDIOMA);
                        break;
			case 3:     printf("\n---- Two files: %s %s %s ----\n",argv[0],argv[1],argv[2]);
                        continuar(VALIDO,IDIOMA);
                        break;
			case 4:     printf("\n---- Three files: %s %s %s %s ----\n",argv[0],argv[1],argv[2],argv[3]);
                        continuar(VALIDO,IDIOMA);
                        break;
			default:    printf("\n---- Error ----\n");
                        continuar(VALIDO,IDIOMA);
                        break;
		}
	}
	IDIOMA = ElegirIdioma(VALIDO,IDIOMA);

	p_counter=0;        // Global products counter
	c_counter=0;        // Global customers counter
	i_counter=0;      // Add +1 to General accountant bills
    i=1;
    while(i<argc && p_counter==0)       // busca el archivo productos
    {
        /*printf("\nArgumentos: %d | Fichero: %s",argc,argv[i]);*/
        LeerFicheroProductos(argv[i],product,VALIDO,IDIOMA);

        i++;
    }
    /*if(p_counter!=0)
    {
        for(indice=1;indice<=p_counter;indice++)
        {
            printf("\n%s ||",product[indice].id_producto);
            printf(" %s ||",product[indice].nombre_producto);
            printf(" %s ||",product[indice].precio_compra);
            printf(" %s ||",product[indice].precio_venta);
            printf(" %s ||",product[indice].stock);
            printf(" %s |",product[indice].num_unidades);
        }
    }*/
	i=1;
    while(i<argc && c_counter==0)       // busca el archivo de clientes
    {
        LeerFicheroClientes(argv[i],client,VALIDO,IDIOMA);
        i++;
    }
    /*if(c_counter!=0)
    {
        for(indice=1;indice<=c_counter;indice++)
        {
            printf("\n| %s ||",client[indice].dni_cif);
            printf(" %s ||",client[indice].nombre_rs);
            printf(" %s |",client[indice].direccion);
        }
    }*/
    i=1;
    while(i<argc && i_counter==0)       // busca el archivo de clientes
    {
        LeerFicheroFacturas(argv[i],invoice,VALIDO,IDIOMA);
        i++;
    }
    /*if(i_counter!=0)
    {
        for(indice=1;indice<=i_counter;indice++)
        {
            printf("\n| %s |",invoice[indice].id_invoice);
            printf("| %s |",invoice[indice].i_cif_company);
            printf("| %s |",invoice[indice].i_name_company);
            printf("| %s |",invoice[indice].i_dir_company);
            printf("| %s |",invoice[indice].dni_cif_client);
            printf("| %s |",invoice[indice].name_rs_client);
            printf("| %s |",invoice[indice].dir_client);
            printf("| %s |",invoice[indice].reg_date);
            printf("| %s |",invoice[indice].i_precio_base);
            printf("| %s |",invoice[indice].i_precio_iva);
            printf("| %s |",invoice[indice].i_precio_total);
            for(i=1;i<=invoice[indice].num_prod;i++)
            {
                printf("\n| %s |",invoice[indice].invo_product[i].name_product);
                printf("| %s |",invoice[indice].invo_product[i].units_product);
                printf("| %s |",invoice[indice].invo_product[i].price_product);
                printf("| %s |",invoice[indice].invo_product[i].total_product);
            }
        }
    }*/
    printf("\n");
    continuar(VALIDO,IDIOMA);
    customer_save = 0;
    product_save = 0;
    invoice_save = 0;
    pintarMensajeBienvenida(IDIOMA);
    continuar(VALIDO,IDIOMA);
    MenuPrincipal(VALIDO,IDIOMA);
    return 0;
}

///** BOTONES DEL MENU PRINCIPAL Y MENUS PRODUCTOS, CLIENTES Y FACTURAS **//

void MenuPrincipal(int valido,int idioma)
{
    char contenedor[31];
    do
    {
        pintarMenuPrincipal(idioma);
        gets(contenedor);
        valido = validarMenuPrincipal(contenedor,valido,idioma);
    }
    while(!valido);

    switch(contenedor[0] - 48)
    {
        case 0:     if(product_save==1)
                    {
                        switch(SaveFile(valido,idioma))
                        {
                            case 0:     pintarMensajeDespedida(idioma);
                                        exit(0);
                            case 1:     EscribirFicheroProductos(product,valido,idioma);
                        }
                    }
                    if(customer_save==1)
                    {
                        switch(SaveFile(valido,idioma))
                        {
                            case 0:     pintarMensajeDespedida(idioma);
                                        exit(0);
                            case 1:     EscribirFicheroClientes(client,valido,idioma);
                        }
                    }
                    if(invoice_save==1)
                    {
                        switch(SaveFile(valido,idioma))
                        {
                            case 0:     pintarMensajeDespedida(idioma);
                                        exit(0);
                            case 1:     EscribirFicheroFacturas(invoice,valido,idioma);
                        }
                    }
                    pintarMensajeDespedida(idioma);
                    exit(0);

        case 1:     MenuProductos(valido,idioma);

        case 2:     MenuClientes(valido,idioma);

        case 3:     MenuFacturas(valido,idioma);

        case 8:     idioma = ElegirIdioma(valido,idioma);
                    MenuPrincipal(valido,idioma);

        default:    pintarError(idioma);
                    MenuPrincipal(valido,idioma);
    }
}
void MenuProductos(int valido,int idioma)
{
    char contenedor[31];
    do
    {
        pintarMenuProductos(idioma);
        gets(contenedor);
        valido = validarMenuProductos(contenedor);
        if(!valido)
        {
            pintarError(idioma);
            continuar(valido,idioma);
        }
    }
    while(!valido);

    switch(contenedor[0] - 48)
    {
        case 0:     MenuPrincipal(valido,idioma);

        case 1:     ProductosCrear(product,valido,idioma);
                    MenuProductos(valido,idioma);

        case 2:     ProductosEditar(valido,idioma);
                    MenuProductos(valido,idioma);

        case 3:     ProductosBorrar(valido,idioma);
                    MenuProductos(valido,idioma);

        case 4:     ProductosBuscar(valido,idioma);
                    MenuProductos(valido,idioma);

        case 5:     ProductosListado(valido,idioma);
                    MenuProductos(valido,idioma);

        case 8:     idioma = ElegirIdioma(valido,idioma);
                    MenuProductos(valido,idioma);

        default:    pintarError(idioma);
                    MenuProductos(valido,idioma);
    }
}
void MenuClientes(int valido,int idioma)
{
    char contenedor[31];
    do
    {
        pintarMenuClientes(idioma);
        gets(contenedor);
        valido = validarMenuClientes(contenedor);
        if(!valido)
        {
            pintarError(idioma);
            continuar(valido,idioma);
        }
    }
    while(!valido);

    switch(contenedor[0] - 48)
    {
        case 0:     MenuPrincipal(valido,idioma);

        case 1:     ClientesCrear(client,valido,idioma);
                    MenuClientes(valido,idioma);

        case 2:     ClientesEditar(client,valido,idioma);
                    MenuClientes(valido,idioma);

        case 3:     ClientesBorrar(client,valido,idioma);
                    MenuClientes(valido,idioma);

        case 4:     ClientesBuscar(client,valido,idioma);
                    MenuClientes(valido,idioma);

        case 5:     ClientesListado(client,valido,idioma);
                    MenuClientes(valido,idioma);

        case 8:     idioma = ElegirIdioma(valido,idioma);
                    MenuClientes(valido,idioma);
        default:    pintarError(idioma);
                    MenuClientes(valido,idioma);
    }
}
void MenuFacturas(int valido,int idioma)
{
    char contenedor[31];
    do
    {
        pintarMenuFacturas(idioma);
        gets(contenedor);
        valido = validarMenuFacturas(contenedor,valido,idioma);
    }
    while(!valido);

    switch(contenedor[0] - 48)
    {
        case 0:     MenuPrincipal(valido,idioma);

        case 1:     FacturasCrear(valido,idioma);
                    MenuFacturas(valido,idioma);

        case 2:     FacturasBorrar(valido,idioma);
                    MenuFacturas(valido,idioma);

        case 3:     FacturasBuscar(invoice,valido,idioma);
                    MenuFacturas(valido,idioma);

        case 4:     FacturasImprimir(valido,idioma);
                    MenuFacturas(valido,idioma);

        case 8:     idioma = ElegirIdioma(valido,idioma);
                    MenuFacturas(valido,idioma);

        default:    pintarError(idioma);
                    MenuFacturas(valido,idioma);
    }
}



/*
void borrar_cadena(CADENA_ENLAZADA **cadena)
{
	CADENA_ENLAZADA *ptr = NULL,*old = NULL;;

	ptr = *cadena;
	while(ptr!=NULL)
	{
		old = ptr;
		ptr = ptr->next;
		free(old);
	}
	old = NULL;
	ptr = NULL;
	*cadena = NULL;
}
int vacia_cadena(CADENA_ENLAZADA *cadena)
{
	return (cadena == NULL);
}
void insertar_cadena(CADENA_ENLAZADA **cadena,char elem)
{
	CADENA_ENLAZADA *ptr;
	CADENA_ENLAZADA *nuevo = malloc(sizeof(struct tnodo));
	nuevo->dato = elem;
	nuevo->next = NULL;

	ptr = *cadena;
	if (*cadena == NULL)
	{
		*cadena = nuevo;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = nuevo;
	}
}
*/
