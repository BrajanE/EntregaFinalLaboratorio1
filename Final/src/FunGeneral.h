#ifndef FUNGENERAL_H_
#define FUNGENERAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "FunGeneral.h"
#include "Articulos.h"
#include "Parser.h"
#include "Controller.h"


void MenuPrincipal(void);
int OrdenarPorArticulo(void* primerDato, void* segundoDato);
void MenuOrden(void);
void* AplicarDescuento(void* pElement);


void MensajeDeCorroboracion(int corroboracion, char mensajeOk[], char mensajeError[]);
int PedirEntero(char mensaje[]);
int PedirEnteroFull(char mensaje[],int maximo);
void CorreccionDeCadenas(char array[]);
int ValidacionDeStrings(char array[]);
void GetString(char mensaje[], char stringIngresado[]);
void PedirArchivo(char mensaje[], char stringIngresado[]);


#endif /* FUNGENERAL_H_ */
