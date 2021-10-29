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


/// @fn int nexo_listarEstadiasLucia(sEstadiaDiaria*, int, sDuenio*, int, sPerro*, int)
/// @brief cuenta cuantas reservas hay de duenios que se llamen lucia
///
/// @param estadias
/// @param estadiasLen
/// @param duenios
/// @param dueniosLen
/// @param perros
/// @param perrosLen
/// @return de encontrar estadias de lucias devuelve [0] caso contrario imprime [-1]
int nexo_listarEstadiasLucia(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen, sPerro* perros, int perrosLen);

/// @fn int nexo_contarDueniosAlan(sEstadiaDiaria*, int, sDuenio*, int)
/// @brief cuenta cuantos alan hay con estadias
///
/// @param estadias
/// @param estadiasLen
/// @param duenios
/// @param dueniosLen
/// @param perros
/// @param perrosLen
/// @return de haber alans en la base de datos devuelve [0] caso contrario [-1]
int nexo_contarDueniosAlan(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen);

/// @fn int nexo_listarPerrosConEstadias(sEstadiaDiaria*, int, sDuenio*, int, sPerro*, int)
/// @brief Mostrar lista de perros con sus estadias
///
/// @param estadias
/// @param estadiasLen
/// @param duenios
/// @param dueniosLen
/// @param perros
/// @param perrosLen
/// @return de encontrar estadias para imprimir devuelve [0] caso contrario devuelve [-1]
int nexo_listarPerrosConEstadias(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen, sPerro* perros, int perrosLen);

/// @fn int nexo_contarEstadias(sEstadiaDiaria*, int, int)
/// @brief cuenta la cantidad de estadias por perro
///
/// @param estadias
/// @param estadiasLen
/// @param idPerro
/// @return de ser exitoso devuelve la cantidad de estadias reservadas, caso contrario devuelve [-1]
int nexo_contarEstadias(sEstadiaDiaria* estadias, int estadiasLen, int idPerro);

/// @fn int nexo_mostrarPerroConMasEstadias(sEstadiaDiaria*, int, sPerro*, int)
/// @brief Muesta los perros con mas estadias
///
/// @param estadias
/// @param estadiasLen
/// @param perros
/// @param perrosLen
/// @return de haber perros para mostrar devuelve [0], caso contrario devuelve [-1]
int nexo_mostrarPerroConMasEstadias(sEstadiaDiaria* estadias, int estadiasLen, sPerro* perros, int perrosLen);

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

/// @fn void nexo_ordenarEstadiasPorFechaNombre(sEstadiaDiaria*, int, sDuenio*, int)
/// @brief ordena el array de estadia por fecha y nombre
///
/// @param estadias
/// @param estadiasLen
/// @param duenios
/// @param dueniosLen
void nexo_ordenarEstadiasPorFechaNombre(sEstadiaDiaria* estadias, int estadiasLen, sDuenio* duenios, int dueniosLen);

/// @fn void nexo_swapearEstadiaDuenio(sEstadiaDiaria, sEstadiaDiaria, sDuenio, sDuenio)
/// @brief intercambia de contenido de 1 al 2 y viceversa
///
/// @param estadia1
/// @param estadia2
/// @param duenio1
/// @param duenio2
void nexo_swapearEstadiaDuenio(sEstadiaDiaria* pEstadia1, sEstadiaDiaria* pEstadia2, sDuenio* pDuenio1, sDuenio* pDuenio2);

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
