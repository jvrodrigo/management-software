#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<time.h>
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

void LeerFicheroFacturas(char *argv,struct Invoices invoice[],int valido,int idioma)
{
    int row,column,index,pos,quotes,flag,final_fichero,p_column,p_row,nuevo_p;
    char garbage[31];
    char buffer[1];
    flag=0;
    FILE *file = NULL;
    file = fopen(argv,"r");
    printf("\n\n(FACTURAS) Comprobando formato: %s",argv);
    fseek(file,0,SEEK_END);
    if(ftell(file)!=0)
    {
        fseek(file,0,SEEK_SET);
        if(strcmp(fgets(garbage,9,file),FACTURAS)==0)
        {
            fseek(file,-13,SEEK_END);
            if(strcmp(fgets(garbage,13,file),FIN_FACTURAS)==0)
            {
                printf("\n(FACTURAS) El fichero coincide con el formato\n");
                flag = 1;
            }
            else
            {
                printf("\n(FACTURAS) El fichero no coincide con el formato\n");
                flag=0;
            }
        }
        else
        {
            printf("\n(FACTURAS) El fichero no coincide con el formato\n");
            flag=0;
        }
    }
    else
    {
        printf("\n(FACTURAS) El fichero no coincide con el formato\n");
    }
    if(flag==1)
    {
        fseek(file,0,SEEK_END);
        final_fichero=ftell(file);
        i_counter=0;
        row=0;
        column=0;
        index=0;
        pos=9;
        quotes=0;
        p_row=1;
        p_column=0;
        invoice[row].num_prod=0;

        while(pos<=final_fichero && flag==1)
        {
            fseek(file,pos,SEEK_SET);
            fread(buffer,1,1,file);
            //printf("\n\tpos[%d]: %c",pos,buffer[0]);
            //printf("\tcolumn: %d",column);
            if(column==13)
            {
                if(flag==1)
                {
                    if(p_column==5)
                    {
                        /*if(buffer[0]==10 && strcmp(fgets(garbage,7,file),INI_FAC)==0)
                        {
                            column=0;
                            printf("\nComprueba INI_FAC: %s",invoice[row].temp);
                            index=0;
                        }*/
                        if(strcmp(invoice[row].temp,FIN_FAC)==0)
                        {
                            //printf("\nVERIFICA FIN_FAC: %s",invoice[row].temp);
                            memset(garbage,'\0',strlen(garbage));
                            memset(invoice[row].temp,'\0',strlen(invoice[row].temp));
                            column=0;
                            index=0;

                            if(strcmp(fgets(garbage,13,file),FIN_FACTURAS)==0)
                            {
                                //printf("\nFIN FACTURAS: %s",garbage);
                                memset(invoice[row].temp,'\0',strlen(invoice[row].temp));
                                flag=0;
                            }
                        }
                        if(strcmp(invoice[row].temp,PRODUCTO)==0)
                        {
                            //printf("\nComprueba EX PRODUCTO: %s pos: %d",invoice[row].temp,pos);
                            invoice[row].num_prod++;   // Add a new product
                            p_column=0;        // Next
                            index=0;
                            p_row++;
                            flag=1;     // Continue
                            memset(invoice[row].temp,'\0',strlen(invoice[row].temp));      // Reset temp
                        }
                        if(buffer[0]!=10)
                        {
                            invoice[row].temp[index]=buffer[0];
                            //printf("\nComprueba: %s pos: %d",invoice[row].temp,pos);
                            index++;
                        }
                    }
                    if(p_column==4)
                    {
                        invoice[row].temp[index]=buffer[0];
                        //printf("\nComprueba P_FIN: %s",invoice[row].temp);
                        index++;
                        if(strcmp(invoice[row].temp,"FIN")==0)
                        {
                            memset(invoice[row].temp,'\0',strlen(invoice[row].temp));
                            p_column++;
                            index=0;
                            nuevo_p=0;  // New Product

                        }
                    }
                    if(p_column==3)
                    {
                        if(buffer[0]==' ' && index>0)
                        {
                            strcpy(invoice[row].temp,"");      // Reset temp
                            p_column++;;
                            index=0;

                        }
                        else if(buffer[0]!=' ')
                        {
                            invoice[row].invo_product[p_row].total_product[index]=buffer[0];
                            //printf("\nComprueba P_TOTAL: %s",invoice[row].invo_product[p_row].total_product);
                            index++;
                        }
                    }
                    if(p_column==2)
                    {
                        if(buffer[0]==' ')
                        {
                            index=0;
                            p_column++;
                        }
                        else if(buffer[0]!=' ')
                        {
                            invoice[row].invo_product[p_row].price_product[index]=buffer[0];
                            //printf("\nComprueba P_UNITARIO: %s",invoice[row].invo_product[p_row].price_product);
                            index++;
                        }
                    }
                    if(p_column==1)
                    {
                        if(buffer[0]==' ' && strlen(invoice[row].invo_product[p_row].units_product)>0)
                        {
                            index=0;
                            p_column++;
                        }
                        else if(buffer[0]!=' ')
                        {
                            invoice[row].invo_product[p_row].units_product[index]=buffer[0];
                            //printf("\nComprueba P_UNIDADES: %s",invoice[row].invo_product[p_row].units_product);
                            index++;
                        }
                    }
                    if(p_column==0)
                    {
                        if(buffer[0]=='"' && quotes%2==1)
                        {
                            quotes=0;
                            index=0;
                            p_column++;
                        }
                        else if(buffer[0]=='"' && quotes%2==0)
                        {
                            index=0;
                            quotes++;
                        }
                        else if(buffer[0]!='"' && quotes%2==1)
                        {
                            invoice[row].invo_product[p_row].name_product[index]=buffer[0];
                            //printf("\nComprueba P_NOMBRE: %s",invoice[row].invo_product[p_row].name_product);
                            index++;
                        }
                    }
                }
            }
            if(column==12)
            {
                if(strcmp(invoice[row].temp,PRODUCTO)==0)
                {
                    memset(invoice[row].temp,'\0',strlen(invoice[row].temp));      // Reset temp
                    column++;  // Next
                    index=0;
                    p_row=1;
                    invoice[row].num_prod++;
                    //printf("\nNumero de Productos: %d",invoice[row].num_prod);
                    nuevo_p=1;      // New Product
                    p_column=0;    // Start to check products
                    flag=1;     //Enter to check products
                }
                if(buffer[0]!='\n' && column==12)
                {
                    invoice[row].temp[index]=buffer[0];
                    //printf("\nComprueba PRODUCTO: %s",invoice[row].temp);
                    index++;
                }
            }
            if(column==11)      // Check TOTAL PRICE
            {
                if(buffer[0]=='\n' && column==11)
                {
                    index=0;
                    column++;      // Next
                }
                else if(buffer[0]!=' ' && column==11)
                {
                    invoice[row].i_precio_total[index]=buffer[0];
                    //printf("\nComprueba PRECIO TOTAL: %s",invoice[row].i_precio_total);
                    index++;
                }
            }
            if(column==10)      // Check TOTAL VAT PRICE
            {
                if(buffer[0]==' ')
                {
                    index=0;
                    column++;      // Next
                }
                else if(buffer[0]!=' ')
                {
                    invoice[row].i_precio_iva[index]=buffer[0];
                    //printf("\nComprueba PRECIO IVA: %s",invoice[row].i_precio_iva);
                    index++;
                }
            }
            if(column==9)      // Check TOTAL BASE PRICE
            {
                if(buffer[0]==' ' && index>0)
                {
                    index=0;
                    column++;      // Next
                }
                else if(buffer[0]!=' ' && buffer[0]!='"')
                {
                    invoice[row].i_precio_base[index]=buffer[0];
                    //printf("\nComprueba PRECIO BASE: %s",invoice[row].i_precio_base);
                    index++;
                }
            }
            if(column==8)      // Check DATE
            {
                if(buffer[0]=='"' && quotes%2==1)
                {
                    quotes=0;
                    index=0;
                    column++;      // Next
                }
                else if(buffer[0]=='"' && quotes%2==0)
                {
                    index=0;
                    quotes++;
                }
                else if(buffer[0]!='"' && quotes%2==1)
                {
                    invoice[row].reg_date[index]=buffer[0];
                    //printf("\nComprueba DATE: %s",invoice[row].reg_date);
                    index++;
                }
            }
            if(column==7)      // Check Customer DIR
            {
                if(buffer[0]=='"' && quotes%2==1)
                {
                    quotes=0;
                    column++;      // Next
                }
                else if(buffer[0]=='"' && quotes%2==0)
                {
                    index=0;
                    quotes++;
                }
                else if(buffer[0]!='"' && quotes%2==1)
                {
                    invoice[row].dir_client[index]=buffer[0];
                    //printf("\nComprueba DIR CLIENTE: %s",invoice[row].dir_client);
                    index++;
                }
            }
            else if(column==6)     // Check Customer Name RS
            {
                if(buffer[0]=='"' && quotes%2==1)
                {
                    quotes=0;
                    column++;      // Next
                }
                else if(buffer[0]=='"' && quotes%2==0)
                {
                    index=0;
                    quotes++;
                }
                else if(buffer[0]!='"' && quotes%2==1)
                {
                    invoice[row].name_rs_client[index]=buffer[0];
                    //printf("\nComprueba NOMBRE CLIENTE: %s",invoice[row].name_rs_client);
                    index++;
                }
            }
            else if(column==5)     // Check DNI or CIF Customer
            {
                if(strlen(invoice[row].dni_cif_client)==9)
                {
                    column++;          // Next
                    index=0;
                }
                else
                {
                    if(buffer[0]!=' ' && buffer[0]!='"')
                    {
                        invoice[row].dni_cif_client[index] = buffer[0];
                        //printf("\nComprueba CLIENTE DNI_CIF: %s",invoice[row].dni_cif_client);
                        index++;
                    }
                }
            }
            else if(column==4)     // Check Address Company
            {
                if(buffer[0]=='"' && quotes%2==1)
                {
                    quotes=0;
                    index=0;
                    column++;      // Next
                }
                else if(buffer[0]=='"' && quotes%2==0)
                {
                    index=0;
                    quotes++;
                }
                else if(buffer[0]!='"' && quotes%2==1)
                {
                    invoice[row].i_dir_company[index]=buffer[0];
                    //printf("\nComprueba DIR_EMPRESA: %s",invoice[row].i_dir_company);
                    index++;
                }
            }
            else if(column==3) // Check Name Company
            {
                if(buffer[0]=='"' && quotes%2==1)
                {
                    quotes=0;
                    column++;      // Next
                }
                else if(buffer[0]=='"' && quotes%2==0)
                {
                    index=0;
                    quotes++;
                }
                else if(buffer[0]!='"' && quotes%2==1)
                {
                    invoice[row].i_name_company[index]=buffer[0];
                    //printf("\nComprueba NOMBRE EMPRESA: %s",invoice[row].i_name_company);
                    index++;
                }
            }
            else if(column==2) // Check CIF Company
            {
                if(strlen(invoice[row].i_cif_company)==9)
                {
                    column++;      // Next
                    index=0;
                }
                else
                {
                    if(buffer[0]!=' ')
                    {
                        invoice[row].i_cif_company[index]=buffer[0];
                        //printf("\nComprueba CIF_EMPRESA: %s",invoice[row].i_cif_company);
                    }
                    index++;
                }
            }
            else if(column==1) // Check Invoice ID
            {
                if(strlen(invoice[row].id_invoice)==8)
                {
                    column++;      // Next
                    index=0;
                }
                else
                {
                    if(buffer[0]!=' ')
                    {
                        invoice[row].id_invoice[index]=buffer[0];
                        //printf("\nComprueba FACTURA_ID: %s",invoice[row].id_invoice);
                        index++;
                    }
                }
            }
            else if(column==0)         // Check INI_FAC
            {
                /*if(strcmp(invoice[row].temp,FIN_FACTURAS)==0)
                {
                    printf("FIN FACTURAS: %s",invoice[row].temp);
                    flag=0;
                }*/
                if(strcmp(invoice[row].temp,INI_FAC)==0)
                {
                    row++;
                    i_counter++;     // Invoice Global counter +1
                    column++;      // Next
                    index=0;
                    //printf("\nVERIFICA INI_FAC: %s, contador Facturas: %d",invoice[row-1].temp,i_counter);
                }
                if(buffer[0]!=10 && column==0)
                {
                    invoice[row].temp[index]=buffer[0];
                    index++;
                }
            }
            if(index>50)
            {
                printf("\nALGUN DATO NO MANTIENE EL FORMATO");
                pintarError(idioma);
                pos=final_fichero;
                i_counter=0;    // Pone a 0 el contador general si hay algun fallo
            }
            pos++;
        }
    }
    else
    {
        printf("\n(FACTURAS) El fichero no coincide con el formato\n");
    }
    if(i_counter!=0)
    {

    }
    if(fclose(file)!=0)
    {
        pintarArchivoNoCerrado(idioma);
    }
}
void FacturasCrear(int valido,int idioma)
{
    char garbage[30];
    int product_pos;    // Searching position
    int client_pos;     // Searching position
    int flag,i;
    int i_p_counter;


    time_t ahora;
    struct tm *fecha;
    time(&ahora);
    fecha = localtime(&ahora);

	flag=0;     // Save changes
	CalculateTotalStock(product);
	if(p_counter!=0 && c_counter!=0 && TOTAL_STOCK!=0)    // if there are customers and products
	{
	    i_p_counter=1;       // Start Invoice Product Counter to add products to NEW Invoice[n]
	    pintarFacturasCrear(idioma);    // Screen menssage
        do                  // NEW Invoice, NEW Customer´s invoice
        {
            pintarClientes_dni_cif(idioma);
            gets(garbage);
            valido = validarClientes_general_dni_cif(garbage,idioma);        // validate DNI or CIF format
        }
        while(!valido);
        client_pos = BuscadorClientes(client,garbage,'a',idioma);       // Search the Coustomer
        if(client_pos!=0)       // if find the customer in the registry
        {
            i_counter++;      // Add +1 to General accountant bills NEW INVOICE
            invoice[i_counter].precio_base=0;      // Start Invoice base price
            while(flag==0 && TOTAL_STOCK!=0)      // Stop when flag!=0 and TOTAL stock==0
            {
                do
                {
                    printf("\nIntroduzca el ID del producto a comprar: ");
                    gets(garbage);
                    valido = validarProductos_general_id_producto(garbage);
                    if(!valido)
                    {
                        pintarValidarProductos_id_producto(idioma);
                    }
                }
                while(!valido);
                product_pos = BuscadorProductos(product,garbage,'a',idioma);        // Product position on register and shows the product on screen
                if(product_pos!=0 && atoi(product[product_pos].stock)!=0)        // If EXIST Product and EXIST Stock_product
                {
                    do
                    {
                        printf("\nIntroduzca el numero de unidades a comprar: ");
                        gets(garbage);
                        valido = validarProductosFacturas_num_unidades(product,garbage,product_pos,idioma);
                    }
                    while(!valido);

                    strcpy(invoice[i_counter].invo_product[i_p_counter].name_product,product[product_pos].nombre_producto);     // Copy Name product to Invoice
                    strcpy(invoice[i_counter].invo_product[i_p_counter].units_product,garbage);                                 // Copy Units product to Invoice
                    strcpy(invoice[i_counter].invo_product[i_p_counter].price_product,product[product_pos].precio_venta);         // Copy Price/U product to Invoice
                    gcvt(atof(product[product_pos].precio_venta)*atoi(garbage),10,invoice[i_counter].invo_product[i_p_counter].total_product);       // ConvertAndCopy //gvct convert price total product and save it in 'factura[n].invo_produc[n].total_product'
                    invoice[i_counter].precio_base = atof(product[product_pos].precio_venta)*atoi(garbage) + invoice[i_counter].precio_base;        // Add Base Price

                    printf("\n| %s |",invoice[i_counter].invo_product[i_p_counter].name_product);
                    printf("%s | ",invoice[i_counter].invo_product[i_p_counter].units_product);
                    printf("%s | ",invoice[i_counter].invo_product[i_p_counter].price_product);
                    printf("%s |\n",invoice[i_counter].invo_product[i_p_counter].total_product);

                    itoa(atoi(product[product_pos].stock)-atoi(garbage),product[product_pos].t_stock,10);        // Product Register: Substrac -1 product[n].stock and save in temp_stock
                    strcpy(product[product_pos].stock,product[product_pos].t_stock);                               //  Product Register: Copy temp_stock to register
                    itoa(atoi(product[product_pos].num_unidades)+atoi(garbage),product[product_pos].t_num_unidades,10);       // Product Register: Add  +1 product[n].num_unidades and save in temp_num_unidades
                    strcpy(product[product_pos].num_unidades,product[product_pos].t_num_unidades);    // Product Register: Copy temp_stock to register

                    CalculateTotalStock(product);
                    do
                    {
                        printf("\nDesea seguir comprando s/n: ");
                        gets(garbage);
                        valido = validarContinuarSIoNO(garbage,valido,idioma);
                    }
                    while(!valido);
                    switch(tolower(garbage[0]))
                    {
                        case 's':   if(TOTAL_STOCK!=0)  // If there are Stock products to buy CONTINUE
                                    {
                                        i_p_counter++;       // Continue adding products to invoice
                                        break;
                                    }
                                    else
                                    {
                                        flag=1;     // Stop
                                        pintarProductosNoExiste_2(idioma);
                                        continuar(valido,idioma);
                                        break;
                                    }
                        case 'y':   if(TOTAL_STOCK!=0)      // If there are Stock products to buy CONTINUE
                                    {
                                        i_p_counter++;       // Continue adding products to invoice
                                        break;
                                    }
                                    else
                                    {
                                        flag=1;     // Stop
                                        pintarProductosNoExiste_2(idioma);
                                        continuar(valido,idioma);
                                        break;
                                    }
                        case 'n':   flag=1;     // Stop adding products to bill
                                    break;
                    }
                }
                else
                {
                    pintarFacturasNoHayStock(idioma);
                }
            }       // End WHILE CREATE INVOICE
            if(flag==1)        // When makes a bill or when there aren´t stock TOTAL PRODUCTS and makes
            {
                strcat(invoice[i_counter].id_invoice,itoa((fecha->tm_year+1900)*1000,invoice[i_counter].temp,10));    // Concat year to id_invoice
                strcat(invoice[i_counter].id_invoice,itoa(i_counter,invoice[i_counter].temp,10));      // Concat i_counter to id_invoice
                strcat(invoice[i_counter].reg_date,itoa(fecha->tm_mday,invoice[i_counter].temp,10));        // Date
                strcat(invoice[i_counter].reg_date,"/");                                                    // Date
                strcat(invoice[i_counter].reg_date,itoa(fecha->tm_mon+1,invoice[i_counter].temp,10));       // Date
                strcat(invoice[i_counter].reg_date,"/");                                                    // Date
                strcat(invoice[i_counter].reg_date,itoa(fecha->tm_year + 1900,invoice[i_counter].temp,10)); // Date
                // Copy Bussines Information to Bill//
                strcpy(invoice[i_counter].i_cif_company,CIF_EMPRESA);
                strcpy(invoice[i_counter].i_name_company,NOMBRE_EMPRESA);
                strcpy(invoice[i_counter].i_dir_company,DIR_EMPRESA);
                // Copy Customer information to Bill //
                strcpy(invoice[i_counter].dni_cif_client,client[client_pos].dni_cif);
                strcpy(invoice[i_counter].name_rs_client,client[client_pos].nombre_rs);
                strcpy(invoice[i_counter].dir_client,client[client_pos].direccion);

                invoice[i_counter].precio_iva = (invoice[i_counter].precio_base)*18/100;        // Calculate VAT Price
                invoice[i_counter].precio_total = invoice[i_counter].precio_iva + invoice[i_counter].precio_base;   // Calculate Total Price

                gcvt(invoice[i_counter].precio_base,10,invoice[i_counter].i_precio_base);   // Double to string
                gcvt(invoice[i_counter].precio_iva,10,invoice[i_counter].i_precio_iva);    // Double to string
                gcvt(invoice[i_counter].precio_total,10,invoice[i_counter].i_precio_total); // Double to string

                invoice[i_counter].num_prod = i_p_counter; // Register Total of Products in bill

                system("cls");
                printf("----------------------------------------------------------------------");
                printf("\nFACTURA %s | %s",invoice[i_counter].id_invoice,invoice[i_counter].reg_date);
                printf("\n----------------------------------------------------------------------");
                printf("\n%s\n%s\n%s",invoice[i_counter].i_name_company,invoice[i_counter].i_cif_company,invoice[i_counter].i_dir_company);
                printf("\n----------------------------------------------------------------------");
                printf("\nCLIENTE:\n%s | %s\n%s",invoice[i_counter].dni_cif_client,invoice[i_counter].name_rs_client,invoice[i_counter].dir_client);
                printf("\n----------------------------------------------------------------------");
                printf("\nDESCRIPCION\t\t\tUNIDADES\tPRECIO/U\tTOTAL");
                printf("\n----------------------------------------------------------------------");
                for(i=1;i<=i_p_counter;i++)
                {
                    printf("\n%s",invoice[i_counter].invo_product[i].name_product);
                    printf("\t\t%s",invoice[i_counter].invo_product[i].units_product);
                    printf("\t\t%s",invoice[i_counter].invo_product[i].price_product);
                    printf("\t\t%.2f",atof(invoice[i_counter].invo_product[i].total_product));
                }
                printf("\n----------------------------------------------------------------------");
                printf("\n\t\t\t\t\t\tBASE:\t\t%.2f",atof(invoice[i_counter].i_precio_base));
                printf("\n----------------------------------------------------------------------");
                printf("\n\t\t\t\t\t\tIVA(18):\t%.2f",atof(invoice[i_counter].i_precio_iva));
                printf("\n----------------------------------------------------------------------");
                printf("\n\t\t\t\t\t\tTOTAL:\t\t%.2f",atof(invoice[i_counter].i_precio_total));
                printf("\n----------------------------------------------------------------------");
                invoice_save=1;
                // SAVE THE INVOICE //
            }
        }
	}
	if(p_counter==0)
	{
	    pintarProductosNoExiste_2(idioma);
	}
	if(c_counter==0)
	{
	    pintarClientesNoExiste_2(idioma);
	}
	if(TOTAL_STOCK==0 && flag==0)
	{
        pintarFacturasNoHayStock(idioma);
	}
    continuar(valido,idioma);
}

