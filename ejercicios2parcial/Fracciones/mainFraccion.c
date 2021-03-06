#include <stdlib.h>
#include <stdio.h>
#include "fraccion.h"

void manejaError(int);
void solicitarDatos(FRAC);
void mostrar(FRAC);
void liberar(FRAC, FRAC, FRAC);

void main()
{
	FRAC n1, n2, n3;

	n1 = crearFraccion();
	n2 = crearFraccion();
	n3 = crearFraccion();
	printf("Fraccion 1\n");
	solicitarDatos(n1);
	printf("Fraccion 2\n");
	solicitarDatos(n2);
	printf("Suma\n");
	n3 = suma(n1, n2);
	mostrar(n3);
	printf("Resta\n");
	n3 = resta(n1, n2);
	mostrar(n3);
	printf("Producto\n");
	n3 = multi(n1, n2);
	mostrar(n3);
	printf("Cociente\n");
	n3 = divi(n1, n2);
	mostrar(n3);
	printf("Inversa\n");
	n3 = inversa(n1);
	mostrar(n3);
	n3 = inversa(n2);
	mostrar(n3);
	//Liberada memora
	liberar(n1, n2, n3);
}

void solicitarDatos(FRAC n)
{
	float num, denom;
	printf("Introduzca el numerador\n");
	scanf("%f", &num);
	printf("Introduzca el denominador\n");
	scanf("%f", &denom);
	n = asignaNum(n, num);
	n = asignaDenom(n, denom);
}

void mostrar(FRAC n)
{
	printf("Numerador: %f \n", obtenNum(n));
	printf("Denomindor: %f \n\n\n", obtenDenom(n));
}
void manejaError(int e)
{
	char *errores[] = {"No hay memoria disponible"};
	printf("%s", errores[e]);
}
void liberar(FRAC n1, FRAC n2, FRAC n3)
{
	free(n1);
	free(n2);
	free(n3);
}
