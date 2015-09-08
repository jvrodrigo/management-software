#ifndef PINTAR_TEXTOS_PRODUCTOS_H
#define PINTAR_TEXTOS_PRODUCTOS_H

// FUNCIONES PARA MOSTRAR MENSAJES EN LA OPCION 1.-PRODUCTOS //

void pintarMenuProductos(int idioma);

void pintarProductosCrear(int idioma);              // opcion 1.1
void pintarProductosEditar(int idioma);             // opcion 1.2
void pintarProductosBorrar(int idioma);             // opcion 1.3
void pintarProductosBuscar(int idioma);             // opcion 1.4
void pintarProductosListado(int idioma);            // opcion 1.5

void pintarProductos_id_producto(int idioma);
void pintarProductos_nombre_producto(int idioma);
void pintarProductos_precio_compra(int idioma);
void pintarProductos_precio_venta(int idioma);
void pintarProductos_stock(int idioma);
void pintarProductos_num_unidades(int idioma);  // Only invoice
void pintarValidarProductos_num_unidades(int idioma);   // Only invoice

void pintarValidarProductos_registro_id_productos(int idioma);
void pintarValidarProductos_id_producto(int idioma);
void pintarValidarProductos_nombre_producto(int idioma);
void pintarValidarProductos_precio_compra(int idioma);
void pintarValidarProductos_precio_venta(int idioma);
void pintarValidarProductos_stock(int idioma);

void pintarValidarProductosBuscar(int idioma);
void pintarValidarProductosListado(int idioma);

void pintarProductosEditar_OK_1(int idioma);        // option 1.2
void pintarProductosEditar_OK_2(int idioma);        // option 1.2
void pintarProductosEditar_NOT(int idioma);         // option 1.2

void pintarProductosBorrar_OK(int idioma);          // option 1.3
void pintarProductosNoBorrado(int idioma);          // option 1.3

void pintarProductosNoExiste_1(int idioma);         // Search Product
void pintarProductosNoExiste_2(int idioma);         // Search Product

#endif // PINTAR_TEXTOS_PRODUCTOS_H
