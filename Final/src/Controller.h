/*
 * Controller.h
 *
 *  Created on: 17 feb. 2022
 *      Author: estra
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "FunGeneral.h"
#include "Articulos.h"
#include "Parser.h"

int controller_loadFromText(char* path , LinkedList* ll_listaArticulos);
void MostrarUnArticulo(LinkedList* ll_listaArticulos, int index);
int MostrarListaArticulos(LinkedList* ll_listaArticulos);
int controller_Save(char* path, LinkedList* this);
void MostrarConRubro(int id, char articulo[], char medidas[], float precio, int rubroId);


#endif /* CONTROLLER_H_ */
