/*
 ============================================================================

	Recuperatorio Primer Parcial de Laboratorio I

	Alumno: Tomas Sanchez de Bustamante
	Division: D
	Parte: 3
	OS: Linux

 ============================================================================
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include "nexo.h"


int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int ultimoIdEstadia = 100000;
	int ultimoIdDuenios = 30004;
	int ultimoIdPerros = 7002;

	sEstadiaDiaria estadias[ESTADIA_LEN];
	estadia_inicializarEstadiaIsEmpty(estadias, ESTADIA_LEN);

	sPerro perros[PERROS_LEN];
	perro_initPerros(perros, PERROS_LEN);
	perro_hardcodearPerros(perros);

	sDuenio duenios[DUENIOS_LEN] = { 	{30000, "Alan", 1152458753, OCUPADO},
										{30001, "Lucia", 1124222012, OCUPADO},
										{30002, "Hernan", 1169858740, OCUPADO},
										{30003, "Marcelo", 1124222012, OCUPADO},
										{30004, "Nicolas", 1169858740, OCUPADO}
	};



	do{
		input_getNumero(&opcion, 	"1. Reservar estadia \n"
									"2. Modificar estadia \n"
									"3. Cancelar estadia \n"
									"4. Listar estadias \n"
									"5. Listar perros \n"
									"6. Promedio de edad de los perros \n"
									"7. Perro con mas estadias \n"
									"8. Listado de perros con sus estadias \n"
									"9. Alta de perro \n"
									"10. Cantidad de dueños que se llaman alan con una estadia o mas \n"
									"11. Listado de estadias por dueñas que se llaman lucia reservadas en la 2da quincena de noviembre \n"
									"12. Salir\n"
									"Ingrese una opcion: ",
									"1. Reservar estadia \n"
									"2. Modificar estadia \n"
									"3. Cancelar estadia \n"
									"4. Listar estadias \n"
									"5. Listar perros \n"
									"6. Promedio de edad de los perros \n"
									"7. Perro con mas estadias \n"
									"8. Listado de perros con sus estadias \n"
									"9. Alta de perro \n"
									"10. Cantidad de dueños que se llaman alan con una estadia o mas \n"
									"11. Listado de estadias por dueñas que se llaman lucia reservadas en la 2da quincena de noviembre \n"
									"12. Salir\n"
									"ERROR. Ingrese una opcion: ", 1, 12);

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
				break;
			case 4:
				nexo_ordenarEstadiasPorFechaNombre(estadias, ESTADIA_LEN, duenios, DUENIOS_LEN);
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
				if(perro_mostrarPromedioDeEdadDePerros(perros, PERROS_LEN) != -1)
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
				if(nexo_mostrarPerroConMasEstadias(estadias, ESTADIA_LEN, perros, PERROS_LEN) != -1)
				{
					input_systemPause();
				}
				break;
			case 8:
				if(nexo_listarPerrosConEstadias(estadias, ESTADIA_LEN, duenios, DUENIOS_LEN, perros, PERROS_LEN) != -1)
				{
					input_systemPause();
				}
				else
				{
					input_limpiarPantalla();
					printf("No hay estadias en la base de datos! \n");
					input_systemPause();
				}
				break;
			case 9:
				if(perro_altaPerros(perros, PERROS_LEN, ultimoIdPerros) != -1)
				{
					input_limpiarPantalla();
					printf("Alta exitosa! \n");
					ultimoIdPerros++;
					input_systemPause();
				}
				break;
			case 10:
				nexo_contarDueniosAlan(estadias, ESTADIA_LEN, duenios, DUENIOS_LEN);
				break;
			case 11:
				if(nexo_listarEstadiasLucia(estadias, ESTADIA_LEN, duenios, DUENIOS_LEN, perros, PERROS_LEN) == -1)
				{
					input_limpiarPantalla();
					printf("No hay estadias por duenios que se llaman Lucia en la segunda quincena de noviembre 2021 \n");
					input_systemPause();
				}
				break;
			case 12:
				input_limpiarPantalla();
				printf("Adios! \n");
				break;
		}
	} while (opcion != 12);


	return EXIT_SUCCESS;
}
