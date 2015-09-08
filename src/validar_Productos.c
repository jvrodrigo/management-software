#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"..\include\funciones_Globales.h"
#include"..\include\funciones_Productos.h"
#include"..\include\validar_Globales.h"
#include"..\include\validar_Productos.h"
#include"..\include\pintar_textos_Globales.h"
#include"..\include\pintar_textos_Productos.h"

// VALIDACIONES DE LAS new_dataS DEL USUARIO POR TECLADO MENU PRODUCTOS //

int validarMenuProductos(char *new_data)
{
    if(((new_data[0]>='0' && new_data[0]<='5') || new_data[0]=='8') && cuentaCaracteres(new_data)==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarProductos_fichero_id_producto(char *new_data)
{
    //printf("     ENTRO A VALIDAR, %s",new_data);
    if((new_data[0]>='A' && new_data[0]<='Z') && ((new_data[1]>='0' && new_data[1]<='9') && (new_data[2]>='0' && new_data[2]<='9')))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarProductos_general_id_producto(char *new_data)     // ID del producto
{
    if(((new_data[0]>='A' && new_data[0]<='Z') && ((new_data[1]>='0' && new_data[1]<='9') && (new_data[2]>='0' && new_data[2]<='9')) && cuentaCaracteres(new_data)==3))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validarProductos_fichero_nombre_producto(char *new_data,int i)
{
    //printf("   ENTRO A VALIDAR, %s",new_data);

    if(i!=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarProductos_nombre_producto(char *new_data) // nombre del producto
{
    if((cuentaCaracteres(new_data)>3)&&(cuentaCaracteres(new_data)<=30))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarProductos_registro_id_producto(struct Products register_products[],char *new_data,int pos,int idioma)
{
    int i,valid;
    valid = 1;
    if(strlen(new_data)==3 && (new_data[0]>='A' && new_data[0]<='Z') && (new_data[1]>='0' && new_data[1]<='9') && (new_data[2]>='0' && new_data[2]<='9'))
    {
        for(i=1;i<=pos;i++)
        {
            //printf("\nComparacion: %d --- %s ---- ||| ---- %s ",strcmp(register_products[i].id_producto,new_data[pos].id_producto),register_products[i].id_producto,new_data[pos].id_producto);
            if(strcmp(register_products[i].id_producto,new_data)==0)
            {
                pintarValidarProductos_registro_id_productos(idioma);
                valid=0;
            }
        }
        if(valid!=0)
        {
            valid=1;
        }
    }
    else
    {
        pintarValidarProductos_id_producto(idioma);
        valid=0;
    }
    if(valid==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarProductos_precio_compra(char *new_data)  // limito el precio de compra desde 0 hasta 999.999
{
    int i = 0;
    int p = 0;
    while ((new_data[i]>='0' && new_data[i]<='9') || new_data[i]=='.')
    {
        i++;
        if(new_data[i]=='.')     // restrinjo que solo halla un punto para los decimales
        {
            p = p + 1;
        }
    }
    if(((cuentaCaracteres(new_data)==i)&&(cuentaCaracteres(new_data)!=0)) && (atof(new_data)>=0 && atof(new_data) < 1000000 )&& (p == 0 || p==1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarProductos_fichero_num_unidades(char *new_data,int i)
{
    //printf("   ENTRO A VALIDAR, %s",new_data);
    if(new_data[i]=='\n')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarProductos_fichero_stock(char *new_data,int i)
{
    //printf("   ENTRO A VALIDAR, %s",new_data);
    if(i!=0 && new_data[i]==' ')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarProductos_fichero_precios(char *new_data)
{
    //printf("   ENTRO A VALIDAR, %s",new_data);
    if(atoi(new_data)>0 && atoi(new_data)<501)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarProductos_precio_venta(char *new_data)  // limito el precio de venta desde 0 hasta 999.999
{
    int i = 0;
    int p = 0;
    while ((new_data[i]>='0' && new_data[i]<='9') || new_data[i]=='.')
    {
        i++;
        if(new_data[i]=='.')
        {
            p = p + 1;     // restrinjo que solo halla un punto para los decimales
        }
    }
    if(((cuentaCaracteres(new_data)==i)&&(cuentaCaracteres(new_data)!=0)) && (atof(new_data)>=0 && atof(new_data) < 1000000 ) && (p == 0 || p==1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarProductos_stock(char *new_data) // unidades a Comprar de un producto [1-999]
{
    int i = 0;
    while(new_data[i]>='0'&& new_data[i]<='9' && (cuentaCaracteres(new_data)>0 && cuentaCaracteres(new_data)<4)) // limito las unidades a comprar entre 1 y 999
        i++;

    if(cuentaCaracteres(new_data)==i && cuentaCaracteres(new_data)!=0 && new_data[0]!='0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validarProductos_num_unidades(char *new_data,int idioma)       // This funtion is used only in invoice
{
    if(atoi(new_data)>0&& atoi(new_data)<500)
    {
        return 1;
    }
    else
    {
        pintarValidarProductos_num_unidades(idioma);
        return 0;
    }
}
int validarProductosFacturas_num_unidades(struct Products producto[],char *new_data,int pos,int idioma)       // This funtion is used only in invoice
{
    if(atoi(new_data)>0&& atoi(new_data)<500)
    {
        if(atoi(producto[pos].stock)-atoi(new_data)>=0)  // If (stock - products to buy) > 0
        {
            return 1;
        }
        else
        {
            pintarFacturasNoHayStock(idioma);   // ONLY USED ON #INCLUDE<...src/pintar_Textos_Facturas.h>
            return 0;
        }
    }
    else
    {
        pintarValidarProductos_num_unidades(idioma);
        return 0;
    }
}
int validarProductosEditar(char *option)
{
    if(strlen(option)==1 && (tolower(option[0])=='a' || tolower(option[0])=='b' || tolower(option[0])=='c' || tolower(option[0])=='d' || tolower(option[0])=='e'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarProductosBuscar(char *new_data)
{
    if((new_data[0]=='a' || new_data[0]=='A' || new_data[0]=='b' || new_data[0]=='B') && cuentaCaracteres(new_data)==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarProductosListado(char *new_data)
{
    if((new_data[0]=='a' || new_data[0]=='A' || new_data[0]=='b' || new_data[0]=='B' || new_data[0]=='c' || new_data[0]=='C')&& cuentaCaracteres(new_data)==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
