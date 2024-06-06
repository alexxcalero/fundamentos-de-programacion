/*Nombre: Alex Calero Revilla*/
/*Código: 20206455*/

#include<stdio.h>

int main(){
	int contador,numero1,numero2,cantDivisoresComunes,sumaDivisoresComunes;
	double promedio;
	
	printf("Ingrese los dos numeros a evaluar: ");
	scanf("%d %d",&numero1,&numero2);
	
	/*inicio el contador en 2, debido a que la indicación dice: "no contar al mismo número como divisor" y
	al hacer la operación de "(numero/1)=(el mismo número)", por ende, iniciamos en 2*/
	contador=2;
	
	cantDivisoresComunes=0;
	sumaDivisoresComunes=0;
	
	/*la condición tiene que ser "contador<numero", ya que si hacemos que "contador<=numero",
	cuando "contador=numero" y operemos "(numero/contador)=1", pero la indicación dice: "no contar al número 1"*/
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
		printf("Los numeros ingresados no tienen divisores en común.");
	}
	else{
		printf("La suma de divisores comunes entre los dos números es: %d\n",sumaDivisoresComunes);
		printf("El promedio de divisores comunes entre los dos números es: %.2lf\n",promedio);
	}
		
	return 0;
}
