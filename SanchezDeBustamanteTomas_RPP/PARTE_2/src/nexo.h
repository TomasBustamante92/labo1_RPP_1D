/*
 * nexo.h
 *
 *  Created on: Oct 22, 2021
 *      Author: user
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "perro.h"
#include "estadiaDiaria.h"
#include "duenio.h"

/// @fn int listarPerrosConEstadias(sEstadiaDiaria*, int, sDuenio*, int, sPerro*, int)
/// @brief Mostrar lista de perros con sus estadias
///
/// @param estadias
/// @param estadiasLen
/// @param duenios
/// @param dueniosLen
/// @param perros
/// @param perrosLen
/// @return de encontrar estadias para imprimir devuelve [0] caso contrario devuelve [-1]
int listarPerrosConEstadias(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen, sPerro* perros, int perrosLen);

/// @fn int mostrarPerroConMasEstadias(sEstadiaDiaria*, int, sPerro*, int)
/// @brief Muesta los perros con mas estadias
///
/// @param estadias
/// @param estadiasLen
/// @param perros
/// @param perrosLen
/// @return de haber perros para mostrar devuelve [0], caso contrario devuelve [-1]
int mostrarPerroConMasEstadias(sEstadiaDiaria* estadias, int estadiasLen, sPerro* perros, int perrosLen);

/// @fn int nexo_modificarEstadia(sEstadiaDiaria*, int, sDuenio*, int, sPerro*, int, int, int)
/// @brief  el usuario puede modificar el telefono o el perro por medio de un sub-menu
///
/// @param estadias
/// @param estadiasLen
/// @param duenios
/// @param dueniosLen
/// @param perros
/// @param perrosLen
/// @param ultimoIdEstadia
/// @param ultimoIdPerros
/// @return  devuelve [0] en caso de que se realice alguna modificacion, caso contrario devuelve [-1]
int nexo_modificarEstadia(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen, sPerro* perros, int perrosLen, int ultimoIdEstadia, int ultimoIdPerros);

/// @fn void ordenarEstadiasPorFechaNombre(sEstadiaDiaria*, int, sDuenio*, int)
/// @brief ordena el array de estadia por fecha y nombre
///
/// @param estadias
/// @param estadiasLen
/// @param duenios
/// @param dueniosLen
void ordenarEstadiasPorFechaNombre(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen);

/// @fn void SwapearEstadiaDuenio(sEstadiaDiaria, sEstadiaDiaria, sDuenio, sDuenio)
/// @brief intercambia de contenido de 1 al 2 y viceversa
///
/// @param estadia1
/// @param estadia2
/// @param duenio1
/// @param duenio2
void SwapearEstadiaDuenio(sEstadiaDiaria* pEstadia1, sEstadiaDiaria* pEstadia2, sDuenio* pDuenio1, sDuenio* pDuenio2);

/// @fn int nexo_cancelarEstadia(sEstadiaDiaria*, int, sDuenio*, int, sPerro*, int, int)
/// @brief  dar de baja logica una estadia
///
/// @param estadias lista array de estadias
/// @param estadiasLen longitud del array de estadias
/// @param duenios lista array de duenios
/// @param dueniosLen longitud del array de duenios
/// @param perros array de perros
/// @param perrosLen longitud de array de perros
/// @param ultimoIdEstadia ultimo ID ingresado anteriormente
/// @return caso de confirmar cancelacion devuelve [0] caso contrario devuelve [-1]
int nexo_cancelarEstadia(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen, sPerro* perros,int perrosLen, int ultimoIdEstadia);

/// @fn int nexo_reservarEstadia(sEstadiaDiaria*, int, sDuenio*, int, sPerro*, int, int, int, int)
/// @brief Pide los datos al usuario de una estadia y pide confirmar, si confirma se guardan en el array de estadia
///
/// @param estadias array de estadias
/// @param estadiasLen longitud del array de estadias
/// @param duenios array de duenios
/// @param dueniosLen longitud del array de duenios
/// @param perros array de perros
/// @param perrosLen longitud del array de perros
/// @param ultimoIdEstadia
/// @param ultimoIdPerros
/// @param ultimoIdDuenios
/// @return si el usuario ingreso correctamente y confirma la estadia devuelve [0] caso contrario [-1]
int nexo_reservarEstadia(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen, sPerro* perros, int perrosLen, int ultimoIdEstadia, int ultimoIdPerros, int ultimoIdDuenios);

/// @fn void nexo_imprimirEstadia(sEstadiaDiaria, sPerro, sDuenio)
/// @brief imprime datos de una estadia
///
/// @param estadia
/// @param perro
/// @param duenio
void nexo_imprimirEstadia(sEstadiaDiaria estadia, sPerro perro, sDuenio duenio);

/// @fn int nexo_imprimirEstadias(sEstadiaDiaria*, int, sDuenio*, int, sPerro*, int)
/// @brief imprime listado de estadias
///
/// @param estadias
/// @param estadiaLen
/// @param duenios
/// @param dueniosLen
/// @param perros
/// @param perrosLen
/// @return si encuentra estadias para imprimir devuelve [0] caso contrario devuelve [-1]
int nexo_imprimirEstadias(sEstadiaDiaria* estadias, int estadiaLen, sDuenio* duenios, int dueniosLen, sPerro* perros, int perrosLen);

/// @fn void nexo_imprimirEstadiaMenu(void)
/// @brief Imprime nombre de datos del menu que van arriba de los datos de las estadias y perros
///
void nexo_imprimirEstadiaMenu(void);

#endif /* NEXO_H_ */
