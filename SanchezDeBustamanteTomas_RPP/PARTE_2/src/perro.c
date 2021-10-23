/*
 * perro.c
 *
 *  Created on: Oct 22, 2021
 *      Author: user
 */

#include "perro.h"

int perro_encontrarIndicePerro(sPerro* perros, int perrosLen, int idPerroAux)
{
	int retorno = -1;
	int i;

	if(perros != NULL && perrosLen > 0)
	{
		for(i=0 ; i<perrosLen ; i++)
		{
			if(perros[i].isEmpty == OCUPADO && perros[i].idPerro == idPerroAux)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


void perro_mostrarPerro(sPerro perro)
{
	printf("%-5d %-15s %-15s %-15d \n", perro.idPerro, perro.nombre, perro.raza, perro.edad);
}

int perro_mostrarPerros(sPerro* perros, int perrosLen)
{
	int retorno = -1;
	int i;

	if(perros != NULL && perrosLen > 0)
	{
		perro_mostrarTopMenuPerros();

		for(i=0 ; i<perrosLen ; i++)
		{
			if(perros[i].isEmpty == OCUPADO)
			{
				perro_mostrarPerro(perros[i]);
				retorno = 0;
			}
		}
	}

	return retorno;
}

void perro_mostrarTopMenuPerros(void)
{
	input_limpiarPantalla();
	printf("%-5s %-15s %-15s %-15s \n"
			"---------------------------------------------\n", "ID", "Nombre", "Raza", "Edad");
}


int perro_encontrarPerroId(sPerro* perros, int perrosLen, int idPerroAux)
{
	int retorno = -1;
	int i;

	if(perros != NULL && perrosLen > 0)
	{
		for(i=0 ; i<perrosLen ; i++)
		{
			if(perros[i].idPerro == idPerroAux)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int promedioDeEdadDePerros(sPerro* perros, int perrosLen)
{
	int retorno = -1;
	float promedio;
	int i;
	int contador = 0;
	int acumuladorEdades = 0;

	if(perros != NULL && perrosLen > 0)
	{
		for(i=0 ; i<perrosLen ; i++)
		{
			if(perros[i].isEmpty == OCUPADO)
			{
				acumuladorEdades += perros[i].edad;
				contador++;
			}
		}

		if(contador > 0)
		{
			promedio = (float)acumuladorEdades / contador;
			retorno = 0;

			input_limpiarPantalla();
			printf("El promedio de edad de los perros es de %.2f años \n", promedio);
		}
	}

	return retorno;
}








