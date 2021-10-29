/*
 * input.c
 *
 *  Created on: Oct 7, 2021
 *      Author: Tomas Sanchez de Bustamante
 */


#include "input.h"

/// @fn int myGets(char*, int)
/// @brief pide un string al usuario corroborando que no se pueda desbordar
///
/// @param cadena array donde se va a guardar el string
/// @param longitud tamanio del array
/// @return devuelve 0
static int myGets(char* cadena, int longitud)
{
	int retorno = -1;

	if(cadena != NULL && longitud > 0)
	{
		__fpurge(stdin);
		fgets(cadena, longitud, stdin);

		cadena[strlen(cadena)-1] = '\0';

		retorno = 0;
	}

	return retorno;
}

/// @fn int esNumerica(char*)
/// @brief corrobora que el string solo contenga numeros enteros
///
/// @param cadena
/// @return devuelve [1] si el string se puede convertir a int y devuelve [0] si no
static int esNumerica(char* cadena)
{
    int retorno = 1;
    int i = 0;

    if(cadena != NULL)
    {
		if((cadena[0] == '-' || cadena[0] == '+') && cadena[1] != '\0')
		{
			i=1;
		}

		for( ; cadena[i] != '\0' ; i++)
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
    }

    return retorno;
}


/// @fn int getInt(int*)
/// @brief pide al usuario un string, corrobora si es un numero entero, y si lo es lo convierte en int
///
/// @param pResultado se devuelve un numero entero en caso de que el usuario haya ingresado un numero correctamente
/// @return devuelve [0] si se ingreso un numero entero, devuelve [-1] en caso de que se ingrese otra cosa
static int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[4096];

    if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer) && pResultado != NULL)
    {
        *pResultado = atoi(buffer);
        retorno = 0;
    }

    return retorno;
}

