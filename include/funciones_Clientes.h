#ifndef FUNCIONES_CLIENTES_H
#define FUNCIONES_CLIENTES_H
#define INI_CLIENTES "CLIENTES"
#define FIN_CLIENTES "FIN CLIENTES"

int customer_save;
int c_counter;
struct Clients
{
    char dni_cif[30], direccion[100],nombre_rs[100];
    char t_dni_cif[30],t_direccion[100],t_nombre_rs[100];

}client[31];

int BuscadorClientes(struct Clients client[],char *entrada,int nif_o_nombre_rs,int idioma);      // devuelve la posicion de la fila del client

void LeerFicheroClientes(char *argv,struct Clients client[],int valido,int idioma);       // devuelve las filas del fichero
void ClientesCrear(struct Clients client[],int valido,int idioma);           // opcion 2.1
void ClientesEditar(struct Clients client[],int valido,int idioma);          // opcion 2.2
void ClientesBorrar(struct Clients client[],int valido,int idioma);          // opcion 2.3
void ClientesBuscar(struct Clients client[],int valido,int idioma);          // opcion 2.4
void ClientesListado(struct Clients client[],int valido,int idioma);         // opcion 2.5

void EscribirFicheroClientes(struct Clients client[],int valido,int idioma);
#endif // FUNCIONES_CLIENTES_H
