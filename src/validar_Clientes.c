#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include"..\include\funciones_Clientes.h"

#include"..\include\validar_Globales.h"
#include"..\include\validar_Clientes.h"

#include"..\include\pintar_textos_Globales.h"
#include"..\include\pintar_textos_Clientes.h"

// VALIDACIONES DE LAS ENTRADAS DEL USUARIO POR TECLADO MENU CLIENTES//

int validarMenuClientes(char *new_data)
{
    if(((new_data[0]>='1' && new_data[0]<='5') || (new_data[0]=='8' || new_data[0]=='0')) && strlen(new_data)==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validarClientes_registro_dni_cif(struct Clients registro_dni_cif[],char *new_data,int pos,int idioma)
{
    int i;
    i=0;
    //  primero comprueba que el formato del DNI o CIF introducido es correcto
    if(strlen(new_data)==9 && new_data[0]>='A' && new_data[0]<='Z')
    {
        i=1;
        while(new_data[i]>='0' && new_data[i]<='9')
        {
            i++;
        }
    }
    else if(strlen(new_data)==9 && new_data[8]>='A' && new_data[8]<='Z')
    {
        i=0;
        while(new_data[i]>='0' && new_data[i]<='9')
        {
            i++;
        }
        i++;
    }
    if(i==9)
    {
        for(i=1;i<=pos;i++)
        {
            //printf("\nComparacion: %d --- %s ---- ||| ---- %s ",strcmp(registro_dni_cif[i].dni_cif,new_data),registro_dni_cif[i].dni_cif,new_data);
            if(strcmp(registro_dni_cif[i].dni_cif,new_data)==0)        // segundo comprueba el DNI o CIF introducido con todos los DNI del registro
            {
                pintarValidarClientes_registro_dni_cif(idioma);
                return 0;
            }
        }
        return 1;
    }
    else
    {
        pintarValidarClientes_dni_cif(idioma);
        return 0;
    }
}
int validarClientes_general_dni_cif(char *new_data,int idioma)
{
    int i;
    if(new_data[0]>='A' && new_data[0]<='Z' && strlen(new_data)==9)
    {
        i=1;
        while(new_data[i]>='0' && new_data[i]<='9')
        {

            i++;
        }
    }
    else if(new_data[8]>='A' && new_data[8]<='Z' && strlen(new_data)==9)
    {
        i=0;
        while(new_data[i]>='0' && new_data[i]<='9')
        {

            i++;
        }
        i++;
    }
    if(i==9)
    {
        return 1;
    }
    else
    {
        pintarValidarClientes_dni_cif(idioma);
        return 0;
    }
}
int validarClientes_fichero_nombre_rs(char *new_data,int i)
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
int validarClientes_fichero_dni_cif(char *new_data)
{
    //printf("   ENTRO A VALIDAR, %s",new_data);
    int i;
    if(new_data[0]>='A' && new_data[0]<='Z' && strlen(new_data)==9)
    {
        i=1;
        while(new_data[i]>='0' && new_data[i]<='9')
        {

            i++;
        }
    }
    else if(new_data[8]>='A' && new_data[8]<='Z' && strlen(new_data)==9)
    {
        i=0;
        while(new_data[i]>='0' && new_data[i]<='9')
        {

            i++;
        }
        i++;
    }
    if(i==9 && strlen(new_data)==9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validarClientes_fichero_direccion(char *new_data,int i)
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
int validarClientes_nombre_rs(char *new_data, int idioma)
{
    if(strlen(new_data)>0 && strlen(new_data)<31)
    {
        return 1;
    }
    else
    {
        pintarValidarClientes_nombre_rs(idioma);
        return 0;
    }
}
int validarClientes_direccion(char *new_data,int idioma)
{
    if(strlen(new_data)>0 && strlen(new_data)<50)
    {
        return 1;
    }
    else
    {
        pintarValidarClientes_direccion(idioma);
        return 0;
    }
}

int validarClientesBuscar(char *new_data,int idioma)
{
    if((new_data[0]=='a' || new_data[0]=='A' || new_data[0]=='b' || new_data[0]=='B') && strlen(new_data)==1)
    {
        return 1;
    }
    else
    {
        pintarValidarClientesBuscar(idioma);
        return 0;
    }
}
int validarClientesEditar(char *new_data,int idioma)
{
    if(towlower(new_data[0])=='a' || tolower(new_data[0]=='b') || tolower(new_data[0]=='c'))
    {
        return 1;
    }
    else
    {
        pintarValidarClientesEditar(idioma);
        return 0;
    }
}
int validarClientesBorrar(char *new_data,int idioma);

int validarClientesListado(char *new_data,int idioma);


/*int validarClientes_dni_cif(char *entrada,int valido,int idioma)
{
    //printf("%c",entrada[8]);  // la letra
    int numero;
    numero = (entrada[0]-48)*10000000+(entrada[1]-48)*1000000+(entrada[2]-48)*100000+(entrada[3]-48)*10000+(entrada[4]-48)*1000+(entrada[5]-48)*100+(entrada[6]-48)*10+entrada[7]-48;
    //printf("\nNUMERO: %d, resto: %d, Letra",numero,numero%23);//
    if(cuentaCaracteres(entrada)==9)
    {
        switch(numero%23)
        {
        case 0:     if(entrada[8]=='T')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        return 0;
                        break;
                    }
        case 1:     if(entrada[8]=='R')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 2:     if(entrada[8]=='W')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 3:     if(entrada[8]=='A')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 4:     if(entrada[8]=='G')
                        {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 5:     if(entrada[8]=='M')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 6:     if(entrada[8]=='Y')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 7:     if(entrada[8]=='F')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 8:     if(entrada[8]=='P')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 9:     if(entrada[8]=='D')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 10:    if(entrada[8]=='X')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 11:    if(entrada[8]=='B')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 12:    if(entrada[8]=='N')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 13:    if(entrada[8]=='J')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 14:    if(entrada[8]=='Z')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 15:    if(entrada[8]=='S')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 16:    if(entrada[8]=='Q')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 17:    if(entrada[8]=='V')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 18:    if(entrada[8]=='H')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 19:    if(entrada[8]=='L')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 20:    if(entrada[8]=='C')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 21:    if(entrada[8]=='K')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        case 22:    if(entrada[8]=='E')
                    {
                        numero = 1;
                        break;
                    }
                        else
                    {
                        pintarValidarClientes_DNICIF(idioma);
                        continuar(valido,idioma);
                        numero = 0;
                        break;
                    }
        }
    }
    else
    {
        pintarValidarClientes_DNICIF(idioma);
        numero = 0;
    }
    return numero;
}*/
