#ifndef VALIDAR_GLOBALES_H
#define VALIDAR_GLOBALES_H


///** VALIDACIONES DE LAS ENTRADAS DEL USUARIO POR TECLADO **///
// VALIDACIONES DE LAS ENTRADAS DEL USUARIO POR TECLADO MENU PRINCIPAL//

int validarMenuPrincipal(char *entrada,int valido, int idioma);
int validarContinuar(char *entrada,int idioma);    // Muestra por pantalla "Pulse <ENTER> para continuar"
int validarElegirIdioma(char *entrada,int valido,int idioma);     // Se elije entre dos valores 1.- Español, 2.- Ingles
int validarError(char *entrada,int valido, int idioma);
int validarContinuarSIoNO(char *entrada,int valido, int idioma);

#endif // VALIDAR_GLOBALES_H
