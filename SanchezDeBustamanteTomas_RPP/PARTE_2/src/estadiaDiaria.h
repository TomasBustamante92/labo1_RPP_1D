/*
 * estadiaDiaria.h
 *
 *  Created on: Oct 22, 2021
 *      Author: user
 */

#ifndef ESTADIADIARIA_H_
#define ESTADIADIARIA_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include "fecha.h"
#include "input.h"

#define ESTADIA_LEN 100

typedef struct{
	int idEstadia;
	int idDuenio;
	int idPerro;
	sFecha fecha;
	int isEmpty;

} sEstadiaDiaria;

/// @fn int estadia_encontrarIndiceEstadia(sEstadiaDiaria*, int, int)
/// @brief compara el id en la lista de estadias
///
/// @param estadias
/// @param estadiasLen
/// @param idEstadiaAux
/// @return si encuentra estadia devuelve el indice, caso contrario [-1]
int estadia_encontrarIndiceEstadia(sEstadiaDiaria* estadias, int estadiasLen, int idEstadiaAux);

/// @fn void estadia_inicializarEstadiaIsEmpty(sEstadiaDiaria*, int)
/// @brief convierte todos los isEmpty del array en VACIO
///
/// @param lista array de estadias
/// @param len longitud del array de estadias
void estadia_inicializarEstadiaIsEmpty(sEstadiaDiaria* estadias, int estadiasLen);

/// @fn int estadia_encontrarLugarEstadia(sEstadiaDiaria*, int)
/// @brief busca en el array por el primer lugar con el valor VACIO en isEmpty
///
/// @param lista array de estadias
/// @param estadiaLen  longitud del array de estadias
/// @return devuelve el indice del primero lugar con el valor VACIO, caso de no encontrar devuelve [-1]
int estadia_encontrarLugarEstadia(sEstadiaDiaria* estadias, int estadiasLen);

#endif /* ESTADIADIARIA_H_ */
