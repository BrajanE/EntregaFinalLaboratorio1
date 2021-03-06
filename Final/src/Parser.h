/*
 * Parser.h
 *
 *  Created on: 17 feb. 2022
 *      Author: estra
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "FunGeneral.h"
#include "Articulos.h"
#include "Controller.h"

int parser_articulosFromText(FILE* pFile , LinkedList* ll_listaArticulos);
int parser_Save(LinkedList* this, FILE* path);

#endif /* PARSER_H_ */
