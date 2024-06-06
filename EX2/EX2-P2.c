//Alex Calero Revilla - 20206455

#include<stdio.h>
#include<math.h>
#define PI 3.141592
#define GRAVEDAD 9.80

//Parámetros
void EfectuarPruebas(int numVarFuerza);
int VerificarDatos(double masaA,double masaB,double angulo);
int ValidarOpcion(char opcion);

int main(){
	int numVarFuerza;
	printf("Ingrese el numero de variaciones de la fuerza para las pruebas a realizar: ");
	scanf("%d",&numVarFuerza);
	if(numVarFuerza>0){
		EfectuarPruebas(numVarFuerza);
	}else
		printf("El numero de variaciones de la fuerza debe ser mayor que cero.\n");
	return 0;
}

//Módulo que efectua las pruebas del programa
void EfectuarPruebas(int numVarFuerza){
	printf("\n"); //Salto de línea que se ve en los casos de prueba
	int i=1;
	double masaA,masaB,angulo;
	char opcion;
	while(1){
		printf("Ingrese la masa del cuerpo A en kg de la prueba %d: ",i);
		scanf("%lf",&masaA);
		printf("Ingrese la masa del cuerpo B en kg de la prueba %d: ",i);
		scanf("%lf",&masaB);
		printf("Ingrese el ángulo de la plataforma en grados de la prueba %d: ",i);
		scanf("%lf",&angulo);
		//Verifico los datos ingresados
		if(VerificarDatos(masaA,masaB,angulo)){
			printf("\n"); //Salto de línea que se ve en los casos de prueba
			printf("Los resultados de un sistema con masas de %.lf kg y %.lf kg y un ángulo de %.lf grados son:\n",masaA,masaB,angulo);
			int i;
			double fuerza=10;
			double angRadianes=(PI*angulo)/(180);
			double aceleracion;
			//Iterativa para calcular la aceleracion con cada fuerza
			for(i=1;i<=numVarFuerza;i++){
				aceleracion=(fuerza-masaA*GRAVEDAD*sin(angRadianes))/(masaA+masaB);
				printf("Con una Fuerza de %.2lf N se obtiene una aceleración de %.2lf m/s2 el sistema ",fuerza,aceleracion);
				if(aceleracion>0)
					printf("avanza.\n");
				else
					printf("no avanza.\n");
				//La fuerza aumenta de 10 en 10
				fuerza=fuerza+10;
			}
			//Mensaje en pantalla para ver si el usuario quiere seguir con otra prueba o no
			printf("Desea realizar una nueva prueba: (S / N): ");
			scanf(" %c",&opcion);
			//Valido la opcion que ingrese el usuario
			if(ValidarOpcion(opcion)){
				printf("\n"); //Salto de línea que se ve en los casos de prueba
			}else
				//Termina el programa
				break;
		}else{
			printf("Las masas deben ser mayor a cero y el ángulo mayor a cero y menor a noventa.\n");
			printf("Ingrese nuevamente la prueba %d.\n",i);
			i--;
		}
		i++;
	}
}

//Módulo que verifica que las masas ingresadas y el ángulo sean correctos
int VerificarDatos(double masaA,double masaB,double angulo){
	if(masaA>0 && masaB>0 && angulo>0 && angulo<90)
		return 1;
	else
		return 0;
}

//Módulo que valida la opción que ingresa el usuario para continuar o no con el programa
int ValidarOpcion(char opcion){
	if(opcion=='S' || opcion=='s')
		return 1;
	else
		return 0;	
}
