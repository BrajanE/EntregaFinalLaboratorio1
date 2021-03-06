/*
 ============================================================================
 Name        : Final.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "FunGeneral.h"
#include "Articulos.h"
#include "Parser.h"
#include "Controller.h"
int main(void) {
	setbuf(stdout,NULL);

	int opcion;
	int flagCarga=-1;
	int corroboracion;
	char archivo[50];
	LinkedList* ll_listaArticulos=NULL;
	LinkedList* ll_listaConDescuentos=NULL;
	ll_listaArticulos=ll_newLinkedList();
	ll_listaConDescuentos=ll_newLinkedList();

	do{
		MenuPrincipal();
		opcion=PedirEnteroFull("Ingrese opcion: ", 6);
		switch(opcion)
		{
		case 1:
			PedirArchivo("Ingrese nombre de archivo Datos.csv (tiene 3 intentos): ", archivo);
			if(strcmp(archivo,"Datos.csv")==0)
			{
				flagCarga=controller_loadFromText(archivo,ll_listaArticulos);
			}
			break;
		case 2:
			if(flagCarga==1)
			{
				MenuOrden();
				opcion=PedirEnteroFull("Ingrese opcion: ", 2);
				ll_sort(ll_listaArticulos, OrdenarPorArticulo, opcion-1);
			}
			break;
		case 3:
			if(flagCarga==1)
			{
				MostrarListaArticulos(ll_listaArticulos);
			}
			break;
		case 4:
			if(flagCarga==1)
			{
				ll_listaConDescuentos= ll_map (ll_listaArticulos, AplicarDescuento);
			}
			break;
		case 5:
			if(ll_listaConDescuentos!=NULL && flagCarga==1)
			{	//printf("entro");
				corroboracion =controller_Save("Mapeado.csv", ll_listaConDescuentos);
				MensajeDeCorroboracion(corroboracion,"Listado guardado en archivo 'Mapeado.csv'.\n","Error escribir archivo.\n");
				MostrarListaArticulos(ll_listaConDescuentos);
			}
			break;
		}
	}while (opcion<6);

	ll_deleteLinkedList(ll_listaArticulos);
	ll_deleteLinkedList(ll_listaConDescuentos);
	return EXIT_SUCCESS;
}
