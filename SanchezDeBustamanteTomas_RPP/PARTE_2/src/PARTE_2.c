/*
 ============================================================================

	Recuperatorio Primer Parcial de Laboratorio I

	Alumno: Tomas Sanchez de Bustamante
	Division: D
	OS: Linux

 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "nexo.h"


int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int ultimoIdEstadia = 100002; // CAMBIAAAAAAAAAAR CUANDO SACAMOS HARDCODEOOO // CAMBIAAAAAAAAAAR CUANDO SACAMOS HARDCODEOOO
	int ultimoIdDuenios = 30004;
	int ultimoIdPerros = 7002;

	sEstadiaDiaria estadias[ESTADIA_LEN];
	inicializarEstadiaIsEmpty(estadias, ESTADIA_LEN);

	sPerro perros[PERROS_LEN] = { 	{7000, "Lobo", "Sharpei", 2 ,OCUPADO},
									{7001, "Sheila", "Golden", 12, OCUPADO},
									{7002, "Reina", "Galgo", 13, OCUPADO}
	};


	sDuenio duenios[DUENIOS_LEN] = { 	{30000, "Juan", 1152458753, OCUPADO},
										{30001, "Lucia", 1124222012, OCUPADO},
										{30002, "Hernan", 1169858740, OCUPADO},
										{30003, "Marcelo", 1124222012, OCUPADO},
										{30004, "Nicolas", 1169858740, OCUPADO}
	};

	// SACAAAAAAAAAR HARDCODEO!!!!!!!!!!!!!!!!!!!!
	sEstadiaDiaria estadiasAux[ESTADIA_LEN] = {	{100000, 30000, 7001, {2,2,2021},OCUPADO}, // SACAAAAAAAAAR HARDCODEO!!!!!!!!!!!!!!!!!!!!
												{100001, 30002, 7000, {2,3,2022},OCUPADO}, // SACAAAAAAAAAR HARDCODEO!!!!!!!!!!!!!!!!!!!!
												{100002, 30000, 7002, {4,2,2021},OCUPADO}  // SACAAAAAAAAAR HARDCODEO!!!!!!!!!!!!!!!!!!!!
	};

	for(int i=0 ; i<3 ; i++)
	{
		estadias[i] = estadiasAux[i];
	}
	// SACAAAAAAAAAR HARDCODEO!!!!!!!!!!!!!!!!!!!!

	do{
		input_getNumero(&opcion, 	"1. Reservar estadia \n"
									"2. Modificar estadia \n"
									"3. Cancelar estadia \n"
									"4. Listar estadias \n"
									"5. Listar perros \n"
									"6. Promedio de edad de los perros \n"
									"7. Perro con mas estadias \n"
									"8. Listado de perros con sus estadias \n"
									"9. Salir\n"
									"Ingrese una opcion: ",
									"1. Reservar estadia \n"
									"2. Modificar estadia \n"
									"3. Cancelar estadia \n"
									"4. Listar estadias \n"
									"5. Listar perros \n"
									"6. Promedio de edad de los perros \n"
									"7. Perro con mas estadias \n"
									"8. Listado de perros con sus estadias \n"
									"9. Salir\n"
									"ERROR. Ingrese una opcion: ", 1, 9);

		switch(opcion)
		{
			case 1:
				if(nexo_reservarEstadia(estadias, ESTADIA_LEN, duenios, DUENIOS_LEN, perros, PERROS_LEN, ultimoIdEstadia, ultimoIdPerros, ultimoIdDuenios) != -1)
				{
					input_limpiarPantalla();
					printf("Reserva exitosa! \n");
					ultimoIdEstadia++;
					input_systemPause();
				}
				break;
			case 2:
				nexo_modificarEstadia(estadias, ESTADIA_LEN, duenios, DUENIOS_LEN, perros, PERROS_LEN, ultimoIdEstadia, ultimoIdPerros);
				break;
			case 3:
				if(nexo_cancelarEstadia(estadias, ESTADIA_LEN, duenios, DUENIOS_LEN, perros, PERROS_LEN, ultimoIdEstadia) != -1)
				{
					input_limpiarPantalla();
					printf("Baja exitosa! \n");
					input_systemPause();
				}
				else
				{
					input_limpiarPantalla();
					printf("ERROR: ARRAYS VACIOS! \n");
					input_systemPause();
				}
				break;
			case 4:
				ordenarEstadiasPorFechaNombre(estadias, ESTADIA_LEN, duenios, DUENIOS_LEN);
				if(nexo_imprimirEstadias(estadias, ESTADIA_LEN, duenios, DUENIOS_LEN, perros, PERROS_LEN) != -1)
				{
					input_systemPause();
				}
				else
				{
					input_limpiarPantalla();
					printf("No hay estadias reservadas! \n");
					input_systemPause();
				}
				break;
			case 5:
				if(perro_mostrarPerros(perros, PERROS_LEN) != -1)
				{
					input_systemPause();
				}
				else
				{
					input_limpiarPantalla();
					printf("No hay perros en la base de datos! \n");
					input_systemPause();
				}
				break;
			case 6:
				if(mostrarPromedioDeEdadDePerros(perros, PERROS_LEN) != -1)
				{
					input_systemPause();
				}
				else
				{
					input_limpiarPantalla();
					printf("No hay perros en la base de datos! \n");
					input_systemPause();
				}
				break;
			case 7:
				if(mostrarPerroConMasEstadias(estadias, ESTADIA_LEN, perros, PERROS_LEN) != -1)
				{
					input_systemPause();
				}
				break;
			case 8:
				if(listarPerrosConEstadias(estadias, ESTADIA_LEN, duenios, DUENIOS_LEN, perros, PERROS_LEN) != -1)
				{
					input_systemPause();
				}
				else
				{
					input_limpiarPantalla();
					printf("No hay perros en la base de datos! \n");
					input_systemPause();
				}
				break;
			case 9:
				input_limpiarPantalla();
				printf("Adios! \n");
				break;
		}
	} while (opcion != 9);


	return EXIT_SUCCESS;
}
