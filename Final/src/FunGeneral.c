#include "FunGeneral.h"


void MensajeDeCorroboracion(int corroboracion, char mensajeOk[], char mensajeError[])
{
	if(corroboracion>=0)
	{
		printf("%s",mensajeOk);
	}else {
		printf("%s",mensajeError);
	}
}

int PedirEntero(char mensaje[])
{
	int numeroIngresado;
	char term;
	printf("%s",mensaje);
	while((scanf("%d%c", &numeroIngresado, &term) != 2 || term != '\n'))
	{
		printf("Digito invalido. %s",mensaje);
		fflush(stdin);
	}
	return numeroIngresado;
}

int PedirEnteroFull(char mensaje[],int maximo)
{
	int numeroIngresado;
	char term;
	printf("%s",mensaje);
	while((scanf("%d%c", &numeroIngresado, &term) != 2 || term != '\n')||(numeroIngresado<1 || numeroIngresado>maximo))
	{
		printf("Digito invalido. %s",mensaje);
		fflush(stdin);
	}
	return numeroIngresado;
}

void CorreccionDeCadenas(char array[])
{
	char auxiliar[51];
	strcpy(auxiliar,array);
	strlwr(auxiliar);
	for(int i=0; i<strlen(auxiliar);i++)
	{
		auxiliar[0] = toupper(auxiliar[0]);
		break;
	}
	strcpy(array,auxiliar);
}

int ValidacionDeStrings(char array[])
{
	int rtn=0;
	for(int i=0;i<strlen(array);i++)
	{	//if((array[i]>=65 && array[i]<=90) && (array[i]>=97 && array[i]<=122) && (array[i]==46));
		if(!(array[i]>=65 && array[i]<=90) && !(array[i]>=97 && array[i]<=122))
		{
			if(array[i]!=' ' || array[i-1]==' ')
			{
				rtn=-1;
				break;
			}
		}
	}
	return rtn;
}

void GetString(char mensaje[], char stringIngresado[])
{
	int corroboracion;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringIngresado);
	corroboracion=ValidacionDeStrings(stringIngresado);
	CorreccionDeCadenas(stringIngresado);
	while(corroboracion ==-1)
	{
		printf("Digito invalido. Ingrese letras: ");
		fflush(stdin);
		scanf("%[^\n]",stringIngresado);
		corroboracion=ValidacionDeStrings(stringIngresado);
		CorreccionDeCadenas(stringIngresado);
	}
}

/////////////////////////////////

void MenuPrincipal(void)
{
	printf("1- Leer archivo\n"
			"2- Ordenar segun articulo\n"
			"3- Mostrar todo los articulos\n"
			"4- Generar descuentos\n"
			"5- Generar archivo de salida\n"
			"6- SALIR\n");
}

void MenuOrden(void)
{
	printf("\t1- Ascendente\n"
			"\t2- Descendente\n");
}

void PedirArchivo(char mensaje[], char stringIngresado[])
{
	int contadorError=0;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringIngresado);
	CorreccionDeCadenas(stringIngresado);
	while(strcmp(stringIngresado,"Datos.csv")!=0 && contadorError<2)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",stringIngresado);
		CorreccionDeCadenas(stringIngresado);
		contadorError++;
	}

}

int OrdenarPorArticulo(void* primerDato, void* segundoDato)
{
	eArticulo* primerArticulo;
	eArticulo* segundoArticulo;
	int comparacion =0;
	primerArticulo=(eArticulo*) primerDato;
	segundoArticulo=(eArticulo*) segundoDato;
	if(primerArticulo!=NULL && segundoArticulo!=NULL)
	{
		if(strcmp(primerArticulo->articulo,segundoArticulo->articulo)<0)
		{
			comparacion = 1;
		}else if(strcmp(primerArticulo->articulo,segundoArticulo->articulo)>0)
		{
			comparacion =-1;
		}
	}
	return comparacion;
}

void* AplicarDescuento(void* pElement)
{
	eArticulo* pArticuloBuscado;
	pArticuloBuscado = (eArticulo*) pElement;
	if(pArticuloBuscado!=NULL)
	{
		if(pArticuloBuscado->rubroId == 1 && pArticuloBuscado->precio>=120)
		{
			pArticuloBuscado->precio=pArticuloBuscado->precio*0.8;
		}
		if(pArticuloBuscado->rubroId == 2 && pArticuloBuscado->precio<=200)
		{
			pArticuloBuscado->precio=pArticuloBuscado->precio*0.9;
		}
	}
	return pArticuloBuscado;
}
