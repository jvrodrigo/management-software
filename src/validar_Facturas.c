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

// VALIDACIONES DE LAS ENTRADAS DEL USUARIO POR TECLADO MENU FACTURAS//

int validarMenuFacturas(char *entrada,int valido, int idioma)
{
    if(((entrada[0]>='0' && entrada[0]<='4') || entrada[0]=='8') && cuentaCaracteres(entrada)==1)
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
int validarFacturasBuscar(char *n_str,int valido,int idioma)
{
    if(strlen(n_str)==1 && (n_str[0]=='a' || n_str[0]=='b'))
    {
        return 1;
    }
    else
    {
        return 0;
        pintarValidarFacturasBuscar(idioma);
        continuar(valido,idioma);
    }
}
int validarFacturasBuscar_id_factura(char *n_string,int valido,int idioma)
{
    int i;
    i=0;
    while(n_string[i]>='0' && n_string[i]<='9' && strlen(n_string)==8)  // Validate AAAANNNN int numbers
    {
        i++;
    }
    if(i==8)
    {
        return 1;
    }
    else
    {
        pintarValidarFacturasBuscar_id_factura(idioma);
        continuar(valido,idioma);
        return 0;
    }
}

int validarFacturas_id_factura(char *entrada,int valido,int idioma);
int validarFacturas_nombre_empresa(char *entrada,int valido,int idioma);

int validarFacturasCrear(char *entrada,int valido,int idioma);
int validarFacturasBorrar(char *entrada,int valido,int idioma);

int validarFacturasImprimir(char *entrada,int valido,int idioma);
