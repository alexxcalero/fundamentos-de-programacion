#include<stdio.h>

/*Nombre: Alex Calero Revilla
  Código: 20206455*/
  
int main(){
	/*Este programa hallará la diferencia en días existentes entre fechas del mismo año*/
	int dd1=29,mm1=1;
	int dd2=7,mm2=4;
	
	/*Hallamos la diferencia de días de la siguiente manera:
	Sumamos la resta de (31-"el día de la fecha 1")+(31*("la diferencia de meses - 1"))+"la cantidad de días de la fecha 2"*/
	int dias_de_diferencia=(31-dd1)+(31*(mm2-mm1-1))+dd2;
	
	printf("Entre %02d/%02d y %02d/%02d existen %d días\n",dd1,mm1,dd2,mm2,dias_de_diferencia);
	return 0;
}
