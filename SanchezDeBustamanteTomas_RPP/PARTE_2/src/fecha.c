/*
 * fecha.c
 *
 *  Created on: Oct 22, 2021
 *      Author: user
 */

#include "fecha.h"

int fecha_pedirFecha(int* dia, int* mes, int* anio)
{
	int retorno = -1;
	int diaAux;
	int mesAux;
	int anioAux;
	int fecha;

	if(dia != NULL && mes != NULL && anio != NULL)
	{
		input_limpiarPantalla();

		do{
			input_getNumero(&diaAux, "Dia: ", "ERROR Dia [1-31]: ", 1, 31);
			input_getNumero(&mesAux, "Mes: ", "ERROR Mes [1-12]: ", 1, 12);

			fecha = validarFecha(diaAux, mesAux);
			if(fecha == -1)
			{
				printf("Fecha incorrecta \n");
			}
		} while(fecha == -1);

		input_getNumero(&anioAux, "Año: ", "ERROR Año [2021-2031]: ", 2021, 2031);

		*dia = diaAux;
		*mes = mesAux;
		*anio = anioAux;

		retorno = 0;
	}

	return retorno;
}

int validarFecha(int dia, int mes)
{
	int retorno = 0;

	if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
	{
		if(dia > 30)
		{
			retorno = -1;
		}
	}
	else
	{
		if(mes == 2)
		{
			if(dia > 28)
			{
				retorno = -1;
			}
		}
	}

	return retorno;

}
