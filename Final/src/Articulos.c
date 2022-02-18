#include "Articulos.h"

/**
 * Inicia el Array
 * @return
 */
eArticulo* articulos_new()
{
	eArticulo* plistaArticulos;
	plistaArticulos = (eArticulo*) malloc(sizeof(eArticulo));

	return plistaArticulos;
}

/**
 * funcion alberga las demas funciones del set, toma cada dato y los guarda en la variable correspondiente
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @param sueldoStr
 * @return
 */
eArticulo* articulo_newParametros(char* idStr,char* articuloStr,char* medidaStr,char* precioStr,char* rubroIdStr)
{
	eArticulo* plistaArticulos;
	plistaArticulos = articulos_new();
	if(plistaArticulos!=NULL && idStr!=NULL && articuloStr!=NULL && medidaStr!=NULL && precioStr!=NULL && rubroIdStr!=NULL)
	{
		articulo_setId(plistaArticulos, atoi(idStr));
		articulo_setArticulo(plistaArticulos,articuloStr);
		articulo_setMedida(plistaArticulos,medidaStr);
		articulo_setPrecio(plistaArticulos, atof(precioStr));
		articulo_setRubroId(plistaArticulos, atoi(rubroIdStr));
	}
	return plistaArticulos;
}

/**
 * Elimina un elemento
 * @param this
 */
void articulo_delete(eArticulo* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

/**
 * Toma un dato ID y lo guarda en el listado
 * @param this
 * @param id
 * @return rtn
 */
int articulo_setId(eArticulo* this,int id)
{
	int rtn = -1;
	if(this!=NULL)
	{
		this->id=id;
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un Id del listado y lo guarda en la variable id que luego se enviara por puntero
 * @param this
 * @param id
 * @return
 */
int articulo_getId(eArticulo* this,int* id)
{
	int rtn = -1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un dato Titulo y lo guarda en el listado
 * @param this
 * @param titulo
 * @return
 */
int articulo_setArticulo(eArticulo* this,char* articulo)
{
	int rtn = -1;
	if(this!=NULL && articulo!=NULL)
	{
		strcpy(this->articulo,articulo);
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un titulo del listado y lo guarda en la variable nombre que luego se enviara por puntero
 * @param this
 * @param titulo
 * @return
 */
int articulo_getArticulo(eArticulo* this,char* articulo)
{
	int rtn = -1;
	if(this!=NULL && articulo !=NULL)
	{
		strcpy(articulo,this->articulo);
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un dato nuevo Autor y lo guarda en el listado
 * @param this
 * @param autor
 * @return
 */
int articulo_setMedida(eArticulo* this,char* medida)
{
	int rtn = -1;
	if(this!=NULL && medida!=NULL)
	{
		strcpy(this->medida,medida);
		rtn = 1;
	}

	return rtn;
}
/**
 * Toma un dato de autor del listado y lo guarda en la variable "horas trabajadas" que luego se enviara por puntero
 * @param this
 * @param autor
 * @return
 */
int articulo_getMedida(eArticulo* this,char* medida)
{
	int rtn = -1;
	if(this!=NULL && medida!=NULL)
	{
		strcpy(medida,this->medida);
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un dato precio y lo guarda en el listado
 * @param this
 * @param precio
 * @return
 */
int articulo_setPrecio(eArticulo* this,float precio)
{
	int rtn = -1;
	if(this!=NULL)
	{
		this->precio=precio;
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un dato de precio del listado y lo guarda en la variable "sueldo" que luego se enviara por puntero
 * @param this
 * @param precio
 * @return
 */
int articulo_getPrecio(eArticulo* this,float* precio)
{
	int rtn = -1;
	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un dato IDeditorial y lo guarda en el listado
 * @param this
 * @param idEditorial
 * @return rtn
 */
int articulo_setRubroId(eArticulo* this,int rubroId)
{
	int rtn = -1;
	if(this!=NULL)
	{
		this->rubroId=rubroId;
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un IdEditorial del listado y lo guarda en la variable id que luego se enviara por puntero
 * @param this
 * @param idEditorial
 * @return
 */
int articulo_getRubroId(eArticulo* this,int* rubroId)
{
	int rtn = -1;
	if(this!=NULL && rubroId!=NULL)
	{
		*rubroId=this->rubroId;
		rtn = 1;
	}

	return rtn;
}


