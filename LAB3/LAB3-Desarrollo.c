/*Nombre: Alex Calero Revilla*/
/*C�digo: 20206455*/

#include<stdio.h>

int main(){
	int contador,numero1,numero2,cantDivisoresComunes,sumaDivisoresComunes;
	double promedio;
	
	printf("Ingrese los dos numeros a evaluar: ");
	scanf("%d %d",&numero1,&numero2);
	
	/*inicio el contador en 2, debido a que la indicaci�n dice: "no contar al mismo n�mero como divisor" y
	al hacer la operaci�n de "(numero/1)=(el mismo n�mero)", por ende, iniciamos en 2*/
	contador=2;
	
	cantDivisoresComunes=0;
	sumaDivisoresComunes=0;
	
	/*la condici�n tiene que ser "contador<numero", ya que si hacemos que "contador<=numero",
	cuando "contador=numero" y operemos "(numero/contador)=1", pero la indicaci�n dice: "no contar al n�mero 1"*/
	while((contador<numero1)&&(contador<numero2)){
		if((numero1%contador==0)&&(numero2%contador==0)){
			sumaDivisoresComunes+=contador;
			cantDivisoresComunes++;
		}
		contador++;
	}
	
	/*promedio de divisores comunes = suma de divisores comunes/cantidad de divisres comunes*/
	promedio=((double)sumaDivisoresComunes)/cantDivisoresComunes;
	
	if(cantDivisoresComunes==0){
		printf("Los numeros ingresados no tienen divisores en com�n.");
	}
	else{
		printf("La suma de divisores comunes entre los dos n�meros es: %d\n",sumaDivisoresComunes);
		printf("El promedio de divisores comunes entre los dos n�meros es: %.2lf\n",promedio);
	}
		
	return 0;
}
