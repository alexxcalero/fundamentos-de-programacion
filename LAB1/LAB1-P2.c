#include<stdio.h>
#include<math.h>
#define PI 3.141592

/*Nombre: Alex Calero Revilla*/
/*Código: 20206455*/

int main(){
	double diametro1,diametro2,generatriz1,generatriz2;
	printf("Ingrese el diámetro y la generatriz del cono 1: ");
	scanf("%lf %lf",&diametro1,&generatriz1);
	printf("Ingrese el diámetro y la generatriz del cono 2: ");
	scanf("%lf %lf",&diametro2,&generatriz2);
	
	/*diámetro=2*radio*/
	/*radio=diámetro/2*/
	double radio1,radio2;
	radio1=diametro1/2;
	radio2=diametro2/2;
		
	double area_lateral1,area_lateral2,area_base1,area_base2,area_total1,area_total2;
	area_lateral1=PI*radio1*generatriz1;
	area_lateral2=PI*radio2*generatriz2;
	area_base1=PI*pow(radio1,2);
	area_base2=PI*pow(radio2,2);
	area_total1=area_lateral1+area_base1;
	area_total2=area_lateral2+area_base2;
	
	/*Aplicando el teorema de Pitágoras*/
	/*radio^2 + altura^2 = generatriz^2*/
	/*altura = sqrt(generatriz^2 - radio^2)*/
	double altura1,altura2;
	altura1=sqrt(pow(generatriz1,2)-pow(radio1,2));
	altura2=sqrt(pow(generatriz2,2)-pow(radio2,2));
	
	double volumen1,volumen2;
	volumen1=((double)1/3)*PI*pow(radio1,2)*altura1;
	volumen2=((double)1/3)*PI*pow(radio2,2)*altura2;
	
	int mayor_altura;
	mayor_altura=(altura1>=altura2)*1 + (altura1<altura2)*2;
	
	printf("\nResultados del Cono 1:\n");
	printf("Altura: %.2lf\n",altura1);
	printf("Área: %.2lf\n",area_total1);
	printf("Volumen: %.2lf\n\n",volumen1);
	printf("Resultados del Cono 2:\n");
	printf("Altura: %.2lf\n",altura2);
	printf("Área: %.2lf\n",area_total2);
	printf("Volumen: %.2lf\n\n",volumen2);
	printf("El cono %d tiene mayor altura.",mayor_altura);
	return 0;
}
