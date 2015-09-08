#ifndef VALIDAR_CLIENTES_H
#define VALIDAR_CLIENTES_H

// VALIDACIONES DE LAS ENTRADAS DEL USUARIO POR TECLADO MENU CLIENTES//

int validarMenuClientes(char *entrada);

int validarClientes_registro_dni_cif(struct Clients registro_dni_cif[],char *teclado_dni_cif,int posicion,int idioma);
int validarClientes_general_dni_cif(char *entrada,int idioma);
int validarClientes_nombre_rs(char *entrada,int idioma);
int validarClientes_direccion(char *entrada,int idioma);

int validarClientes_fichero_nombre_rs(char *entrada,int i);
int validarClientes_fichero_dni_cif(char *entrada);
int validarClientes_fichero_direccion(char *entrada,int i);

int validarClientesCrear(char *entrada,int idioma);
int validarClientesEditar(char *entrada,int idioma);
int validarClientesBorrar(char *entrada,int idioma);
int validarClientesBuscar(char *entrada,int idioma);
int validarClientesListado(char *entrada,int idioma);

#endif // VALIDAR_CLIENTES_H
