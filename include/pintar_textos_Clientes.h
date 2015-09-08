#ifndef PINTAR_TEXTOS_CLIENTES_H
#define PINTAR_TEXTOS_CLIENTES_H


void pintarMenuClientes(int idioma);
void pintarValidarMenuClientes(int idioma);

void pintarClientes_dni_cif(int idioma);
void pintarClientes_nombre_rs(int idioma);     // opcion 2.1, 2.3
void pintarClientes_direccion(int idioma);

void pintarValidarClientes_dni_cif(int idioma);  // opcion 2.1
void pintarValidarClientes_nombre_rs(int idioma);
void pintarValidarClientes_direccion(int idioma);
void pintarValidarClientes_registro_dni_cif(int idioma);

void pintarClientesCrear(int idioma);                // opcion 2.1

void pintarClientesEditar(int idioma);               // opcion 2.2
void pintarValidarClientesEditar(int idioma);
void pintarClientesEditar_OK_1(int idioma);
void pintarClientesEditar_OK_2(int idioma);
void pintarClientesEditar_NOT(int idioma);

void pintarClientesBorrar(int idioma);             // opcion 2.3
void pintarClientesBorrar_OK(int idioma);
void pintarClienteNoBorrado(int idioma);

void pintarClientesBuscar(int idioma);               // opcion 1.4
void pintarValidarClientesBuscar(int idioma);


void pintarClientesListado(int idioma);              // opcion 1.5

void pintarClientesNoExiste_1(int idioma);
void pintarClientesNoExiste_2(int idioma);
#endif // PINTAR_TEXTOS_CLIENTES_H
