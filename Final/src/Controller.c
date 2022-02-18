#include "Controller.h"


int controller_loadFromText(char* path , LinkedList* ll_listaArticulos)
{
	int rtn = -1;

	FILE* pFile;
	if(ll_listaArticulos!=NULL && path!=NULL)
	{
		pFile = fopen(path, "r");
			if(pFile!=NULL)
			{
				parser_articulosFromText(pFile ,ll_listaArticulos);
			}
			rtn=1;

		fclose(pFile);
	}
    return rtn;
}

void MostrarUnArticulo(LinkedList* ll_listaArticulos, int index)
{
	eArticulo* pArticuloAuxiliar;
	int id;
	char articulo[50];
	char medidas[51];
	float precio;
	int rubroId;
	if(ll_listaArticulos!=NULL)
	{
		pArticuloAuxiliar = ll_get(ll_listaArticulos, index);

		articulo_getId(pArticuloAuxiliar,&id);
		articulo_getArticulo(pArticuloAuxiliar,articulo);
		articulo_getMedida(pArticuloAuxiliar,medidas);
		articulo_getPrecio(pArticuloAuxiliar,&precio);
		articulo_getRubroId(pArticuloAuxiliar,&rubroId);

		//printf("%d\t%s%25s%20.2f%20d\n", id,articulo,medidas,precio, rubroId);
		MostrarConRubro(id, articulo, medidas, precio, rubroId);

	}
}

void MostrarConRubro(int id, char articulo[], char medidas[], float precio, int rubroId)
{
	char primero[]="Cuidado de Ropa";
	char segundo[]="Limpieza y desinfeccion";
	char tercero[]="Cuidado personal e higiene";
	char cuarto[]="Cuidado del automotor";
	switch(rubroId)
	{
	case 1:
		printf("%d\t%s%25s%20.2f\t\t %s\n", id,articulo,medidas,precio, primero);
		break;
	case 2:
		printf("%d\t%s%25s%20.2f\t\t %s\n", id,articulo,medidas,precio, segundo);
		break;
	case 3:
		printf("%d\t%s%25s%20.2f\t\t %s\n", id,articulo,medidas,precio, tercero);
		break;
	case 4:
		printf("%d\t%s%25s%20.2f\t\t %s\n", id,articulo,medidas,precio, cuarto);
		break;
	}
}

int MostrarListaArticulos(LinkedList* ll_listaArticulos)
{
	int rtn=-1;
	int len=ll_len(ll_listaArticulos);
	if(ll_listaArticulos!=NULL && len>0)
	{
		printf("ID\tArticulos\t\tMedidas\t\tPrecios\tRubroId\n");
		for(int i=0;i<len;i++)
		{
			MostrarUnArticulo(ll_listaArticulos,i);
			rtn=1;
		}
	}
	return rtn;
}

int controller_Save(char* path, LinkedList* this)
{
	int rtn=-1;
	FILE* pFile;
	if(path!=NULL && this!=NULL)
	{
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			rtn= parser_Save(this, pFile);
		}
		fclose(pFile);
	}
	return rtn;
}
