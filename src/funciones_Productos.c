#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"..\include\funciones_Globales.h"
#include"..\include\funciones_Productos.h"
#include"..\include\funciones_Facturas.h"
#include"..\include\validar_Productos.h"
#include"..\include\validar_Facturas.h"
#include"..\include\pintar_textos_Globales.h"
#include"..\include\pintar_textos_Productos.h"
#include"..\include\pintar_textos_Facturas.h"

int CalculateTotalStock(struct Products producto[])
{
    TOTAL_STOCK=0;  // Start Calculate
    int i;
    for(i=1;i<=p_counter;i++)
    {
        TOTAL_STOCK = atoi(producto[i].stock) + TOTAL_STOCK;
    }
    return TOTAL_STOCK;
}

void LeerFicheroProductos(char *argv,struct Products product[],int valido,int idioma)
{
    int row,column,index,pos,quotes,space,flag,flag_OK,final_fichero;
    char garbage[31];
    char buffer[1];
    flag=1;
    FILE *file = NULL;
    file = fopen(argv,"r");
    printf("\n(PRODUCTOS) Comprobando formato: %s",argv);
    fseek(file,0,SEEK_END);
    memset(garbage,'\0',strlen(garbage));
    if(ftell(file)!=0)
    {
        fseek(file,0,SEEK_SET);
        if(strcmp(fgets(garbage,10,file),INI_PRODUCTOS)==0)
        {
            memset(garbage,'\0',strlen(garbage));
            fseek(file,-14,SEEK_END);
            if(strcmp(fgets(garbage,14,file),FIN_PRODUCTOS)==0)
            {
                printf("\n(PRODUCTOS) El fichero coincide con el formato\n");
                flag = 1;
            }
            else
            {
                printf("\n(PRODUCTOS) El fichero no coincide con el formato\n");
                flag=0;
            }
        }
        else
        {
            printf("\n(PRODUCTOS) El fichero no coincide con el formato\n");
            flag=0;
        }
    }
    else
    {
        printf("\nEl fichero esta vacio");
    }
    if(flag==1)
    {
        memset(garbage,'\0',strlen(garbage));
        fseek(file,0,SEEK_END);
        final_fichero=ftell(file);
        p_counter=1;
        row=0;
        column=0;
        index=0;
        pos=10;
        quotes=0;
        space=0;
        flag_OK=0;

        while(pos<=final_fichero-strlen(FIN_PRODUCTOS) && flag==1)
        {
            fseek(file,pos,SEEK_SET);
            fread(buffer,1,1,file);
            //printf("\n\tpos[%d]: %d",pos,buffer[0]);
            if(column==5)
            {
                if(buffer[0]==10 && column==5)
                {
                    memset(garbage,'\0',strlen(garbage));
                    if(strcmp(FIN_PRODUCTOS,fgets(garbage,14,file))!=0)
                    {
                        //printf("\n%s: VALIDO FORMATO UNIDADES",producto[p_counter].t_num_unidades);
                        space=0;
                        index=0;
                        column=0;
                        p_counter++;    // Contador de los productos leidos en el fichero
                    }
                    else
                    {
                        flag_OK=1;
                        flag=0;
                    }
                    //printf("\n-----Comparo: %s",garbage);

                }
                else if(buffer[0]!=' ' && column==5)
                {
                    product[p_counter].t_num_unidades[index]=buffer[0];
                    //printf("index: %d",index);
                    index++;
                }
            }
            else if(column==4)
            {
                if(buffer[0]==' ' && column==4)
                {
                    //printf("\n%s: VALIDO FORMATO STOCK",product[p_counter].t_stock);
                    space=0;
                    index=0;
                    column++;
                }
                else if(buffer[0]!=' ' && column==4)
                {
                    product[p_counter].t_stock[index]=buffer[0];
                    //printf("index: %d",index);
                    index++;
                }
            }
            else if(column==3)
            {
                if(buffer[0]==' ' && column==3)
                {
                    //printf("\n%s: VALIDO FORMATO PRECIO VENTA",product[p_counter].t_precio_venta);
                    space=0;
                    index=0;
                    column++;
                }
                else if(buffer[0]!=' ' && column==3)
                {
                    product[p_counter].t_precio_venta[index]=buffer[0];
                    //printf("index: %d",index);
                    index++;
                }
            }
            else if(column==2)
            {
                if(buffer[0]==' ' && space%2==1 && column==2)
                {
                    if(validarProductos_fichero_precios(product[p_counter].t_precio_compra))
                    {
                        //printf("---2nd space---- Colum2");
                        //printf("\n%s: VALIDO FORMATO PRECIO COMPRA",product[p_counter].t_precio_compra);
                        space=0;
                        index=0;
                        column++;
                    }
                    else
                    {
                        flag=2;
                    }

                }
                else if(buffer[0]==' ' && space%2==0 && column==2)
                {
                    //printf("---1er space---- Colum2");
                    index=0;
                    space++;  // First space
                }
                else if(buffer[0]!=' ' && space%2==1 && column==2)
                {
                    product[p_counter].t_precio_compra[index]=buffer[0];
                    //printf("index: %d",index);
                    index++;
                }
            }
            else if(column==1)
            {
                if(buffer[0]=='"' && quotes%2==1 && column==1)
                {
                    if(validarProductos_fichero_nombre_producto(product[p_counter].t_nombre_producto,idioma)==1)
                    {
                        //printf("---2nd quotes---- Colum1");
                        //printf("\n%s: VALIDO FORMATO NOMBRE",product[p_counter].t_nombre_producto);
                        quotes=0;
                        column++;
                    }
                    else
                    {
                        flag=2;
                    }
                }
                else if(buffer[0]=='"' && quotes%2==0 && column==1)
                {
                    //printf("---1er quotes---- Colum1");
                    index=0;
                    quotes++;
                }
                else if(buffer[0]!='"' && quotes%2==1 && column==1)
                {
                    product[p_counter].t_nombre_producto[index]=buffer[0];
                    //printf("index: %d",index);
                    index++;
                }
            }
            else if(column==0)
            {
                if(strlen(product[p_counter].t_id_producto)==3 && validarProductos_registro_id_producto(product,product[p_counter].t_id_producto,p_counter,idioma)==1)
                {
                    strcpy(product[p_counter].id_producto,product[p_counter].t_id_producto);
                    //printf("\n%s: Formato valido ID PRODUCTO",product[p_counter].t_id_producto);
                    column++;
                }
                else if(buffer[0]!=10)
                {
                    product[p_counter].t_id_producto[index]=buffer[0];
                    //printf("index: %d",index);
                    index++;
                }
            }
            if(index>30)
            {
                printf("\nALGUN DATO NO MANTIENE EL FORMATO");
                pintarError(idioma);
                pos=final_fichero;
                p_counter=0;    // Pone a 0 el contador general si hay algun fallo
            }
            pos++;
        }
    }
    else
    {
        printf("\n(PRODUCTOS) El fichero no coincide con el formato\n");
    }
    if(flag==2)
    {
        printf("\nALGUN DATO NO MANTIENE EL FORMATO");
        p_counter=0;
    }
    if(fclose(file)!=0)
    {
        pintarArchivoNoCerrado(idioma);
    }
    if(flag_OK==1)
    {
        for(index=1;index<=p_counter;index++)
        {
            strcpy(product[index].id_producto,product[index].t_id_producto);
            strcpy(product[index].nombre_producto,product[index].t_nombre_producto);
            strcpy(product[index].precio_compra,product[index].t_precio_compra);
            strcpy(product[index].precio_venta,product[index].t_precio_venta);
            strcpy(product[index].stock,product[index].t_stock);
            strcpy(product[index].num_unidades,product[index].t_num_unidades);
        }
    }
    else
    {
        p_counter=0;
    }
}
void ProductosCrear(struct Products product[],int valido,int idioma)           // Crear Productos      opcion 1.1
{
    if(!(p_counter>=0 && p_counter<=100))
    {
        pintarRegistroCompleto(idioma);
        continuar(valido,idioma);
    }
    else
    {
        pintarProductosCrear(idioma);
        switch(ContinuarSIoNO(valido, idioma))
        {
            case 1:
                    do                                      // Productos Crear ID Producto
                    {
                        pintarProductos_id_producto(idioma);
                        gets(product[0].t_id_producto);            // temp produc id
                        valido = validarProductos_registro_id_producto(product,product[0].t_id_producto,p_counter,idioma);
                    }
                    while(!valido);
                    do                                      // Productos Crear Nombre del Producto
                    {
                        pintarProductos_nombre_producto(idioma);
                        gets(product[0].t_nombre_producto);
                        valido = validarProductos_nombre_producto(product[0].t_nombre_producto);
                        if(!valido)
                        {
                            pintarValidarProductos_nombre_producto(idioma);
                            continuar(valido,idioma);
                        }
                    }
                    while(!valido);
                    do                                      // Productos Crear Precio de Compra
                    {
                        pintarProductos_precio_compra(idioma);
                        gets(product[0].t_precio_compra);
                        valido = validarProductos_precio_compra(product[0].t_precio_compra);
                        if(!valido)
                        {
                            pintarValidarProductos_precio_compra(idioma);
                            continuar(valido,idioma);
                        }
                    }
                    while(!valido);
                    do                                      // Productos Crear Precio de Venta
                    {
                        pintarProductos_precio_venta(idioma);
                        gets(product[0].t_precio_venta);
                        valido = validarProductos_precio_venta(product[0].t_precio_venta);
                        if(!valido)
                        {
                            pintarValidarProductos_precio_venta(idioma);
                            continuar(valido,idioma);
                        }
                    }
                    while(!valido);
                    do                                      // Productos Crear Stock
                    {
                        pintarProductos_stock(idioma);
                        gets(product[0].t_stock);
                        valido = validarProductos_stock(product[0].t_stock);
                        if(!valido)
                        {
                            pintarValidarProductos_stock(idioma);
                            continuar(valido,idioma);
                        }
                    }
                    while(!valido);

                    // shows on screen Products to save //
                    pintarProductos_id_producto(idioma);
                    printf("%s", product[0].t_id_producto);
                    pintarProductos_nombre_producto(idioma);
                    printf("%c",34);
                    printf("%s", product[0].t_nombre_producto);
                    printf("%c",34);
                    pintarProductos_precio_compra(idioma);
                    printf("%.2f",atof(product[0].t_precio_compra));
                    pintarProductos_precio_venta(idioma);
                    printf("%.2f",atof(product[0].t_precio_venta));
                    pintarProductos_stock(idioma);
                    printf("%d\n",atoi(product[0].t_stock));
                    continuar(valido,idioma);


                    p_counter++;        // General products counter
                    // copy temp var to new product
                    strcpy(product[p_counter].id_producto,product[0].t_id_producto);
                    strcpy(product[p_counter].nombre_producto,product[0].t_nombre_producto);
                    strcpy(product[p_counter].precio_compra,product[0].t_precio_compra);
                    strcpy(product[p_counter].precio_venta,product[0].t_precio_venta);
                    strcpy(product[p_counter].stock,product[0].t_stock); // paso el numero de unidades compradas al stock del producto nuevo
                    strcpy(product[p_counter].num_unidades,"0");
                    product_save = 1;           // flag product to save at the end of the application
                    // clear temp var product //
                    strcpy(product[0].t_id_producto,"");
                    strcpy(product[0].t_nombre_producto,"");
                    strcpy(product[0].t_precio_compra,"");
                    strcpy(product[0].t_precio_venta,"");
                    strcpy(product[0].t_stock,"");
        }
    }
}
void ProductosEditar(int valido,int idioma)
{
    int pos;
    char opcion[10];
    if(p_counter==0)
    {
        pintarProductosNoExiste_2(idioma);
        continuar(valido,idioma);
    }
    else
    {
        pintarProductosEditar(idioma);
        do
        {
            pintarProductos_id_producto(idioma);
            gets(product[0].t_id_producto);
            valido = validarProductos_general_id_producto(product[0].t_id_producto);
            if(!valido)
            {
                pintarValidarProductos_id_producto(idioma);
            }
        }
        while(!valido);

        pos = BuscadorProductos(product,product[0].t_id_producto,'a',idioma);
        if(pos!=0)
        {
            switch(ContinuarSIoNO(valido,idioma))
            {
                case 1:     do
                            {
                                system("cls");
                                pintarMenuProductos(idioma);
                                printf("\n\n");
                                printf("| %s | %s | %s | %s | %s | %s |",product[pos].id_producto,product[pos].nombre_producto,product[pos].precio_compra,product[pos].precio_venta,product[pos].stock,product[pos].num_unidades);
                                pintarProductosEditar_OK_1(idioma);
                                gets(opcion);
                                valido = validarProductosEditar(opcion);
                                if(!valido)
                                {
                                    continuar(valido,idioma);
                                }
                            }
                            while(!valido);

                            switch(tolower(opcion[0]))
                            {
                                case 'a':
                                            do          // option 'A' Edit Product ID
                                            {
                                                pintarProductos_id_producto(idioma);
                                                gets(product[0].t_id_producto);        // temp produc[0].t_id_product
                                                valido = validarProductos_registro_id_producto(product,product[0].t_id_producto,p_counter,idioma);
                                            }
                                            while(!valido);
                                            printf("\n| %s | %s | %s | %s | %s | %s |\n",product[0].t_id_producto,product[pos].nombre_producto,product[pos].precio_compra,product[pos].precio_venta,product[pos].stock,product[pos].num_unidades);

                                            if(ContinuarSIoNO(valido,idioma)==1)
                                            {
                                                strcpy(product[pos].id_producto,product[0].t_id_producto);
                                                pintarProductosEditar_OK_2(idioma);
                                                strcpy(product[0].t_id_producto,"");     // clear product[0].t_id_product
                                                product_save = 1;                         // flag product to save at the end of the application
                                                continuar(valido,idioma);
                                                break;
                                            }
                                            else
                                            {
                                                pintarProductosEditar_NOT(idioma);
                                                continuar(valido,idioma);
                                                break;
                                            }
                                case 'b':          // option 'B' Edit Product Name
                                            do
                                            {
                                                pintarProductos_nombre_producto(idioma);
                                                gets(product[0].t_nombre_producto);        // temp produc[0].t_nombre_producto
                                                valido = validarProductos_nombre_producto(product[0].t_nombre_producto);
                                            }
                                            while(!valido);
                                            printf("\n| %s | %s | %s | %s | %s | %s |\n",product[pos].id_producto,product[0].t_nombre_producto,product[pos].precio_compra,product[pos].precio_venta,product[pos].stock,product[pos].num_unidades);

                                            if(ContinuarSIoNO(valido,idioma)==1)
                                            {
                                                strcpy(product[pos].nombre_producto,product[0].t_nombre_producto);
                                                pintarProductosEditar_OK_2(idioma);
                                                strcpy(product[0].t_nombre_producto,"");     // clear product[0].t_nombre_producto
                                                product_save = 1;                         // flag product to save at the end of the application
                                                continuar(valido,idioma);
                                                break;
                                            }
                                            else
                                            {
                                                pintarProductosEditar_NOT(idioma);
                                                continuar(valido,idioma);
                                                break;
                                            }
                                case 'c':                   // option 'C' Edit Product Purcharse Price
                                            do
                                            {
                                                pintarProductos_precio_compra(idioma);
                                                gets(product[0].t_precio_compra);        // temp produc[0].t_precio_compra
                                                valido = validarProductos_precio_compra(product[0].t_precio_compra);
                                            }
                                            while(!valido);
                                            printf("\n| %s | %s | %s | %s | %s | %s |\n",product[pos].id_producto,product[pos].nombre_producto,product[0].t_precio_compra,product[pos].precio_venta,product[pos].stock,product[pos].num_unidades);
                                            if(ContinuarSIoNO(valido,idioma)==1)
                                            {
                                                strcpy(product[pos].precio_compra,product[0].t_precio_compra);
                                                pintarProductosEditar_OK_2(idioma);
                                                strcpy(product[0].t_precio_compra,"");     // clear product[0].t_precio_compra
                                                product_save = 1;                         // flag product to save at the end of the application
                                                continuar(valido,idioma);
                                                break;
                                            }
                                            else
                                            {
                                                pintarProductosEditar_NOT(idioma);
                                                continuar(valido,idioma);
                                                break;
                                            }
                                case 'd':                   // option 'D' Edit Product Selling Price
                                            do
                                            {
                                                pintarProductos_precio_venta(idioma);
                                                gets(product[0].t_precio_venta);        // temp produc[0].t_precio_venta
                                                valido = validarProductos_precio_venta(product[0].t_precio_venta);
                                            }
                                            while(!valido);
                                            printf("\n| %s | %s | %s | %s | %s | %s |\n",product[pos].id_producto,product[pos].nombre_producto,product[pos].precio_compra,product[0].t_precio_venta,product[pos].stock,product[pos].num_unidades);
                                            if(ContinuarSIoNO(valido,idioma)==1)
                                            {
                                                strcpy(product[pos].precio_venta,product[0].t_precio_venta);
                                                pintarProductosEditar_OK_2(idioma);
                                                strcpy(product[0].t_precio_venta,"");     // clear product[0].t_precio_venta
                                                product_save = 1;                         // flag product to save at the end of the application
                                                continuar(valido,idioma);
                                                break;
                                            }
                                            else
                                            {
                                                pintarProductosEditar_NOT(idioma);
                                                continuar(valido,idioma);
                                                break;
                                            }
                                case 'e':                   // opcion 'E' Edit Product Stock
                                            do
                                            {
                                                pintarProductos_stock(idioma);
                                                gets(product[0].t_stock);        // temp produc[0].t_stock
                                                valido = validarProductos_stock(product[0].t_stock);
                                            }
                                            while(!valido);
                                            printf("\n| %s | %s | %s | %s | %s | %s |\n",product[pos].id_producto,product[pos].nombre_producto,product[pos].precio_compra,product[pos].precio_venta,product[0].t_stock,product[pos].num_unidades);
                                            if(ContinuarSIoNO(valido,idioma)==1)        // last continue edit the product
                                            {
                                                strcpy(product[pos].stock,product[0].t_stock);
                                                pintarProductosEditar_OK_2(idioma);
                                                strcpy(product[0].t_stock,"");     // clear product[0].t_stock
                                                product_save = 1;                         // flag product to save at the end of the application
                                                continuar(valido,idioma);
                                                break;
                                            }
                                            else
                                            {
                                                pintarProductosEditar_NOT(idioma);
                                                continuar(valido,idioma);
                                                break;
                                            }
                                }
                default:break;
            }
        }
        else
        {
            continuar(valido,idioma);
        }
    }
}
void ProductosBorrar(int valido,int idioma)
{
    int pos;
    if(p_counter==0)        // if products counter==0 there aren´t products in the register
    {
        pintarProductosNoExiste_2(idioma);
        continuar(valido,idioma);
    }
    else
    {
        pintarProductosBorrar(idioma);
        do
        {
            pintarProductos_id_producto(idioma);
            gets(product[0].t_id_producto);
            valido = validarProductos_general_id_producto(product[0].t_id_producto);
            if(!valido)
            {
                pintarValidarProductos_id_producto(idioma);
                continuar(valido,idioma);
            }
        }
        while(!valido);
        pos = BuscadorProductos(product,product[0].t_id_producto,'a',idioma);     // returns row position of product, if pos=0 the Product don´t exist
        if(pos==0)
        {
            continuar(valido,idioma);
        }
        else
        {
            switch(ContinuarSIoNO(valido,idioma))
            {
            case 1:
                        // deletes the last product to product to remove //
                        strcpy(product[pos].id_producto,product[p_counter].id_producto);
                        strcpy(product[pos].nombre_producto,product[p_counter].nombre_producto);
                        strcpy(product[pos].precio_compra,product[p_counter].precio_compra);
                        strcpy(product[pos].precio_venta,product[p_counter].precio_venta);
                        strcpy(product[pos].stock,product[p_counter].stock);
                        strcpy(product[pos].num_unidades,product[p_counter].num_unidades);
                        product_save = 1;                         // flag product to save at the end of the application
                        // copy the empty string at the last product //
                        strcpy(product[p_counter].id_producto,"");
                        strcpy(product[p_counter].nombre_producto,"");
                        strcpy(product[p_counter].precio_compra,"");
                        strcpy(product[p_counter].precio_venta,"");
                        strcpy(product[p_counter].stock,"");
                        strcpy(product[p_counter].num_unidades,"");
                        p_counter--;      //substrac 1 to clients counter
                        pintarProductosBorrar_OK(idioma);
                        continuar(valido,idioma);
                        break;

            default:    pintarProductosNoBorrado(idioma);
                        continuar(valido,idioma);
                        break;
            }
        }
    }
}
int BuscadorProductos(struct Products product[],char *entrada,int id_product_o_name_product,int idioma)
{
    int index,i,j,k,flag;          // el flag es para saber si se ha encontrado un cliente por su nombre
    int stop;
    int find;

    if(id_product_o_name_product=='a')        // Search by Product ID
    {
        stop=0;
        index=0;
        find=0;
        while(stop==0 && find==0)
        {
            index++;
            if(strncmp(product[index].id_producto,entrada,3)==0)
            {
                printf("\n| %s | %s | %s | %s | %s | %s |\n",product[index].id_producto,product[index].nombre_producto,product[index].precio_compra,product[index].precio_venta,product[index].stock,product[index].num_unidades);
                find=1;
            }
            if(index>p_counter && find==0)
            {
                pintarProductosNoExiste_1(idioma);
                index=0;
                stop=1;
            }
        }
        if(find==0)
        {
            index=0;
        }
        return index;
    }
    else if(id_product_o_name_product=='b')   // Search Product Name
    {
        stop=0;
        index=1;
        find=0;
        flag=0;
        i=0;
        for(index=1;index<=p_counter;index++)
        {
            while(i<=strlen(product[index].nombre_producto) && find==0)
            {
                if(tolower(product[index].nombre_producto[i]) == tolower(entrada[0]))
                {
                    j=i;
                    k=0;
                    while(tolower(product[index].nombre_producto[j]) == tolower(entrada[k]) && strlen(entrada)>k)
                    {
                        k++;
                        j++;
                    }
                    if(k==strlen(entrada))
                    {

                        printf("\n| %s | %s | %s | %s | %s | %s |\n",product[index].id_producto,product[index].nombre_producto,product[index].precio_compra,product[index].precio_venta,product[index].stock,product[index].num_unidades);
                        find=1;
                        flag=1;
                    }
                    i++;
                }
                else
                {
                    i++;
                }
            }
            i=0;
            find=0;
        }
        if(flag==0)
        {
            pintarProductosNoExiste_1(idioma);
        }
    }
    return index;
}
void ProductosBuscar(int valido,int idioma)
{
    char garbage[30];
    if(p_counter==0)
    {
        pintarProductosNoExiste_2(idioma);
        continuar(valido,idioma);
    }
    else
    {
        do
        {
            system("cls");
            pintarMenuProductos(idioma);
            pintarProductosBuscar(idioma);
            gets(garbage);
            valido = validarProductosBuscar(garbage);
            if(!valido)
            {
                pintarValidarProductosBuscar(idioma);
                continuar(valido,idioma);
            }
        }
        while(!valido);

        switch(tolower(garbage[0]))
        {
            case 'a':   do                                      // Productos Buscar ID Producto
                        {
                            pintarProductos_id_producto(idioma);
                            gets(garbage);
                            valido = validarProductos_general_id_producto(garbage);
                            if(!valido)
                            {
                                pintarValidarProductos_id_producto(idioma);
                            }
                        }
                        while(!valido);
                        BuscadorProductos(product,garbage,'a',idioma);
                        continuar(valido,idioma);
                        break;

            case 'b':   do                                      // Productos Buscar Nombre Producto
                        {
                            pintarProductos_nombre_producto(idioma);
                            gets(garbage);
                            valido = validarProductos_nombre_producto(garbage);
                            if(!valido)
                            {
                                pintarValidarProductos_nombre_producto(idioma);
                            }
                        }
                        while(!valido);
                        BuscadorProductos(product,garbage,'b',idioma);
                        continuar(valido,idioma);
                        break;
                                                    // Productos Buscar ID Producto
        default:    break;
        }
    }
}
void ProductosListado(int valido,int idioma)
{
    char garbage[30];
    if(p_counter==0)
    {
        pintarProductosNoExiste_2(idioma);
        continuar(valido,idioma);
    }
    else
    {
        do
        {
            system("cls");
            pintarMenuProductos(idioma);
            pintarProductosListado(idioma);
            gets(garbage);
            valido = validarProductosListado(garbage);
            if(!valido)
            {
                pintarValidarProductosListado(idioma);
                continuar(valido,idioma);
            }
        }
        while(!valido);
        switch(tolower(garbage[0]))
        {
            case 'a':   ProductosListado_max_vendido(valido,idioma);
                        continuar(valido,idioma);
                        break;
            case 'b':   ProductosListado_max_rentabilidad(valido,idioma);
                        continuar(valido,idioma);
                        break;
            case 'c':   ProductosListado_max_stock(valido,idioma);
                        continuar(valido,idioma);
                        break;
            default:    pintarError(idioma);
                        continuar(valido,idioma);
                        break;
        };
    }

}
void ProductosListado_max_vendido(int valido,int idioma)
{
    int i,j;
    char temp[30];

    i=1;
    if(p_counter!=0)        // si hay productos en el registro paso todos los datos de los productos a una variable temporal
    {
        for(i=1;i<=p_counter;i++)
        {
            strcpy(product[i].t_id_producto,product[i].id_producto);          // temp_produc
            strcpy(product[i].t_nombre_producto,product[i].nombre_producto);  // temp_name
            strcpy(product[i].t_precio_compra,product[i].precio_compra);      // temp_purch_price
            strcpy(product[i].t_precio_venta,product[i].precio_venta);        // temp_sell_price
            strcpy(product[i].t_stock,product[i].stock);                      // temp_stock
            strcpy(product[i].t_num_unidades,product[i].num_unidades);        // temp_num_units
        }
        i=0;
        for (i=1;i<=p_counter;i++)
        {
            for(j=1; j<=p_counter-1; j++)
            {
                if(atoi(product[j].t_num_unidades)<atoi(product[j+1].t_num_unidades))
                {
                        strcpy(temp,product[j].t_id_producto);
                        strcpy(product[j].t_id_producto,product[j+1].t_id_producto);
                        strcpy(product[j+1].t_id_producto,temp);
                        strcpy(temp,product[j].t_nombre_producto);
                        strcpy(product[j].t_nombre_producto,product[j+1].t_nombre_producto);
                        strcpy(product[j+1].t_nombre_producto,temp);
                        strcpy(temp,product[j].t_precio_compra);
                        strcpy(product[j].t_precio_compra,product[j+1].t_precio_compra);
                        strcpy(product[j+1].t_precio_compra,temp);
                        strcpy(temp,product[j].t_precio_venta);
                        strcpy(product[j].t_precio_venta,product[j+1].t_precio_venta);
                        strcpy(product[j+1].t_precio_venta,temp);
                        strcpy(temp,product[j].t_stock);
                        strcpy(product[j].t_stock,product[j+1].t_stock);
                        strcpy(product[j+1].t_stock,temp);
                        strcpy(temp,product[j].t_num_unidades);
                        strcpy(product[j].t_num_unidades,product[j+1].t_num_unidades);
                        strcpy(product[j+1].t_num_unidades,temp);
                }
            }
        }
        for(i=1;i<=p_counter;i++)
        {
            printf("\n%d.- %s | %s | %s | %s | %s | %s |\n",i,product[i].t_id_producto,product[i].t_nombre_producto,product[i].t_precio_compra,product[i].t_precio_venta,product[i].t_stock,product[i].t_num_unidades);
            if(i%10==0)
            {
                printf("----------- || ----------- || -----------");
                continuar(valido,idioma);
            }
        }
    }
    else        // si no hay productos en el array muestra este mensaje en pantalla
    {
        pintarProductosNoExiste_2(idioma);
    }
}
void ProductosListado_max_rentabilidad(int valido,int idioma)
{
    int i,j;
    char temp[30];

    i=1;
    if(p_counter!=0)        // si hay productos en el registro paso todos los datos de los productos a una variable temporal
    {
        for(i=1;i<=p_counter;i++)
        {
            strcpy(product[i].t_id_producto,product[i].id_producto);          // temp_produc
            strcpy(product[i].t_nombre_producto,product[i].nombre_producto);  // temp_name
            strcpy(product[i].t_precio_compra,product[i].precio_compra);      // temp_purch_price
            strcpy(product[i].t_precio_venta,product[i].precio_venta);        // temp_sell_price
            strcpy(product[i].t_stock,product[i].stock);                      // temp_stock
            strcpy(product[i].t_num_unidades,product[i].num_unidades);        // temp_num_units
        }
        i=0;
        for (i=1;i<=p_counter;i++)
        {
            for(j=1; j<=p_counter-1; j++)
            {       // La maxima rentabilidad la calcula con la diferencia entre el precio de compra y el precio de venta
                if(atof(product[j].t_precio_venta)-atof(product[j].t_precio_compra)<atof(product[j+1].t_precio_venta)-atof(product[j+1].t_precio_compra))
                {
                        strcpy(temp,product[j].t_id_producto);
                        strcpy(product[j].t_id_producto,product[j+1].t_id_producto);
                        strcpy(product[j+1].t_id_producto,temp);
                        strcpy(temp,product[j].t_nombre_producto);
                        strcpy(product[j].t_nombre_producto,product[j+1].t_nombre_producto);
                        strcpy(product[j+1].t_nombre_producto,temp);
                        strcpy(temp,product[j].t_precio_compra);
                        strcpy(product[j].t_precio_compra,product[j+1].t_precio_compra);
                        strcpy(product[j+1].t_precio_compra,temp);
                        strcpy(temp,product[j].t_precio_venta);
                        strcpy(product[j].t_precio_venta,product[j+1].t_precio_venta);
                        strcpy(product[j+1].t_precio_venta,temp);
                        strcpy(temp,product[j].t_stock);
                        strcpy(product[j].t_stock,product[j+1].t_stock);
                        strcpy(product[j+1].t_stock,temp);
                        strcpy(temp,product[j].t_num_unidades);
                        strcpy(product[j].t_num_unidades,product[j+1].t_num_unidades);
                        strcpy(product[j+1].t_num_unidades,temp);
                }
            }
        }
        for(i=1;i<=p_counter;i++)
        {
            printf("\n%d.- %s | %s | %s | %s | %s | %s |\n",i,product[i].t_id_producto,product[i].t_nombre_producto,product[i].t_precio_compra,product[i].t_precio_venta,product[i].t_stock,product[i].t_num_unidades);
            if(i%10==0)
            {
                printf("----------- || ----------- || -----------");
                continuar(valido,idioma);
            }
        }
    }
    else        // si no hay productos en el array muestra este mensaje en pantalla
    {
        pintarProductosNoExiste_2(idioma);
    }
}
void ProductosListado_max_stock(int valido,int idioma)
{
    int i,j;
    char temp[30];

    i=1;
    if(p_counter!=0)        // si hay productos en el registro paso todos los datos de los productos a una variable temporal
    {
        for(i=1;i<=p_counter;i++)
        {
            strcpy(product[i].t_id_producto,product[i].id_producto);          // temp_produc
            strcpy(product[i].t_nombre_producto,product[i].nombre_producto);  // temp_name
            strcpy(product[i].t_precio_compra,product[i].precio_compra);      // temp_purch_price
            strcpy(product[i].t_precio_venta,product[i].precio_venta);        // temp_sell_price
            strcpy(product[i].t_stock,product[i].stock);                      // temp_stock
            strcpy(product[i].t_num_unidades,product[i].num_unidades);        // temp_num_units
        }
        i=0;
        for (i=1;i<=p_counter;i++)
        {
            for(j=1; j<=p_counter-1; j++)
            {
                if(atoi(product[j].t_stock)<atoi(product[j+1].t_stock))
                {
                        strcpy(temp,product[j].t_id_producto);
                        strcpy(product[j].t_id_producto,product[j+1].t_id_producto);
                        strcpy(product[j+1].t_id_producto,temp);
                        strcpy(temp,product[j].t_nombre_producto);
                        strcpy(product[j].t_nombre_producto,product[j+1].t_nombre_producto);
                        strcpy(product[j+1].t_nombre_producto,temp);
                        strcpy(temp,product[j].t_precio_compra);
                        strcpy(product[j].t_precio_compra,product[j+1].t_precio_compra);
                        strcpy(product[j+1].t_precio_compra,temp);
                        strcpy(temp,product[j].t_precio_venta);
                        strcpy(product[j].t_precio_venta,product[j+1].t_precio_venta);
                        strcpy(product[j+1].t_precio_venta,temp);
                        strcpy(temp,product[j].t_stock);
                        strcpy(product[j].t_stock,product[j+1].t_stock);
                        strcpy(product[j+1].t_stock,temp);
                        strcpy(temp,product[j].t_num_unidades);
                        strcpy(product[j].t_num_unidades,product[j+1].t_num_unidades);
                        strcpy(product[j+1].t_num_unidades,temp);
                }
            }
        }
        for(i=1;i<=p_counter;i++)
        {
            printf("\n%d.- %s | %s | %s | %s | %s | %s |\n",i,product[i].t_id_producto,product[i].t_nombre_producto,product[i].t_precio_compra,product[i].t_precio_venta,product[i].t_stock,product[i].t_num_unidades);
            if(i%10==0)
            {
                printf("----------- || ----------- || -----------");
                continuar(valido,idioma);
            }
        }
    }
    else        // si no hay productos en el array muestra este mensaje en pantalla
    {
        pintarProductosNoExiste_2(idioma);
    }
}
void EscribirFicheroProductos(struct Products product[],int valido,int idioma)
{
    FILE *file;
    int index;
    char garbage[30];
    printf("\nPRODUCTOS FICHERO, guardar como: ");
    //memset(fin_carro,10,strlen(fin_carro));
    gets(garbage);

    file = fopen(garbage,"wb");

        fprintf(file,"%s%c",INI_PRODUCTOS,10);

        index=1;
        for(index=1;index<=p_counter;index++)
        {
            fprintf(file,"%s %c%s%c %s %s %s %s%c",product[index].id_producto,34,product[index].nombre_producto,34,product[index].precio_compra,product[index].precio_venta,product[index].stock,product[index].num_unidades,10);
        }
        fprintf(file,"%s%c",FIN_PRODUCTOS,10);
        /*for(index=1;index<=p_counter;index++)
        {
            printf("\n%s ||",product[index].id_producto);
            printf(" %s ||",product[index].nombre_producto);
            printf(" %s ||",product[index].precio_compra);
            printf(" %s ||",product[index].precio_venta);
            printf(" %s ||",product[index].stock);
            printf(" %s |",product[index].num_unidades);
        }*/
        continuar(valido,idioma);
        if(fclose(file)!=0)
        {
            pintarArchivoNoCerrado(idioma);
            continuar(valido,idioma);
        }
}
