/*
 * input.h
 *
 *  Created on: Oct 7, 2021
 *      Author: Tomas Sanchez de Bustamante
 */

#ifndef INPUT_H_
#define INPUT_H_


#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VACIO 1
#define OCUPADO 0


/// @fn void input_systemPause(void)
/// @brief pide al usuario que ingrese enter para continuar
///
void input_systemPause(void);

/// @fn int input_pedirStringNombreApellido(char*, char*, char*, int)
/// @brief pide un nombre o apellido al usuario
///
/// @param string devuelve un string en caso de que lo que se haya ingresado este correcto
/// @param message mensaje para que el usuario ingrese un string
/// @param errorMessage mensaje para que el usuario en caso de que haya contestado con un error
/// @param max numero maximo de caracteres que puede ingresar
/// @return devuelve [0] en caso de que se haya ingresado un string correctamente, caso contrario se devolvera un [-1]
int input_pedirStringNombreApellido(char* string, char* message, char* errorMessage, int max);

/// @fn void cambiarInicialesMayuscula(char*)
/// @brief Cambia las iniciales a mayuscula
///
/// @param string string
void cambiarInicialesMayuscula(char* string);

/// @fn int input_confirmacion(char*, char*)
/// @brief se le pide al usuario que confirme alguna accion, si escribe "si" se devuelve [0]
///
/// @param mensaje mensaje para el usuario
/// @param error mensaje de error para el usuario
/// @return si el usuario confirma devuelve [0] caso contrario [-1]
int input_confirmacion(char* mensaje, char* error);

/// @fn void input_limpiarPantalla(void)
/// @brief imprime espacios y una barra para hacer el menu mas prolijo
///
void input_limpiarPantalla(void);

/// @fn void input_convertirStringMinuscula(char*)
/// @brief cambia todas las letras de un string a minuscula
///
/// @param string palabra a modificar
void input_convertirStringMinuscula(char* string);


/// @fn int input_requestCharacter(char*, char*, char*)
/// @brief Imprime mensaje pidiendo un caracter al usuario
///
/// @param character char
/// @param message mensaje para el usuario
/// @param errorMessage mensaje de error para el usuario
/// @return  si se ingreso correctamente devuelve [0] caso contrario devuelve [-1]
int input_requestCharacter(char* character, char* message, char* errorMessage);

/// @fn int input_getNumero(int*, char*, char*, int, int)
/// @brief imprime mensaje pidiendo un numero entero al usuario, en caso de que se respete el minimo y el maximo, se devolvera un numero int,
/// 		 caso contrario se imprime un mensaje de error con su reintento
///
/// @param pResultado devuelve numero int en caso de que lo que se haya ingresado este correcto
/// @param mensaje mensaje para que el usuario ingrese un numero entero
/// @param error mensaje para que el usuario en caso de que haya contestado con un error
/// @param min numero minimo que pueda ingresar el usuario
/// @param max numero minimo que pueda ingresar el usuario
/// @return devuelve [0] en caso de que se haya ingresado un numero correctamente, caso contrario se devolvera un [-1]
int input_getNumero(int* pResultado, char* mensaje, char* error, int min, int max);

/// @fn int input_getFloat(float*, char*, char*, int, int)
/// @brief imprime mensaje pidiendo un numero flotante al usuario, en caso de que se respete el minimo y el maximo, se devolvera un numero flotante,
/// 		 caso contrario se imprime un mensaje de error con su reintento
///
/// @param pResultado devuelve numero flotante en caso de que lo que se haya ingresado este correcto
/// @param mensaje mensaje para que el usuario ingrese un numero flotante
/// @param error mensaje para que el usuario en caso de que haya contestado con un error
/// @param min numero minimo que pueda ingresar el usuario
/// @param max numero minimo que pueda ingresar el usuario
/// @return devuelve [0] en caso de que se haya ingresado un numero correctamente, caso contrario se devolvera un [-1]
int input_getFloat(float* pResultado, char* mensaje, char* error, int min, int max);

/// @fn int input_getString(char*, char*, char*, int)
/// @brief imprime mensaje pidiendo un string al usuario, en caso de que se respete se devolvera el string,
/// 		 caso contrario se imprime un mensaje de error con su reintento
///
/// @param string devuelve un string en caso de que lo que se haya ingresado este correcto
/// @param message mensaje para que el usuario ingrese un string
/// @param errorMessage mensaje para que el usuario en caso de que haya contestado con un error
/// @param max numero maximo de caracteres que puede ingresar
/// @return devuelve [0] en caso de que se haya ingresado un string correctamente, caso contrario se devolvera un [-1]
int input_getString(char* string, char* message, char* errorMessage, int max);

/// @fn int validarLetras(char*, int)
/// @brief verifica que el string solo contenga letras
///
/// @param string
/// @param len
/// @return devuelve [0] en caso de que se ingresen solo letras, caso contrario devuelve [-1]
int validarLetras(char* string, int len);

/// @fn int input_requestStringOnlyLetters(char*, char*, char*, int)
/// @brief imprime mensaje pidiendo un string al usuario, en caso de que se respete se devolvera el string,
/// 		 caso contrario se imprime un mensaje de error con su reintento
///
/// @param string returns a string in case everything is correct
/// @param message mensaje para que el usuario ingrese un string
/// @param errorMessage mensaje para que el usuario en caso de que haya contestado con un error
/// @param max numero maximo de caracteres que puede ingresar
/// @return devuelve [0] en caso de que se haya ingresado un string de solamente letras, caso contrario se devolvera un [-1]
int input_requestStringOnlyLetters(char* string, char* message, char* errorMessage, int max);


#endif /* INPUT_H_ */
