/*
 * nexo.c
 *
 *  Created on: Oct 22, 2021
 *      Author: user
 */

#include "nexo.h"

int nexo_modificarEstadia(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen, sPerro* perros, int perrosLen, int ultimoIdEstadia, int ultimoIdPerros)
{
	int retorno = -1;
	int opciones;
	int idEstadiaAux;
	int indiceEstadia;
	int indiceDuenio;
	int indicePerro;
	int indicePerroAux;
	int idPerro;
	sDuenio duenioAux;

	if(estadias != NULL && estadiasLen > 0 && duenios != NULL && dueniosLen > 0 && perros != NULL && perrosLen > 0 && ultimoIdEstadia > 0 && ultimoIdPerros > 0)
	{
		if(nexo_imprimirEstadias(estadias, estadiasLen, duenios, dueniosLen, perros, perrosLen) != -1)
		{
			// ELEGIR ESTADIA
			input_getNumero(&idEstadiaAux, "\nIngrese ID del dia a modificar: ", "ERROR. Ingrese ID del dia a modificar: ", 100000, ultimoIdEstadia);
			indiceEstadia = estadia_encontrarIndiceEstadia(estadias, estadiasLen, idEstadiaAux);

			if(indiceEstadia != -1)
			{
				indiceDuenio = duenio_encontrarIndiceDuenio(duenios, dueniosLen, estadias[indiceEstadia].idDuenio);
				indicePerro = perro_encontrarIndicePerro(perros, perrosLen, estadias[indiceEstadia].idPerro);

				do{
					// MENU DE MODIFICACION
					nexo_imprimirEstadiaMenu();
					nexo_imprimirEstadia(estadias[indiceEstadia], perros[indicePerro], duenios[indiceDuenio]);
					input_getNumero(&opciones, 	"\n1. Modificar telefono de contacto \n"
												"2. Modificar perro \n"
												"3. Atras \n"
												"Opcion: ",
												"\n1. Modificar telefono de contacto \n"
												"2. Modificar perro \n"
												"3. Atras \n"
												"ERROR. Opcion: ", 1, 3);
					switch (opciones)
					{
						case 1:
							// CAMBIAR TELEFONO DUENIO
							input_limpiarPantalla();
							duenioAux = duenios[indiceDuenio];
							input_getNumero(&duenioAux.telefono, "Telefono de contacto [11********]: ", "ERROR. Telefono de contacto [11********]: ", 1100000000, 1199999999);


							// CONFIRMACION
							nexo_imprimirEstadiaMenu();
							nexo_imprimirEstadia(estadias[indiceEstadia], perros[indicePerro], duenioAux);
							if(input_confirmacion("\nConfirmar modificacion [si/no]: ", "Confirmar modificacion [si/no]: ") == 0)
							{
								duenios[indiceDuenio].telefono = duenioAux.telefono;
								retorno = 0;

								input_limpiarPantalla();
								printf("Modificacion exitosa! \n");
								input_systemPause();
							}
							else
							{
								input_limpiarPantalla();
								printf("Modificacion de telefono cancelada! \n");
								input_systemPause();
							}

							break;
						case 2:
							// CAMBIAR PERRO
							if(perro_mostrarPerros(perros, perrosLen) != -1)
							{
								input_getNumero(&idPerro, "Ingrese ID del perro: ", "ERROR. Ingrese ID del perro: ", 7000, ultimoIdPerros);
								indicePerroAux = perro_encontrarIndicePerro(perros, perrosLen, idPerro);
								if(indicePerroAux != -1)
								{
									// CONFIRMACION
									nexo_imprimirEstadiaMenu();
									nexo_imprimirEstadia(estadias[indiceEstadia], perros[indicePerroAux], duenios[indiceDuenio]);
									if(input_confirmacion("\nConfirmar modificacion [si/no]: ", "Confirmar modificacion [si/no]: ") == 0)
									{
										estadias[indiceEstadia].idPerro = idPerro;
										retorno = 0;
										indicePerro = indicePerroAux;

										input_limpiarPantalla();
										printf("Modificacion exitosa! \n");
										input_systemPause();
									}
									else
									{
										input_limpiarPantalla();
										printf("Modificacion de perro cancelada! \n");
										input_systemPause();
									}
								}
							}
							else
							{
								input_limpiarPantalla();
								printf("No hay perros en la base de datos! \n");
								input_systemPause();
							}
							break;
					}

				}while(opciones != 3);
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


	if(estadias != NULL && estadiasLen > 0 && duenios != NULL && dueniosLen > 0 && perros != NULL && perrosLen > 0)
	{
		nexo_imprimirEstadiaMenu();

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

void ordenarEstadiasPorFechaNombre(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen)
{
	int i;
	int j;
	int nuevoLen = estadiasLen;
	int duenioIndice1;
	int duenioIndice2;


	if(estadias != NULL && estadiasLen > 0 && duenios != NULL && dueniosLen > 0)
	{
		for(i=0 ; i<nuevoLen-1 ; i++)
		{
			for(j=i+1 ; j<nuevoLen ; j++)
			{
				if(estadias[i].isEmpty == OCUPADO && estadias[j].isEmpty == OCUPADO)
				{
					duenioIndice1 = duenio_encontrarIndiceDuenio(duenios, dueniosLen, estadias[i].idDuenio);
					duenioIndice2 = duenio_encontrarIndiceDuenio(duenios, dueniosLen, estadias[j].idDuenio);

					if(estadias[i].fecha.anio < estadias[j].fecha.anio)
					{
						estadiaDuenioSwap(&estadias[i], &estadias[j], &duenios[duenioIndice1], &duenios[duenioIndice2]);
					}
					else if(estadias[i].fecha.anio == estadias[j].fecha.anio && estadias[i].fecha.mes < estadias[j].fecha.mes)
					{
						estadiaDuenioSwap(&estadias[i], &estadias[j], &duenios[duenioIndice1], &duenios[duenioIndice2]);
					}
					else if(estadias[i].fecha.anio == estadias[j].fecha.anio && estadias[i].fecha.mes == estadias[j].fecha.mes && estadias[i].fecha.dia < estadias[j].fecha.dia)
					{
						estadiaDuenioSwap(&estadias[i], &estadias[j], &duenios[duenioIndice1], &duenios[duenioIndice2]);
					}
					else if(estadias[i].fecha.anio == estadias[j].fecha.anio && estadias[i].fecha.mes == estadias[j].fecha.mes && estadias[i].fecha.dia == estadias[j].fecha.dia)
					{

						if(strcmp(duenios[duenioIndice1].nombre, duenios[duenioIndice2].nombre) > 0)
						{
							estadiaDuenioSwap(&estadias[i], &estadias[j], &duenios[duenioIndice1], &duenios[duenioIndice2]);
						}
					}
				}
			}
		nuevoLen--;
		}
	}
}

void estadiaDuenioSwap(sEstadiaDiaria* pEstadia1, sEstadiaDiaria* pEstadia2, sDuenio* pDuenio1, sDuenio* pDuenio2)
{
	sEstadiaDiaria estadiaAux;
	sDuenio duenioAux;

	estadiaAux = *pEstadia1;
	*pEstadia1 = *pEstadia2;
	*pEstadia2 = estadiaAux;

	duenioAux = *pDuenio1;
	*pDuenio1 = *pDuenio2;
	*pDuenio2 = duenioAux;
}













