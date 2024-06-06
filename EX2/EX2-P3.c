//Alex Calero Revilla - 20206455

#include<stdio.h>
#include<math.h>

//Parámetros
int VerificarNumero(int numero);
void CalcularNumeroMotzkin(int numero,int *numFormas);
int CalcularFactorial(int numero);
int CalcularCombinatoria(int numero1,int numero2);

int main(){
	int numero,numFormas;
	while(1){
		printf("Ingrese el número n para calcular Mn: ");
		scanf("%d",&numero);
		if(VerificarNumero(numero)==1){
			CalcularNumeroMotzkin(numero,&numFormas);
			printf("Para el valor %d es posible dibujar dichos acordes de %d formas\n",numero,numFormas);
		}else if(VerificarNumero(numero)==2)
			printf("El valor ingresado no es mayor a 1\n");
		else
			break;
	}
	return 0;
}

//Módulo que verifica que el número sea correcto
int VerificarNumero(int numero){
	if(numero>1)
		return 1;
	else if(numero==0)
		return 0;
	else
		return 2;
}

//Módulo para hallar el número de Motzkin
void CalcularNumeroMotzkin(int numero,int *numFormas){
	*numFormas=0;
	int mitad=(numero/2);
	int k;
	double combinatoria1,combinatoria2;
	double sumatoria=0;
	for(k=0;k<=mitad;k++){
		combinatoria1=CalcularCombinatoria((2*k),k);
		combinatoria2=CalcularCombinatoria(numero,(2*k));
		sumatoria=sumatoria+((1/(k+1))*combinatoria1*combinatoria2);
		printf("En la iteración %d el término vale: %.lf\n",k+1,sumatoria);
		if(sumatoria>*numFormas)
			*numFormas=sumatoria;
	}
}

//Módulo para hallar el factorial
int CalcularFactorial(int numero){
	int factorial=1;
	int i;
	for(i=1;i<=numero;i++){
		factorial=factorial*i;
	}
	return factorial;
}

//Módulo para hallar la combinatoria
int CalcularCombinatoria(int numero1,int numero2){
	int a=CalcularFactorial(numero1);
	int b=CalcularFactorial(numero2);
	int a_menos_b=CalcularFactorial(abs(numero1-numero2));
	return a/b*(a_menos_b);
}
