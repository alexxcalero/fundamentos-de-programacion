#include<stdio.h>

/*Nombre: Alex Calero Revilla
  C�digo: 20206455*/
  
int main(){
	/*Este programa hallar� la diferencia en d�as existentes entre fechas del mismo a�o*/
	int dd1=29,mm1=1;
	int dd2=7,mm2=4;
	
	/*Hallamos la diferencia de d�as de la siguiente manera:
	Sumamos la resta de (31-"el d�a de la fecha 1")+(31*("la diferencia de meses - 1"))+"la cantidad de d�as de la fecha 2"*/
	int dias_de_diferencia=(31-dd1)+(31*(mm2-mm1-1))+dd2;
	
	printf("Entre %02d/%02d y %02d/%02d existen %d d�as\n",dd1,mm1,dd2,mm2,dias_de_diferencia);
	return 0;
}
