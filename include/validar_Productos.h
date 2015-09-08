#ifndef VALIDAR_PRODUCTOS_H
#define VALIDAR_PRODUCTOS_H

// VALIDACIONES DE LAS ENTRADAS DEL USUARIO POR TECLADO MENU CLIENTES//

int validarMenuProductos(char *entrada);

int validarProductos_registro_id_producto(struct Products reg_id_product[],char *new_data,int pos,int idioma);     // ID del producto
int validarProductos_nombre_producto(char *entrada); // nombre del producto
int validarProductos_precio_compra(char *entrada);  // limito el precio de compra desde 0 hasta 999.999
int validarProductos_precio_venta(char *entrada);  // limito el precio de venta desde 0 hasta 999.999
int validarProductos_stock(char *entrada); // unidades a Comprar de un producto [1-999]

int validarProductosBuscar(char *entrada);
int validarProductosListado(char *entrada);

int validarProductos_general_id_producto(char *entrada);

int validarProductosEditar(char *option);

int validarProductos_fichero_id_producto(char *entrada);
int validarProductos_fichero_nombre_producto(char *entrada,int i);
int validarProductos_fichero_precios(char *entrada);
int validarProductos_fichero_stock(char *entrada,int i);
int validarProductos_fichero_num_unidades(char *entrada,int i);

int validarProductosFacturas_num_unidades(struct Products product[],char *new_data,int pos,int idioma);       // This funtion is used only in invoice
int validarProductos_num_unidades(char *new_data,int idioma);       // This funtion is used only in invoice

#endif // VALIDAR_PRODUCTOS_H
