#ifndef ARTICULOS_H_
#define ARTICULOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "FunGeneral.h"


typedef struct
{
	int id;
	char articulo[50];
	char medida[50];
	float precio;
	int rubroId;
}eArticulo;


eArticulo* articulos_new();
eArticulo* articulo_newParametros(char* idStr,char* articuloStr,char* medidaStr,char* precioStr,char* rubroIdStr);
void articulo_delete(eArticulo* this);
int articulo_setId(eArticulo* this,int id);
int articulo_getId(eArticulo* this,int* id);
int articulo_setArticulo(eArticulo* this,char* articulo);
int articulo_getArticulo(eArticulo* this,char* articulo);
int articulo_setMedida(eArticulo* this,char* medida);
int articulo_getMedida(eArticulo* this,char* medida);
int articulo_setPrecio(eArticulo* this,float precio);
int articulo_getPrecio(eArticulo* this,float* precio);
int articulo_setRubroId(eArticulo* this,int rubroId);
int articulo_getRubroId(eArticulo* this,int* rubroId);










#endif /* ARTICULOS_H_ */
