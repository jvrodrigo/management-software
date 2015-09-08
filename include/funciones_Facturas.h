#ifndef FUNCIONES_FACTURAS_H
#define FUNCIONES_FACTURAS_H

#define FACTURAS "FACTURAS"
#define INI_FAC "INI_FAC"
#define PRODUCTO "PRODUCTO"
#define FIN_FAC "FIN_FAC"

#define INI_FACTURAS "FACTURAS"
#define FIN_FACTURAS "FIN FACTURAS"

#define NOMBRE_EMPRESA "AGROALIMENTOS.S.A."
#define CIF_EMPRESA "X12345678"
#define DIR_EMPRESA "Poligono Los Olivares, 1, 23000, Jaen"

int i_counter;
int invoice_save;

int id_factura_num;
struct Invoice_products
{
   char name_product[30],units_product[10],price_product[10],total_product[10];
};
struct Invoices
{
    int num_prod;
    struct Invoice_products invo_product[30];
    char id_invoice[10],i_cif_company[10],i_name_company[30],i_dir_company[50],dni_cif_client[12], name_rs_client[30], dir_client[100],fecha[15],reg_date[15],temp[50];
    double precio_base, precio_iva, precio_total;
    char i_precio_base[10],i_precio_iva[10],i_precio_total[10];
}invoice[100];        // 100 Invoices MAX
void LeerFicheroFacturas(char *argv,struct Invoices invoice[],int valido,int idioma);        // Read Invoice Files
void FacturasCrear(int valido,int idioma);
void FacturasBorrar(int valido,int idioma);
void FacturasBuscar(struct Invoices invoice[],int valido,int idioma);
void FacturasImprimir(int valido,int idioma);

void EscribirFicheroFacturas(struct Invoices invoice[],int valido,int idioma);
#endif // FUNCIONES_FACTURAS_H
