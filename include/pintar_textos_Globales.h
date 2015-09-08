#ifndef PINTAR_TEXTOS_GLOBALES_H
#define PINTAR_TEXTOS_GLOBALES_H


///** FUNCIONES PARA PINTAR POR PANTALLA TODOS LOS MENSAJES DE LA APLICACION **///

void pintarError(int idioma);
void pintarContinuar(int idioma);
void pintarElegirIdioma(int valido,int idioma);
void pintarIdioma(int idioma);            // Muestra en el menu el idioma seleccionado: 1.- Español, 2.- English
void pintarContinuarSIoNO(int idioma);
void paintSaveFile(int idioma);
void pintarArchivoNoAbierto(int idioma);
void pintarArchivoNoCerrado(int idioma);
void pintarArchivoNoExiste(int idioma);
void pintarRegistroCompleto(int idioma);

void pintarMensajeBienvenida(int idioma);
void pintarMensajeDespedida(int idioma);

void pintarMenuPrincipal(int idioma);

void pintarFacturasNoHayStock(int idioma);
#endif // PINTAR_TEXTOS_GLOBALES_H
