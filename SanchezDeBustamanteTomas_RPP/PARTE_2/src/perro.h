/*
 * perro.h
 *
 *  Created on: Oct 22, 2021
 *      Author: user
 */

#ifndef PERRO_H_
#define PERRO_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

#define PERROS_LEN 3
#define NOMBRE_RAZA_PERRO 21


typedef struct{
	int idPerro;
	char nombre[NOMBRE_RAZA_PERRO];
	char raza[NOMBRE_RAZA_PERRO];
	int edad;
	int isEmpty;

} sPerro;


/// @fn float promedioDeEdadDePerros(Perro*, int)
/// @brief imprime el promedio de edad de los perros
///
/// @param perros array de perros
/// @param perrosLen longitud del array de perros
/// @return si hay perros devuelve [0], caso de que no haya ninguno devuelve [-1]
int mostrarPromedioDeEdadDePerros(sPerro* perros,int perrosLen);

/// @fn int perro_encontrarPerroId(Perro*, int, int)
/// @brief se le ingresa un ID y lo busca en el array de perros, caso de que lo encuentre devuelve el indice
///
/// @param perros array de perros
/// @param perrosLen longitud de array de perros
/// @param reservaId ID que se desee buscar el indice
/// @return caso de encontrar al perro se devulve el indice, sino se encuentra devuelve [-1]
int perro_encontrarPerroId(sPerro* perros, int perrosLen, int idPerroAux);

/// @fn int perro_encontrarIndicePerro(sPerro*, int, int)
/// @brief compara el id ingresado en la lista de perros
///
/// @param perro
/// @param perrosLen
/// @param idPerroAux
/// @return si encuentra al perro devuelve el indice, caso contrario [-1]
int perro_encontrarIndicePerro(sPerro* perros, int perrosLen, int idPerroAux);

/// @fn void dperro_mostrarTopMenuPerros(void)
/// @brief muestra la barra de menu de perros
///
void perro_mostrarTopMenuPerros(void);

/// @fn void perro_mostrarPerro(sPerro)
/// @brief imprime datos de un perro
///
/// @param perro estructura de un perro
void perro_mostrarPerro(sPerro perro);

/// @fn int perro_mostrarPerros(sPerro*, int)
/// @brief muestra todos los perros en la base de datos
///
/// @param perros array de perros
/// @param len longitud del array de perros
/// @return devuelve [0] en caso de poder mostrar los perros, caso que no haya ninguno devuelve [-1]
int perro_mostrarPerros(sPerro* perros, int perrosLen);

#endif /* PERRO_H_ */
