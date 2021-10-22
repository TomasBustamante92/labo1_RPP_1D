/*
 * nexo.c
 *
 *  Created on: Oct 22, 2021
 *      Author: user
 */

#include "nexo.h"

int nexo_cancelarEstadia(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen, sPerro* perros,int perrosLen, int ultimoIdEstadia)
{
	int retorno = -1;
	int indiceEstadias;
	int indicePerros;
	int indiceDuenios;
	int idEstadiaAux;


	if(estadias != NULL && estadiasLen > 0 && duenios != NULL && dueniosLen > 0 && perros != NULL && perrosLen > 0 && ultimoIdEstadia > 0)
	{
		if(nexo_imprimirEstadias(estadias, estadiasLen, duenios, dueniosLen, perros, perrosLen) != -1)
		{
			input_getNumero(&idEstadiaAux, "Ingrese ID estadia: ", "ERROR. Ingrese ID estadia: ", 100000, ultimoIdEstadia);

			indiceEstadias = estadia_encontrarIndiceEstadia(estadias, estadiasLen, idEstadiaAux);

			if(indiceEstadias != -1)
			{
				indicePerros = perro_encontrarPerroId(perros, perrosLen, estadias[indiceEstadias].idPerro);
				indiceDuenios = duenio_encontrarIndiceDuenio(duenios, dueniosLen, estadias[indiceEstadias].idDuenio);

				if(indicePerros != -1 && indiceDuenios != -1)
				{
					// CONFIRMACION
					nexo_imprimirEstadiaMenu();
					nexo_imprimirEstadia(estadias[indiceEstadias], perros[indicePerros], duenios[indiceDuenios]);
					if(input_confirmacion("Confirmar baja [si/no]: ", "ERROR. Confirmar baja [si/no]: ") != -1)
					{
						estadias[indiceEstadias].isEmpty = VACIO;
						retorno = 0;
					}
					else
					{
						input_limpiarPantalla();
						printf("Baja cancelada! \n");
						input_systemPause();
					}
				}
				else
				{
					input_limpiarPantalla();
					printf("Perro o dueño no encontrado! \n");
					input_systemPause();
				}
			}
			else
			{
				input_limpiarPantalla();
				printf("No se encuentra la estadia en la base de datos! \n");
				input_systemPause();
			}
		}
		else
		{
			input_limpiarPantalla();
			printf("No hay estadias reservadas! \n");
			input_systemPause();
		}
	}
	return retorno;
}

void nexo_imprimirEstadiaMenu(void)
{
	input_limpiarPantalla();
	printf(	"%-7s %-16s %-15s %-13s %-15s %-15s %-15s \n"
			"-------------------------------------------------------------------------------------------\n",
			"ID", "Dueño", "Telefono", "Fecha", "Perro", "Raza", "Edad");
}

void nexo_imprimirEstadia(sEstadiaDiaria estadia, sPerro perro, sDuenio duenio)
{

	printf("%-7d %-15s %-14d %2d/%2d/%-8d %-15s %-15s %-15d \n",
			estadia.idEstadia, duenio.nombre, duenio.telefono, estadia.fecha.dia,estadia.fecha.mes,estadia.fecha.anio, perro.nombre, perro.raza, perro.edad);
}

int nexo_imprimirEstadias(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen, sPerro* perros, int perrosLen)
{
	int retorno = -1;
	int i;
	int indicePerros;
	int indiceDuenios;

	nexo_imprimirEstadiaMenu();

	if(estadias != NULL && estadiasLen > 0 && duenios != NULL && dueniosLen > 0 && perros != NULL && perrosLen > 0)
	{
		for(i=0 ; i<estadiasLen ; i++)
		{
			if(estadias[i].isEmpty == OCUPADO)
			{
				indicePerros = perro_encontrarPerroId(perros, perrosLen, estadias[i].idPerro);
				indiceDuenios = duenio_encontrarIndiceDuenio(duenios, dueniosLen, estadias[i].idDuenio);

				if(indicePerros != -1 && indiceDuenios != -1)
				{
					nexo_imprimirEstadia(estadias[i], perros[indicePerros], duenios[indiceDuenios]);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int nexo_reservarEstadia(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen, sPerro* perros, int perrosLen, int ultimoIdEstadia, int ultimoIdPerros, int ultimoIdDuenios)
{
	int retorno = -1;
	sEstadiaDiaria estadiaAux;
	int idDuenioAux;
	int idPerroAux;
	int indiceEstadias;
	int indicePerro;
	int indiceDuenio;

	if(estadias != NULL && estadiasLen > 0 && duenios != NULL && dueniosLen > 0 && perros != NULL && perrosLen > 0 && ultimoIdEstadia > 0 && ultimoIdPerros > 0 && ultimoIdDuenios > 0)
	{
		indiceEstadias = encontrarLugarEstadia(estadias, estadiasLen);

		if(indiceEstadias != -1)
		{
			// ID
			estadiaAux.idEstadia = ultimoIdEstadia +1;

			// DUENIO
			if(duenio_mostrarDuenios(duenios, dueniosLen) != -1)
			{
				input_getNumero(&idDuenioAux, "Ingrese ID del dueño: ", "ERROR. Ingrese ID del dueño: ", 30000, ultimoIdDuenios);
				indiceDuenio = duenio_encontrarIndiceDuenio(duenios, dueniosLen, idDuenioAux);
				if(indiceDuenio != -1)
				{

					estadiaAux.idDuenio = idDuenioAux;

					// PERRO
					if(perro_mostrarPerros(perros, perrosLen) != -1)
					{
						input_getNumero(&idPerroAux, "Ingrese ID del perro: ", "ERROR. Ingrese ID del perro: ", 7000, ultimoIdPerros);
						indicePerro = perro_encontrarIndicePerro(perros, perrosLen, idPerroAux);
						if(indicePerro != -1)
						{
							estadiaAux.idPerro = idPerroAux;

							// FECHA
							fecha_pedirFecha(&estadiaAux.fecha.dia, &estadiaAux.fecha.mes, &estadiaAux.fecha.anio);

							// CONFIRMACION
							nexo_imprimirEstadiaMenu();
							nexo_imprimirEstadia(estadiaAux, perros[indicePerro], duenios[indiceDuenio]);
							if(input_confirmacion("Confirmar reserva [si/no]: ", "ERROR. Confirmar reserva [si/no]: ") != -1)
							{
								estadias[indiceEstadias] = estadiaAux;
								estadias[indiceEstadias].isEmpty = OCUPADO;
								retorno = 0;
							}
							else
							{
								input_limpiarPantalla();
								printf("Reserva cancelada! \n");
								input_systemPause();
							}
						}
						else
						{
							input_limpiarPantalla();
							printf("No se encuenta al perro en la base de datos! \n");
							input_systemPause();
						}
					}
					else
					{
						input_limpiarPantalla();
						printf("No hay perros en la base de datos! \n");
						input_systemPause();
					}

				}
				else
				{
					input_limpiarPantalla();
					printf("No se encuenta al dueño en la base de datos! \n");
					input_systemPause();
				}
			}
			else
			{
				input_limpiarPantalla();
				printf("No hay dueños en la base de datos! \n");
				input_systemPause();
			}
		}
		else
		{
			input_limpiarPantalla();
			printf("No hay mas lugar disponible! \n");
			input_systemPause();
		}
	}

	return retorno;
}
