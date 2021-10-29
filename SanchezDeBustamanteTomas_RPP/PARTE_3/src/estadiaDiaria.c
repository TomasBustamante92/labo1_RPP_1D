/*
 * estadiaDiaria.c
 *
 *  Created on: Oct 22, 2021
 *      Author: user
 */

#include "estadiaDiaria.h"

void estadia_inicializarEstadiaIsEmpty(sEstadiaDiaria* estadias, int estadiasLen)
{
	int i;

	if(estadias != NULL && estadiasLen > 0)
	{
		for(i=0; i<estadiasLen ; i++)
		{
			estadias[i].isEmpty = VACIO;
		}
	}
}

int estadia_encontrarLugarEstadia(sEstadiaDiaria* estadias, int estadiasLen)
{
	int retorno = -1;
	int i;

	if(estadias != NULL && estadiasLen > 0)
	{
		for(i=0 ; i<estadiasLen ; i++)
		{
			if(estadias[i].isEmpty == VACIO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int estadia_encontrarIndiceEstadia(sEstadiaDiaria* estadias, int estadiasLen, int idEstadiaAux)
{
	int retorno = -1;
	int i;

	if(estadias != NULL && estadiasLen > 0)
	{
		for(i=0 ; i<estadiasLen ; i++)
		{
			if(estadias[i].idEstadia == idEstadiaAux)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}







