/*
El conserje de un edificio está muy atareado con el cobro 
de los gastos comunidades de los habitantes del edificio. 
Le pide que le ayude a con la organización de los departamentos 
del edificio y para eso le brinda la siguiente estructura de datos:

El conserje necesita saber algunas cosas específicas del edicio, 
las cuales usted debe implementar. Estas son:

	* Deuda total del edicio.
	* Gastos mensuales de un piso dado.
	* Cantidad de departamentos desocupados de edificio.

Se brinda como ayuda el siguiente esquema de un piso del edificio.



-----------------------------
|1	|2	|3	 |... |... |...	|
|___|___|____|____|____|____|
|	PASILLO			   |...	|
|______________________|____|
|N	|...|... |... |... |...	|
|	|	|	 |	  |	   |	|
-----------------------------
*/

#include <cstdlib>
#include <iostream>

using namespace std;

class Departamento{

	string dueño;
	int piso;
	bool ocupado;

	float agua_mes, gas_mes, internet_mes, corriente_mes;
	float agua_deuda, gas_deuda, internet_deuda, corriente_deuda;

	Departamento *arriba;
	Departamento *abajo;

	Departamento *depto_sig;
	Departamento *depto_ant;



float deuda_total_edificio(Departamento *p){
	Departamento *aux = p;
	while(aux->depto_ant != NULL){
		aux = aux->depto_ant;
	}
	while(aux->abajo != NULL){
		aux = aux->abajo;
	}
	float suma = 0;
	Departamento *inicio = aux;
	while(aux && aux->arriba != NULL){
		
		while(aux && aux->depto_sig != NULL){
			suma = aux->agua_deuda + aux->agua_mes + suma;
			aux = aux->depto_sig;
		}

	aux = inicio->arriba;
	}



}

float gastos_mensuales_piso(int p, Departamento *p){
	float suma_gastos = 0;
	Departamento *aux = p;
	while(aux){
		suma_gastos += aux->agua_mes 
						+ aux->agua_deuda
						+ aux->gas_mes
						+ aux->gas_deuda
						+ aux->internet_mes
						+ aux->internet_deuda
						+ aux->corriente_mes
						+ aux->corriente_deuda;
		aux = aux->depto_sig;
	}
	aux = p->depto_ant;
	while(aux){
		suma_gastos += aux->agua_mes 
						+ aux->agua_deuda
						+ aux->gas_mes
						+ aux->gas_deuda
						+ aux->internet_mes
						+ aux->internet_deuda
						+ aux->corriente_mes
						+ aux->corriente_deuda;
		aux = aux->depto_ant;
	}

	return suma_gastos;
}

int departamentos_desocupados(Departamento *p){
	//Es igual al primero.	
}

};