/*
 * duenio.h
 *
 *  Created on: Oct 22, 2021
 *      Author: user
 */

#ifndef DUENIO_H_
#define DUENIO_H_


#include <stdio_ext.h>
#include <stdlib.h>
#include "input.h"

#define NOMBRE_DUENIO 41
#define DUENIOS_LEN 5

typedef struct
{
	int idDuenio;
	char nombre[NOMBRE_DUENIO];
	int telefono;
	int isEmpty;

} sDuenio;

/// @fn int duenio_buscarIndice(sDuenio*, int, int)
/// @brief busca el indice del duenio
///
/// @param duenios
/// @param dueniosLen
/// @param idDuenio
/// @returnde encontrar devuelve el indice del duenio. caso contrario devuelve [-1]
int duenio_buscarIndice(sDuenio* duenios, int dueniosLen, int idDuenio);

/// @fn int duenio_idLucia(sDuenio*, int)
/// @brief busca el id del duenio lucia
///
/// @param duenios
/// @param dueniosLen
/// @return de encontrar duenios que se llamen lucia devuelve el id, caso contrario devuelve [-1]
int duenio_idLucia(sDuenio* duenios, int dueniosLen);

/// @fn int duenio_contadorAlan(sDuenio*, int)
/// @brief busca el id del duenio alan
///
/// @param duenios
/// @param dueniosLen
/// @return de encontrar duenios que se llamen alan devuelve el id, caso contrario devuelve [-1]
int duenio_idAlan(sDuenio* duenios, int dueniosLen);

/// @fn int duenio_encontrarIndiceDuenio(sDuenio*, int, int)
/// @brief compara el id ingresado con la lista de duenios
///
/// @param duenios array de duenios
/// @param dueniosLen longitud del array de duenios
/// @param idDuenioAux
/// @return En caso de que haya encontrado al duenio se devuelve el indice, caso contrario devuelve [-1]
int duenio_encontrarIndiceDuenio(sDuenio* duenios, int dueniosLen, int idDuenioAux);

/// @fn int duenio_mostrarDuenios(sDuenio*, int)
/// @brief imprime en pantalla todos los duenios
///
/// @param duenios array de duenios
/// @param len longitud del array de duenios
/// @return devuelve [0] en caso de que haya duenios para imprimir, caso contrario devuelve [-1]
int duenio_mostrarDuenios(sDuenio* duenios, int dueniosLen);

/// @fn void duenio_mostrarDuenio(sDuenio)
/// @brief imprime un duenio en pantalla
///
/// @param duenio estructura de un duenio
void duenio_mostrarDuenio(sDuenio duenio);

/// @fn void duenio_mostrarTopMenuDuenio(void)
/// @brief mustra informacion de la lista de duenios
///
void duenio_mostrarTopMenuDuenio(void);

#endif /* DUENIO_H_ */
