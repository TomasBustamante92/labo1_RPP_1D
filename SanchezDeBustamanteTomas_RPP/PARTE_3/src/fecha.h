/*
 * fecha.h
 *
 *  Created on: Oct 22, 2021
 *      Author: user
 */

#ifndef FECHA_H_
#define FECHA_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include "input.h"

typedef struct{
	int dia;
	int mes;
	int anio;

} sFecha;

/// @fn int fecha_validarSegundaQuincenaNoviembre(int, int, int)
/// @brief valida que la fecha sea solo en la 2da quincena de noviembre 2021
///
/// @param dia
/// @param mes
/// @param anio
/// @return de ser verdad devuelve [0] caso contrario devuelve [-1]
int fecha_validarSegundaQuincenaNoviembre(int dia, int mes, int anio);

/// @fn int fecha_validarFecha(int, int)
/// @brief corroborar que la fecha exista
///
/// @param dia
/// @param mes
/// @return devuelve [0] si existe la fecha, caso contrario [-1]
int fecha_validarFecha(int dia, int mes);

/// @fn int fecha_pedirFecha(int*, int*, int*)
/// @brief pide al usuario por una fecha
///
/// @param dia
/// @param mes
/// @param anio
/// @return devuelve [0] si se pudo agendar la fecha, caso contrario [-1]
int fecha_pedirFecha(int* dia, int* mes, int* anio);

#endif /* FECHA_H_ */
