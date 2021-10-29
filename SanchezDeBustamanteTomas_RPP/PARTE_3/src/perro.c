/*
 * perro.c
 *
 *  Created on: Oct 22, 2021
 *      Author: user
 */

#include "perro.h"

void perro_hardcodearPerros(sPerro* perros)
{
	sPerro perrosAux[PERROS_LEN] = { 	{7000, "Lobo", "Sharpei", 2 ,OCUPADO},
										{7001, "Sheila", "Golden", 12, OCUPADO},
										{7002, "Reina", "Galgo", 13, OCUPADO}
	};

	for(int i=0 ; i<3 ; i++)
	{
		perros[i] = perrosAux[i];
	}
}

void perro_initPerros(sPerro* perros, int perrosLen)
{
	int i;

	if(perros != NULL && perrosLen > 0)
	{
		for(i=0 ; i<perrosLen ; i++)
		{
			perros[i].isEmpty = VACIO;
		}
	}
}

int perro_encontrarEspacioVacio(sPerro* perros, int perrosLen)
{
	int retorno = -1;
	int i;

	if(perros != NULL && perrosLen > 0)
	{
		for(i=0 ; i<perrosLen ; i++)
		{
			if(perros[i].isEmpty == VACIO)
			{
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}

int perro_altaPerros(sPerro* perros, int perrosLen, int ultimoIdPerros)
{
	int retorno = -1;
	sPerro perroAux;
	int perroIndice;

	if(perros != NULL && perrosLen > 0)
	{
		perroIndice = perro_encontrarEspacioVacio(perros, perrosLen);

		if(perroIndice != -1)
		{
			// ID
			perroAux.idPerro = ultimoIdPerros +1;

			// NOMBRE
			input_limpiarPantalla();
			input_pedirStringNombreApellido(perroAux.nombre, "Nombre: ", "ERROR. Nombre: ", sizeof(perroAux.nombre));

			// RAZA
			input_limpiarPantalla();
			input_pedirStringNombreApellido(perroAux.raza, "Raza: ", "ERROR. Raza: ", sizeof(perroAux.raza));

			// EDAD
			input_limpiarPantalla();
			input_getNumero(&perroAux.edad, "Edad: ", "ERROR. Edad [1-40]: ", 1, 40);

			// CONFIRMACION
			perro_mostrarTopMenuPerros();
			perro_mostrarPerro(perroAux);
			if(input_confirmacion("Confirmar reserva [si/no]: ", "ERROR. Confirmar reserva [si/no]: ") != -1)
			{
				perros[perroIndice] = perroAux;
				perros[perroIndice].isEmpty = OCUPADO;
				retorno = 0;
			}
			else
			{
				input_limpiarPantalla();
				printf("Perro cancelado! \n");
				input_systemPause();
			}
		}
		else
		{
			input_limpiarPantalla();
			printf("No hay espacio disponible! \n");
			input_systemPause();
		}

	}
	return retorno;
}

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

int perro_mostrarPromedioDeEdadDePerros(sPerro* perros, int perrosLen)
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








