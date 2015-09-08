#ifndef VALIDAR_FACTURAS_H
#define VALIDAR_FACTURAS_H


// VALIDACIONES DE LAS ENTRADAS DEL USUARIO POR TECLADO MENU FACTURAS//

int validarMenuFacturas(char *entrada,int valido, int idioma);

int validarFacturasBuscar(char *entrada,int valido,int idioma);
int validarFacturasBuscar_id_factura(char *entrada,int valido,int idioma);





int validarFacturas_id_factura(char *entrada,int valido,int idioma);
int validarFacturas_nombre_empresa(char *entrada,int valido,int idioma);

int validarFacturasCrear(char *entrada,int valido,int idioma);
int validarFacturasBorrar(char *entrada,int valido,int idioma);
int validarFacturasImprimir(char *entrada,int valido,int idioma);



#endif // VALIDAR_FACTURAS_H