/// @fn int esFloat(char*)
/// @brief corrobora que el string contenga numeros flotantes
///
/// @param cadena
/// @return devuelve [1] si el string se puede convertir a float y devuelve [0] si no
static int esFloat(char* cadena)
{
    int retorno = 1;
    int i = 0;
    int contadorPuntos = 0;

    if(cadena != NULL)
    {
		if((cadena[0] == '-' || cadena[0] == '+') && cadena[1] != '\0')
		{
			i=1;
		}

		for( ; cadena[i] != '\0' ; i++)
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				if(cadena[i] == '.')
				{
					contadorPuntos++;

					if(contadorPuntos > 1)
					{
						retorno = 0;
						break;
					}
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
    }

    return retorno;
}

/// @fn int getFloat(float*)
/// @brief pide al usuario un string, corrobora si es un numero flotante, y si lo es lo convierte en float
///
/// @param pResultado se devuelve un numero entero en caso de que el usuario haya ingresado un numero correctamente
/// @return devuelve [0] si se ingreso un numero flotante, devuelve [-1] en caso de que se ingrese otra cosa
static int getFloat(float* pResultado)
{
    int retorno = -1;
    char buffer[4096];

    if(myGets(buffer, sizeof(buffer)) == 0 && esFloat(buffer) && pResultado != NULL)
    {
        *pResultado = atof(buffer);
        retorno = 0;
    }

    return retorno;
}



int input_getFloat(float* pResultado, char* mensaje, char* error, int min, int max)
{
    int retorno = -1;
    float buffer;
    int respuestaBuffer;

    if(pResultado != NULL && mensaje != NULL && error != NULL && min <= max)
    {
        printf("%s",mensaje);
    	respuestaBuffer = getFloat(&buffer);

		while(respuestaBuffer == -1 || buffer < min || buffer > max)
		{
			printf("%s", error);
			respuestaBuffer = getFloat(&buffer);
		}

		*pResultado = buffer;
		retorno = 0;
    }

    return retorno;
}


int input_getNumero(int* pResultado, char* mensaje, char* error, int min, int max)
{
    int retorno = -1;
    int buffer;
    int respuestaBuffer;

    if(pResultado != NULL && mensaje != NULL && error != NULL && min <= max)
    {
        printf("%s",mensaje);
    	respuestaBuffer = getInt(&buffer);

		while(respuestaBuffer == -1 || buffer < min || buffer > max)
		{
			printf("%s", error);
			respuestaBuffer = getInt(&buffer);
		}

		*pResultado = buffer;
		retorno = 0;
    }

    return retorno;
}



int input_getString(char* string, char* message, char* errorMessage, int max)
{
	int retorno = -1;
	char buffer[256];
	int len;

	if(string != NULL && message != NULL && errorMessage != NULL && max > 0)
	{
		printf("%s", message);
		__fpurge(stdin);
		scanf("%[^\n]", buffer);
		len = strlen(buffer);

		while(len > max)
		{
			printf("%s", errorMessage);
			__fpurge(stdin);
			scanf("%[^\n]", buffer);
			len = strlen(buffer);
		}

		strcpy(string, buffer);
		retorno = 0;
	}

	return retorno;
}

int input_requestCharacter(char* character, char* message, char* errorMessage)
{
	int retorno = -1;
	char buffer[256];
	int len;

	if(character != NULL && message != NULL && errorMessage != NULL)
	{
		printf("%s", message);
		__fpurge(stdin);
		scanf("%[^\n]", buffer);
		len = strlen(buffer);

		while(len > 1)
		{
			printf("%s", errorMessage);
			__fpurge(stdin);
			scanf("%[^\n]", buffer);
			len = strlen(buffer);
		}

		*character = buffer[0];
		retorno = 0;
	}

	return retorno;
}


int input_requestStringOnlyLetters(char* string, char* message, char* errorMessage, int max)
{
	int retorno = -1;
	char buffer[256];
	int len;
	int errorString;

	if(string != NULL && message != NULL && errorMessage != NULL && max > 0)
	{
		printf("%s", message);
		__fpurge(stdin);
		scanf("%[^\n]", buffer);
		len = strlen(buffer);
		errorString = validarLetras(buffer, len);

		while(len > max || errorString == -1)
		{
			printf("%s", errorMessage);
			__fpurge(stdin);
			scanf("%[^\n]", buffer);
			len = strlen(buffer);
			errorString = validarLetras(buffer, len);
		}


		strcpy(string, buffer);
		retorno = 0;
	}

	return retorno;
}


int validarLetras(char* cadena, int len)
{
	int retorno = 0;
	int i;

	if(cadena != NULL && len > 0)
	{
		for(i=0 ; i<len ; i++)
		{
			input_convertirStringMinuscula(cadena);

			if((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] != ' ' || cadena[0] == ' ' ))
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int input_confirmacion(char* mensaje, char* error)
{
	int retorno = -1;
	char confirmacion[3];

	if(mensaje != NULL && error != NULL)
	{
		if(input_getString(confirmacion, mensaje, error, 3) == -1)
		{
			printf("ERROR FATAL");
		}

		input_convertirStringMinuscula(confirmacion);

		if(strcmp(confirmacion, "si") == 0)
		{
			retorno = 0;
		}
	}

	return retorno;
}

void input_limpiarPantalla(void)
{
	printf("\n\n\n\n\n\n     .-.     .-.     .-.     .-.     .-.     .-.     .-. \n"
			"`._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'   `._.'\n\n\n\n\n\n");
}


void input_convertirStringMinuscula(char* string)
{
	int i;

	if(string != NULL)
	{
		for(i=0 ; i<strlen(string) ; i++)
		{
			string[i] = tolower(string[i]);
		}
	}
}

int input_pedirStringNombreApellido(char* string, char* message, char* errorMessage, int max)
{
	int retorno = -1;

	if(string != NULL && message != NULL && errorMessage != NULL && max > 0)
	{
		if(input_requestStringOnlyLetters(string, message, errorMessage, max) == 0)
		{
			cambiarInicialesMayuscula(string);
			retorno = 0;
		}
	}

	return retorno;
}

void cambiarInicialesMayuscula(char* string)
{
    int i;

    if(string != NULL)
	{
		for(i=0 ; i<strlen(string) ; i++)
		{
		    if(i==0)
            {
                string[i] = toupper(string[i]);
            }
            else if(string[i] == ' ')
            {
                string[i+1] = toupper(string[i+1]);
            }

		}
	}
}

void input_systemPause(void)
{
	printf("\n\nIngrese ENTER para continuar... ");
	__fpurge(stdin);
	getchar();
	input_limpiarPantalla();
}