void FacturasBorrar(int valido,int idioma)
{
    char garbage[30];
    int index,flag,i;
    do
    {
        pintarFacturasBorrar(idioma);
        gets(garbage);
        valido = validarFacturasBuscar_id_factura(garbage,valido,idioma);
    }
    while(!valido);
    index=1;
    flag=0;
    while(index<=i_counter && flag==0)
    {
        if(strcmp(garbage,invoice[index].id_invoice)==0)            // Write Invoice
        {
            system("cls");
            printf("----------------------------------------------------------------------");
            printf("\nFACTURA %s | %s",invoice[index].id_invoice,invoice[index].reg_date);
            printf("\n----------------------------------------------------------------------");
            printf("\n%s\n%s\n%s",invoice[index].i_name_company,invoice[index].i_cif_company,invoice[index].i_dir_company);
            printf("\n----------------------------------------------------------------------");
            printf("\nCLIENTE:\n%s | %s\n%s",invoice[index].dni_cif_client,invoice[index].name_rs_client,invoice[index].dir_client);
            printf("\n----------------------------------------------------------------------");
            printf("\nDESCRIPCION\t\t\tUNIDADES\tPRECIO/U\tTOTAL");
            printf("\n----------------------------------------------------------------------");
            for(i=1;i<=invoice[index].num_prod;i++)
            {
                printf("\n%s",invoice[index].invo_product[i].name_product);
                printf("\t\t%s",invoice[index].invo_product[i].units_product);
                printf("\t\t%s",invoice[index].invo_product[i].price_product);
                printf("\t\t%s",invoice[index].invo_product[i].total_product);
            }
            printf("\n----------------------------------------------------------------------");
            printf("\n\t\t\t\t\t\tBASE:\t\t%s",invoice[index].i_precio_base);
            printf("\n----------------------------------------------------------------------");
            printf("\n\t\t\t\t\t\tIVA(18):\t%s",invoice[index].i_precio_iva);
            printf("\n----------------------------------------------------------------------");
            printf("\n\t\t\t\t\t\tTOTAL:\t\t%s",invoice[index].i_precio_total);
            printf("\n----------------------------------------------------------------------");       // FIN Write Invoice
            flag=1;
        }
        if(flag==0)
        {
            index++;
        }
    }
    if(flag!=0)
    {
        switch(ContinuarSIoNO(valido,idioma))
        {
            case 1:     memset(invoice[index].id_invoice,'\0',strlen(invoice[index].id_invoice));
                        memset(invoice[index].reg_date,'\0',strlen(invoice[index].reg_date));
                        memset(invoice[index].i_name_company,'\0',strlen(invoice[index].i_name_company));
                        memset(invoice[index].i_cif_company,'\0',strlen(invoice[index].i_cif_company));
                        memset(invoice[index].i_dir_company,'\0',strlen(invoice[index].i_dir_company));
                        memset(invoice[index].dni_cif_client,'\0',strlen(invoice[index].dni_cif_client));
                        memset(invoice[index].name_rs_client,'\0',strlen(invoice[index].name_rs_client));
                        memset(invoice[index].dir_client,'\0',strlen(invoice[index].dir_client));
                        for(i=1;i<=invoice[index].num_prod;i++)
                        {
                            memset(invoice[index].invo_product[i].name_product,'\0',strlen(invoice[index].invo_product[i].name_product));
                            memset(invoice[index].invo_product[i].units_product,'\0',strlen(invoice[index].invo_product[i].units_product));
                            memset(invoice[index].invo_product[i].price_product,'\0',strlen(invoice[index].invo_product[i].price_product));
                            memset(invoice[index].invo_product[i].total_product,'\0',strlen(invoice[index].invo_product[i].total_product));
                        }
                        memset(invoice[index].i_precio_base,'\0',strlen(invoice[index].i_precio_base));
                        memset(invoice[index].i_precio_iva,'\0',strlen(invoice[index].i_precio_iva));
                        memset(invoice[index].i_precio_total,'\0',strlen(invoice[index].i_precio_total));
                        printf("\n---- Factura Borrada OK ----\n");
                        break;
            default:    printf("\n---- Factura No Borrada ----\n");
                        break;
        }
    }
    else
    {
        printf("\n---- No existe la Factura ----\n");
    }
    continuar(valido,idioma);
}
void FacturasBuscar(struct Invoices invoice[],int valido,int idioma)
{
    char garbage[30];
    int index,flag,i;
    do
    {
        pintarFacturasBuscar(idioma);
        gets(garbage);
        valido=validarFacturasBuscar(garbage,valido,idioma);
    }
    while(!valido);
    switch(tolower(garbage[0]))
    {
        case 'a':
                    do
                    {
                        pintarFacturasBuscar_id_factura(idioma);
                        gets(garbage);
                        valido = validarFacturasBuscar_id_factura(garbage,valido,idioma);
                    }
                    while(!valido);
                    index=1;
                    flag=0;
                    while(index<=i_counter && flag==0)
                    {
                        if(strcmp(garbage,invoice[index].id_invoice)==0)            // Write Invoice
                        {
                            flag=1;
                            system("cls");
                            printf("----------------------------------------------------------------------");
                            printf("\nFACTURA %s | %s",invoice[index].id_invoice,invoice[index].reg_date);
                            printf("\n----------------------------------------------------------------------");
                            printf("\n%s\n%s\n%s",invoice[index].i_name_company,invoice[index].i_cif_company,invoice[index].i_dir_company);
                            printf("\n----------------------------------------------------------------------");
                            printf("\nCLIENTE:\n%s | %s\n%s",invoice[index].dni_cif_client,invoice[index].name_rs_client,invoice[index].dir_client);
                            printf("\n----------------------------------------------------------------------");
                            printf("\nDESCRIPCION\t\t\tUNIDADES\tPRECIO/U\tTOTAL");
                            printf("\n----------------------------------------------------------------------");
                            for(i=1;i<=invoice[index].num_prod;i++)
                            {
                                printf("\n%s",invoice[index].invo_product[i].name_product);
                                printf("\t\t%s",invoice[index].invo_product[i].units_product);
                                printf("\t\t%s",invoice[index].invo_product[i].price_product);
                                printf("\t\t%s",invoice[index].invo_product[i].total_product);
                            }
                            printf("\n----------------------------------------------------------------------");
                            printf("\n\t\t\t\t\t\tBASE:\t\t%s",invoice[index].i_precio_base);
                            printf("\n----------------------------------------------------------------------");
                            printf("\n\t\t\t\t\t\tIVA(18):\t%s",invoice[index].i_precio_iva);
                            printf("\n----------------------------------------------------------------------");
                            printf("\n\t\t\t\t\t\tTOTAL:\t\t%s",invoice[index].i_precio_total);
                            printf("\n----------------------------------------------------------------------");       // FIN Write Invoice
                            break;
                        }
                        index++;
                    }
                    if(flag==0)
                    {
                        printf("\n---- No existe la Factura ----\n");
                    }
                    break;
        case 'b':
                    do
                    {
                        pintarClientes_dni_cif(idioma);
                        gets(garbage);
                        valido=validarClientes_general_dni_cif(garbage,idioma);
                    }
                    while(!valido);
                    index=1;
                    flag=0;
                    while(index<=i_counter)
                    {

                        if(strcmp(garbage,invoice[index].dni_cif_client)==0)
                        {
                            if(flag==0)
                            {
                                flag=1;
                                system("cls");
                                printf("----------------------------------------------------------------------");
                                printf("\nFACTURA %s | %s",invoice[index].id_invoice,invoice[index].reg_date);
                                printf("\n----------------------------------------------------------------------");
                                printf("\n%s\n%s\n%s",invoice[index].i_name_company,invoice[index].i_cif_company,invoice[index].i_dir_company);
                                printf("\n----------------------------------------------------------------------");
                                printf("\nCLIENTE:\n%s | %s\n%s",invoice[index].dni_cif_client,invoice[index].name_rs_client,invoice[index].dir_client);
                                printf("\n----------------------------------------------------------------------");
                                printf("\nDESCRIPCION\t\t\tUNIDADES\tPRECIO/U\tTOTAL");
                                printf("\n----------------------------------------------------------------------");
                                for(i=1;i<=invoice[index].num_prod;i++)
                                {
                                    printf("\n%s",invoice[index].invo_product[i].name_product);
                                    printf("\t\t%s",invoice[index].invo_product[i].units_product);
                                    printf("\t\t%s",invoice[index].invo_product[i].price_product);
                                    printf("\t\t%s",invoice[index].invo_product[i].total_product);
                                }
                                printf("\n----------------------------------------------------------------------");
                                printf("\n\t\t\t\t\t\tBASE:\t\t%s",invoice[index].i_precio_base);
                                printf("\n----------------------------------------------------------------------");
                                printf("\n\t\t\t\t\t\tIVA(18):\t%s",invoice[index].i_precio_iva);
                                printf("\n----------------------------------------------------------------------");
                                printf("\n\t\t\t\t\t\tTOTAL:\t\t%s",invoice[index].i_precio_total);
                                printf("\n----------------------------------------------------------------------");       // FIN Write Invoice
                                break;
                            }
                            else
                            {
                                printf("\n---- No existe la Factura ----\n");
                            }
                        }
                        index++;
                    }
                    if(flag==0)
                    {
                        printf("\n---- No Existe la Factura ----\n");
                    }
                    break;
    }
    continuar(valido,idioma);
}
void FacturasImprimir(int valido,int idioma)
{
    char garbage[30],formato[30];
    int index,flag,i;
    FILE *file;
    do
    {
        pintarFacturasImprimir(idioma);
        gets(garbage);
        valido = validarFacturasBuscar_id_factura(garbage,valido,idioma);        // Use validate SearchBill
    }
    while(!valido);

    index=1;
    flag=0;
    while(index<=i_counter && flag==0)
    {
        if(strcmp(garbage,invoice[index].id_invoice)==0)            // Write Invoice
        {
            system("cls");
            printf("----------------------------------------------------------------------");
            printf("\nFACTURA %s | %s",invoice[index].id_invoice,invoice[index].reg_date);
            printf("\n----------------------------------------------------------------------");
            printf("\n%s\n%s\n%s",invoice[index].i_name_company,invoice[index].i_cif_company,invoice[index].i_dir_company);
            printf("\n----------------------------------------------------------------------");
            printf("\nCLIENTE:\n%s | %s\n%s",invoice[index].dni_cif_client,invoice[index].name_rs_client,invoice[index].dir_client);
            printf("\n----------------------------------------------------------------------");
            printf("\nDESCRIPCION\t\t\tUNIDADES\tPRECIO/U\tTOTAL");
            printf("\n----------------------------------------------------------------------");
            for(i=1;i<=invoice[index].num_prod;i++)
            {
                printf("\n%s",invoice[index].invo_product[i].name_product);
                printf("\t\t%s",invoice[index].invo_product[i].units_product);
                printf("\t\t%s",invoice[index].invo_product[i].price_product);
                printf("\t\t%s",invoice[index].invo_product[i].total_product);
            }
            printf("\n----------------------------------------------------------------------");
            printf("\n\t\t\t\t\t\tBASE:\t\t%s",invoice[index].i_precio_base);
            printf("\n----------------------------------------------------------------------");
            printf("\n\t\t\t\t\t\tIVA(18):\t%s",invoice[index].i_precio_iva);
            printf("\n----------------------------------------------------------------------");
            printf("\n\t\t\t\t\t\tTOTAL:\t\t%s",invoice[index].i_precio_total);
            printf("\n----------------------------------------------------------------------");       // FIN Write Invoice
            flag=1;
        }
        if(flag==0)
        {
            index++;
        }
    }
    if(flag!=0)
    {
        switch(ContinuarSIoNO(valido,idioma))
        {
            case 1:
                        strcpy(formato,".txt");
                        strcpy(invoice[index].temp,invoice[index].id_invoice);    // ID Invoice Copy to temp
                        strcat(invoice[index].temp,formato);     // Strcat Format .txt whit ID Invoice
                        file = fopen(invoice[index].temp,"w");
                        fputs("----------------------------------------------------------------------",file);
                        fputs("\nFACTURA ",file);
                        fputs(invoice[index].id_invoice,file);
                        fputs(" | ",file);
                        fputs(invoice[index].reg_date,file);
                        fputs("\n----------------------------------------------------------------------",file);
                        fputs("\n",file);
                        fputs(invoice[index].i_name_company,file);
                        fputs("\n",file);
                        fputs(invoice[index].i_cif_company,file);
                        fputs("\n",file);
                        fputs(invoice[index].i_dir_company,file);
                        fputs("\n----------------------------------------------------------------------",file);
                        fputs("\nCLIENTE:\n",file);
                        fputs(invoice[index].dni_cif_client,file);
                        fputs(" | ",file);
                        fputs(invoice[index].name_rs_client,file);
                        fputs("\n",file);
                        fputs(invoice[index].dir_client,file);
                        fputs("\n----------------------------------------------------------------------",file);
                        fputs("\nDESCRIPCION\t\t\tUNIDADES\tPRECIO/U\tTOTAL",file);
                        fputs("\n----------------------------------------------------------------------",file);
                        for(i=1;i<=invoice[index].num_prod;i++)
                        {
                            fputs("\n",file);
                            fputs(invoice[index].invo_product[i].name_product,file);
                            fputs("\t\t",file);
                            fputs(invoice[index].invo_product[i].units_product,file);
                            fputs("\t\t",file);
                            fputs(invoice[index].invo_product[i].price_product,file);
                            fputs("\t\t",file);
                            fputs(invoice[index].invo_product[i].total_product,file);
                        }
                        fputs("\n----------------------------------------------------------------------",file);
                        fputs("\n\t\t\t\t\t\tBASE:\t\t",file);
                        fputs(invoice[index].i_precio_base,file);
                        fputs("\n----------------------------------------------------------------------",file);
                        fputs("\n\t\t\t\t\t\tIVA(18):\t",file);
                        fputs(invoice[index].i_precio_iva,file);
                        fputs("\n----------------------------------------------------------------------",file);
                        fputs("\n\t\t\t\t\t\tTOTAL:\t\t",file);
                        fputs(invoice[index].i_precio_total,file);
                        fputs("\n----------------------------------------------------------------------",file); // END Write Invoice
                        if(fclose(file)!=0)
                        {
                            pintarArchivoNoCerrado(idioma);
                        }
                        break;
            default: break;
        }
    }
    else
    {
        printf("\n---- No existe la factura ----\n");
    }
    continuar(valido,idioma);
}

