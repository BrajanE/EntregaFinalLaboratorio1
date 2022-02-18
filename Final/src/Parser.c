#include "Parser.h"

int parser_articulosFromText(FILE* pFile , LinkedList* ll_listaArticulos)
{
	int rtn=-1;
	char idStr[100];
	char articuloStr[100];
	char medidaStr[100];
	char precioStr[100];
	char rubroIdStr[100];
	eArticulo* pListaArticulos;
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,articuloStr,medidaStr,precioStr,rubroIdStr);
	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,articuloStr,medidaStr,precioStr,rubroIdStr);
		pListaArticulos = articulo_newParametros(idStr,articuloStr,medidaStr,precioStr,rubroIdStr);
		ll_add(ll_listaArticulos, pListaArticulos);
		rtn=1;

	}
    return rtn;
}

int parser_Save(LinkedList* this, FILE* path)
{
	int rtn=-1;
	eArticulo* articuloAuxiliar;
	int id;
	char articulo[100];
	char medidas[100];
	float precio;
	int rubroId;
	int len=ll_len(this);
	fprintf(path,"ID,Articulo,Medida,Precio,RubroId\n");
	for(int i=0; i<len;i++)
	{
		articuloAuxiliar=ll_get(this, i);
		articulo_getId(articuloAuxiliar, &id);
		articulo_getArticulo(articuloAuxiliar, articulo);
		articulo_getMedida(articuloAuxiliar, medidas);
		articulo_getPrecio(articuloAuxiliar, &precio);
		articulo_getRubroId(articuloAuxiliar, &rubroId);

		fprintf(path,"%d,%s,%s,%.2f,%d\n",id,articulo,medidas,precio,rubroId);
		rtn=1;
	}

	return rtn;
}
