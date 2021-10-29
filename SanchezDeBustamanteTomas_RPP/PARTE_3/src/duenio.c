/*
 * duenio.c
 *
 *  Created on: Oct 22, 2021
 *      Author: user
 */

#include "duenio.h"

int duenio_buscarIndice(sDuenio* duenios, int dueniosLen, int idDuenio)
{
	int retorno = -1;
	int i;

	if(duenios != NULL && dueniosLen > 0)
	{
		for(i=0 ; i<dueniosLen ; i++)
		{
			if(duenios[i].isEmpty == OCUPADO && idDuenio == duenios[i].idDuenio)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int duenio_idLucia(sDuenio* duenios, int dueniosLen)
{
	int retorno = -1;
	int i;

	if(duenios != NULL && dueniosLen > 0)
	{
		for(i=0 ; i<dueniosLen ; i++)
		{
			if(duenios[i].isEmpty == OCUPADO && strcmp(duenios[i].nombre,"Lucia") == 0)
			{
				retorno = duenios[i].idDuenio;
				break;
			}
		}
	}
	return retorno;
}

int duenio_idAlan(sDuenio* duenios, int dueniosLen)
{
	int retorno = -1;
	int i;

	if(duenios != NULL && dueniosLen > 0)
	{
		for(i=0 ; i<dueniosLen ; i++)
		{
			if(duenios[i].isEmpty == OCUPADO && strcmp(duenios[i].nombre,"Alan") == 0)
			{
				retorno = duenios[i].idDuenio;
				break;
			}
		}
	}
	return retorno;
}

void duenio_mostrarTopMenuDuenio(void)
{
	input_limpiarPantalla();
	printf("%-6s %-15s %-15s \n"
			"-----------------------------------\n", "ID", "Nombre", "Telefono");
}

void duenio_mostrarDuenio(sDuenio duenio)
{
	printf("%-6d %-15s %-15d \n",duenio.idDuenio, duenio.nombre, duenio.telefono);
}

int duenio_mostrarDuenios(sDuenio* duenios, int dueniosLen)
{
	int retorno = -1;
	int i;

	if(duenios != NULL && duenios > 0)
	{
		duenio_mostrarTopMenuDuenio();

		for(i=0 ; i<dueniosLen ; i++)
		{
			if(duenios[i].isEmpty == OCUPADO)
			{
				duenio_mostrarDuenio(duenios[i]);
				retorno = 0;
			}
		}
	}

	return retorno;
}

int duenio_encontrarIndiceDuenio(sDuenio* duenios, int dueniosLen, int idDuenioAux)
{
	int retorno = -1;
	int i;

	if(duenios != NULL && duenios > 0)
	{
		for(i=0 ; i<dueniosLen ; i++)
		{
			if(duenios[i].isEmpty == OCUPADO && duenios[i].idDuenio == idDuenioAux)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}