void EscribirFicheroFacturas(struct Invoices invoice[],int valido,int idioma)
{
    FILE *file;
    int index,i;
    char garbage[30];
    printf("\nEscriba el nombre del fichero FACTURAS: ");
    gets(garbage);
    file = fopen(garbage,"wb");

        fputs(INI_FACTURAS,file);
        fputc(10,file);

        for(index=1;index<=i_counter;index++)
        {
            if(strlen(invoice[index].id_invoice)!=0)
            {
                fputs(INI_FAC,file);
                fputs(" ",file);
                fputs(invoice[index].id_invoice,file);
                fputs(" ",file);
                fputs(invoice[index].i_cif_company,file);
                fputs(" ",file);
                fputc(34,file);
                fputs(invoice[index].i_name_company,file);
                fputc(34,file);
                fputs(" ",file);
                fputc(34,file);
                fputs(invoice[index].i_dir_company,file);
                fputc(34,file);
                fputs(" ",file);
                fputc(34,file);
                fputs(invoice[index].dni_cif_client,file);
                fputc(34,file);
                fputs(" ",file);
                fputc(34,file);
                fputs(invoice[index].name_rs_client,file);
                fputc(34,file);
                fputs(" ",file);
                fputc(34,file);
                fputs(invoice[index].dir_client,file);
                fputc(34,file);
                fputs(" ",file);
                fputc(34,file);
                fputs(invoice[index].reg_date,file);
                fputc(34,file);
                fputs(" ",file);
                fprintf(file,"%.2f",atof(invoice[index].i_precio_base));
                fputs(" ",file);
                fprintf(file,"%.2f",atof(invoice[index].i_precio_iva));
                fputs(" ",file);
                fprintf(file,"%.2f",atof(invoice[index].i_precio_total));
                fputc(10,file);
                for(i=1;i<=invoice[index].num_prod;i++)
                {
                    fputs(PRODUCTO,file);
                    fputs(" ",file);
                    fputc(34,file);
                    fputs(invoice[index].invo_product[i].name_product,file);
                    fputc(34,file);
                    fputs(" ",file);
                    fputs(invoice[index].invo_product[i].units_product,file);
                    fputs(" ",file);
                    fputs(invoice[index].invo_product[i].price_product,file);
                    fputs(" ",file);
                    fprintf(file,"%.2f",atof(invoice[index].invo_product[i].total_product));
                    fputs(" ",file);
                    fputs("FIN",file);
                    fputc(10,file);
                }
                fputs(FIN_FAC,file);
                fputc(10,file);
            }

        }
        fputs(FIN_FACTURAS,file);
        fputc(10,file);

        continuar(valido,idioma);
        if(fclose(file)!=0)
        {
            pintarArchivoNoCerrado(idioma);
            continuar(valido,idioma);
        }
}
