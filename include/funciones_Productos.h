#ifndef FUNCIONES_PRODUCTOS_H
#define FUNCIONES_PRODUCTOS_H
#define INI_PRODUCTOS "PRODUCTOS"
#define FIN_PRODUCTOS "FIN PRODUCTOS"
int TOTAL_STOCK;
int product_save;
int p_counter;
struct Products
{
    char id_producto[30], nombre_producto[30],precio_compra[30],precio_venta[30],stock[30],num_unidades[30];
    char t_id_producto[30],t_nombre_producto[30],t_precio_compra[30],t_precio_venta[30],t_stock[30],t_num_unidades[30];// variables temporales
}product[100];

void LeerFicheroProductos(char *argv,struct Products producto[],int valido,int idioma);
void ProductosCrear(struct Products producto[],int valido,int idioma);                     // opcion 1.1
void ProductosEditar(int valido,int idioma);                    // opcion 1.2
void ProductosBorrar(int valido,int idioma);                    // opcion 1.3
void ProductosBuscar(int valido,int idioma);                    // opcion 1.4
int BuscadorProductos(struct Products producto[],char *contenedor,int id_producto_o_nombre_producto,int idioma);  // returns int position row
void ProductosListado(int valido,int idioma);                   // opcion 1.5
void ProductosListado_max_stock(int valido,int idioma);                    // opcion 1.5.1
void ProductosListado_max_vendido(int valido,int idioma);                  // opcion 1.5.1
void ProductosListado_max_rentabilidad(int valido,int idioma);             // opcion 1.5.1

void EscribirFicheroProductos(struct Products producto[],int valido,int idioma);
int CalculateTotalStock(struct Products producto[]);     // Only used invoice Menu

#endif // FUNCIONES_PRODUCTOS_H
