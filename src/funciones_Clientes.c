#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"..\include\funciones_Globales.h"
#include"..\include\funciones_Clientes.h"
#include"..\include\funciones_Facturas.h"
#include"..\include\validar_Clientes.h"
#include"..\include\validar_Facturas.h"
#include"..\include\pintar_textos_Globales.h"
#include"..\include\pintar_textos_Clientes.h"
#include"..\include\pintar_textos_Facturas.h"

void LeerFicheroClientes(char *argv,struct Clients client[],int valido,int idioma)
{
    FILE *file;
    int column,index,pos,quotes,flag,flag_OK,end_file;
    char garbage[31];
    char buffer[1];
    file=fopen(argv,"r");
    printf("\n\n(CLIENTES) Comprobando fichero: %s",argv);
    fseek(file,0,SEEK_END);
    memset(garbage,'\0',strlen(garbage));
    if(ftell(file)!=0)
    {
        fseek(file,0,SEEK_SET);
        if(strcmp(fgets(garbage,9,file),INI_CLIENTES)==0)
        {
            memset(garbage,'\0',strlen(garbage));
            fseek(file,-13,SEEK_END);
            if(strcmp(fgets(garbage,13,file),FIN_CLIENTES)==0)
            {
                printf("\n(CLIENTES) El fichero coincide con el formato\n");
                flag=1;
            }
            else
            {
                printf("\n(CLIENTES) El fichero no coincide con el formato\n");
                flag=0;
            }

        }
        else
        {
            printf("\n(CLIENTES) El fichero no coincide con el formato\n");
            flag=0;
        }
    }
    else
    {
        printf("\n(CLIENTES) El fichero esta vacio");
        flag=0;
    }
    if(flag==1)
    {
        fseek(file,0,SEEK_END);
        end_file = ftell(file);
        c_counter=1;
        column=0;
        index=0;
        pos=strlen(INI_CLIENTES);
        quotes=0;
        flag_OK=0;
        //printf("\nEl archivo coincide en el formato, pos:%d end_file:%d",pos,end_file);
        while(pos<=end_file-strlen(FIN_CLIENTES) && flag==1)      // Run file
        {
            fseek(file,pos,SEEK_SET);      // position file
            fread(buffer,1,1,file);     // Read
            //printf("\nLeo: %c",buffer[0]);
            if(column==2)
            {
                if(buffer[0]=='"' && quotes%2==1 && column==2)
                {
                    if(validarClientes_direccion(client[c_counter].t_direccion,idioma)==1)
                    {
                        index=0;
                        column=-1;
                    }
                    else
                    {
                        printf("\n(CLIENTES) La direccion no mantiene el formato");
                        flag=0;
                    }

                }
                if(buffer[0]=='"' && quotes%2==0 && column==2)
                {
                    //printf("---1er Comillas---- Colum2");
                    index = 0;
                    quotes++;
                }
                if(buffer[0]!='"' && quotes%2==1 && column==2 )
                {
                    client[c_counter].t_direccion[index]=buffer[0];
                    //printf("\nCliente: %s",client[c_counter].t_direccion);
                    index++;
                }
            }
            if(column==1)
            {
                if(buffer[0]=='"' && quotes%2==1 && column==1)
                {
                    if(validarClientes_nombre_rs(client[c_counter].t_nombre_rs,idioma)==1)
                    {
                        column++;
                        quotes=0;
                        index=0;
                    }
                    else
                    {
                        printf("\n(CLIENTES) El nombre no mantiene el formato");
                        flag=0;
                    }
                }
                if(buffer[0]=='"' && quotes%2==0 && column==1)
                {
                    index = 0;
                    quotes++;
                }
                if(buffer[0]!='"' && quotes%2==1 && column==1)
                {
                    client[c_counter].t_nombre_rs[index]=buffer[0];
                    index++;
                }
                //printf("\n%s: Formato valido NOMBRE CLIENTE",client[c_counter].t_nombre_rs);
            }
            if(column==0)
            {
                if(index==9)
                {
                    if(validarClientes_registro_dni_cif(client,client[c_counter].t_dni_cif,c_counter,idioma)==1)
                    {
                        strcpy(client[c_counter].dni_cif,client[c_counter].t_dni_cif);
                        //printf("\n%s: Formato valido DNI CLIENTE",client[c_counter].t_dni_cif);
                        column++;
                        index=0;
                        quotes=0;
                    }
                    else
                    {
                        flag=0;
                        printf("\n(CLIENTES) El DNI o CIF no mantiene el formato");
                    }
                }
                if(buffer[0]!=' ' && buffer[0]!=10 && column==0)
                {
                    client[c_counter].t_dni_cif[index]=buffer[0];
                    index++;
                }

            }
            if(buffer[0]==10 && column==-1)
            {
                memset(garbage,'\0',strlen(garbage));
                if(strcmp(FIN_CLIENTES,fgets(garbage,13,file))!=0)
                {
                    //printf("\n-------Con: %s",garbage);
                    column=0;
                    index=0;
                    c_counter++;

                }
                else
                {
                    flag_OK=1; // Stop
                }
            }
            if(index>50)
            {
                printf("\n(CLIENTES) ALGUN DATO NO MANTIENE EL FORMATO\n");
                pintarError(idioma);
                pos=end_file;       // si el index supera 50 termina el bucle while
                c_counter=0;  // si el formato no coincide limpio el contador general de clientes
            }
            pos++;
        }
    }
    else
    {
        printf("\n(CLIENTES) El fichero no tiene el formato");
        flag=0;     // Stop
        c_counter=0;    // Restart customer counter
    }
    if(flag==0)
    {
        printf("\n(CLIENTES) ALGUN DATO NO MANTIENE EL FORMATO\n");
        c_counter=0;    // Restart customer counter
    }
    if(flag_OK==1 && flag==1)
    {
        for(index=1;index<=c_counter;index++)        // Temp to real var
        {
            strcpy(client[index].dni_cif,client[index].t_dni_cif);
            strcpy(client[index].nombre_rs,client[index].t_nombre_rs);
            strcpy(client[index].direccion,client[index].t_direccion);
        }
    }
    else
    {
        printf("\n(CLIENTES) ALGUN DATO NO MANTIENE EL FORMATO\n");
        c_counter=0;    // Restart customer counter
    }
    if(fclose(file)!=0)
    {
        pintarArchivoNoCerrado(idioma);
    }
}

