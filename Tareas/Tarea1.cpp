// Tarea1Graficas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


/*
* TAREA 1: GRÁFICAS POR COMPUTADORA
* Nombre: Andrea Bellesia Álvarez de la Cuadra
* Clave Única: 188642
* 
* Instrucciones: Escribir un programa en C para manipular una nómina de empleados en una estructura dinámica 
usando apuntadores.
*/


//Se cargan las librerías necesarias para manipular cadenas de caracteres (string)
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXIMA_LONGITUD_CADENA 30 //longitud de los arreglos que contendrán alguna cadena de caracteres



//ESTRUCTURA DE TIPO EMPLEADO
typedef struct EMP {
	char nombre[MAXIMA_LONGITUD_CADENA];
	int id;
	struct DIR dir; //tiene un atributo de tipo DIR
	float salario;
	char genero;
	int num_hijos;
	char estado_civil;
	struct EMP* ant; //va a apuntar al anrterior empleado de la lista
	struct EMP* sig; //va a apuntar al siguiente empleado de la lista
} empleado;


//ESTRUCTURA ADICIONAL PARA LA DIRECCIÓN
typedef struct DIR {
	char calle[MAXIMA_LONGITUD_CADENA];
	int num;
	int cp;
	char ciudad[MAXIMA_LONGITUD_CADENA];
	char pais[MAXIMA_LONGITUD_CADENA];
} direccion;




//Función que inserta el empleado
void insertar_empleado(EMP *nuevo, EMP *lista ) {
	if (lista == NULL) { //si la lista está vacía, se inicia con el nuevo empleado cuyo ID  es 1
		lista = nuevo;
		lista->id = 1;
	}
	else { //si la lista ya contiene elementos, entonces se recorre hasta encontrar el último 
		//y se inserta el nuevo empleado
		EMP* buscador = lista;
		while (lista->sig != NULL) {
			buscador = buscador->sig;
		}
		buscador->sig = nuevo;
		nuevo->ant = buscador;
		nuevo->id = buscador->id + 1; //el ID del nuevo empleado es el ID del empleado anterior + 1
	}
}

//función que crea un empleado
void crear_empleado(empleado *e) { //recibe un apuntador de tipo empleado
	//Agrega todos los datos del empleado excepto el ID que se egenera automáticamente
	printf("Agregar datos para un empleado\n");
	printf("Nombre completo: ");
	fgets(e->nombre, MAXIMA_LONGITUD_CADENA, stdin);
	e->nombre[strlen(e->nombre) - 1] = '\0';
	printf("Agregar los datos de la dirección: \n");
	printf("Calle: ");
	fgets(e->dir.calle, MAXIMA_LONGITUD_CADENA, stdin);
	printf("Número: ");
	scanf_s("%d", e->dir.num);
	printf("Código postal: ");
	scanf_s("%d", e->dir.cp);
	printf("Ciudad: ");
	fgets(e->dir.ciudad, MAXIMA_LONGITUD_CADENA, stdin);
	printf("País: ");
	fgets(e->dir.pais, MAXIMA_LONGITUD_CADENA, stdin);
	printf("Genero (M/F/N): ");
	scanf_s("%c", &e->genero);
	printf("Estado civil(soltero=s, casado=c): ");
	scanf_s("%c", &e->estado_civil);
	printf("Numero de hijos: ");
	scanf_s("%d", &e->num_hijos);
	printf("Salario mensual: ");
	scanf_s("%f", &e->salario);
	fgetc(stdin);
 }

//Función que borra un epleado:
//Cambia los apuntadores para que ya no tomen en cuenta al que se quiere eliminar
void borrar_empleado(int idB, EMP *e) {
	EMP* buscador = e;
	while (buscador->id != idB) {
		buscador = buscador->sig;
	}
	buscador->sig->ant = buscador->ant;
	buscador->ant->sig = buscador->sig;
}

//Función que muestra la información de un empleado dado su ID 
empleado mostrar_empleado(int idB, EMP* buscador) {
	//recorre toda la lista hasta que encuentra el id buscado
	while (buscador->id != idB) {
		buscador = buscador->sig;
	}
	printf("\n\nInformacion del empleado\n");
	printf("Nombre del empleado %s\n", buscador->nombre);
	printf("Genero del empleado %c\n", buscador->genero);
	printf("Numero de hijos del empleado %d\n", buscador->num_hijos);
	printf("Salario mensual del empleado %f\n", buscador->salario);
	
}

void los_empleados(EMP *e) {
	//recorre toda la lista, imprimiendo la información de cada empleado
	while (e != NULL) {
		printf("\n\nInformacion del empleado\n");
		printf("ID del empleado %s\n", e->id);
		printf("Nombre del empleado %s\n", e->nombre);
		printf("Dirección del empleado: \n");
		printf("	Calle: %s", e->dir.calle);
		printf("	Número: %d", e->dir.num);
		printf("	Código posta: %d", e->dir.cp);
		printf("	Ciudad: %s", e->dir.ciudad);
		printf("	País: %s", e->dir.pais);
		printf("Genero del empleado %c\n", e->genero);
		printf("Numero de hijos del empleado %d\n", e->num_hijos);
		printf("Salario mensual del empleado %f\n", e->salario);
		printf("Estado civil del empleado %c\n", e->estado_civil);
		e = e->sig;
	}
}

int main()
{
	EMP* e; //inicio de la lista
	e = (empleado*)malloc(sizeof(empleado));
	char accion;
	while (accion != 't')
	{
		printf("¿Qué es lo que deseas hacer?: \n a) Agregar un empleado\nb) Borrar un empleado\nc) Encontrar la información de un empleado\nd) Imprimir la información de todos los empleados\n t)Terminar");
		scanf_s("%c", accion);
		switch (accion) {
		case 'a':
			EMP * nuevo;
			crear_empleado(nuevo);
			insertar_empleado(e, e->sig);
			break;
		case 'b':
			int id;
			printf("¿Cuál es el ID del empleado?: ");
			scanf_s("%d", id);
			borrar_empleado(id, e);
			break;
		case 'c':
			int id;
			printf("¿Cuál es el ID del empleado?: ");
			scanf_s("%d", id);
			mostrar_empleado(id, e);
			break;
		case 'd':
			los_empleados(e);
			break;
		}
	}

}