void EscribirFicheroClientes(struct Clients client[],int valido,int idioma)
{
    char garbage[30];
    FILE *file;
    int index;
    printf("\nCLIENTES FICHERO, guardar como: ");
    gets(garbage);
    file = fopen(garbage,"wb");

        fprintf(file,"%s%c",INI_CLIENTES,10);

        for(index=1;index<=c_counter;index++)
        {
            fprintf(file,"%s %c%s%c %c%s%c%c",client[index].dni_cif,34,client[index].nombre_rs,34,34,client[index].direccion,34,10);
        }
            fprintf(file,"%s%c",FIN_CLIENTES,10);
        fclose(file);
}

void ClientesCrear(struct Clients client[],int valido,int idioma)           // opcion 2.1
{

    if(!(c_counter>=0 && c_counter<=30))
    {
        pintarRegistroCompleto(idioma);
        continuar(valido,idioma);
    }
    else
    {
        pintarClientesCrear(idioma);
        switch(ContinuarSIoNO(valido,idioma))
        {
            case 1:
                    do                                      // Clientes Crear ID Producto
                    {
                        pintarClientes_dni_cif(idioma);
                        gets(client[0].t_dni_cif);     // temp client[0].t_dni_cif
                        valido = validarClientes_registro_dni_cif(client,client[0].t_dni_cif,c_counter,idioma); // comprueba que no repite el DNI
                    }
                    while(!valido);

                    do                                      // Clientes Crear Nombre del Producto
                    {
                        pintarClientes_nombre_rs(idioma);
                        gets(client[0].t_nombre_rs);   // temp client[0].t_nombre_rs
                        valido = validarClientes_nombre_rs(client[0].t_nombre_rs,idioma);
                    }
                    while(!valido);
                    do                                      // Clientes Crear Precio de Compra
                    {
                        pintarClientes_direccion(idioma);
                        gets(client[0].t_direccion);       // temp client[0].t_direccion
                        valido = validarClientes_direccion(client[0].t_direccion,idioma);
                    }
                    while(!valido);

                    pintarClientes_dni_cif(idioma);      // muestra en pantalla los datos del Cliente a guardar
                    printf("%s",client[0].t_dni_cif);
                    pintarClientes_nombre_rs(idioma);
                    printf("%c",34);
                    printf("%s",client[0].t_nombre_rs);
                    printf("%c",34);
                    pintarClientes_direccion(idioma);
                    printf("%s",client[0].t_direccion);
                    printf("\n");

                    c_counter++;        // Al crear un nuevo client sumo 1 al contador general de clientes
                    strcpy(client[c_counter].dni_cif,client[0].t_dni_cif);              // copia al cliente siguiente el DNI o CIF
                    strcpy(client[c_counter].nombre_rs,client[0].t_nombre_rs);          // copia al cliente siguiente el Nombre o RS
                    strcpy(client[c_counter].direccion,client[0].t_direccion);          // copia al cliente siguiente la Direccion
                    customer_save = 1;                    // flag customer to save at the end of the application
                    continuar(valido,idioma);

            default:break;
        }
    }
}
void ClientesEditar(struct Clients client[],int valido,int idioma)
{
    int pos;
    char opcion[10];
    if(c_counter==0)
    {
        pintarClientesNoExiste_2(idioma);
        continuar(valido,idioma);
    }
    else
    {
        pintarClientesEditar(idioma);
        do
        {
            pintarClientes_dni_cif(idioma);
            gets(client[0].t_dni_cif);
            valido = validarClientes_general_dni_cif(client[0].t_dni_cif,idioma);
        }
        while(!valido);

        pos = BuscadorClientes(client,client[0].t_dni_cif,'a',idioma);
        if(pos!=0)
        {
            switch(ContinuarSIoNO(valido,idioma))
            {
                case 1:     do
                            {
                                system("cls");
                                pintarMenuClientes(idioma);
                                printf("\n\n");
                                printf("| %s | %s | %s |",client[pos].dni_cif,client[pos].nombre_rs,client[pos].direccion);
                                pintarClientesEditar_OK_1(idioma);
                                gets(opcion);
                                valido = validarClientesEditar(opcion,idioma);
                                if(!valido)
                                {
                                    continuar(valido,idioma);
                                }
                            }
                            while(!valido);

                            switch(tolower(opcion[0]))
                            {
                                case 'a':
                                            do
                                            {
                                                pintarClientes_dni_cif(idioma);
                                                gets(client[0].t_dni_cif);       // temp client[0].t_dni_cif
                                                valido = validarClientes_registro_dni_cif(client,client[0].t_dni_cif,c_counter,idioma);
                                            }
                                            while(!valido);
                                            printf("\n| %s | %s | %s |\n",client[0].t_dni_cif,client[pos].nombre_rs,client[pos].direccion);

                                            if(ContinuarSIoNO(valido,idioma)==1)    // if continue save
                                            {
                                                strcpy(client[pos].dni_cif,client[0].t_dni_cif);
                                                pintarClientesEditar_OK_2(idioma);
                                                strcpy(client[0].t_dni_cif,"");      // clear temp client[0].t_dni_cif
                                                customer_save = 1;                    // flag customer to save at the end of the application
                                                continuar(valido,idioma);
                                                break;
                                            }
                                            else        // else not save and not flag to save at the end of the application
                                            {
                                                pintarClientesEditar_NOT(idioma);
                                                continuar(valido,idioma);
                                                break;
                                            }
                                case 'b':
                                            do
                                            {
                                                pintarClientes_nombre_rs(idioma);
                                                gets(client[0].t_nombre_rs);
                                                valido = validarClientes_direccion(client[0].t_nombre_rs,idioma);
                                            }
                                            while(!valido);
                                            printf("\n| %s | %s | %s |\n",client[pos].dni_cif,client[0].t_nombre_rs,client[pos].direccion);

                                            if(ContinuarSIoNO(valido,idioma)==1)
                                            {
                                                strcpy(client[pos].nombre_rs,client[0].t_nombre_rs);
                                                pintarClientesEditar_OK_2(idioma);
                                                strcpy(client[0].t_nombre_rs,"");    // clear temp client[0].t_name_rs
                                                customer_save = 1;                    // flag customer to save at the end of the application
                                                continuar(valido,idioma);
                                                break;
                                            }
                                            else
                                            {
                                                pintarClientesEditar_NOT(idioma);
                                                continuar(valido,idioma);
                                                break;
                                            }
                                case 'c':
                                            do
                                            {
                                                pintarClientes_direccion(idioma);
                                                gets(client[0].t_direccion);
                                                valido = validarClientes_direccion(client[0].t_direccion,idioma);
                                            }
                                            while(!valido);
                                            printf("\n| %s | %s | %s |\n",client[pos].dni_cif,client[pos].nombre_rs,client[0].t_direccion);
                                            if(ContinuarSIoNO(valido,idioma)==1)
                                            {
                                                strcpy(client[pos].direccion,client[0].t_direccion);
                                                pintarClientesEditar_OK_2(idioma);
                                                strcpy(client[0].t_direccion,"");      // clear temp client[0].t_direccion
                                                customer_save = 1;                    // flag customer to save at the end of the application
                                                continuar(valido,idioma);
                                                break;
                                            }
                                            else
                                            {
                                                pintarClientesEditar_NOT(idioma);
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

void ClientesBorrar(struct Clients client[],int valido,int idioma)          // opcion 2.3
{
    int pos;
    if(c_counter==0)
    {
        pintarClientesNoExiste_2(idioma);
        continuar(valido,idioma);
    }
    else
    {
        pintarClientesBorrar(idioma);
        do
        {
            pintarClientes_dni_cif(idioma);
            gets(client[0].t_dni_cif);
            valido = validarClientes_general_dni_cif(client[0].t_dni_cif,idioma);
        }
        while(!valido);
        pos = BuscadorClientes(client,client[0].t_dni_cif,'a',idioma);
        if(pos==0)
        {
            continuar(valido,idioma);
        }
        else
        {
            switch(ContinuarSIoNO(valido,idioma))
            {
            case 1:     // deletes the last client to client to remove //
                        strcpy(client[pos].dni_cif,client[c_counter].dni_cif);
                        strcpy(client[pos].nombre_rs,client[c_counter].nombre_rs);
                        strcpy(client[pos].direccion,client[c_counter].direccion);
                        customer_save = 1;                    // flag customer to save at the end of the application
                        pintarClientesBorrar_OK(idioma);
                        // copy the empty string at the last product //
                        strcpy(client[c_counter].dni_cif,"");
                        strcpy(client[c_counter].nombre_rs,"");
                        strcpy(client[c_counter].direccion,"");
                        c_counter--;
                        continuar(valido,idioma);
                        break;

            default:    pintarClienteNoBorrado(idioma);
                        continuar(valido,idioma);
                        break;
            }
        }
    }
}

int BuscadorClientes(struct Clients client[],char *entrada,int nif_o_nombre_rs,int idioma)
{
    int index,i,j,k;
    int flag;
    int stop;
    int encontrado;

    if(nif_o_nombre_rs=='a')        // Search client the dni_cif or cif
    {
        stop=0;
        index=0;
        encontrado=0;
        while(stop==0 && encontrado==0)
        {
            index++;
            if(strncmp(client[index].dni_cif,entrada,9)==0 && index<=c_counter)
            {
                printf("\n| %s | %s | %s |\n",client[index].dni_cif,client[index].nombre_rs,client[index].direccion);
                encontrado=1;
            }
            if(index>c_counter && encontrado==0)
            {
                pintarClientesNoExiste_1(idioma);
                stop=1;
            }
        }
        if(encontrado==0)
        {
            index=0;
        }
        return index;
    }
    else if(nif_o_nombre_rs=='b')   // Search by client name
    {
        stop=0;
        encontrado=0;
        flag=0;
        i=0;
        index=1;
        while(index<=c_counter)
        {
            while(i<=strlen(client[index].nombre_rs) && encontrado==0)
            {
                if(tolower(client[index].nombre_rs[i]) == tolower(entrada[0]))
                {
                    j=i;
                    k=0;
                    while(tolower(client[index].nombre_rs[j]) == tolower(entrada[k]) && strlen(entrada)>k)
                    {
                        k++;
                        j++;
                    }
                    if(k==strlen(entrada))
                    {
                        printf("\n| %s || %s || %s |\n",client[index].nombre_rs,client[index].dni_cif,client[index].direccion);
                        encontrado=1;
                        flag=1;
                    }
                    i++;
                }
                else
                {
                    i++;
                }
            }
            index++;
            i=0;
            encontrado=0;
        }
        if(flag==0)
        {
            pintarClientesNoExiste_1(idioma);
        }
    }
    return 0;
}
void ClientesBuscar(struct Clients client[],int valido,int idioma)          // opcion 2.4
{
    char garbage[30];
    if(c_counter==0)          // if clients counter==0 there are not clients
    {
        pintarClientesNoExiste_2(idioma);
        continuar(valido,idioma);
    }
    else
    {
        do
        {
            system("cls");
            pintarMenuClientes(idioma);
            pintarClientesBuscar(idioma);
            gets(garbage);
            valido = validarClientesBuscar(garbage,idioma);      // valido la entrada a buscar
            if(!valido)
            {
                continuar(valido,idioma);
            }
        }
        while(!valido);

        switch(tolower(garbage[0]))
        {
            case 'a':    do                 // Clientes Buscar por DNI o CIF
                        {
                            pintarClientes_dni_cif(idioma);
                            gets(garbage);
                            valido=validarClientes_general_dni_cif(garbage,idioma);
                        }
                        while(!valido);
                        BuscadorClientes(client,garbage,'a',idioma);
                        continuar(valido,idioma);
                        break;

            case 'b':   do                  // Clientes Buscar por NOMBRE_RS
                        {
                            pintarClientes_nombre_rs(idioma);
                            gets(garbage);
                            valido=validarClientes_nombre_rs(garbage,idioma);
                        }
                        while(!valido);
                        BuscadorClientes(client,garbage,'b',idioma);
                        continuar(valido,idioma);
                        break;

            default:    break;
        }
    }
}
void ClientesListado(struct Clients client[],int valido,int idioma)         // opcion 2.5
{

    int i,j;
    char temp[100];

    i=1;
    if(c_counter==0)
    {
        pintarClientesNoExiste_2(idioma);
        continuar(valido,idioma);
    }
    else
    {
        pintarClientesListado(idioma);
        for(i=1;i<=c_counter;i++)
        {
            strcpy(client[i].t_dni_cif,client[i].dni_cif);
            strcpy(client[i].t_nombre_rs,client[i].nombre_rs);
            strcpy(client[i].t_direccion,client[i].direccion);
        }
        i=0;
        for (i=1;i<=c_counter;i++)
        {
            for(j=1; j<=c_counter-1; j++)
            {
                if(strncmp(client[j].t_nombre_rs,client[j+1].t_nombre_rs,10)==1)
                {
                    strcpy(temp,client[j].t_nombre_rs);
                    strcpy(client[j].t_nombre_rs,client[j+1].t_nombre_rs);
                    strcpy(client[j+1].t_nombre_rs,temp);
                    strcpy(temp,client[j].t_dni_cif);
                    strcpy(client[j].t_dni_cif,client[j+1].t_dni_cif);
                    strcpy(client[j+1].t_dni_cif,temp);
                    strcpy(temp,client[j].t_direccion);
                    strcpy(client[j].t_direccion,client[j+1].t_direccion);
                    strcpy(client[j+1].t_direccion,temp);
                }
            }
        }
        for(i=1;i<=c_counter;i++)
        {
            printf("\n%d.-| %s || %s || %s |\n",i,client[i].t_nombre_rs,client[i].t_dni_cif,client[i].t_direccion);
            if(i%10==0)
            {
                printf("----------- || ----------- || -----------");
                continuar(valido,idioma);
            }
        }
        continuar(valido,idioma);
    }
}


